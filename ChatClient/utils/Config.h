#ifndef CONFIG_H
#define CONFIG_H

#include <QObject>
#include <QMutex>
#include <QMutexLocker>
#include <QString>
#include <QSettings>
#include <QDir>
#include <QFileInfo>
#include <QHostAddress>
#include <QDebug>
#include "global.h"

class Config : public QObject
{
    Q_OBJECT
public:
    static Config* getInstance();    // 获取单例对象
    static void deleteInstance();
    void m_readIni(const QString& ini_path);        // 读取配置文件
    QHostAddress m_getServerAddress() const;        // 获取服务端IP地址
    quint16 m_getServerMsgPort() const;             // 获取服务端消息监听端口
    float m_getServerMaxConnectTime() const;        // 获取断线重连的最大时间

    QString m_getLocalDataPath() const;             // 获取本地文件的存放文件夹的路径
    QString m_getLocalTmpPath() const;              // 获取本地临时文件的存放文件夹的路径
    QString m_getLocalChatPicsPath() const;        // 获取本地存放聊天图片的文件夹路径
    void m_setLocalDbPath(const QString& db_name);         // 设置本地数据库的路径
    QString m_getLocalDbPath() const;               // 获取本地数据库的路径
    void m_setLocalAccountPath(const QString& account);                   // 设置本地当前账户的路径
    QString m_getLocalAccountPath() const;          // 获取本地当前账户的路径

    void m_setLoginClientInfo(const sttClientInfo& client_info);                    // 设置登录成功的用户信息
    sttClientInfo m_getLoginClientInfo() const;     // 获取登录成功的用户信息
    quint32 m_getLoginClientId() const;             // 获取登录成功的用户id
    void m_setLoginClientHead(const QString& head_path);            // 设置登录成功的用户的头像路径
    QString m_getLoginClientHead() const;                           // 获取登录成功的用户的头像路径
    void m_debugPrint() const;

private:
    explicit Config(QObject *parent = nullptr);
    ~Config();
    Config(const Config&  other);
    const Config& operator=(const Config& other);

    static Config* m_instance;   // 唯一单例对象智能指针
    static QMutex m_mutex;

    QString m_iniPath;                  // ini文件的路径
    QHostAddress m_serverAddress;       // 服务端的IP地址
    quint16 m_serverMsgPort;            // 服务端的消息监听端口
    float m_serverMaxConnectTime;       // 断线重连的最大时间，ms
    QString m_localDataPath;            // 本地文件的存放文件夹的路径
    QString m_localTmpPath;             // 本地临时文件的存放文件夹的路径
    QString m_localAccountPath;         // 本地当前登录账户的文件存放路径
    QString m_localChatPicsPath;        // 本地存放聊天图片的文件夹路径
    QString m_localDbPath;              // 本地数据库的路径
    sttClientInfo m_loginClientInfo;    // --- 登录成功的用户信息 ---
    QString m_loginClientHead;          // 登录成功的用户的头像的路径


signals:

public slots:
};

#endif // CONFIG_H
