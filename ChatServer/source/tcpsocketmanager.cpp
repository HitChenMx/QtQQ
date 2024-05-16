#include "tcpsocketmanager.h"

TcpSocketManager::TcpSocketManager(qintptr socketDescriptor, QSharedPointer<sttDatabaseInfo> db_info, QObject *parent) :
    m_socketDescriptor(socketDescriptor),
    QObject(parent),
    m_socket(nullptr),
    m_peerAddress(QHostAddress(-1)),
    m_peerPort(-1),
    m_dbInfo(db_info),
    m_dbManager(nullptr),
    m_loginUserID(-1)
{

}

TcpSocketManager::~TcpSocketManager()
{
    qDebug() << "~TcpSocketManager";
    if(m_socket != nullptr)
    {
        if(m_socket->state() == QAbstractSocket::ConnectedState)
        {
            m_socket->disconnectFromHost();      // --- 断开socket，成功断开后发射 disconnected()信号 ---
        }
    }
}

void TcpSocketManager::m_init()         // 初始化
{
    qDebug() << QThread::currentThread() << " ================================ child thread" ;
    qRegisterMetaType<qintptr>("qintptr");

    if(m_socket != nullptr)
    {
        qDebug() << "m_socket must be nullptr before init, please check TcpSocketManager::m_init";
    }
    m_socket = new QTcpSocket;
    bool _result = m_socket->setSocketDescriptor(m_socketDescriptor);
    if(_result == false)
    {
        qDebug() << "QTcpSocket setSocketDescriptor failed.";
        return;
    }
    m_dbManager = new DatabaseManager(this, m_dbInfo);
    if(m_dbManager->m_getInitFlag() == false)
    {
        qDebug() << QThread::currentThread() << " ================================ " << m_socketDescriptor << "init failed." ;
        emit signal_databaseConnectFailed();
    }

    qRegisterMetaType<QAbstractSocket::SocketState>("QAbstractSocket::SocketState");
    qRegisterMetaType<sttClientInfo>("sttClientInfo");
    qRegisterMetaType<QHostAddress>("QHostAddress");
    qRegisterMetaType<quint16>("quint16");
    qRegisterMetaType<quint64>("quint64");
    qRegisterMetaType<QByteArray>("QByteArray");
    qRegisterMetaType<QMap<quint32,sttGroupInfo>>("QMap<quint32,sttGroupInfo>");
    qRegisterMetaType<ChatType::ChatCMD>("ChatType::ChatCMD");
    qRegisterMetaType<QVector<quint32>>("QVector<quint32>");

    connect(m_socket, &QTcpSocket::connected, this, &TcpSocketManager::slot_socketConnected);
    connect(m_socket, SIGNAL(disconnected()), this, SLOT(slot_socketDisconnected()));
    connect(m_socket, SIGNAL(stateChanged(QAbstractSocket::SocketState)), this, SLOT(slot_socketStateChanged(QAbstractSocket::SocketState)));
    connect(m_socket, &QTcpSocket::readyRead, this, &TcpSocketManager::slot_socketReadyRead, Qt::DirectConnection);
    connect(m_socket, static_cast<void(QAbstractSocket::*)(QAbstractSocket::SocketError)>(&QAbstractSocket::error), [this](QAbstractSocket::SocketError socket_error){
        emit signal_socketError(socket_error);
    });

    if(m_socket->state() == QAbstractSocket::ConnectedState)
    {
        {
            QMutexLocker locker(&m_mutex);
            m_peerAddress = m_socket->peerAddress();
            m_peerPort = m_socket->peerPort();
        }
        slot_socketConnected();
    }
}

QHostAddress TcpSocketManager::m_getPeerAddress()      // 获取peer的IP地址
{
    QHostAddress res(-1);
    if(m_mutex.tryLock(100))
    {
        res = m_peerAddress;
        m_mutex.unlock();
    }
    return res;
}

quint16 TcpSocketManager::m_getPeerPort()              // 获取peer的端口号
{
    quint16 res = -1;
    if(m_mutex.tryLock(100))
    {
        res = m_peerPort;
        m_mutex.unlock();
    }
    return res;
}

QAbstractSocket::SocketState TcpSocketManager::m_getSocketState()
{
    QAbstractSocket::SocketState res = QAbstractSocket::ClosingState;
    if(m_mutex.tryLock(100))
    {
        res = m_socketState;
        m_mutex.unlock();
    }
    return res;
}

void TcpSocketManager::slot_socketConnected()
{
    qDebug() << QThread::currentThread() << " ================================ TcpSocketManager::slot_socketConnected";
    QHostAddress address;
    quint16 port;
    {
        QMutexLocker locker(&m_mutex);
        address = m_socket->peerAddress();
        port = m_socket->peerPort();
        m_peerAddress = address;
        m_peerPort = port;
        m_socketState = m_socket->state();
    }
    emit signal_socketConnected(address, port);
}

void TcpSocketManager::slot_socketDisconnected()
{
    qDebug() << QThread::currentThread() << " ================================ TcpSocketManager::slot_socketDisconnected" ;
    QHostAddress address = m_getPeerAddress();
    quint16 port = m_getPeerPort();
    {
        QMutexLocker locker(&m_mutex);
        m_socketState = m_socket->state();
        m_socket->deleteLater();
        m_socket = nullptr;
    }

    QVector<quint32> user_allFriends;
    m_dbManager->m_queryUserAllFriends(m_loginUserID, &user_allFriends);
    emit signal_socketDisconnected(m_loginUserID, address, port, user_allFriends);
}

void TcpSocketManager::slot_socketStateChanged(const QAbstractSocket::SocketState socket_state)
{
    // qDebug() << QThread::currentThread() << " ================================ TcpSocketManager::slot_socketStateChanged: ";
    {
        QMutexLocker locker(&m_mutex);
        m_socketState = socket_state;
    }
}

void TcpSocketManager::slot_socketReadyRead()
{
    // qDebug() << QThread::currentThread() << " ================================ TcpSocketManager::slot_socketReadyRead";
    if(m_socket == nullptr)
    {
        qDebug() << "m_socket is a null pointer, so can not read message.";
        return;
    }
    QByteArray _message = m_socket->readAll();
    emit signal_readFinished(m_getPeerAddress(), m_getPeerPort(), _message);

    m_analyseMessage(_message);     // 解析字节流
}

