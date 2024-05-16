#ifndef LOCALDATABASE_H
#define LOCALDATABASE_H

#include <QObject>
#include <QtSql>
#include <QSqlQuery>
#include <QVector>
#include <QDebug>
#include <QMap>
#include "Config.h"
#include "global.h"

class LocalDatabase : public QObject
{
    Q_OBJECT
public:
    static LocalDatabase* getInstance();        // 获取单例对象
    static void deleteInstance();

    bool m_replaceIntotGroupInfo(const quint32& group_id, const QString& group_name);        // 插入分组信息，存在就覆写，不存在就创建
    bool m_replaceIntoFriendInfo(const sttFriendInfo& friend_info);                          // 插入好友信息，存在就覆写，不存在就创建
    bool m_queryFriendName(const quint32& friend_id, QString* friend_name);                  // 查询好友名字
    bool m_queryFriendInWhichGroup(const quint32& friend_id, quint32* group_id);             // 查询好友所在的分组
    bool m_queryFriendInfo(const quint32& friend_id, sttFriendInfo* friend_info);            // 查询好友信息
    bool m_queryAllGroups(QMap<quint32, sttGroupInfo>* all_group_infos);                     // 查询得到所有的分组信息，包括所有的好友信息
    bool m_queryAllGroupIdNames(QMap<quint32, QString>* all_group_names);                            // 查询得到所有的分组id和名称
    bool m_insertChatLog(const sttChatMsgInfo& chat_log);                                    // 添加聊天记录到本地数据库
    bool m_queryChatLog(const quint32& user1_id, const quint32& user2_id,
                        QVector<sttChatMsgInfo>* chat_logs, const int* const log_num = nullptr);    // 查询两个用户之间的聊天记录
    bool m_queryAllFriendId(QVector<quint32>* all_friend_id);                                // 查询得到所有好友的id
    bool m_queryFriendHead(const quint32& friend_id, QString* head_path);                    // 查询好友的头像
    bool m_modifyFriendHead(const quint32& friend_id, const QString& head_path);             // 修改好友的头像
    bool m_modifyFriendInWhichGroup(const quint32& friend_id, const quint32& group_id);      // 修改好友所属的分组

private:
    explicit LocalDatabase(QObject *parent = nullptr, QString db_path = "");
    ~LocalDatabase();
    LocalDatabase(const LocalDatabase& other);
    const LocalDatabase& operator=(const LocalDatabase& other);

    static LocalDatabase* m_instance;   // 唯一单例对象智能指针
    static QMutex m_mutex;
    QSqlDatabase m_database;        // 数据库对象
    bool m_initFlag;                // 初始化成功标志
    QSqlQuery m_query;              // SQL query

    bool m_createTableIfNotExist();         // 如果不存在表，就创建

signals:

public slots:
};

#endif // LOCALDATABASE_H
