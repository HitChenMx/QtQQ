#include "tcpservermanager.h"

TcpServerManager::TcpServerManager(QObject *parent, QSharedPointer<sttDatabaseInfo> db_info) :
    QTcpServer(parent),
    m_dbInfo(db_info)
{
//    qDebug() << m_dbInfo->database_name;
//    qDebug() << m_dbInfo->host_name;
//    qDebug() << m_dbInfo->user_name;
//    qDebug() << m_dbInfo->password;
    qDebug() << QThread::currentThread() << " ================================ main thread" ;
}

TcpServerManager::~TcpServerManager()
{
    qDebug() << "~TcpServerManager";
    for(QHash<QString, TcpSocketManager*>::iterator ite = m_sockets.begin(); ite!=m_sockets.end(); ++ite)
    {
        if(*ite != nullptr)
        {
            (*ite)->deleteLater();
        }
    }
    m_sockets.clear();
    for(QList<QThread*>::iterator ite=m_threads.begin(); ite!=m_threads.end(); ++ite)
    {
        if(*ite != nullptr)
        {
            (*ite)->quit();
        }
    }
    m_threads.clear();
}

void TcpServerManager::incomingConnection(qintptr socketDescriptor)
{
    TcpSocketManager* _socket_manager = new TcpSocketManager(socketDescriptor, m_dbInfo);

    connect(_socket_manager, &TcpSocketManager::signal_databaseConnectFailed, [this, socketDescriptor](){
        emit signal_databaseConnectFailed(socketDescriptor);
        TcpSocketManager* object_sender = qobject_cast<TcpSocketManager*>(sender());
        object_sender->deleteLater();
    });
    connect(_socket_manager, &TcpSocketManager::signal_socketConnected, this, &TcpServerManager::slot_clientConnected);
    connect(_socket_manager, &TcpSocketManager::signal_socketDisconnected, this, &TcpServerManager::slot_clientDisconnected);
    connect(_socket_manager, &TcpSocketManager::signal_readFinished, this, &TcpServerManager::slot_receiveClientMessage);
    connect(_socket_manager, &TcpSocketManager::signal_sendFinished, [this](const QHostAddress address, const quint16 port, const quint64 send_bytes){
        emit signal_sendClientMessageFinished(address, port, send_bytes);
    });
    connect(_socket_manager, &TcpSocketManager::signal_socketError, [this](const QAbstractSocket::SocketError socket_error){
        emit signal_clientSocketError(socket_error);
    });
    connect(_socket_manager, &TcpSocketManager::signal_loginSuccess, this, &TcpServerManager::slot_clientLoginSuccess);
    connect(this, &TcpServerManager::signal_sendClientMessage, _socket_manager, &TcpSocketManager::slot_socketSendMessage);
    connect(_socket_manager, &TcpSocketManager::signal_queryOnlineState, this, &TcpServerManager::slot_clientQueryOnlineState);
    connect(this, &TcpServerManager::signal_replyQueryOnlineState, _socket_manager, &TcpSocketManager::slot_receiveReplyOnlineState);
    connect(_socket_manager, &TcpSocketManager::signal_requestRelayBytes, this, &TcpServerManager::slot_relayBytesToClients);

    QThread* _thread = new QThread;                 // 每与一个用户建立连接，就开一个线程
    m_threads.push_back(_thread);
    int _thread_index = m_threads.size() - 1;
    connect(m_threads.at(_thread_index), &QThread::destroyed, [_thread_index, this]() mutable {
        if(_thread_index < this->m_threads.size())
        {
            this->m_threads[_thread_index] = nullptr;
        }
    });
    _socket_manager->moveToThread(_thread);
    connect(_thread, &QThread::started, _socket_manager, &TcpSocketManager::m_init);    // 线程开始才执行初始化
    connect(_socket_manager, &TcpSocketManager::signal_socketDisconnected, _thread, &QThread::quit, Qt::QueuedConnection);    // 用户连接断开时线程结束
    connect(_thread, &QThread::finished, this, &TcpServerManager::slot_threadFinished);         // 线程结束，释放线程
    _thread->start();       // 启动线程
}

void TcpServerManager::slot_threadFinished()                // 线程结束，释放线程
{
    QThread* _thread = qobject_cast<QThread*>(sender());
    if(_thread != nullptr)
    {
        _thread->wait();
        if(_thread->isFinished())
        {
            _thread->deleteLater();
            qDebug() << _thread << " is deleted.";
            _thread = nullptr;
        }
    }
}

QAbstractSocket::SocketState TcpServerManager::m_getClientState(const QHostAddress address, const quint16 port) const
{
    QString _client_IP_port = address.toString() + ":" + QString::number(port);
    return this->m_getClientState(_client_IP_port);
}

QAbstractSocket::SocketState TcpServerManager::m_getClientState(const QString client_IP_port) const
{
    QHash<QString, TcpSocketManager*>::const_iterator _ite = m_sockets.find(client_IP_port);
    if(_ite == m_sockets.end())
    {
        // qDebug() << QString("TcpServerManager::m_getClientState Error: can't find %1 from m_sockets.").arg(client_IP_port);
        return QAbstractSocket::ClosingState;
    }
    TcpSocketManager* _socket_manager = _ite.value();
    return _socket_manager->m_getSocketState();
}

