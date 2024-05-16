#include "Login.h"
#include "ui_Login.h"

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login),
    m_connect_flag(false)
{
    qDebug() << QThread::currentThread() << " ========================================================== " << "Login thread";
    this->setMinimumSize(450, 600);
    this->setMaximumSize(450, 600);
    this->setFixedSize(450, 600);
    this->setWindowFlags(this->windowFlags() | Qt::MSWindowsFixedSizeDialogHint);
    ui->setupUi(this);

    ui->stackedWidget->setCurrentIndex(0);
    // 设置登录提示
    ui->cmbAccounts->lineEdit()->setPlaceholderText(QStringLiteral("输入QQ号"));
    ui->cmbAccounts->lineEdit()->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    ui->btnLogin->setFocus();
    // 设置密码输入模式
    ui->edtPassword->setEchoMode(QLineEdit::Password);
    ui->edtRegisterPassword->setEchoMode(QLineEdit::Password);
    ui->edtConfirmPassword->setEchoMode(QLineEdit::Password);
    // 设置使能
    ui->btnLogin->setEnabled(false);
    ui->btnRegister->setEnabled(false);
    // 让界面显示在显示屏1的中间
    int screenWidth = QApplication::desktop()->screenGeometry(0).width();
    int screenHeight = QApplication::desktop()->screenGeometry(0).height();
    this->move(screenWidth/2-this->width()/2, screenHeight/2-this->height()/2);
    // socket管理对象初始化
    m_socketManager_init(Config::getInstance()->m_getServerAddress(),
                         Config::getInstance()->m_getServerMsgPort(),
                         Config::getInstance()->m_getServerMaxConnectTime());
    // 信号与槽
    connect(ui->cmbAccounts, &QComboBox::currentTextChanged, this, &Login::slot_edtRemoveIllegal);
    connect(ui->edtPassword, &QLineEdit::textChanged, this, &Login::slot_edtRemoveIllegal);
    connect(ui->edtRegisterAccount, &QLineEdit::textChanged, this, &Login::slot_edtRemoveIllegal);
    connect(ui->edtRegisterPassword, &QLineEdit::textChanged, this, &Login::slot_edtRemoveIllegal);
    connect(ui->edtConfirmPassword, &QLineEdit::textChanged, this, &Login::slot_edtRemoveIllegal);
    connect(ui->btnRegisterPage, SIGNAL(clicked()), this, SLOT(slot_btnRegisterPage_clicked()));
    connect(ui->btnReturn, SIGNAL(clicked()), this, SLOT(slot_btnReturn_clicked()));
    connect(ui->btnRegister, SIGNAL(clicked()), this, SLOT(slot_btnRegister_clicked()));
    connect(ui->cmbAccounts, &QComboBox::currentTextChanged, this, &Login::slot_btnLogin_checkEnable);
    connect(ui->edtPassword, &QLineEdit::textChanged, this, &Login::slot_btnLogin_checkEnable);
    connect(ui->edtRegisterAccount, &QLineEdit::textChanged, this, &Login::slot_btnRegister_checkEnable);
    connect(ui->edtRegisterPassword, &QLineEdit::textChanged, this, &Login::slot_btnRegister_checkEnable);
    connect(ui->edtConfirmPassword, &QLineEdit::textChanged, this, &Login::slot_btnRegister_checkEnable);
    connect(ui->btnLogin, SIGNAL(clicked()), this, SLOT(slot_btnLogin_clicked()));
    connect(ui->edtPassword, SIGNAL(returnPressed()), this, SLOT(slot_btnLogin_clicked()));
    connect(ui->btnCancelLogin, &QPushButton::clicked, this, &Login::slot_btnCancelLogin_clicked);
}

Login::~Login()
{
    disconnect(m_socketManager.data(), &TcpSocketManager::signal_socketConnectFailed, this, &Login::slot_connectionFailed);
    disconnect(m_socketManager.data(), &TcpSocketManager::signal_socketDisconnected, this, &Login::slot_connectionFailed);
    disconnect(this, &Login::signal_sendMessage, m_socketManager.data(), &TcpSocketManager::slot_socketWrite);
    disconnect(m_socketManager.data(), &TcpSocketManager::signal_registerSuccess, this, &Login::slot_registerSuccess);
    disconnect(m_socketManager.data(), &TcpSocketManager::signal_registerFailed, this, &Login::slot_registerFailed);
    disconnect(m_socketManager.data(), &TcpSocketManager::signal_loginSuccess, this, &Login::slot_loginSuccess);
    disconnect(m_socketManager.data(), &TcpSocketManager::signal_loginFailed, this, &Login::slot_loginFailed);

    delete ui;
}

