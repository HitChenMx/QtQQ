#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_serverManager(nullptr),
    m_modelClient(new QStringListModel())
{
    ui->setupUi(this);

    // 让界面显示在显示屏1的中间
    int screenWidth = QApplication::desktop()->screenGeometry(0).width();
    int screenHeight = QApplication::desktop()->screenGeometry(0).height();
    this->move(screenWidth/2-this->width()/2, screenHeight/2-this->height()/2);

    bool _init_success = m_init();
    if(_init_success == false)
    {
        QMessageBox::critical(this, QStringLiteral("错误"), QStringLiteral("初始化失败！"));
        abort();
    }
    m_serverManager_init();
}

MainWindow::~MainWindow()
{
    qDebug() << "~MainWindow()";
    if(m_serverManager != nullptr)
    {
        if(m_serverManager->isListening())
            m_serverManager->close();                   // --- 停止监听 ---
        m_serverManager->deleteLater();
    }
    m_modelClient->deleteLater();
    delete ui;
}

bool MainWindow::m_init()
{
    // 添加状态显示
    m_listenState = new QLabel(QStringLiteral("监听状态:"));
    m_socketState = new QLabel(QStringLiteral("Socket状态:"));
    m_listenState->setMinimumWidth(300);
    m_socketState->setMinimumWidth(300);
    ui->statusbar->addWidget(m_listenState);
    ui->statusbar->addWidget(m_socketState);
    // 设置使能
    ui->action_startListen->setEnabled(true);
    ui->action_stopListen->setEnabled(false);
    // 设置model
    ui->lstClientView->setModel(m_modelClient);
    ui->lstClientView->setEditTriggers(QAbstractItemView::NoEditTriggers);  // 禁用编辑
    // 界面上的控件：连接信号与槽
    connect(ui->btnSendMessage, SIGNAL(clicked()), this, SLOT(slot_btnSendMessage_clicked()));
    connect(ui->edtMessage, SIGNAL(returnPressed()), this, SLOT(slot_btnSendMessage_clicked()));
    connect(ui->action_exit, SIGNAL(triggered()), this, SLOT(slot_action_exit_triggered()));
    connect(ui->action_startListen, SIGNAL(triggered()), this, SLOT(slot_action_startListen_triggered()));
    connect(ui->action_stopListen, SIGNAL(triggered()), this, SLOT(slot_action_stopListen_triggered()));
    connect(ui->action_clearOutput, SIGNAL(triggered()), this, SLOT(slot_action_clearOutput_triggered()));
    connect(ui->lstClientView, &QListView::clicked, this, &MainWindow::slot_lstClientView_clicked);
    // 获取本机IP
    QString _localIP = getLocalIP();
    this->setWindowTitle(this->windowTitle() + QStringLiteral("===本机IP: ") + _localIP + "===");
    ui->cmbIPAddress->addItem(_localIP);

    return true;
}

bool MainWindow::m_serverManager_init()
{
    if(m_serverManager != nullptr)
    {
        qDebug() << "m_serverManager is not null, but init is called, please check.";
        return false;
    }

    sttDatabaseInfo db_info = Config::getInstance()->m_getDatabaseInfo();
    QSharedPointer<sttDatabaseInfo> p_db_info = QSharedPointer<sttDatabaseInfo>::create();
    p_db_info->database_name = db_info.database_name;
    p_db_info->host_name = db_info.host_name;
    p_db_info->user_name = db_info.user_name;
    p_db_info->password = db_info.password;
    m_serverManager = new TcpServerManager(this, p_db_info);
    connect(m_serverManager, &TcpServerManager::signal_databaseConnectFailed, this, &MainWindow::slot_clientDatabaseConnectFailed);
    connect(m_serverManager, &TcpServerManager::signal_clientConnected, this, &MainWindow::slot_clientConnected);
    connect(m_serverManager, &TcpServerManager::signal_clientDisconnected, this, &MainWindow::slot_clientDisconnected);
    connect(m_serverManager, &TcpServerManager::signal_receiveClientMessage, this, &MainWindow::slot_receiveClientMessage);
    connect(m_serverManager, &TcpServerManager::signal_clientSocketError, [](const QAbstractSocket::SocketError socket_error){
        qDebug() << "socket error:" << socket_error;
    });
    connect(m_serverManager, &TcpServerManager::signal_sendClientMessageFinished, this, &MainWindow::slot_sendClientMessageFinished);

    return true;
}

