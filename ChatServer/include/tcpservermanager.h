#ifndef TCPSERVERMANAGER_H
#define TCPSERVERMANAGER_H

#include <QHash>
#include <QTcpServer>
#include <QThread>
#include <QList>
#include <QVector>
#include "global.h"
#include "tcpsocketmanager.h"


class TcpServerManager : public QTcpServer
{
    Q_OBJECT
public:
    explicit TcpServerManager(QObject *parent = nullptr, QSharedPointer<sttDatabaseInfo> db_info = QSharedPointer<sttDatabaseInfo>::create());
    ~TcpServerManager();

    void m_sendClientMessage(const QHostAddress address, const quint16 port, const QByteArray message);      // 向用户发送消息，返回成功发送的字节数
    void m_sendClientMessage(const QString client_IP_port, const QByteArray message);                           // 支持QString("IP:port")来发送消息
    QAbstractSocket::SocketState m_getClientState(const QHostAddress address, const quint16 port) const;     // 获取用户的socket state
    QAbstractSocket::SocketState m_getClientState(const QString client_IP_port) const;                          // 支持QString("IP:port")来查询

private:
    QHash<QString, TcpSocketManager*> m_sockets;        // "IP:端口号" 对应的 socket管理对象
    QList<QThread*> m_threads;                          // 保存开了哪些线程
    QSharedPointer<sttDatabaseInfo> m_dbInfo;
    QHash<quint32, QString> m_userID2IP;                // 用户登录成功后，记录用户ID和IP:端口号的对应关系

    void incomingConnection(qintptr socketDescriptor) override;
    void m_replyUserOnlineState(const quint32 query_id,
                                const QHostAddress reply_address, const quint16 reply_port);        // 查询query_id的在线状态，回复给reply_address:reply_port

signals:
    void signal_databaseConnectFailed(qintptr socketDescriptor);
    void signal_clientConnected(const QHostAddress address, const quint16 port);         // 信号：用户成功连接
    void signal_clientDisconnected(const QHostAddress address, const quint16 port);      // 信号：用户连接断开
    void signal_receiveClientMessage(const QHostAddress address, const quint16 port, const QByteArray message);    // 信号：接收到用户消息
    void signal_sendClientMessage(const QHostAddress address, const quint16 port, const QByteArray message);       // 信号：向用户发送消息
    void signal_sendClientMessageFinished(const QHostAddress address, const quint16 port, const quint64 send_bytes);       // 信号：向用户发送消息完毕
    void signal_clientSocketError(const QAbstractSocket::SocketError socket_error);    // 信号：用户socket error
    void signal_replyQueryOnlineState(const QHostAddress client_self_address, const quint16 client_self_port,       // 信号：向用户回复是否在线
                                      const quint32 query_user_id, const ChatType::ChatCMD cmd_type);

private slots:
    void slot_clientConnected(const QHostAddress address, const quint16 port);
    void slot_clientDisconnected(const quint32 user_id, const QHostAddress address, const quint16 port,
                                 const QVector<quint32> user_friend_list);
    void slot_receiveClientMessage(const QHostAddress address, const quint16 port, const QByteArray message);
    void slot_clientLoginSuccess(const quint32 user_id, const QHostAddress address, const quint16 port,
                                 const QVector<quint32> user_friend_list);                  // 用户登录成功
    void slot_clientQueryOnlineState(const quint32 user_id);        // 处理用户的请求：查询用户在线状态
    void slot_relayBytesToClients(const QVector<quint32> relay_to_these, const QByteArray bytes);       // 向用户转发字节流

    void slot_threadFinished();         // 线程结束，释放线程
};



#endif // TCPSERVERMANAGER_H