void Login::m_socketManager_init(QHostAddress address, quint16 port, float max_connect_time)
{
    if(m_socketManager != nullptr)
    {
        m_socketManager.clear();
    }

    m_socketManager = QSharedPointer<TcpSocketManager>::create(address, port, max_connect_time, nullptr);
    QThread* socket_thread = new QThread();
    m_socketManager->moveToThread(socket_thread);
    connect(socket_thread, &QThread::started, m_socketManager.data(), &TcpSocketManager::slot_init);
    connect(m_socketManager.data(), &TcpSocketManager::signal_socketConnected, [this](){
        m_connect_flag = true;
        qDebug() << "connect to Server successfully.";
    });
    connect(m_socketManager.data(), &TcpSocketManager::signal_socketConnectFailed, this, &Login::slot_connectionFailed, Qt::QueuedConnection);
    connect(m_socketManager.data(), &TcpSocketManager::signal_socketDisconnected, this, &Login::slot_connectionFailed, Qt::QueuedConnection);
    connect(this, &Login::signal_sendMessage, m_socketManager.data(), &TcpSocketManager::slot_socketWrite);
    connect(m_socketManager.data(), &TcpSocketManager::signal_registerSuccess, this, &Login::slot_registerSuccess);
    connect(m_socketManager.data(), &TcpSocketManager::signal_registerFailed, this, &Login::slot_registerFailed);
    connect(m_socketManager.data(), &TcpSocketManager::signal_loginSuccess, this, &Login::slot_loginSuccess);
    connect(m_socketManager.data(), &TcpSocketManager::signal_loginFailed, this, &Login::slot_loginFailed);

    socket_thread->start();
}

void Login::slot_connectionFailed()                         // 连接服务端失败
{
    m_connect_flag = false;
    qDebug() << "connect to Server failed.";
}

QSharedPointer<TcpSocketManager> Login::m_getSocketManager() const
{
    return m_socketManager;
}

void Login::slot_edtRemoveIllegal(const QString &text)      // 禁止用户输入非法字符：空格
{
    QRegularExpression regex("\\s");
    QObject* senderObject = sender();

    if (senderObject->inherits("QLineEdit"))
    {
        QLineEdit* lineEdit = qobject_cast<QLineEdit*>(senderObject);
        if (text.contains(regex))
        {
            QString newText = text;
            newText.remove(regex);
            lineEdit->setText(newText);
        }
    }
    else if (senderObject->inherits("QComboBox"))
    {
        QComboBox* comboBox = qobject_cast<QComboBox*>(senderObject);
        if (text.contains(regex))
        {
            QString newText = text;
            newText.remove(regex);
            comboBox->setEditText(newText);
        }
    }
}

void Login::slot_btnRegisterPage_clicked()                  // 按下“注册账号”
{
    ui->stackedWidget->setCurrentIndex(1);
    ui->btnRegister->setFocus();
}

void Login::slot_btnReturn_clicked()                        // 按下“返回”
{
    ui->stackedWidget->setCurrentIndex(0);
    ui->btnLogin->setFocus();
}

void Login::slot_btnRegister_clicked()                      // 按下“注册”
{
    if(m_connect_flag == false)
    {
        ui->edtRegisterAccount->clear();
        ui->edtRegisterPassword->clear();
        ui->edtConfirmPassword->clear();
        QMessageBox msg_box;
        msg_box.setWindowIcon(QIcon(":/qqicons/qrc/QQicon.svg"));
        msg_box.setWindowTitle(QStringLiteral("注册失败"));
        msg_box.setText(QStringLiteral("网络连接失败，请稍后重试"));
        msg_box.addButton(QStringLiteral("确认"), QMessageBox::AcceptRole);
        msg_box.setModal(true);
        msg_box.exec();
        ui->btnRegister->setFocus();
        return;
    }
    QString register_account = ui->edtRegisterAccount->text().trimmed();
    QString register_password = ui->edtRegisterPassword->text().trimmed();
    QString confirm_password = ui->edtConfirmPassword->text().trimmed();
    if(register_password != confirm_password)
    {
        QMessageBox::information(this, QStringLiteral("提示"), QStringLiteral("两次输入密码不一致"));
        return;
    }

    ui->edtRegisterAccount->clear();
    ui->edtRegisterPassword->clear();
    ui->edtConfirmPassword->clear();

    // 构建发送字节流
    QByteArray send_bytes;
    QDataStream opt_buffer(&send_bytes, QIODevice::WriteOnly);
    opt_buffer.setVersion(QDataStream::Qt_5_9);
    opt_buffer.setByteOrder(QDataStream::LittleEndian);
    opt_buffer.setFloatingPointPrecision(QDataStream::SinglePrecision);
    quint16 cmd_type = ChatType::RegisterRequest;
    quint64 total_bytes_place = ChatType::MessageMinSize;        // 占位
    opt_buffer<<total_bytes_place;
    opt_buffer<<cmd_type;
    opt_buffer<<register_account.toUtf8();
    opt_buffer<<register_password.toUtf8();
    quint64 total_bytes = send_bytes.size();
    opt_buffer.device()->seek(0);
    opt_buffer<<total_bytes;
    emit signal_sendMessage(send_bytes);
}

void Login::slot_btnLogin_checkEnable()                 // 检查“登录”是否有效
{
    QString _account = ui->cmbAccounts->lineEdit()->text();
    QString _password = ui->edtPassword->text();
    ui->btnLogin->setEnabled(!_account.isEmpty() && !_password.isEmpty());
}