QString MainWindow::getLocalIP()
{
    QString _host_name = QHostInfo::localHostName();                // 本机主机名
    qDebug() << QStringLiteral("===本机IP: ") << _host_name;
    QHostInfo _host_info = QHostInfo::fromName(_host_name);
    QList<QHostAddress> _host_addresses = _host_info.addresses();   // 本机IP列表

    QString res_localIP = "";
    if(_host_addresses.isEmpty())
        return res_localIP;
    for(QHostAddress _cur_address : _host_addresses)
    {
        if(_cur_address.protocol() == QAbstractSocket::IPv4Protocol)    // 判断是否是IPv4
        {
            res_localIP = _cur_address.toString();
            break;
        }
    }
    return res_localIP;
}

void MainWindow::slot_action_startListen_triggered()
{
    QString _selectIP = ui->cmbIPAddress->currentText();
    QString _selectPort = ui->spbPort->text();

    if(m_serverManager == nullptr)
    {
        m_serverManager_init();
    }

    bool _success = m_serverManager->listen(QHostAddress(_selectIP), _selectPort.toUInt());           // --- 开始监听 ---
    if(_success == false)
    {
        QMessageBox::critical(this, QStringLiteral("失败"), QStringLiteral("监听失败! "));
        qDebug() << m_serverManager->errorString();
        return;
    }
    ui->edtOutputShow->appendPlainText(QString(QStringLiteral("开始监听: %1:%2")).arg(_selectIP, _selectPort));
    m_listenState->setText(QStringLiteral("监听状态: 正在监听"));
    ui->action_startListen->setEnabled(false);  // 关闭“开始监听”的使能
    ui->action_stopListen->setEnabled(true);    // 打开“停止监听”的使能
}

void MainWindow::slot_action_stopListen_triggered()
{
    if(m_serverManager != nullptr)
    {
        if(m_serverManager->isListening())
        {
            m_serverManager->close();
            m_serverManager->deleteLater();
            m_serverManager = nullptr;
            ui->action_startListen->setEnabled(true);
            ui->action_stopListen->setEnabled(false);
            m_listenState->setText(QStringLiteral("监听状态: 停止监听"));
            ui->edtOutputShow->appendPlainText(QStringLiteral("已停止监听!"));
        }
        m_serverManager = nullptr;
    }
}

void MainWindow::slot_action_clearOutput_triggered()
{
    ui->edtOutputShow->clear();
}

void MainWindow::slot_action_exit_triggered()
{
    this->close();
}

void MainWindow::slot_btnSendMessage_clicked()
{
    QItemSelectionModel* _lstSelection_model = ui->lstClientView->selectionModel();
    if(!_lstSelection_model->hasSelection())
    {
        QMessageBox::information(this, QStringLiteral("提示"), QStringLiteral("请选择一个客户"));
        return;
    }
    if(m_serverManager == nullptr)
    {
        qDebug() << "m_serverManager is null.";
        return;
    }
    QModelIndexList client_lists =  _lstSelection_model->selectedIndexes();
    for(QModelIndex client : client_lists)
    {
        QString client_IP_port = m_modelClient->data(client).toString();
        QByteArray message;
        QString _send_QString = ui->edtMessage->text();
        message.append(_send_QString.toUtf8());          // 转为Utf-8
        ui->edtMessage->clear();
        ui->edtMessage->setFocus();
        m_serverManager->m_sendClientMessage(client_IP_port, message);
    }
}