quint64 TcpSocketManager::slot_socketSendMessage(const QHostAddress address, const quint16 port, const QByteArray message)
{
    // qDebug() << QThread::currentThread() << " ================================ TcpSocketManager::slot_socketSendMessage" ;

    if(address!=m_getPeerAddress() || port!=m_getPeerPort())
    {
//        qDebug() << address << m_getPeerAddress();
//        qDebug() << port << m_getPeerPort();
        return quint64(0);
    }

    if(m_socket != nullptr && m_socket->state() == QAbstractSocket::ConnectedState)
    {
        quint64 byte_num = m_socket->write(message);
        qDebug() << "send msg to" << address << ":" << port << byte_num << "bytes";
        emit signal_sendFinished(address, port, byte_num);
        return byte_num;
    }
    return quint64(0);
}

void TcpSocketManager::m_analyseMessage(const QByteArray message)
{
    if(m_dbManager == nullptr)
        return;

    // qDebug() << QThread::currentThread() << " ================================ TcpSocketManager::m_analyseMessage" ;
    m_messageBuffer.append(message);
    if(m_messageBuffer.size() < ChatType::MessageMinSize)
        return;

    int total_buffer_size = m_messageBuffer.size();
    // 对方可能会一下子发过来1个以上的数据包，那么自己就需要有一个循环，把这些数据包都完成解析
    while(total_buffer_size > 0)
    {
        // 设置读取字节流
        QDataStream buffer(&m_messageBuffer, QIODevice::ReadOnly);
        buffer.setVersion(QDataStream::Qt_5_9);
        buffer.setByteOrder(QDataStream::LittleEndian);
        buffer.setFloatingPointPrecision(QDataStream::SinglePrecision);
        quint64 total_bytes;
        buffer >> total_bytes;
        if(total_buffer_size < total_bytes)     // 但如果当前数据包不是一个完整的数据包，就直接退出，等待下次解析
            return;

        // qDebug() << "two size: " << total_bytes << total_buffer_size;
        // 根据命令类型分不同的情况
        quint16 cmd_type;
        buffer >> cmd_type;
        switch(cmd_type)
        {
            case ChatType::RegisterRequest:         // 请求注册
            {
                qDebug() << "receive ChatType::RegisterRequest.";
                m_analyseMessage_register(buffer);
                break;
            }
            case ChatType::LoginRequest:            // 请求登录
            {
                qDebug() << "receive ChatType::LoginRequest.";
                m_analyseMessage_login(buffer);
                break;
            }
            case ChatType::ModifyUserInfoRequest:   // 请求修改用户消息
            {
                qDebug() << "receive ChatType::ModifyUserInfoRequest.";
                m_analyseMessage_modifyUserInfo(buffer);
                break;
            }
            case ChatType::AddGroupRequest:         // 请求增添好友分组
            {
                qDebug() << "receive ChatType::AddGroupRequest.";
                m_analyseMessage_addGroup(buffer);
                break;
            }
            case ChatType::RenameGroupRequest:      // 请求重命名好友分组
            {
                qDebug() << "receive ChatType::RenameGroupRequest.";
                m_analyseMessage_renameGroup(buffer);
                break;
            }
            case ChatType::QueryOnlineState:        // 查询用户是否在线
            {
                qDebug() << "receive ChatType::QueryOnlineState.";
                m_analyseMessage_queryOnlineState(buffer);
                break;
            }
            case ChatType::SendChatMsgRequest:      // 向好友发送聊天信息
            {
                qDebug() << "receive ChatType::SendChatMsgRequest.";
                m_analyseMessage_sendChatMsg(buffer);
                break;
            }
            case ChatType::SearchUserRequest:       // 根据关键词搜索用户
            {
                qDebug() << "receive ChatType::SearchUserRequest.";
                m_analyseMessage_searchUserRequest(buffer);
                break;
            }
            case ChatType::AddFriendRequest:        // 请求添加好友
            {
                qDebug() << "receive ChatType::AddFriendRequest.";
                m_analyseMessage_addFriendRequest(buffer);
                break;
            }
            case ChatType::ReplyAddFriendRequest:   // 回复添加好友请求
            {
                qDebug() << "receive ChatType::ReplyAddFriendRequest.";
                m_analyseMessage_replyAddFriendRequest(buffer);
                break;
            }
            case ChatType::RequestUserHeadPic:      // 请求用户头像
            {
                qDebug() << "receive ChatType::RequestUserHeadPic.";
                m_analyseMessage_requestUserHeadPic(buffer);
                break;
            }
            case ChatType::ModifyUserHeadRequest:   // 修改用户头像
            {
                qDebug() << "receive ChatType::ModifyUserHeadRequest.";
                m_analyseMessage_modifyUserHead(buffer);
                break;
            }
            case ChatType::SendChatPicRequest:      // 发送聊天图片
            {
                qDebug() << "receive ChatType::SendChatPicRequest.";
                m_analyseMessage_sendChatPic(buffer);
                break;
            }
            case ChatType::MoveFriendToGroup:       // 移动好友至指定分组
            {
                qDebug() << "receive ChatType::MoveFriendToGroup.";
                m_analyseMessage_moveFriendToGroup(buffer);
                break;
            }
            default: break;
        }
        // 更新缓冲区
        m_messageBuffer = m_messageBuffer.right(total_buffer_size - total_bytes);
        total_buffer_size = m_messageBuffer.size();
    }
}

