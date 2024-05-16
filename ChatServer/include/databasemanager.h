#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QObject>
#include <QtSql>
#include <QStringList>
#include <QDebug>
#include <QMap>
#include <QVector>
#include <QDateTime>
#include "global.h"
#include "Helper.h"

class DatabaseManager : public QObject
{
    Q_OBJECT
public:
    explicit DatabaseManager(QObject *parent = nullptr, QSharedPointer<sttDatabaseInfo> database_info = QSharedPointer<sttDatabaseInfo>::create());
    ~DatabaseManager();

    bool m_getInitFlag() const;
    bool m_queryUserInfo(QString account, sttClientInfo* client_info = nullptr);                    // 查询用户信息
    bool m_queryUserInfo(quint32 user_id, sttClientInfo* client_info = nullptr);                    // 查询用户信息
    bool m_insertUserInfo(const sttClientInfo user_info, quint32* user_id = nullptr);               // 插入用户
    bool m_modifyUserInfo(const quint32 id, const QString item_name, const QVariant value);         // 修改用户信息
    bool m_queryUserAllGroups(const quint32 id, QMap<quint32, sttGroupInfo>* all_group_infos);      // 查询得到用户所有的分组信息
    bool m_queryUserAllFriends(const quint32 id, QVector<quint32>* friend_id_list);                 // 查询得到用户所有的好友的id
    bool m_userAddGroup(const quint32 id, const QString group_name, quint32* group_id=nullptr);     // 添加分组
    bool m_userRenameGroup(const quint32 id, const quint32 group_id, const QString group_new_name); // 重命名分组
    bool m_queryIsFriendOrNot(const quint32 id, const quint32 other_id,
                              bool* is_friend, quint32* group_id);                                  // 查询用户other_id是否是用户id的好友
    bool m_searchSimilarUser(const quint32 user_from_id, const QString search_text,
                             QVector<sttFriendInfo>* search_res);                                   // 根据用户user_from_id给出的关键词search_text查询搜索用户
    bool m_buildFriendShip(const quint32 user1, const quint32 user1_group, const quint32 user2, const quint32 user2_group);     // 为用户1和用户2建立好友关系
    bool m_queryFriendInfo(const quint32 user_id, const quint32 friend_id, sttFriendInfo* friend_info);         // 查询好友信息
    bool m_queryHeadPath(const quint32 user_id, QString* head_path);                                // 查询用户的头像路径
    bool m_modifyUserFriendGroup(const quint32 user_id, const quint32 friend_id, const quint32 group_id);       // 修改用户的好友所在的分组

private:
    QSharedPointer<sttDatabaseInfo> m_databaseInfo;             // 数据库信息
    QSqlDatabase m_database;                     // 数据库对象
    QSqlQuery m_query;                           // 数据库查询

    bool m_initFlag;            // 指示是否初始化成功
    bool m_checkDatabaseValid();

signals:

public slots:
    bool  m_init();             // 初始化
};

#endif // DATABASEMANAGER_H
