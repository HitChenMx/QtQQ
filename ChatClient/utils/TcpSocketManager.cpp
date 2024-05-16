#include "TcpSocketManager.h"

TcpSocketManager::TcpSocketManager(QHostAddress host_address, quint16 host_port, float max_connect_time, QObject *parent) :
    QObject(parent),
    m_tcpSocket(nullptr),
    m_hostAddress(host_address),
    m_hostPort(host_port),
    m_maxConnectTime(max_connect_time)
{

}

TcpSocketManager::~TcpSocketManager()
{

}

void TcpSocketManager::slot_closeSocket()
{
    // m_tcpSocket 是在子线程中被创建的，所以也应当在子线程中被释放
    QThread* cur_thread = QThread::currentThread();
    qDebug() << cur_thread << " ========================================================== " << "TcpSocketManager::slot_closeSocket";
    if(m_tcpSocket != nullptr)
    {
        if(m_tcpSocket->state() == QAbstractSocket::ConnectedState)
        {
            m_tcpSocket->disconnectFromHost();
        }
    }
    m_tcpSocket = nullptr;
    cur_thread->quit();         // 连同socket所在的线程一起释放
    qDebug() << "socket is closed successfully." << cur_thread << "quit successfully.";
}

void TcpSocketManager::slot_init()
{
    qDebug() << QThread::currentThread() << " ========================================================== " << "TcpSocketManager child thread";

    qRegisterMetaType<sttClientInfo>("sttClientInfo");
    qRegisterMetaType<QByteArray>("QByteArray");
    qRegisterMetaType<QMap<quint32,sttGroupInfo>>("QMap<quint32,sttGroupInfo>");
    qRegisterMetaType<QHostAddress>("QHostAddress");
    qRegisterMetaType<QVector<sttFriendInfo>>("QVector<sttFriendInfo>");
    qRegisterMetaType<sttFriendInfo>("sttFriendInfo");
    qRegisterMetaType<QVector<int>>("QVector<int>");

    m_tcpSocket = new QTcpSocket();
    connect(m_tcpSocket, &QTcpSocket::connected, [this](){                                // --- 成功连接 --
        m_connectTimer->stop();
        emit signal_socketConnected();
    });
    connect(m_tcpSocket, &QTcpSocket::disconnected, [this](){                                 // --- 断开连接 --
        emit signal_socketDisconnected();
    });
    connect(m_tcpSocket, &QTcpSocket::readyRead, this, &TcpSocketManager::slot_socketReadyRead);           // --- socket收到消息 ---

    m_connectTimer = new QTimer(this);
    connect(m_connectTimer, &QTimer::timeout, [this](){                                       // --- 连接超时 --
        emit signal_socketConnectFailed();
        // 自动重连
        m_connectTimer->stop();
        m_tcpSocket->abort();
        m_tcpSocket->connectToHost(m_hostAddress, m_hostPort);
        m_connectTimer->start(m_maxConnectTime);
    });

    m_tcpSocket->connectToHost(m_hostAddress, m_hostPort);
    m_connectTimer->start(m_maxConnectTime);
}