void TcpSocketManager::m_analyseMessage_register(QDataStream& buffer)
{
    QByteArray register_account_bytes;
    QByteArray register_password_bytes;
    buffer >> register_account_bytes >> register_password_bytes;
    QString register_account = QString::fromUtf8(register_account_bytes);
    QString register_password = QString::fromUtf8(register_password_bytes);

    bool register_query = m_dbManager->m_queryUserInfo(register_account);
    if(register_query == true)      // 注册失败：用户已存在
    {
        qDebug() << "register failed.";
        // 构建发送字节流
        QByteArray send_bytes;
        QDataStream opt_buffer(&send_bytes, QIODevice::WriteOnly);
        opt_buffer.setVersion(QDataStream::Qt_5_9);
        opt_buffer.setByteOrder(QDataStream::LittleEndian);
        opt_buffer.setFloatingPointPrecision(QDataStream::SinglePrecision);
        quint16 cmd_type = ChatType::RegisterFailed;
        quint64 total_bytes_place = ChatType::MessageMinSize;
        quint8 fail_reason = ChatType::RegisterFailReason::AccountExist;
        opt_buffer<<total_bytes_place;
        opt_buffer<<cmd_type;
        opt_buffer<<fail_reason;
        quint64 total_bytes = send_bytes.size();
        opt_buffer.device()->seek(0);
        opt_buffer<<total_bytes;
        this->slot_socketSendMessage(m_getPeerAddress(), m_getPeerPort(), send_bytes);
    }
    else
    {
        sttClientInfo _user_info;
        _user_info.account = register_account;
        _user_info.password = register_password;
        _user_info.name = QStringLiteral("我的昵称");
        _user_info.level = 0;
        _user_info.age = 0;
        _user_info.signature = QStringLiteral("这个人很懒，什么都没留下。");
        quint32 register_user_id;
        bool _register_success = m_dbManager->m_insertUserInfo(_user_info, &register_user_id);
        // 注册成功后为该用户添加一个默认分组：我的好友
        bool _add_group_success = false;
        if(_register_success)
            _add_group_success = m_dbManager->m_userAddGroup(register_user_id, QStringLiteral("我的好友"));
        if(_register_success && _add_group_success)     // 注册成功
        {
            qDebug() << "register successfully.";
            // 构建发送字节流
            QByteArray send_bytes;
            QDataStream opt_buffer(&send_bytes, QIODevice::WriteOnly);
            opt_buffer.setVersion(QDataStream::Qt_5_9);
            opt_buffer.setByteOrder(QDataStream::LittleEndian);
            opt_buffer.setFloatingPointPrecision(QDataStream::SinglePrecision);
            quint16 cmd_type = ChatType::RegisterSuccess;
            quint64 total_bytes_place = ChatType::MessageMinSize;
            opt_buffer<<total_bytes_place;
            opt_buffer<<cmd_type;
            opt_buffer<<register_account.toUtf8()<<register_password.toUtf8();
            quint64 total_bytes = send_bytes.size();
            opt_buffer.device()->seek(0);
            opt_buffer<<total_bytes;
            this->slot_socketSendMessage(m_getPeerAddress(), m_getPeerPort(), send_bytes);
        }
        else                                                            // 注册失败
        {
            qDebug() << "register failed.";
            // 构建发送字节流
            QByteArray send_bytes;
            QDataStream opt_buffer(&send_bytes, QIODevice::WriteOnly);
            opt_buffer.setVersion(QDataStream::Qt_5_9);
            opt_buffer.setByteOrder(QDataStream::LittleEndian);
            opt_buffer.setFloatingPointPrecision(QDataStream::SinglePrecision);
            quint16 cmd_type = ChatType::RegisterFailed;
            quint64 total_bytes_place = ChatType::MessageMinSize;
            quint8 fail_reason = ChatType::RegisterFailReason::OtherReason;
            opt_buffer<<total_bytes_place;
            opt_buffer<<cmd_type;
            opt_buffer<<fail_reason;
            quint64 total_bytes = send_bytes.size();
            opt_buffer.device()->seek(0);
            opt_buffer<<total_bytes;
            this->slot_socketSendMessage(m_getPeerAddress(), m_getPeerPort(), send_bytes);
        }
    }
}

void TcpSocketManager::m_analyseMessage_login(QDataStream &buffer)
{
    QByteArray account_bytes;
    QByteArray password_bytes;
    buffer >> account_bytes >> password_bytes;
    QString _account = QString::fromUtf8(account_bytes);
    QString _password = QString::fromUtf8(password_bytes);

    sttClientInfo* _client_info = new sttClientInfo;
    if(m_dbManager->m_queryUserInfo(_account, _client_info) == false)       // 账号不存在
    {
        qDebug() << "login failed.";
        // 构建发送字节流
        QByteArray send_bytes;
        QDataStream opt_buffer(&send_bytes, QIODevice::WriteOnly);
        opt_buffer.setVersion(QDataStream::Qt_5_9);
        opt_buffer.setByteOrder(QDataStream::LittleEndian);
        opt_buffer.setFloatingPointPrecision(QDataStream::SinglePrecision);
        quint16 cmd_type = ChatType::LoginFailed;
        quint64 total_bytes_place = ChatType::MessageMinSize;
        quint8 fail_reason = ChatType::LoginFailReason::AccountNotExist;
        opt_buffer<<total_bytes_place;
        opt_buffer<<cmd_type;
        opt_buffer<<fail_reason;
        quint64 total_bytes = send_bytes.size();
        opt_buffer.device()->seek(0);
        opt_buffer<<total_bytes;
        this->slot_socketSendMessage(m_getPeerAddress(), m_getPeerPort(), send_bytes);
    }
    else if(_password != _client_info->password)         // 密码错误
    {
        qDebug() << "login failed.";
        // 构建发送字节流
        QByteArray send_bytes;
        QDataStream opt_buffer(&send_bytes, QIODevice::WriteOnly);
        opt_buffer.setVersion(QDataStream::Qt_5_9);
        opt_buffer.setByteOrder(QDataStream::LittleEndian);
        opt_buffer.setFloatingPointPrecision(QDataStream::SinglePrecision);
        quint16 cmd_type = ChatType::LoginFailed;
        quint64 total_bytes_place = ChatType::MessageMinSize;
        quint8 fail_reason = ChatType::LoginFailReason::PasswordError;
        opt_buffer<<total_bytes_place;
        opt_buffer<<cmd_type;
        opt_buffer<<fail_reason;
        quint64 total_bytes = send_bytes.size();
        opt_buffer.device()->seek(0);
        opt_buffer<<total_bytes;
        this->slot_socketSendMessage(m_getPeerAddress(), m_getPeerPort(), send_bytes);
    }
    else
    {

        QMap<quint32, sttGroupInfo> user_allGroupInfo;
        bool get_group_success = m_dbManager->m_queryUserAllGroups(_client_info->id, &user_allGroupInfo);
        QString _curTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
        bool modify_success = m_dbManager->m_modifyUserInfo(_client_info->id, "last_online", _curTime);
        QVector<quint32> user_allFriends;
        bool query_friend_success = m_dbManager->m_queryUserAllFriends(_client_info->id, &user_allFriends);
        if(get_group_success==false || modify_success==false || query_friend_success==false)               // 数据库读取失败
        {
            qDebug() << "login failed.";
            // 构建发送字节流
            QByteArray send_bytes;
            QDataStream opt_buffer(&send_bytes, QIODevice::WriteOnly);
            opt_buffer.setVersion(QDataStream::Qt_5_9);
            opt_buffer.setByteOrder(QDataStream::LittleEndian);
            opt_buffer.setFloatingPointPrecision(QDataStream::SinglePrecision);
            quint16 cmd_type = ChatType::LoginFailed;
            quint64 total_bytes_place = ChatType::MessageMinSize;
            quint8 fail_reason = ChatType::LoginFailReason::LoginOtherReason;
            opt_buffer<<total_bytes_place;
            opt_buffer<<cmd_type;
            opt_buffer<<fail_reason;
            quint64 total_bytes = send_bytes.size();
            opt_buffer.device()->seek(0);
            opt_buffer<<total_bytes;
            this->slot_socketSendMessage(m_getPeerAddress(), m_getPeerPort(), send_bytes);
        }
        else                                                                    // 登录成功
        {
            _client_info->address = m_getPeerAddress();
            _client_info->port = m_getPeerPort();
            _client_info->last_online = _curTime;
            // 构建发送字节流
            QByteArray send_bytes;
            QDataStream opt_buffer(&send_bytes, QIODevice::WriteOnly);
            opt_buffer.setVersion(QDataStream::Qt_5_9);
            opt_buffer.setByteOrder(QDataStream::LittleEndian);
            opt_buffer.setFloatingPointPrecision(QDataStream::SinglePrecision);
            quint16 cmd_type = ChatType::LoginSuccess;
            quint64 total_bytes_place = ChatType::MessageMinSize;
            opt_buffer<<total_bytes_place;
            opt_buffer<<cmd_type;
            opt_buffer<<(*_client_info);
            quint8 group_num = user_allGroupInfo.size();
            opt_buffer<<group_num;
            for(QMap<quint32, sttGroupInfo>::const_iterator ite = user_allGroupInfo.begin(); ite!=user_allGroupInfo.end(); ++ite)
            {
                opt_buffer << ite.key();
                opt_buffer << ite.value();
            }
            quint64 total_bytes = send_bytes.size();
            opt_buffer.device()->seek(0);
            opt_buffer<<total_bytes;
            m_loginUserID = _client_info->id;
            emit signal_loginSuccess(_client_info->id, m_getPeerAddress(), m_getPeerPort(), user_allFriends);
            this->slot_socketSendMessage(m_getPeerAddress(), m_getPeerPort(), send_bytes);
        }
    }
    delete _client_info;
}