void TcpServerManager::slot_clientConnected(const QHostAddress address, const quint16 port)
{
    TcpSocketManager* _socket_manager = qobject_cast<TcpSocketManager*>(sender());
    if(_socket_manager == nullptr)
    {
        qDebug() << "TcpServerManager::slot_clientConnected Error: _socket_manager is a null pointer.";
        return;
    }

    QString _client_IP_port = address.toString() + ":" + QString::number(port);
    m_sockets.insert(_client_IP_port, _socket_manager);       // 保存这个用户socket

    emit signal_clientConnected(address, port);
}

void TcpServerManager::slot_clientDisconnected(const quint32 user_id, const QHostAddress address, const quint16 port,
                                               const QVector<quint32> user_friend_list)
{
    // 移除对应的socket管理对象
    QString _client_IP_port = address.toString() + ":" + QString::number(port);
    m_sockets.remove(_client_IP_port);
    if(m_userID2IP.contains(user_id))
        m_userID2IP.remove(user_id);

    // 释放对应的socket管理对象
    TcpSocketManager* socket_manager = qobject_cast<TcpSocketManager*>(sender());
    if(socket_manager != nullptr)
    {
        socket_manager->deleteLater();
        socket_manager = nullptr;
    }

    // 告知该用户的好友们：该用户已下线
    for(quint32 cur_friend_id : user_friend_list)
    {
        if(m_userID2IP.contains(cur_friend_id))
        {
            QStringList cur_IP_port_lists = m_userID2IP.value(cur_friend_id).split(":");
            m_replyUserOnlineState(user_id, QHostAddress(cur_IP_port_lists.at(0)), cur_IP_port_lists.at(1).toUInt());
        }
    }

    emit signal_clientDisconnected(address, port);
}

void TcpServerManager::slot_receiveClientMessage(const QHostAddress address, const quint16 port, const QByteArray message)
{
    emit signal_receiveClientMessage(address, port, message);
}

void TcpServerManager::m_replyUserOnlineState(const quint32 query_id, const QHostAddress reply_address, const quint16 reply_port)
{
    ChatType::ChatCMD _online_state = ChatType::ChatCMD::ReturnOffline;
    if(m_userID2IP.contains(query_id))
    {
        QString _client_IP_port = m_userID2IP.value(query_id);
        if(m_sockets.contains(_client_IP_port))                        // 有这名用户的登录信息，并且存在socket管理对象，说明在线
        {
            _online_state = ChatType::ChatCMD::ReturnOnline;
            emit signal_replyQueryOnlineState(reply_address, reply_port,
                                              query_id, _online_state);
            return;
        }
        else            // 有该用户的登录信息，但socket管理对象已被析构，说明离线
        {
            m_userID2IP.remove(query_id);
            _online_state = ChatType::ChatCMD::ReturnOffline;
            emit signal_replyQueryOnlineState(reply_address, reply_port,
                                              query_id, _online_state);
            return;
        }
    }
    else        // 没有这名用户的登录信息
    {
        _online_state = ChatType::ChatCMD::ReturnOffline;
        emit signal_replyQueryOnlineState(reply_address, reply_port,
                                          query_id, _online_state);
        return;
    }
}

void TcpServerManager::slot_clientLoginSuccess(const quint32 user_id, const QHostAddress address, const quint16 port,
                                               const QVector<quint32> user_friend_list)
{
    qDebug() << "user id:" << user_id << "login successfully.";
    QString _IP_port = address.toString() + ":" + QString::number(port);
    if(m_userID2IP.contains(user_id))
    {
        qDebug() << "login user id is duplicated.";
        return;
    }
    m_userID2IP.insert(user_id, _IP_port);

    // 告知该用户的好友们：该用户已上线
    for(quint32 cur_friend_id : user_friend_list)
    {
        if(m_userID2IP.contains(cur_friend_id))
        {
            QStringList cur_IP_port_lists = m_userID2IP.value(cur_friend_id).split(":");
            m_replyUserOnlineState(user_id, QHostAddress(cur_IP_port_lists.at(0)), cur_IP_port_lists.at(1).toUInt());
        }
    }
}

void TcpServerManager::slot_clientQueryOnlineState(const quint32 user_id)
{
    TcpSocketManager* object_sender = qobject_cast<TcpSocketManager*>(sender());
    if(object_sender == nullptr)
        return;
    QHostAddress client_self_address = object_sender->m_getPeerAddress();
    quint16 client_self_port = object_sender->m_getPeerPort();

    m_replyUserOnlineState(user_id, client_self_address, client_self_port);
}

void TcpServerManager::m_sendClientMessage(const QHostAddress address, const quint16 port, const QByteArray message)
{
    emit signal_sendClientMessage(address, port, message);
}

void TcpServerManager::m_sendClientMessage(const QString client_IP_port, const QByteArray message)
{
    QStringList IP_port_lists = client_IP_port.split(":");
    if(IP_port_lists.size() != 2)
    {
        qDebug() << "TcpServerManager::m_sendClientMessage Error: please check client_IP_port.";
        return;
    }
    QHostAddress address = QHostAddress(IP_port_lists.at(0));
    quint16 port = IP_port_lists.at(1).toUInt();
    this->m_sendClientMessage(address, port, message);
}

void TcpServerManager::slot_relayBytesToClients(const QVector<quint32> relay_to_these, const QByteArray bytes)
{
    for(QVector<quint32>::const_iterator ite = relay_to_these.begin(); ite!=relay_to_these.end(); ++ite)
    {
        quint32 cur_user_id = *ite;
        if(m_userID2IP.contains(cur_user_id))
        {
            QString cur_IP_port = m_userID2IP.value(cur_user_id);
            qDebug() << "relay" << bytes.size() << "bytes to" << cur_IP_port;
            m_sendClientMessage(cur_IP_port, bytes);
        }
    }
}
