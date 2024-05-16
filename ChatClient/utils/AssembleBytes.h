#ifndef PARSEBYTES_H
#define PARSEBYTES_H

#include <QObject>
#include <QDataStream>
#include <QMap>
#include <QThread>
#include <QTextCodec>
#include <QDebug>
#include <QFile>
#include <QFileInfo>
#include "global.h"

// 设置读写字节流的规则
extern QDataStream::Version _My_VERSION;
extern QDataStream::ByteOrder _My_ORDER;
extern QDataStream::FloatingPointPrecision _My_PRECISION;


// --- 组数据包：单例模式，子线程运行 ---
class AssembleBytes : public QObject
{
    Q_OBJECT
public:
    static AssembleBytes* getInstance();        // 获取单例对象
    static void deleteInstance();

private:
    explicit AssembleBytes(QObject *parent = nullptr);
    ~AssembleBytes();
    AssembleBytes(const AssembleBytes& other);
    const AssembleBytes& operator=(const AssembleBytes& other);

    void m_sendFileToServer(QFile& file_to_send);     // 向服务器发送文件，不含包头

    static AssembleBytes* m_instance;   // 唯一单例对象智能指针
    static QMutex m_mutex;

signals:
    void signal_assembleBytesDone(const QByteArray bytes);      // 信号：组数据包完成

public slots:
    void slot_asmModifyUserInfo(const quint32 user_id, const QMap<QString, QVariant> user_info);        // 请求修改用户信息
    void slot_asmSendChatMsg(const quint32 send_id, const quint32 rcv_id, const QString chat_msg);      // 发送聊天消息
    void slot_asmAddGroup(const quint32 user_id, const QString group_name);                             // 请求添加分组
    void slot_asmRenameGroup(const quint32 user_id, const quint32 group_id, const QString new_name);    // 重命名分组
    void slot_asmQueryOnlineState(const quint32 user_id);                                               // 查询在线状态
    void slot_asmSearchUser(const quint32 send_id, const QString search_text);                          // 搜索用户
    void slot_asmAddFriend(const quint32 send_id, const sttClientInfo rcv_info,
                           const QString verify_msg, const quint32 which_group_id);                     // 添加好友
    void slot_asmReplyAddFriend(const quint32 who_reply, const quint32 reply_to_who,
                                const bool reply_agree,
                                const quint32 group_of_who_reply, const quint32 group_of_reply_to_who); // 回复添加好友请求
    void slot_asmRequestUserHeadPic(const quint32 user_id);                                               // 查询用户的头像
    void slot_asmModifyUserHead(const quint32 user_id, const QString head_path);                          // 修改用户的头像
    void slot_asmSendChatPic(const quint32 send_id, const quint32 rcv_id, const QString chat_pic_path);   // 发送聊天图片
    void slot_asmMoveFriendToGroup(const quint32 user_id, const quint32 friend_id, const quint32 group_id);     // 移动好友至指定分组
};



#endif // PARSEBYTES_H