void TcpSocketManager::m_analyseMessage_modifyUserInfo(QDataStream &buffer)
{
    quint32 user_id;
    quint8 modify_num;
    buffer >> user_id;
    buffer >> modify_num;
    bool _modify_success = false;
    int i;
    for(i=0; i<modify_num; ++i)
    {
        QByteArray _modify_key_bytes;
        QByteArray _modify_value_bytes;
        buffer >> _modify_key_bytes >> _modify_value_bytes;
        QString _modify_key = QString::fromUtf8(_modify_key_bytes);
        QString _modify_value = QString::fromUtf8(_modify_value_bytes);

        bool _item_success = m_dbManager->m_modifyUserInfo(user_id, _modify_key, QVariant(_modify_value));
        if(_item_success == false)
            break;
    }
    _modify_success = (i==modify_num)? true:false;
    if(_modify_success)
    {
        qDebug() << "modify user info successfully.";
        sttClientInfo _client_info;
        bool _query_success = m_dbManager->m_queryUserInfo(user_id, &_client_info);
        if(_query_success == false)
        {
            qDebug() << "but query user info from database is failed. No reply.";
            return;
        }
        // 构建发送字节流
        QByteArray send_bytes;
        QDataStream opt_buffer(&send_bytes, QIODevice::WriteOnly);
        opt_buffer.setVersion(QDataStream::Qt_5_9);
        opt_buffer.setByteOrder(QDataStream::LittleEndian);
        opt_buffer.setFloatingPointPrecision(QDataStream::SinglePrecision);
        quint16 cmd_type = ChatType::ModifyUserInfoSuccess;
        quint64 total_bytes_place = ChatType::MessageMinSize;
        opt_buffer<<total_bytes_place;
        opt_buffer<<cmd_type;
        opt_buffer<<_client_info;
        quint64 total_bytes = send_bytes.size();
        opt_buffer.device()->seek(0);
        opt_buffer<<total_bytes;
        this->slot_socketSendMessage(m_getPeerAddress(), m_getPeerPort(), send_bytes);

        // 告知该用户的好友：该用户修改了个人信息
        QVector<quint32> friend_id_lists;
        bool _query_friend_success = m_dbManager->m_queryUserAllFriends(user_id, &friend_id_lists);
        if(_query_friend_success)
        {
            for(quint32 cur_friend_id : friend_id_lists)
            {
                // 查询该用户作为cur_friend_id的好友的sttFriendInfo
                sttFriendInfo _user_friend_info;
                bool _query_friend_info_success = m_dbManager->m_queryFriendInfo(cur_friend_id, user_id, &_user_friend_info);
                if(_query_friend_info_success)
                {
                    // 然后让服务端转发给该用户的好友
                    QByteArray send_bytes;
                    QDataStream opt_buffer(&send_bytes, QIODevice::WriteOnly);
                    opt_buffer.setVersion(QDataStream::Qt_5_9);
                    opt_buffer.setByteOrder(QDataStream::LittleEndian);
                    opt_buffer.setFloatingPointPrecision(QDataStream::SinglePrecision);
                    quint16 cmd_type = ChatType::UpdateFriendInfo;
                    quint64 total_bytes_place = ChatType::MessageMinSize;
                    opt_buffer<<total_bytes_place;
                    opt_buffer<<cmd_type;
                    opt_buffer<<user_id;
                    opt_buffer<<_user_friend_info;
                    quint64 total_bytes = send_bytes.size();
                    opt_buffer.device()->seek(0);
                    opt_buffer<<total_bytes;
                    QVector<quint32> relay_to_who = {cur_friend_id};
                    emit signal_requestRelayBytes(relay_to_who, send_bytes);
                }
            }
        }
    }
    else
    {
        qDebug() << "modify user info failed.";
        // 构建发送字节流
        QByteArray send_bytes;
        QDataStream opt_buffer(&send_bytes, QIODevice::WriteOnly);
        opt_buffer.setVersion(QDataStream::Qt_5_9);
        opt_buffer.setByteOrder(QDataStream::LittleEndian);
        opt_buffer.setFloatingPointPrecision(QDataStream::SinglePrecision);
        quint16 cmd_type = ChatType::ModifyUserInfoFailed;
        quint64 total_bytes_place = ChatType::MessageMinSize;
        opt_buffer<<total_bytes_place;
        opt_buffer<<cmd_type;
        quint64 total_bytes = send_bytes.size();
        opt_buffer.device()->seek(0);
        opt_buffer<<total_bytes;
        this->slot_socketSendMessage(m_getPeerAddress(), m_getPeerPort(), send_bytes);
    }
}

