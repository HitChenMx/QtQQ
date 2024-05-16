#include "AssembleBytes.h"

QDataStream::Version _My_VERSION = QDataStream::Qt_5_9;
QDataStream::ByteOrder _My_ORDER = QDataStream::LittleEndian;
QDataStream::FloatingPointPrecision _My_PRECISION = QDataStream::SinglePrecision;

AssembleBytes* AssembleBytes::m_instance = nullptr;
QMutex AssembleBytes::m_mutex;

// ============================================ AssembleBytes ============================================

AssembleBytes::AssembleBytes(QObject *parent):
    QObject(parent)
{

}

AssembleBytes* AssembleBytes::getInstance()
{
    // 双检锁
    if(m_instance == nullptr)
    {
        QMutexLocker locker(&m_mutex);
        if(m_instance == nullptr)
        {
            // qDebug() << "AssembleBytes create...";
            AssembleBytes* tmp = new AssembleBytes;
            m_instance = tmp;
            QThread* new_thread = new QThread;          // 新开一个子线程来组数据包
            m_instance->moveToThread(new_thread);
            new_thread->start();
        }
    }
    return m_instance;
}

void AssembleBytes::deleteInstance()
{
    QMutexLocker locker(&m_mutex);
    if(m_instance)
    {
        m_instance->thread()->quit();
        m_instance->deleteLater();
        m_instance = nullptr;
    }
}

AssembleBytes::~AssembleBytes()
{

}

void AssembleBytes::m_sendFileToServer(QFile &file_to_send)
{
    quint64 bytes_to_write = file_to_send.size();
    quint64 load_size = 50 * 1024;                   // 每次发送50KB
    if(file_to_send.open(QIODevice::ReadOnly))
    {
        while(!file_to_send.atEnd())
        {
            qint64 read_size = qMin(bytes_to_write, load_size);
            QByteArray cur_bytes = file_to_send.read(read_size);
            emit signal_assembleBytesDone(cur_bytes);
            bytes_to_write -= read_size;
        }
        file_to_send.close();
    }
}

void AssembleBytes::slot_asmModifyUserInfo(const quint32 user_id, const QMap<QString, QVariant> user_info)
{
    qDebug() << QThread::currentThread() << " ========================================================== " << "AssembleBytes::slot_asmModifyUserInfo";
    quint8 modify_num = user_info.size();
    // 构建发送字节流
    QByteArray send_bytes;
    QDataStream opt_buffer(&send_bytes, QIODevice::WriteOnly);
    opt_buffer.setVersion(_My_VERSION);
    opt_buffer.setByteOrder(_My_ORDER);
    opt_buffer.setFloatingPointPrecision(_My_PRECISION);
    quint16 cmd_type = ChatType::ModifyUserInfoRequest;
    quint64 total_bytes_place = ChatType::MessageMinSize;        // 占位
    opt_buffer<<total_bytes_place;
    opt_buffer<<cmd_type;
    opt_buffer<<user_id;
    opt_buffer<<modify_num;
    for(QMap<QString, QVariant>::const_iterator ite=user_info.begin(); ite!=user_info.end(); ++ite)
    {
        opt_buffer << ite.key().toUtf8();
        opt_buffer << ite.value().toString().toUtf8();
    }
    quint64 total_bytes = send_bytes.size();
    opt_buffer.device()->seek(0);
    opt_buffer<<total_bytes;

    emit signal_assembleBytesDone(send_bytes);
}

void AssembleBytes::slot_asmSendChatMsg(const quint32 send_id, const quint32 rcv_id, const QString chat_msg)
{
    qDebug() << QThread::currentThread() << " ========================================================== " << "AssembleBytes::slot_asmSendChatMsg";
    // 构建发送字节流
    QByteArray send_bytes;
    QDataStream opt_buffer(&send_bytes, QIODevice::WriteOnly);
    opt_buffer.setVersion(_My_VERSION);
    opt_buffer.setByteOrder(_My_ORDER);
    opt_buffer.setFloatingPointPrecision(_My_PRECISION);
    quint16 cmd_type = ChatType::SendChatMsgRequest;
    quint64 total_bytes_place = ChatType::MessageMinSize;        // 占位
    opt_buffer<<total_bytes_place;
    opt_buffer<<cmd_type;
    opt_buffer<<send_id<<rcv_id;
    opt_buffer<<chat_msg.toUtf8();
    quint64 total_bytes = send_bytes.size();
    opt_buffer.device()->seek(0);
    opt_buffer<<total_bytes;

    emit signal_assembleBytesDone(send_bytes);
}