void TcpSocketManager::m_receiveFile(const qint64& file_size, const QString& file_save_path, QDataStream& buffer)
{
    if(file_size <= 0)
        return;
    qint64 bytes_to_read = file_size;
    QFile file(file_save_path);
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

void TcpSocketManager::slot_socketReadyRead()
{
    QByteArray message = m_tcpSocket->readAll();
    m_messageBuffer.append(message);
    if(m_messageBuffer.size() < ChatType::MessageMinSize)
        return;

    int total_buffer_size = m_messageBuffer.size();
    // 对方可能会一下子发过来1个以上的数据包，那么自己就需要有一个循环，把这些数据包都完成解析
    while(total_buffer_size > 0)
    {
        // 设置读取字节流
        QDataStream buffer(&m_messageBuffer, QIODevice::ReadOnly);
        buffer.setVersion(_My_VERSION);
        buffer.setByteOrder(_My_ORDER);
        buffer.setFloatingPointPrecision(_My_PRECISION);
        quint64 total_bytes;
        buffer >> total_bytes;
        if(total_buffer_size < total_bytes)         // 如果当前数据包不是一个完整的数据包，就直接退出，等待下次解析
            return;

        // 根据命令类型分不同的情况
        quint16 cmd_type;
        buffer >> cmd_type;
        switch(cmd_type)
        {
            case ChatType::RegisterSuccess:             // ========== 注册成功 ==========
            {
                qDebug() << "ChatType::RegisterSuccess";
                emit signal_registerSuccess();
                break;
            }
            case ChatType::RegisterFailed:              // ========== 注册失败 ==========
            {
                qDebug() << "ChatType::RegisterFailed";
                quint8 fail_cmd;
                buffer >> fail_cmd;
                QString fail_reason = "";
                switch(fail_cmd)
                {
                    case ChatType::RegisterFailReason::AccountExist:
                    {
                        fail_reason = QStringLiteral("该用户已存在");
                        break;
                    }
                    case ChatType::RegisterFailReason::OtherReason:
                    {
                        fail_reason = "";
                        break;
                    }
                    default:    break;
                }
                emit signal_registerFailed(fail_reason);
                break;
            }
            case ChatType::LoginSuccess:                // ========== 登录成功 ==========
            {
                qDebug() << "ChatType::LoginSuccess";
                sttClientInfo client_info;
                buffer >> client_info;
                quint8 group_num;
                buffer >> group_num;
                QMap<quint32, sttGroupInfo> all_group_info;
                for(int i=0; i<group_num; ++i)
                {
                    quint32 group_id;
                    buffer >> group_id;
                    sttGroupInfo cur_group_info;
                    buffer >> cur_group_info;
                    all_group_info.insert(group_id, cur_group_info);
                }
                emit signal_loginSuccess(client_info, all_group_info);
                break;
            }
            case ChatType::LoginFailed:                 // ========== 登录失败 ==========
            {
                qDebug() << "ChatType::LoginFailed";
                quint8 fail_cmd;
                buffer >> fail_cmd;
                QString fail_reason = "";
                switch(fail_cmd)
                {
                    case ChatType::LoginFailReason::AccountNotExist:
                    {
                        fail_reason = QStringLiteral("账号不存在");
                        break;
                    }
                case ChatType::LoginFailReason::PasswordError:
                    {
                        fail_reason = QStringLiteral("用户名或密码错误");
                        break;
                    }
                    default:    break;
                }
                emit signal_loginFailed(fail_reason);
                break;
            }
            case ChatType::ModifyUserInfoSuccess:       // ========== 修改用户消息成功 ==========
            {
                qDebug() << "ChatType::ModifyUserInfoSuccess";
                sttClientInfo client_info;
                buffer >> client_info;
                emit signal_modifyUserInfoSuccess(client_info);
                break;
            }
            case ChatType::ModifyUserInfoFailed:        // ========== 修改用户消息失败 ==========
            {
                qDebug() << "ChatType::ModifyUserInfoFailed";
                emit signal_modifyUserInfoFailed();
                break;
            }
            case ChatType::AddGroupSuccess:             // ========== 添加分组成功 ==========
            {
                qDebug() << "ChatType::AddGroupSuccess";
                quint32 new_group_id;
                buffer >> new_group_id;
                QByteArray group_name_bytes;
                buffer >> group_name_bytes;
                QString group_name = QString::fromUtf8(group_name_bytes);
                emit signal_addGroupSuccess(new_group_id, group_name);
                break;
            }
            case ChatType::AddGroupFailed:              // ========== 添加分组失败 ==========
            {
                qDebug() << "ChatType::AddGroupFailed";
                emit signal_addGroupFailed();
                break;
            }
            case ChatType::ReturnOnline:                // ========== 查询到用户在线 ==========
            {
                qDebug() << "ChatType::ReturnOnline";
                quint32 user_id;
                buffer >> user_id;
                emit signal_userOnline(user_id);
                break;
            }
            case ChatType::ReturnOffline:               // ========== 查询到用户离线 ==========
            {
                qDebug() << "ChatType::ReturnOffline";
                quint32 user_id;
                buffer >> user_id;
                emit signal_userOffline(user_id);
                break;
            }
            case ChatType::ReceiveChatMsg:              // ========== 收到聊天消息 ==========
            {
                qDebug() << "ChatType::ReceiveChatMsg";
                quint32 send_id;
                quint32 rcv_id;
                buffer >> send_id >> rcv_id;
                QByteArray msg_bytes;
                buffer >> msg_bytes;
                QString msg = QString::fromUtf8(msg_bytes);
                emit signal_receiveChatMsg(send_id, rcv_id, msg);
                break;
            }
            case ChatType::SearchUserSuccess:           // ========== 搜索用户结果 ==========
            {
                qDebug() << "ChatType::SearchUserSuccess";
                QVector<sttFriendInfo> rcv_search_records;
                QByteArray search_text_bytes;
                buffer >> search_text_bytes;
                QString search_text = QString::fromUtf8(search_text_bytes);
                quint8 record_num;
                buffer >> record_num;
                rcv_search_records.resize(record_num);
                for(int i=0; i<record_num; i++)
                {
                    sttFriendInfo cur_friend_info;
                    buffer >> cur_friend_info;
                    rcv_search_records[i] = cur_friend_info;
                }
                emit signal_receiveSearchUserRecords(search_text, rcv_search_records);
                break;
            }
            case ChatType::ReceiveAddFriendRequest:     // ========== 收到添加好友请求 ==========
            {
                qDebug() << "ChatType::ReceiveAddFriendRequest";
                quint32 rcv_id;
                sttClientInfo send_client_info;
                buffer >> rcv_id >> send_client_info;
                QByteArray verify_msg_bytes;
                buffer >> verify_msg_bytes;
                QString verify_msg = QString::fromUtf8(verify_msg_bytes);
                quint32 send_select_id;
                buffer >> send_select_id;
                emit signal_receiveAddFriendRequest(rcv_id, send_client_info, verify_msg, send_select_id);
                break;
            }
            case ChatType::RejectAddFriendRequest:      // ========== 收到拒绝添加好友请求 ==========
            {
                qDebug() << "ChatType::RejectAddFriendRequest";
                quint32 _reply_to_who;
                quint32 _who_reply;
                quint32 _group_of_reply_to_who;
                buffer >> _reply_to_who >> _who_reply >> _group_of_reply_to_who;
                emit signal_receiveRejectAddFriendRequest(_reply_to_who, _who_reply, _group_of_reply_to_who);
                break;
            }
            case ChatType::AgreeAddFriendRequest:       // ========== 收到同意添加好友请求 ==========
            {
                qDebug() << "ChatType::AgreeAddFriendRequest";
                quint32 rcv_id;
                quint32 rcv_select_group_id;
                sttFriendInfo new_friend_info;
                buffer >> rcv_id >> rcv_select_group_id >> new_friend_info;
                emit signal_receiveAgreeAddFriendRequest(rcv_id, rcv_select_group_id, new_friend_info);
                break;
            }
            case ChatType::UpdateFriendInfo:            // ========== 收到更新好友的用户信息 ==========
            {
                qDebug() << "ChatType::UpdateFriendInfo";
                quint32 friend_id;
                sttFriendInfo friend_update_info;
                buffer >> friend_id >> friend_update_info;
                emit signal_receiveUpdateFriendInfo(friend_id, friend_update_info);
                break;
            }
            case ChatType::ReceiveUserHeadPic:          // ========== 收到用户的头像 ==========
            {
                qDebug() << "ChatType::ReceiveUserHeadPic";
                quint32 user_id;
                buffer >> user_id;
                QByteArray name_bytes;
                buffer >> name_bytes;
                QString name = QString::fromUtf8(name_bytes);
                QString pic_path = generateRandomFilePath(Config::getInstance()->m_getLocalTmpPath(), name);
                qint64 pic_size;
                buffer >> pic_size;
                if(pic_size > ChatType::PicMaxSize)
                    break;
                m_receiveFile(pic_size, pic_path, buffer);
                emit signal_receiveUserHeadPic(user_id, pic_path);
                break;
            }
            case ChatType::ReceiveChatPic:
            {
                qDebug() << "ChatType::ReceiveChatPic";
                quint32 send_id;
                quint32 rcv_id;
                buffer >> send_id >> rcv_id;
                QByteArray name_bytes;
                buffer >> name_bytes;
                QString name = QString::fromUtf8(name_bytes);
                QString pic_path = generateRandomFilePath(Config::getInstance()->m_getLocalTmpPath(), name);
                qint64 pic_size;
                buffer >> pic_size;
                if(pic_size > ChatType::PicMaxSize)
                    break;
                m_receiveFile(pic_size, pic_path, buffer);
                emit signal_receiveChatPic(send_id, rcv_id, pic_path);
                break;
            }
            default: break;
        }
        // 更新缓冲区
        m_messageBuffer = m_messageBuffer.right(total_buffer_size - total_bytes);
        total_buffer_size = m_messageBuffer.size();
    }
}

void TcpSocketManager::slot_socketWrite(const QByteArray message)
{
    qint64 send_bytes = m_tcpSocket->write(message);
    qDebug() << "ready send message size:" << message.size() << ", send bytes:" << send_bytes;
}