void TcpSocketManager::m_analyseMessage_addGroup(QDataStream &buffer)
{
    quint32 user_id;
    buffer >> user_id;
    QByteArray group_name_bytes;
    buffer >> group_name_bytes;
    QString group_name = QString::fromUtf8(group_name_bytes);
    quint32 new_group_id;
    bool add_success = m_dbManager->m_userAddGroup(user_id, group_name, &new_group_id);
    if(add_success)
    {
        qDebug() << "add group successfully.";
        // 构建发送字节流
        QByteArray send_bytes;
        QDataStream opt_buffer(&send_bytes, QIODevice::WriteOnly);
        opt_buffer.setVersion(QDataStream::Qt_5_9);
        opt_buffer.setByteOrder(QDataStream::LittleEndian);
        opt_buffer.setFloatingPointPrecision(QDataStream::SinglePrecision);
        quint16 cmd_type = ChatType::AddGroupSuccess;
        quint64 total_bytes_place = ChatType::MessageMinSize;
        opt_buffer<<total_bytes_place;
        opt_buffer<<cmd_type;
        opt_buffer<<new_group_id;
        opt_buffer<<group_name.toUtf8();
        quint64 total_bytes = send_bytes.size();
        opt_buffer.device()->seek(0);
        opt_buffer<<total_bytes;
        this->slot_socketSendMessage(m_getPeerAddress(), m_getPeerPort(), send_bytes);
    }
    else
    {
        qDebug() << "add group failed.";
        // 构建发送字节流
        QByteArray send_bytes;
        QDataStream opt_buffer(&send_bytes, QIODevice::WriteOnly);
        opt_buffer.setVersion(QDataStream::Qt_5_9);
        opt_buffer.setByteOrder(QDataStream::LittleEndian);
        opt_buffer.setFloatingPointPrecision(QDataStream::SinglePrecision);
        quint16 cmd_type = ChatType::AddGroupFailed;
        quint64 total_bytes_place = ChatType::MessageMinSize;
        opt_buffer<<total_bytes_place;
        opt_buffer<<cmd_type;
        quint64 total_bytes = send_bytes.size();
        opt_buffer.device()->seek(0);
        opt_buffer<<total_bytes;
        this->slot_socketSendMessage(m_getPeerAddress(), m_getPeerPort(), send_bytes);
    }
}

void TcpSocketManager::m_analyseMessage_renameGroup(QDataStream &buffer)
{
    quint32 user_id;
    quint32 group_id;
    QByteArray new_name_bytes;
    buffer >> user_id >> group_id >> new_name_bytes;
    QString new_name = QString::fromUtf8(new_name_bytes);

    m_dbManager->m_userRenameGroup(user_id, group_id, new_name);
}

void TcpSocketManager::m_analyseMessage_queryOnlineState(QDataStream &buffer)
{
    quint32 user_id;
    buffer >> user_id;
    emit signal_queryOnlineState(user_id);
}

void TcpSocketManager::slot_receiveReplyOnlineState(const QHostAddress client_self_address, const quint16 client_self_port,
                                                    const quint32 query_user_id, const ChatType::ChatCMD cmd_type)
{
    if(client_self_address!=m_getPeerAddress() || client_self_port!=m_getPeerPort())
        return;
    switch(cmd_type)
    {
        case ChatType::ChatCMD::ReturnOnline:
        {
            qDebug() << "the user queried is online.";
            // 构建发送字节流
            QByteArray send_bytes;
            QDataStream opt_buffer(&send_bytes, QIODevice::WriteOnly);
            opt_buffer.setVersion(QDataStream::Qt_5_9);
            opt_buffer.setByteOrder(QDataStream::LittleEndian);
            opt_buffer.setFloatingPointPrecision(QDataStream::SinglePrecision);
            quint16 cmd_type = ChatType::ReturnOnline;
            quint64 total_bytes_place = ChatType::MessageMinSize;
            opt_buffer<<total_bytes_place;
            opt_buffer<<cmd_type;
            opt_buffer<<query_user_id;
            quint64 total_bytes = send_bytes.size();
            opt_buffer.device()->seek(0);
            opt_buffer<<total_bytes;
            this->slot_socketSendMessage(m_getPeerAddress(), m_getPeerPort(), send_bytes);
            break;
        }
        default:
        {
            qDebug() << "the user queried is offline.";
            // 构建发送字节流
            QByteArray send_bytes;
            QDataStream opt_buffer(&send_bytes, QIODevice::WriteOnly);
            opt_buffer.setVersion(QDataStream::Qt_5_9);
            opt_buffer.setByteOrder(QDataStream::LittleEndian);
            opt_buffer.setFloatingPointPrecision(QDataStream::SinglePrecision);
            quint16 cmd_type = ChatType::ReturnOffline;
            quint64 total_bytes_place = ChatType::MessageMinSize;
            opt_buffer<<total_bytes_place;
            opt_buffer<<cmd_type;
            opt_buffer<<query_user_id;
            quint64 total_bytes = send_bytes.size();
            opt_buffer.device()->seek(0);
            opt_buffer<<total_bytes;
            this->slot_socketSendMessage(m_getPeerAddress(), m_getPeerPort(), send_bytes);
            break;
        }
    }
}

void TcpSocketManager::m_analyseMessage_sendChatMsg(QDataStream &buffer)
{
    quint32 send_id;
    quint32 rcv_id;
    buffer >> send_id >> rcv_id;
    QByteArray msg_bytes;
    buffer >> msg_bytes;
    QString msg = QString::fromUtf8(msg_bytes);

    // 构建发送字节流
    QByteArray send_bytes;
    QDataStream opt_buffer(&send_bytes, QIODevice::WriteOnly);
    opt_buffer.setVersion(QDataStream::Qt_5_9);
    opt_buffer.setByteOrder(QDataStream::LittleEndian);
    opt_buffer.setFloatingPointPrecision(QDataStream::SinglePrecision);
    quint16 cmd_type = ChatType::ReceiveChatMsg;
    quint64 total_bytes_place = ChatType::MessageMinSize;
    opt_buffer<<total_bytes_place;
    opt_buffer<<cmd_type;
    opt_buffer << send_id << rcv_id;
    opt_buffer << msg.toUtf8();
    quint64 total_bytes = send_bytes.size();
    opt_buffer.device()->seek(0);
    opt_buffer<<total_bytes;

    QVector<quint32> these_users = {rcv_id};

    emit signal_requestRelayBytes(these_users, send_bytes);
}