void AssembleBytes::slot_asmAddGroup(const quint32 user_id, const QString group_name)
{
    qDebug() << QThread::currentThread() << " ========================================================== " << "AssembleBytes::slot_asmAddGroup";
    // 构建发送字节流
    QByteArray send_bytes;
    QDataStream opt_buffer(&send_bytes, QIODevice::WriteOnly);
    opt_buffer.setVersion(_My_VERSION);
    opt_buffer.setByteOrder(_My_ORDER);
    opt_buffer.setFloatingPointPrecision(_My_PRECISION);
    quint16 cmd_type = ChatType::AddGroupRequest;
    quint64 total_bytes_place = ChatType::MessageMinSize;        // 占位
    opt_buffer<<total_bytes_place;
    opt_buffer<<cmd_type;
    opt_buffer<<user_id;
    opt_buffer<<group_name.toUtf8();
    quint64 total_bytes = send_bytes.size();
    opt_buffer.device()->seek(0);
    opt_buffer<<total_bytes;

    emit signal_assembleBytesDone(send_bytes);
}

void AssembleBytes::slot_asmRenameGroup(const quint32 user_id, const quint32 group_id, const QString new_name)
{
    qDebug() << QThread::currentThread() << " ========================================================== " << "AssembleBytes::slot_asmRenameGroup";
    // 构建发送字节流
    QByteArray send_bytes;
    QDataStream opt_buffer(&send_bytes, QIODevice::WriteOnly);
    opt_buffer.setVersion(_My_VERSION);
    opt_buffer.setByteOrder(_My_ORDER);
    opt_buffer.setFloatingPointPrecision(_My_PRECISION);
    quint16 cmd_type = ChatType::RenameGroupRequest;
    quint64 total_bytes_place = ChatType::MessageMinSize;        // 占位
    opt_buffer<<total_bytes_place;
    opt_buffer<<cmd_type;
    opt_buffer<<user_id;
    opt_buffer<<group_id;
    opt_buffer<<new_name.toUtf8();
    quint64 total_bytes = send_bytes.size();
    opt_buffer.device()->seek(0);
    opt_buffer<<total_bytes;

    emit signal_assembleBytesDone(send_bytes);
}

void AssembleBytes::slot_asmQueryOnlineState(const quint32 user_id)
{
    qDebug() << QThread::currentThread() << " ========================================================== " << "AssembleBytes::slot_asmQueryOnlineState";
    // 构建发送字节流
    QByteArray send_bytes;
    QDataStream opt_buffer(&send_bytes, QIODevice::WriteOnly);
    opt_buffer.setVersion(_My_VERSION);
    opt_buffer.setByteOrder(_My_ORDER);
    opt_buffer.setFloatingPointPrecision(_My_PRECISION);
    quint16 cmd_type = ChatType::QueryOnlineState;
    quint64 total_bytes_place = ChatType::MessageMinSize;        // 占位
    opt_buffer<<total_bytes_place;
    opt_buffer<<cmd_type;
    opt_buffer<<user_id;
    quint64 total_bytes = send_bytes.size();
    opt_buffer.device()->seek(0);
    opt_buffer<<total_bytes;

    emit signal_assembleBytesDone(send_bytes);
}

void AssembleBytes::slot_asmSearchUser(const quint32 send_id, const QString search_text)
{
    qDebug() << QThread::currentThread() << " ========================================================== " << "AssembleBytes::slot_asmSearchUser";
    // 构建发送字节流
    QByteArray send_bytes;
    QDataStream opt_buffer(&send_bytes, QIODevice::WriteOnly);
    opt_buffer.setVersion(_My_VERSION);
    opt_buffer.setByteOrder(_My_ORDER);
    opt_buffer.setFloatingPointPrecision(_My_PRECISION);
    quint16 cmd_type = ChatType::SearchUserRequest;
    quint64 total_bytes_place = ChatType::MessageMinSize;        // 占位
    opt_buffer<<total_bytes_place;
    opt_buffer<<cmd_type;
    opt_buffer<<send_id;
    opt_buffer << search_text.toUtf8();
    quint64 total_bytes = send_bytes.size();
    opt_buffer.device()->seek(0);
    opt_buffer<<total_bytes;

    emit signal_assembleBytesDone(send_bytes);
}

