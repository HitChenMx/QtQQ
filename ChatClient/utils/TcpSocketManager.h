#ifndef TCPSOCKETMANAGER_H
#define TCPSOCKETMANAGER_H

#include <QObject>
#include <QTcpSocket>
#include <QHostAddress>
#include <QTimer>
#include <QThread>
#include <QDataStream>
#include <QTextCodec>
#include <QMap>
#include <QVector>
#include <QFile>
#include "global.h"
#include "Config.h"
#include "AssembleBytes.h"
#include "Helper.h"

class TcpSocketManager : public QObject
{
    Q_OBJECT
public:
    explicit TcpSocketManager(QHostAddress host_address, quint16 host_port, float max_connect_time, QObject *parent = nullptr);
    ~TcpSocketManager();

private:
    QTcpSocket* m_tcpSocket;        // 与服务端之间收发消息的套接字
    QHostAddress m_hostAddress;     // 服务端的IP地址
    quint16 m_hostPort;             // 服务端的端口号
    float m_maxConnectTime;         // 连接服务端的最大等待时间
    QTimer* m_connectTimer;         // 连接服务端的定时器
    QByteArray m_messageBuffer;     // 接收消息缓冲区

    void m_receiveFile(const qint64& file_size, const QString& file_save_path, QDataStream& buffer);      // 从数据流中接收文件

signals:
    void signal_socketConnected();          // 信号：连接成功
    void signal_socketDisconnected();       // 信号：连接断开
    void signal_socketConnectFailed();      // 信号：连接失败
    void signal_socketReadFinished(const QByteArray message);
    void signal_registerSuccess();                              // 信号：注册成功
    void signal_registerFailed(const QString reason);           // 信号：注册失败
    void signal_loginSuccess(const sttClientInfo client_info, const QMap<quint32, sttGroupInfo> all_group_info);  // 信号：登录成功
    void signal_loginFailed(const QString reason);              // 信号：登录失败
    void signal_modifyUserInfoSuccess(const sttClientInfo client_info);                        // 信号：修改用户消息成功
    void signal_modifyUserInfoFailed();                         // 信号：修改用户消息失败
    void signal_addGroupSuccess(const quint32 new_group_id, const QString group_name);      // 信号：添加分组成功
    void signal_addGroupFailed();                               // 信号：添加分组失败
    void signal_userOnline(const quint32 user_id);              // 信号：用户在线
    void signal_userOffline(const quint32 user_id);             // 信号：用户离线
    void signal_receiveChatMsg(const quint32 send_id, const quint32 rcv_id, const QString chat_msg);    // 信号：收到聊天消息
    void signal_receiveSearchUserRecords(const QString search_text, const QVector<sttFriendInfo> search_user_records);        // 信号：收到搜索用户的结果
    void signal_receiveAddFriendRequest(const quint32 rcv_id, const sttClientInfo send_user_info,
                                        const QString verify_msg, const quint32 group_id);              // 信号：收到添加好友请求
    void signal_receiveRejectAddFriendRequest(const quint32 rcv_id, const quint32 send_id, const quint32 rcv_group_id);     // 信号：收到拒绝添加好友请求
    void signal_receiveAgreeAddFriendRequest(const quint32 rcv_id, const quint32 rcv_select_group_id,
                                             const sttFriendInfo new_friend_info);                                          // 信号：收到同意添加好友请求
    void signal_receiveUpdateFriendInfo(const quint32 friend_id, const sttFriendInfo friend_update_info);           // 信号：收到更新好友的用户信息
    void signal_receiveUserHeadPic(const quint32 user_id, const QString pic_path);                                  // 信号：收到用户的头像
    void signal_receiveChatPic(const quint32 send_id, const quint32 rcv_id, const QString chat_pic_path);           // 信号：收到聊天图片

public slots:
    void slot_init();
    void slot_closeSocket();                // 关闭socket，退出自身所在的线程
    void slot_socketWrite(const QByteArray message);    // socket发送消息

private slots:
    void slot_socketReadyRead();
};


#endif // TCPSOCKETMANAGER_H