void TcpSocketManager::m_analyseMessage_searchUserRequest(QDataStream &buffer)
{
    quint32 send_id;
    buffer >> send_id;
    QByteArray search_text_bytes;
    buffer >> search_text_bytes;
    QString search_text = QString::fromUtf8(search_text_bytes);

    if(search_text.isEmpty())
        return;
    QVector<sttFriendInfo> search_records;      // 根据关键词搜索得到的记录
    bool search_success = m_dbManager->m_searchSimilarUser(send_id, search_text, &search_records);
    if(search_success)      // 搜索成功
    {
        // 构建发送字节流：先把用户信息发过去
        QByteArray send_bytes;
        QDataStream opt_buffer(&send_bytes, QIODevice::WriteOnly);
        opt_buffer.setVersion(QDataStream::Qt_5_9);
        opt_buffer.setByteOrder(QDataStream::LittleEndian);
        opt_buffer.setFloatingPointPrecision(QDataStream::SinglePrecision);
        quint16 cmd_type = ChatType::SearchUserSuccess;
        quint64 total_bytes_place = ChatType::MessageMinSize;
        opt_buffer<<total_bytes_place;
        opt_buffer<<cmd_type;
        opt_buffer<<search_text.toUtf8();
        quint8 record_num = search_records.size();
        opt_buffer<<record_num;
        for(sttFriendInfo cur_friend_info : search_records)
        {
            opt_buffer << cur_friend_info;
        }
        quint64 total_bytes = send_bytes.size();
        opt_buffer.device()->seek(0);
        opt_buffer<<total_bytes;
        this->slot_socketSendMessage(m_getPeerAddress(), m_getPeerPort(), send_bytes);

        // 再发送头像
        for(sttFriendInfo cur_friend_info : search_records)
        {
            QString cur_head_path;
            m_dbManager->m_queryHeadPath(cur_friend_info.id, &cur_head_path);
            if(!cur_head_path.isEmpty() && QFile(cur_head_path).exists())
            {
                QVector<quint32> relay_to_who = {m_loginUserID};
                this->m_sendHeadPictoClient(relay_to_who, cur_friend_info.id, cur_head_path);
            }
        }
    }
    else                    // 搜索失败
    {
        // 构建发送字节流
        QByteArray send_bytes;
        QDataStream opt_buffer(&send_bytes, QIODevice::WriteOnly);
        opt_buffer.setVersion(QDataStream::Qt_5_9);
        opt_buffer.setByteOrder(QDataStream::LittleEndian);
        opt_buffer.setFloatingPointPrecision(QDataStream::SinglePrecision);
        quint16 cmd_type = ChatType::SearchUserFailed;
        quint64 total_bytes_place = ChatType::MessageMinSize;
        opt_buffer<<total_bytes_place;
        opt_buffer<<cmd_type;
        quint64 total_bytes = send_bytes.size();
        opt_buffer.device()->seek(0);
        opt_buffer<<total_bytes;
        this->slot_socketSendMessage(m_getPeerAddress(), m_getPeerPort(), send_bytes);
    }
}

void TcpSocketManager::m_analyseMessage_addFriendRequest(QDataStream &buffer)
{
    quint32 send_id;
    quint32 rcv_id;
    buffer >> send_id >> rcv_id;
    QByteArray verify_msg_bytes;
    buffer >> verify_msg_bytes;
    QString msg = QString::fromUtf8(verify_msg_bytes);
    quint32 group_id;
    buffer >> group_id;

    // 查询发送方的用户信息
    sttClientInfo _client_info;
    bool query_success = m_dbManager->m_queryUserInfo(send_id, &_client_info);
    if(query_success == false)
        // TODO 查询失败时发送添加好友失败
        return;
    _client_info.password.clear();      // 发送方的密码不可以泄露

    qDebug() << "add friend request from" << send_id << "is relayed to" << rcv_id;
    // 向接受方转发发送方的信息
    QByteArray send_bytes;
    QDataStream opt_buffer(&send_bytes, QIODevice::WriteOnly);
    opt_buffer.setVersion(QDataStream::Qt_5_9);
    opt_buffer.setByteOrder(QDataStream::LittleEndian);
    opt_buffer.setFloatingPointPrecision(QDataStream::SinglePrecision);
    quint16 cmd_type = ChatType::ReceiveAddFriendRequest;
    quint64 total_bytes_place = ChatType::MessageMinSize;
    opt_buffer<<total_bytes_place;
    opt_buffer<<cmd_type;
    opt_buffer << rcv_id;
    opt_buffer << _client_info;
    opt_buffer << msg.toUtf8();
    opt_buffer << group_id;
    quint64 total_bytes = send_bytes.size();
    opt_buffer.device()->seek(0);
    opt_buffer<<total_bytes;
    QVector<quint32> these_users = {rcv_id};
    emit signal_requestRelayBytes(these_users, send_bytes);

    // 再把发送方的头像也发给接收方
    QString sender_head_path;
    m_dbManager->m_queryHeadPath(send_id, &sender_head_path);
    if(!sender_head_path.isEmpty() && QFile(sender_head_path).exists())
    {
        QVector<quint32> relay_to_who = {rcv_id};
        this->m_sendHeadPictoClient(relay_to_who, send_id, sender_head_path);
    }
}