void MainWindow::slot_lstClientView_clicked(const QModelIndex& index)
{
    if(m_serverManager == nullptr)
    {
        qDebug() << "m_serverManager is null.";
        return;
    }

    QString _client_IP_port = m_modelClient->data(index).toString();
    QAbstractSocket::SocketState client_state = m_serverManager->m_getClientState(_client_IP_port);

    switch (client_state) {
    case QAbstractSocket::UnconnectedState:
        m_socketState->setText(QStringLiteral("Socket状态: UnconnectedState"));
        break;
    case QAbstractSocket::HostLookupState:
        m_socketState->setText(QStringLiteral("Socket状态: HostLookupState"));
        break;
    case QAbstractSocket::ConnectingState:
        m_socketState->setText(QStringLiteral("Socket状态: ConnectingState"));
        break;
    case QAbstractSocket::ConnectedState:
        m_socketState->setText(QStringLiteral("Socket状态: ConnectedState"));
        break;
    case QAbstractSocket::BoundState:
        m_socketState->setText(QStringLiteral("Socket状态: BoundState"));
        break;
    case QAbstractSocket::ListeningState:
        m_socketState->setText(QStringLiteral("Socket状态: ListeningState"));
        break;
    case QAbstractSocket::ClosingState:
        m_socketState->setText(QStringLiteral("Socket状态: ClosingState"));
        break;
    default:
        m_socketState->setText(QStringLiteral("Socket状态: "));
        break;
    }
}

void MainWindow::slot_clientDatabaseConnectFailed(qintptr socketDescriptor)
{
    ui->edtOutputShow->appendPlainText(QStringLiteral("socket连接数据库失败: ") + QString::number(socketDescriptor));
}

void MainWindow::slot_clientConnected(const QHostAddress address, const quint16 port)
{
    QString _IP_address = address.toString();
    QString _port = QString::number(port);
    ui->edtOutputShow->appendPlainText(QString(QStringLiteral("用户%1:%2已上线")).arg(_IP_address, _port));

    // 插入到客户在线列表
    m_modelClient->insertRow(m_modelClient->rowCount());
    int insert_row = m_modelClient->rowCount()-1;
    QModelIndex _index = m_modelClient->index(insert_row);
    m_modelClient->setData(_index, _IP_address+":"+_port, Qt::DisplayRole);
    ui->lstClientView->setCurrentIndex(_index);
    QString IP_port = _IP_address + ":" + _port;
}

void MainWindow::slot_clientDisconnected(const QHostAddress address, const quint16 port)
{
    QString _IP_address  = address.toString();
    QString _port = QString::number(port);
    ui->edtOutputShow->appendPlainText(QString(QStringLiteral("用户%1:%2已下线")).arg(_IP_address, _port));
    QString IP_port = _IP_address + ":" + _port;
    int delete_row = m_modelClient->stringList().indexOf(IP_port);
    m_modelClient->removeRow(delete_row);
}

void MainWindow::slot_receiveClientMessage(const QHostAddress address, const quint16 port, const QByteArray message)
{
    QString _IP_address  = address.toString();
    QString _port = QString::number(port);
    QString client_IP_port = _IP_address + ":" + _port;
    int message_size = message.size();
    QString _show_text = QStringLiteral("[in]: 收到 ") + client_IP_port + QStringLiteral(" 发送的") + QString::number(message_size) + QStringLiteral("个字节");
    ui->edtOutputShow->appendPlainText(_show_text);
}

void MainWindow::slot_sendClientMessageFinished(const QHostAddress address, const quint16 port, const quint64 send_bytes)
{
    if(send_bytes >= 0)
    {
        QString _IP_address  = address.toString();
        QString _port = QString::number(port);
        QString client_IP_port = _IP_address + ":" + _port;
        QString _output = QStringLiteral("向") + client_IP_port +  QStringLiteral("发送了") + QString::number(send_bytes) + QStringLiteral("个字节");
        ui->edtOutputShow->appendPlainText(_output);
    }
}