void AssembleBytes::slot_asmAddFriend(const quint32 send_id, const sttClientInfo rcv_info, const QString verify_msg, const quint32 which_group_id)
{
    qDebug() << QThread::currentThread() << " ========================================================== " << "AssembleBytes::slot_asmAddFriend";
    // 构建发送字节流
    QByteArray send_bytes;
    QDataStream opt_buffer(&send_bytes, QIODevice::WriteOnly);
    opt_buffer.setVersion(_My_VERSION);
    opt_buffer.setByteOrder(_My_ORDER);
    opt_buffer.setFloatingPointPrecision(_My_PRECISION);
    quint16 cmd_type = ChatType::AddFriendRequest;
    quint64 total_bytes_place = ChatType::MessageMinSize;        // 占位
    opt_buffer<<total_bytes_place;
    opt_buffer<<cmd_type;
    opt_buffer<<send_id;
    opt_buffer<<rcv_info.id;
    opt_buffer<<verify_msg.toUtf8();
    opt_buffer<<which_group_id;
    quint64 total_bytes = send_bytes.size();
    opt_buffer.device()->seek(0);
    opt_buffer<<total_bytes;

    emit signal_assembleBytesDone(send_bytes);
}

void AssembleBytes::slot_asmReplyAddFriend(const quint32 who_reply, const quint32 reply_to_who,
                                           const bool reply_agree,
                                           const quint32 group_of_who_reply, const quint32 group_of_reply_to_who)
{
    qDebug() << QThread::currentThread() << " ========================================================== " << "AssembleBytes::slot_asmReplyAddFriend";
    // 构建发送字节流
    QByteArray send_bytes;
    QDataStream opt_buffer(&send_bytes, QIODevice::WriteOnly);
    opt_buffer.setVersion(_My_VERSION);
    opt_buffer.setByteOrder(_My_ORDER);
    opt_buffer.setFloatingPointPrecision(_My_PRECISION);
    quint16 cmd_type = ChatType::ReplyAddFriendRequest;
    quint64 total_bytes_place = ChatType::MessageMinSize;        // 占位
    opt_buffer<<total_bytes_place;
    opt_buffer<<cmd_type;
    opt_buffer<<who_reply;
    opt_buffer<<reply_to_who;
    quint8 comment_bytes = reply_agree? 0x00 : 0xFF;
    opt_buffer<<comment_bytes;
    opt_buffer<<group_of_who_reply;
    opt_buffer<<group_of_reply_to_who;
    quint64 total_bytes = send_bytes.size();
    opt_buffer.device()->seek(0);
    opt_buffer<<total_bytes;

    emit signal_assembleBytesDone(send_bytes);
}

void AssembleBytes::slot_asmRequestUserHeadPic(const quint32 user_id)
{
    qDebug() << QThread::currentThread() << " ========================================================== " << "AssembleBytes::slot_asmRequestUserHeadPic";
    // 构建发送字节流
    QByteArray send_bytes;
    QDataStream opt_buffer(&send_bytes, QIODevice::WriteOnly);
    opt_buffer.setVersion(_My_VERSION);
    opt_buffer.setByteOrder(_My_ORDER);
    opt_buffer.setFloatingPointPrecision(_My_PRECISION);
    quint16 cmd_type = ChatType::RequestUserHeadPic;
    quint64 total_bytes_place = ChatType::MessageMinSize;        // 占位
    opt_buffer<<total_bytes_place;
    opt_buffer<<cmd_type;
    opt_buffer<<user_id;
    quint64 total_bytes = send_bytes.size();
    opt_buffer.device()->seek(0);
    opt_buffer<<total_bytes;

    emit signal_assembleBytesDone(send_bytes);
}