void TcpSocketManager::m_analyseMessage_replyAddFriendRequest(QDataStream &buffer)
{
    quint32 _who_reply;
    quint32 _reply_to_who;
    quint8 _comment_bytes;
    quint32 _group_of_who_reply;
    quint32 _group_of_reply_to_who;

    buffer >> _who_reply >> _reply_to_who >> _comment_bytes >> _group_of_who_reply >> _group_of_reply_to_who;
    bool _reply_is_agree = (_comment_bytes == 0x00)? true : false;

    if(_reply_is_agree)         // 同意添加好友请求
    {
        sttClientInfo _client_who_reply;
        sttClientInfo _client_reply_to_who;
        bool _success_1 = m_dbManager->m_queryUserInfo(_who_reply, &_client_who_reply);
        bool _success_2 = m_dbManager->m_queryUserInfo(_reply_to_who, &_client_reply_to_who);
        if(_success_1==false || _success_2==false)
        {
            qDebug() << "Error from TcpSocketManager::m_analyseMessage_replyAddFriendRequest: query user info failed.";
            return;
        }
        bool _build_success = m_dbManager->m_buildFriendShip(_who_reply, _group_of_who_reply, _reply_to_who, _group_of_reply_to_who);
        if(_build_success == false)
        {
            qDebug() << "Error from TcpSocketManager::m_analyseMessage_replyAddFriendRequest: build friendship in database failed.";
            return;
        }
        qDebug() << _who_reply << "and" << _reply_to_who << "build friendship successfully.";

        {
            // 向发送方发送字节流
            sttFriendInfo _friendInfo_other;
            _friendInfo_other.id = _client_reply_to_who.id;
            _friendInfo_other.group_id = _group_of_who_reply;
            _friendInfo_other.account = _client_reply_to_who.account;
            _friendInfo_other.name = _client_reply_to_who.name;
            _friendInfo_other.level = _client_reply_to_who.level;
            _friendInfo_other.signature = _client_reply_to_who.signature;
            _friendInfo_other.sex = _client_reply_to_who.sex;
            _friendInfo_other.age = _client_reply_to_who.age;
            _friendInfo_other.last_online = _client_reply_to_who.last_online;
            QByteArray send_bytes;
            QDataStream opt_buffer(&send_bytes, QIODevice::WriteOnly);
            opt_buffer.setVersion(QDataStream::Qt_5_9);
            opt_buffer.setByteOrder(QDataStream::LittleEndian);
            opt_buffer.setFloatingPointPrecision(QDataStream::SinglePrecision);
            quint16 cmd_type = ChatType::AgreeAddFriendRequest;
            quint64 total_bytes_place = ChatType::MessageMinSize;
            opt_buffer<<total_bytes_place;
            opt_buffer<<cmd_type;
            opt_buffer<<_who_reply;
            opt_buffer<<_group_of_who_reply;
            opt_buffer<<_friendInfo_other;
            quint64 total_bytes = send_bytes.size();
            opt_buffer.device()->seek(0);
            opt_buffer<<total_bytes;
            this->slot_socketSendMessage(m_getPeerAddress(), m_getPeerPort(), send_bytes);
        }
        {
            // 向接收方发送字节流
            sttFriendInfo _friendInfo_other;
            _friendInfo_other.id = _client_who_reply.id;
            _friendInfo_other.group_id = _group_of_reply_to_who;
            _friendInfo_other.account = _client_who_reply.account;
            _friendInfo_other.name = _client_who_reply.name;
            _friendInfo_other.level = _client_who_reply.level;
            _friendInfo_other.signature = _client_who_reply.signature;
            _friendInfo_other.sex = _client_who_reply.sex;
            _friendInfo_other.age = _client_who_reply.age;
            _friendInfo_other.last_online = _client_who_reply.last_online;
            QByteArray send_bytes;
            QDataStream opt_buffer(&send_bytes, QIODevice::WriteOnly);
            opt_buffer.setVersion(QDataStream::Qt_5_9);
            opt_buffer.setByteOrder(QDataStream::LittleEndian);
            opt_buffer.setFloatingPointPrecision(QDataStream::SinglePrecision);
            quint16 cmd_type = ChatType::AgreeAddFriendRequest;
            quint64 total_bytes_place = ChatType::MessageMinSize;
            opt_buffer<<total_bytes_place;
            opt_buffer<<cmd_type;
            opt_buffer<<_reply_to_who;
            opt_buffer<<_group_of_reply_to_who;
            opt_buffer<<_friendInfo_other;
            quint64 total_bytes = send_bytes.size();
            opt_buffer.device()->seek(0);
            opt_buffer<<total_bytes;
            QVector<quint32> these_users = {_reply_to_who};
            emit signal_requestRelayBytes(these_users, send_bytes);
        }
    }
    else                        // 拒绝添加好友请求
    {
        // 构建发送字节流
        qDebug() << _who_reply << "reject the add friend request from" << _reply_to_who;
        QByteArray send_bytes;
        QDataStream opt_buffer(&send_bytes, QIODevice::WriteOnly);
        opt_buffer.setVersion(QDataStream::Qt_5_9);
        opt_buffer.setByteOrder(QDataStream::LittleEndian);
        opt_buffer.setFloatingPointPrecision(QDataStream::SinglePrecision);
        quint16 cmd_type = ChatType::RejectAddFriendRequest;
        quint64 total_bytes_place = ChatType::MessageMinSize;
        opt_buffer<<total_bytes_place;
        opt_buffer<<cmd_type;
        opt_buffer << _reply_to_who;
        opt_buffer << _who_reply;
        opt_buffer << _group_of_reply_to_who;
        quint64 total_bytes = send_bytes.size();
        opt_buffer.device()->seek(0);
        opt_buffer<<total_bytes;
        QVector<quint32> these_users = {_reply_to_who};
        emit signal_requestRelayBytes(these_users, send_bytes);
    }
}


void TcpSocketManager::m_analyseMessage_requestUserHeadPic(QDataStream &buffer)
{
    quint32 user_id;
    buffer >> user_id;
    qDebug() << QThread::currentThread() << " ================================ TcpSocketManager::m_analyseMessage_requestUserHeadPic, request id is" << user_id;
    QString head_path;
    bool _query_head_success = m_dbManager->m_queryHeadPath(user_id, &head_path);
    qDebug() << "query head success:" << _query_head_success << ", get head path:" << head_path;
    if(head_path.isEmpty() || !QFile(head_path).exists())
    {
        head_path = ":/icon/UserFile/default.png";
    }
    QVector<quint32> relay_to_who = {m_loginUserID};
    this->m_sendHeadPictoClient(relay_to_who, user_id, head_path);
}

void TcpSocketManager::m_sendFileToClient(const QVector<quint32>& rcv_ids, QFile& file_to_send)
{
    quint64 bytes_to_write = file_to_send.size();
    quint64 load_size = 50 * 1024;                   // 每次发送50KB
    quint64 bytes_already_send = 0;
    if(file_to_send.open(QIODevice::ReadOnly))
    {
        while(!file_to_send.atEnd())
        {
            qint64 read_size = qMin(bytes_to_write, load_size);
            QByteArray cur_bytes = file_to_send.read(read_size);
            emit signal_requestRelayBytes(rcv_ids, cur_bytes);
            bytes_to_write -= read_size;
            bytes_already_send += read_size;
            qDebug() << "send file to" << rcv_ids << "progress:  " << bytes_already_send << "/" << file_to_send.size();
        }
        file_to_send.close();
    }
}