void Login::slot_btnRegister_checkEnable()              // 检查“注册”是否有效
{
    QString _account = ui->edtRegisterAccount->text();
    QString _password = ui->edtRegisterPassword->text();
    QString _password_confirm = ui->edtConfirmPassword->text();
    ui->btnRegister->setEnabled(!_account.isEmpty() && !_password.isEmpty() && !_password_confirm.isEmpty());
}

void Login::slot_btnLogin_clicked()                     // 按下“登录”
{
    if(m_connect_flag == false)
    {
        ui->cmbAccounts->clearEditText();
        ui->edtPassword->clear();
        QMessageBox msg_box;
        msg_box.setWindowIcon(QIcon(":/qqicons/qrc/QQicon.svg"));
        msg_box.setWindowTitle(QStringLiteral("登录失败"));
        msg_box.setText(QStringLiteral("网络连接失败，请稍后重试"));
        msg_box.addButton(QStringLiteral("确认"), QMessageBox::AcceptRole);
        msg_box.setModal(true);
        msg_box.exec();
        ui->btnLogin->setFocus();
        return;
    }
    QString _account = ui->cmbAccounts->lineEdit()->text().trimmed();
    QString _password = ui->edtPassword->text().trimmed();

    // 登录加载界面
    m_loginLoad_flag = true;
    QPropertyAnimation* btnLoginAnimation = new QPropertyAnimation(ui->lblQQIconLoad, "pos");
    QPoint _start_pos_global = ui->lblQQIcon->mapToGlobal(QPoint(0, 0));
    QPoint _start_pos = ui->lblQQIconLoad->parentWidget()->mapFromGlobal(_start_pos_global);
    QPoint _end_pos_global = ui->lblQQIcon->mapToGlobal(QPoint(0, 80));
    QPoint _end_pos = ui->lblQQIconLoad->parentWidget()->mapFromGlobal(_end_pos_global);
    btnLoginAnimation->setDuration(500);
    btnLoginAnimation->setStartValue(_start_pos);
    btnLoginAnimation->setEndValue(_end_pos);
    btnLoginAnimation->setEasingCurve(QEasingCurve::InOutQuad);
    btnLoginAnimation->start();
    ui->stackedWidget->setCurrentIndex(2);
    ui->btnLogin->setFocus();

    // 构建发送字节流
    QByteArray send_bytes;
    QDataStream opt_buffer(&send_bytes, QIODevice::WriteOnly);
    opt_buffer.setVersion(QDataStream::Qt_5_9);
    opt_buffer.setByteOrder(QDataStream::LittleEndian);
    opt_buffer.setFloatingPointPrecision(QDataStream::SinglePrecision);
    quint16 cmd_type = ChatType::LoginRequest;
    quint64 total_bytes_place = ChatType::MessageMinSize;        // 占位
    opt_buffer<<total_bytes_place;
    opt_buffer<<cmd_type;
    opt_buffer<<_account.toUtf8();
    opt_buffer<<_password.toUtf8();
    quint64 total_bytes = send_bytes.size();
    opt_buffer.device()->seek(0);
    opt_buffer<<total_bytes;
    emit signal_sendMessage(send_bytes);
}

void Login::slot_registerSuccess()
{
    QMessageBox::information(this, QStringLiteral("提示"), QStringLiteral("注册成功"));
}

void Login::slot_registerFailed(const QString reason)
{
    QString _show_text = QStringLiteral("注册失败");
    if(!reason.isEmpty())
    {
        _show_text += ": " + reason;
    }
    QMessageBox::information(this, QStringLiteral("提示"), _show_text);
}

void Login::slot_btnCancelLogin_clicked()
{
    m_loginLoad_flag = false;
    ui->stackedWidget->setCurrentIndex(0);
    ui->btnLogin->setFocus();
}

void Login::slot_loginSuccess(const sttClientInfo client_info, const QMap<quint32, sttGroupInfo> all_group_info)
{
    if(m_loginLoad_flag == false)
        return;
    // 写入本地数据库
    Config::getInstance()->m_setLoginClientInfo(client_info);
    Config::getInstance()->m_setLocalAccountPath(client_info.account);
    Config::getInstance()->m_setLocalDbPath("local.db");
    for(QMap<quint32, sttGroupInfo>::const_iterator ite = all_group_info.begin(); ite!=all_group_info.end(); ++ite)
    {
        quint32 _cur_group_id = ite.key();
        QString _cur_group_name = ite.value().group_name;
        LocalDatabase::getInstance()->m_replaceIntotGroupInfo(_cur_group_id, _cur_group_name);
        for(int i = 0; i < ite.value().friend_num; ++i)
        {
            LocalDatabase::getInstance()->m_replaceIntoFriendInfo(ite.value().friend_list.at(i));
        }
    }
    this->accept();
}

void Login::slot_loginFailed(const QString reason)
{
    if(m_loginLoad_flag == false)
        return;
    ui->stackedWidget->setCurrentIndex(0);
    QString _show_text = QStringLiteral("登录失败");
    if(!reason.isEmpty())
    {
        _show_text += ": " + reason;
    }
    QMessageBox::information(this, QStringLiteral("提示"), _show_text);
}