void AssembleBytes::slot_asmModifyUserHead(const quint32 user_id, const QString head_path)
{
    qDebug() << QThread::currentThread() << " ========================================================== " << "AssembleBytes::slot_asmModifyUserHead";
    QFile file_to_send(head_path);
    if(!file_to_send.exists())
    {
        return;
    }
    quint64 pic_size = file_to_send.size();
    if(pic_size > ChatType::PicMaxSize)
        return;

    // 先发送包头
    QByteArray send_bytes;
    QDataStream opt_buffer(&send_bytes, QIODevice::WriteOnly);
    opt_buffer.setVersion(_My_VERSION);
    opt_buffer.setByteOrder(_My_ORDER);
    opt_buffer.setFloatingPointPrecision(_My_PRECISION);
    quint16 cmd_type = ChatType::ModifyUserHeadRequest;
    quint64 total_bytes_place = ChatType::MessageMinSize;        // 占位
    opt_buffer<<total_bytes_place;
    opt_buffer<<cmd_type;
    opt_buffer<<user_id;
    QString pic_name = QFileInfo(head_path).fileName();
    opt_buffer<<pic_name.toUtf8();
    opt_buffer<<quint64(pic_size);
    quint64 total_bytes = send_bytes.size() + pic_size;
    opt_buffer.device()->seek(0);
    opt_buffer<<total_bytes;
    emit signal_assembleBytesDone(send_bytes);

    // 再发送头像
    m_sendFileToServer(file_to_send);
}

void AssembleBytes::slot_asmSendChatPic(const quint32 send_id, const quint32 rcv_id, const QString chat_pic_path)
{
    qDebug() << QThread::currentThread() << " ========================================================== " << "AssembleBytes::slot_asmSendChatPic";
    QFile file_to_send(chat_pic_path);
    if(!file_to_send.exists())
    {
        return;
    }
    quint64 pic_size = file_to_send.size();
    if(pic_size > ChatType::PicMaxSize)
        return;

    // 先发送包头
    QByteArray send_bytes;
    QDataStream opt_buffer(&send_bytes, QIODevice::WriteOnly);
    opt_buffer.setVersion(_My_VERSION);
    opt_buffer.setByteOrder(_My_ORDER);
    opt_buffer.setFloatingPointPrecision(_My_PRECISION);
    quint16 cmd_type = ChatType::SendChatPicRequest;
    quint64 total_bytes_place = ChatType::MessageMinSize;        // 占位
    opt_buffer<<total_bytes_place;
    opt_buffer<<cmd_type;
    opt_buffer<<send_id;
    opt_buffer<<rcv_id;
    QString pic_name = QFileInfo(chat_pic_path).fileName();
    opt_buffer<<pic_name.toUtf8();
    opt_buffer<<quint64(pic_size);
    quint64 total_bytes = send_bytes.size() + pic_size;
    opt_buffer.device()->seek(0);
    opt_buffer<<total_bytes;
    emit signal_assembleBytesDone(send_bytes);

    // 再发送头像
    m_sendFileToServer(file_to_send);
}

void AssembleBytes::slot_asmMoveFriendToGroup(const quint32 user_id, const quint32 friend_id, const quint32 group_id)
{
    qDebug() << QThread::currentThread() << " ========================================================== " << "AssembleBytes::slot_asmMoveFriendToGroup";
    // 构建发送字节流
    QByteArray send_bytes;
    QDataStream opt_buffer(&send_bytes, QIODevice::WriteOnly);
    opt_buffer.setVersion(_My_VERSION);
    opt_buffer.setByteOrder(_My_ORDER);
    opt_buffer.setFloatingPointPrecision(_My_PRECISION);
    quint16 cmd_type = ChatType::MoveFriendToGroup;
    quint64 total_bytes_place = ChatType::MessageMinSize;        // 占位
    opt_buffer<<total_bytes_place;
    opt_buffer<<cmd_type;
    opt_buffer<<user_id;
    opt_buffer<<friend_id;
    opt_buffer<<group_id;
    quint64 total_bytes = send_bytes.size();
    opt_buffer.device()->seek(0);
    opt_buffer<<total_bytes;

    emit signal_assembleBytesDone(send_bytes);
}