void TcpSocketManager::m_sendHeadPictoClient(const QVector<quint32>& rcv_ids, const quint32& query_id, const QString& pic_path)
{
    try{
        QFile file_to_send(pic_path);
        if(!file_to_send.exists())
            return;
        quint64 pic_size = file_to_send.size();    // 图片大小
        qDebug() << "query id:" << query_id << ", pic size:" << pic_size << ", pic_path:" << pic_path;

        if(pic_size > ChatType::PicMaxSize)
            return;

        // 构建包头，先发包头
        QByteArray send_bytes;
        QDataStream opt_buffer(&send_bytes, QIODevice::WriteOnly);
        opt_buffer.setVersion(QDataStream::Qt_5_9);
        opt_buffer.setByteOrder(QDataStream::LittleEndian);
        opt_buffer.setFloatingPointPrecision(QDataStream::SinglePrecision);
        quint16 cmd_type = ChatType::ReceiveUserHeadPic;
        quint64 total_bytes_place = ChatType::MessageMinSize;
        opt_buffer<<total_bytes_place;
        opt_buffer<<cmd_type;
        opt_buffer << query_id;
        QString pic_name = QFileInfo(pic_path).fileName();
        opt_buffer << pic_name.toUtf8();
        opt_buffer << quint64(pic_size);
        quint64 total_bytes = send_bytes.size()+pic_size;
        opt_buffer.device()->seek(0);
        opt_buffer<<total_bytes;
        emit signal_requestRelayBytes(rcv_ids, send_bytes);     // 直接请求服务端转发

        // 发图片
        m_sendFileToClient(rcv_ids, file_to_send);
    }
    catch(...){
        qDebug() << "An Error occured in m_sendHeadPictoClient.";
    }

}

void TcpSocketManager::m_receiveAndSaveFile(const qint64 &file_size, const QString &file_save_path, QDataStream &buffer)
{
    if(file_size <= 0)
        return;
    qint64 bytes_to_read = file_size;
    QFile file(file_save_path);
    if(file.exists())
        file.remove();
    if(file.open(QIODevice::WriteOnly))
    {
        qint64 load_size = 50*1024;         // 每次至多读50KB，写入文件
        while(bytes_to_read > 0 && !buffer.atEnd())
        {
            quint64 read_size = qMin(load_size, bytes_to_read);
            QByteArray cur_read_bytes;
            cur_read_bytes.resize(read_size);
            buffer.readRawData(cur_read_bytes.data(), read_size);
            bytes_to_read -= read_size;
            file.write(cur_read_bytes);
        }
        file.close();
    }
}

void TcpSocketManager::m_analyseMessage_modifyUserHead(QDataStream &buffer)
{
    quint32 user_id;
    buffer >> user_id;
    QByteArray name_bytes;
    buffer >> name_bytes;
    QString pic_name = QString::fromUtf8(name_bytes);
    QString pic_path = Config::getInstance()->m_getUserFilePath() + "/" + QString::number(user_id) + "_head." + QFileInfo(pic_name).suffix();       // 命名例如 1_head.jpg
    qint64 pic_size;
    buffer >> pic_size;
    if(pic_size > ChatType::PicMaxSize)
        return;
    QString _old_head_path;
    m_dbManager->m_queryHeadPath(user_id, &_old_head_path);
    if(!_old_head_path.isEmpty() && QFile(_old_head_path).exists())          // 删除旧头像
        QFile(_old_head_path).remove();
    m_receiveAndSaveFile(pic_size, pic_path, buffer);                   // 头像保存到本地
    m_dbManager->m_modifyUserInfo(user_id, "head_path", pic_path);      // 更新头像的路径到数据库

    // 告知该用户的好友：该用户修改了头像
    QVector<quint32> friend_id_lists;
    bool _query_friend_success = m_dbManager->m_queryUserAllFriends(user_id, &friend_id_lists);
    if(_query_friend_success)
    {
        m_sendHeadPictoClient(friend_id_lists, user_id, pic_path);
    }
}

void TcpSocketManager::m_analyseMessage_sendChatPic(QDataStream &buffer)
{
    quint32 send_id;
    quint32 rcv_id;
    buffer >> send_id >> rcv_id;
    QByteArray name_bytes;
    buffer >> name_bytes;
    quint64 pic_size;
    buffer >> pic_size;
    QString local_pic_path = generateRandomFilePath(Config::getInstance()->m_getUserFilePath(), QString::fromUtf8(name_bytes));
    m_receiveAndSaveFile(pic_size, local_pic_path, buffer);

    // 构建发送字节流
    QByteArray send_bytes;
    QDataStream opt_buffer(&send_bytes, QIODevice::WriteOnly);
    opt_buffer.setVersion(QDataStream::Qt_5_9);
    opt_buffer.setByteOrder(QDataStream::LittleEndian);
    opt_buffer.setFloatingPointPrecision(QDataStream::SinglePrecision);
    quint16 cmd_type = ChatType::ReceiveChatPic;
    quint64 total_bytes_place = ChatType::MessageMinSize;
    opt_buffer<<total_bytes_place;
    opt_buffer<<cmd_type;
    opt_buffer << send_id << rcv_id;
    opt_buffer << name_bytes << pic_size;
    quint64 total_bytes = send_bytes.size() + pic_size;
    opt_buffer.device()->seek(0);
    opt_buffer<<total_bytes;

    QVector<quint32> these_users = {rcv_id};
    emit signal_requestRelayBytes(these_users, send_bytes);

    QFile pic_to_relay(local_pic_path);
    m_sendFileToClient(these_users, pic_to_relay);

    // TODO 目前服务端还没有实现备份用户聊天记录的功能，聊天图片转发完毕就删除了
    if(pic_to_relay.exists())
        pic_to_relay.remove();
}

void TcpSocketManager::m_analyseMessage_moveFriendToGroup(QDataStream &buffer)
{
    quint32 user_id;
    quint32 friend_id;
    quint32 group_id;
    buffer >> user_id >> friend_id >> group_id;
    m_dbManager->m_modifyUserFriendGroup(user_id, friend_id, group_id);
}
