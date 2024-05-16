#ifndef GLOBAL_H
#define GLOBAL_H

#include <QString>
#include <QVector>
#include <QHostAddress>
#include <QDataStream>
#include <QSettings>

namespace ChatType {
    enum ChatCMD
    {
        RegisterRequest         = 0x0F00,
        RegisterSuccess         = 0xF000,
        RegisterFailed          = 0xF001,
        LoginRequest            = 0x0F04,
        LoginSuccess            = 0xF004,
        LoginFailed             = 0xF005,
        ModifyUserInfoRequest   = 0x0F08,
        ModifyUserInfoSuccess   = 0xF008,
        ModifyUserInfoFailed    = 0xF009,
        AddGroupRequest         = 0x0F0C,
        AddGroupSuccess         = 0xF00C,
        AddGroupFailed          = 0xF00D,
        QueryOnlineState        = 0x0F0E,
        ReturnOnline            = 0xF00E,
        ReturnOffline           = 0xF00F,
        SendChatMsgRequest      = 0x1F00,
        ReceiveChatMsg          = 0xF100,
        SearchUserRequest       = 0x1F04,
        SearchUserSuccess       = 0xF104,
        SearchUserFailed        = 0xF105,
        AddFriendRequest        = 0x1F08,
        ReceiveAddFriendRequest = 0xF108,
        ReplyAddFriendRequest   = 0x1F0C,
        RejectAddFriendRequest  = 0xF10C,
        AgreeAddFriendRequest   = 0xF10D,
        UpdateFriendInfo        = 0xF10F,
        RenameGroupRequest      = 0x2F00,
        MoveFriendToGroup       = 0x2F01,
        RequestUserHeadPic      = 0x3F00,
        ReceiveUserHeadPic      = 0xF300,
        ModifyUserHeadRequest   = 0x3F04,
        SendChatPicRequest      = 0x3F08,
        ReceiveChatPic          = 0xF308
    };
    enum RegisterFailReason
    {
        AccountExist    = 0x00,
        OtherReason     = 0x01
    };
    enum LoginFailReason
    {
        AccountNotExist = 0x02,
        PasswordError   = 0x03,
        LoginOtherReason     = 0x01
    };
    const int MessageMinSize = 10;              // 最小10字节
    const int PicMaxSize     = 2*1024*1024;     // 图片最大2MB
}


struct sttClientInfo{           // 用户信息
    QHostAddress address;
    quint16 port;
    quint32 id;
    QString account;
    QString password;
    QString name;
    quint8 level;
    QString signature;
    QString sex;
    quint8 age;
    QString last_online;

    // 用于序列化的函数
    friend QDataStream &operator<<(QDataStream &out, const sttClientInfo &data) {
        out << data.address.toString().toUtf8() << data.port << data.id << data.account
            << data.password << data.name << data.level << data.signature
            << data.sex << data.age << data.last_online;
        return out;
    }

    // 用于反序列化的函数
    friend QDataStream &operator>>(QDataStream &in, sttClientInfo &data) {
        QByteArray address_bytes;
        in >> address_bytes;
        data.address = QHostAddress(QString::fromUtf8(address_bytes));
        in >> data.port >> data.id >> data.account >>
              data.password >> data.name >> data.level >>
              data.signature >> data.sex >> data.age >> data.last_online;
        return in;
    }
};


struct sttDatabaseInfo      // 数据库信息
{
    QString host_name;
    QString user_name;
    QString password;
    QString database_name;
};


struct sttFriendInfo{           // 朋友信息
    quint32     id;
    quint32     group_id;
    QString     account;
    QString     name;
    quint8      level;
    QString     signature;
    QString     sex;
    quint8      age;
    QString     last_online;

    // 写入字节流
    friend QDataStream &operator<<(QDataStream &out, const sttFriendInfo &data) {
        out << data.id << data.group_id << data.account
            << data.name << data.level << data.signature
            << data.sex << data.age << data.last_online;
        return out;
    }

    // 读出字节流
    friend QDataStream &operator>>(QDataStream &in, sttFriendInfo &data) {
        in >> data.id >> data.group_id >> data.account >>
              data.name >> data.level >> data.signature >>
              data.sex >> data.age >> data.last_online;
        return in;
    }
};

struct sttGroupInfo{            // 分组信息
    quint32 user_id;
    QString group_name;
    quint8  friend_num;
    QVector<sttFriendInfo> friend_list;

    // 写入字节流
    friend QDataStream &operator<<(QDataStream &out, const sttGroupInfo &data) {
        out << data.user_id << data.group_name.toUtf8() << data.friend_num;
        for(QVector<sttFriendInfo>::const_iterator ite = data.friend_list.begin(); ite!=data.friend_list.end(); ++ite)
        {
            out << (*ite);
        }
        return out;
    }

    // 读出字节流
    friend QDataStream &operator>>(QDataStream &in, sttGroupInfo &data) {
        QByteArray group_name_bytes;
        in >> data.user_id >> group_name_bytes>> data.friend_num;
        data.group_name = QString::fromUtf8(group_name_bytes);
        data.friend_list.clear();
        for(int i=0; i<data.friend_num; ++i)
        {
            sttFriendInfo cur_info;
            in >> cur_info;
            data.friend_list.append(cur_info);
        }
        return in;
    }
};


class Config : public QObject
{
    Q_OBJECT
public:
    static Config* getInstance();    // 获取单例对象
    static void deleteInstance();
    void m_readIni(const QString& ini_path);        // 读取配置文件
    void m_setUserFilePath(const QString& path);
    QString m_getUserFilePath() const;
    sttDatabaseInfo m_getDatabaseInfo() const;

private:
    explicit Config(QObject *parent = nullptr);
    ~Config();
    Config(const Config&  other);
    const Config& operator=(const Config& other);

    static Config* m_instance;   // 唯一单例对象智能指针
    static QMutex m_mutex;

    QString m_iniPath;                  // ini文件的路径
    QString m_userFilePath;             // 保存用户数据的文件夹
    sttDatabaseInfo m_dbInfo;           // 数据库信息


signals:

public slots:
};






#endif // GLOBAL_H
