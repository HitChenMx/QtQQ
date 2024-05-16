#ifndef TCPSOCKETMANAGER_H
#define TCPSOCKETMANAGER_H

#include <QThread>
#include <QMutex>
#include <QMutexLocker>
#include <QTcpSocket>
#include <QHostAddress>
#include <QByteArray>
#include <QString>
#include <QDebug>
#include <QDateTime>
#include <QVector>
#include <QFile>
#include "global.h"
#include "databasemanager.h"

class TcpSocketManager : public QObject
{
    Q_OBJECT
public:
    explicit TcpSocketManager(qintptr socketDescriptor, QSharedPointer<sttDatabaseInfo> db_info, QObject *parent = nullptr);
    ~TcpSocketManager();

    QHostAddress m_getPeerAddress();        // 获取peer的IP地址
    quint16 m_getPeerPort();                // 获取peer的端口号
    QAbstractSocket::SocketState m_getSocketState();        // 获取socket的状态

private:
    QTcpSocket* m_socket;
    QAbstractSocket::SocketState m_socketState;
    qintptr m_socketDescriptor;
    QHostAddress m_peerAddress;
    quint16 m_peerPort;
    QSharedPointer<sttDatabaseInfo> m_dbInfo;           // 数据库信息
    DatabaseManager* m_dbManager;                       // 数据库管理对象
    QByteArray m_messageBuffer;                         // 接收到的消息缓冲
    quint32 m_loginUserID;                              // 登录成功的用户ID

    QMutex m_mutex;

    void m_analyseMessage(const QByteArray message);            // 解析字节流
    void m_analyseMessage_register(QDataStream& buffer);
    void m_analyseMessage_login(QDataStream& buffer);
    void m_analyseMessage_modifyUserInfo(QDataStream& buffer);
    void m_analyseMessage_addGroup(QDataStream& buffer);
    void m_analyseMessage_renameGroup(QDataStream& buffer);
    void m_analyseMessage_queryOnlineState(QDataStream& buffer);
    void m_analyseMessage_sendChatMsg(QDataStream& buffer);
    void m_analyseMessage_searchUserRequest(QDataStream& buffer);
    void m_analyseMessage_addFriendRequest(QDataStream& buffer);
    void m_analyseMessage_replyAddFriendRequest(QDataStream& buffer);
    void m_analyseMessage_requestUserHeadPic(QDataStream& buffer);
    void m_analyseMessage_modifyUserHead(QDataStream& buffer);
    void m_analyseMessage_sendChatPic(QDataStream& buffer);
    void m_analyseMessage_moveFriendToGroup(QDataStream& buffer);

    void m_sendFileToClient(const QVector<quint32>& rcv_ids, QFile& file_to_send);                                 // 单纯地发送文件
    void m_receiveAndSaveFile(const qint64& file_size, const QString& file_save_path, QDataStream& buffer);         // 接收并保存文件
    void m_sendHeadPictoClient(const QVector<quint32>& rcv_ids, const quint32& query_id, const QString& pic_path);        // 向用户发送某一个用户的头像，包括包头和图片数据


signals:
    void signal_databaseConnectFailed();
    void signal_socketConnected(const QHostAddress address, const quint16 port);          // 信号：连接成功
    void signal_socketDisconnected(const quint32 user_id, const QHostAddress address, const quint16 port,
                                   const QVector<quint32> user_friend_list);                // 信号：连接断开，用户下线
    void signal_readFinished(const QHostAddress address, const quint16 port, const QByteArray message);               // 信号：读取消息完成
    void signal_sendFinished(const QHostAddress address, const quint16 port, const quint64 send_bytes);                // 信号：发送消息完成
    void signal_socketError(const QAbstractSocket::SocketError socket_error);      // 信号：socket error
    void signal_loginSuccess(const quint32 user_id, const QHostAddress address, const quint16 port,
                             const QVector<quint32> user_friend_list);                                      // 信号：登录成功
    void signal_queryOnlineState(const quint32 user_id);                                                    // 信号：请求查询用户的在线状态
    void signal_requestRelayBytes(const QVector<quint32> relay_to_these, const QByteArray bytes);           // 信号：请求向一些用户转发字节流

private slots:
    void slot_socketConnected();
    void slot_socketDisconnected();
    void slot_socketStateChanged(const QAbstractSocket::SocketState socket_state);
    void slot_socketReadyRead();

public slots:
    void m_init();                      // 初始化
    quint64 slot_socketSendMessage(const QHostAddress address, const quint16 port, const QByteArray message);                 // 发送消息
    void slot_receiveReplyOnlineState(const QHostAddress client_self_address, const quint16 client_self_port,
                                      const quint32 query_user_id, const ChatType::ChatCMD cmd_type);      // 收到回复：用户的在线状态

};

#endif // TCPSOCKETMANAGER_H
