#include "databasemanager.h"

DatabaseManager::DatabaseManager(QObject *parent, QSharedPointer<sttDatabaseInfo> database_info) :
    QObject(parent),
    m_databaseInfo(database_info),
    m_initFlag(false)
{
    m_initFlag = m_init();
}

DatabaseManager::~DatabaseManager()
{
    if(m_database.isOpen())
        m_database.close();
}

bool DatabaseManager::m_init()
{
    QString old_connect_name = "";
    if(m_database.isOpen())
    {
        qDebug() << "start reconnect MySQL database...";
        old_connect_name = m_database.connectionName();
        m_database.close();
    }

//    // 连接数据库
//    if(QSqlDatabase::contains("server_mysql"))
//    {
//        // 旧的MySQL连接已失效，需要换一个连接名
//        if(old_connect_name == "server_mysql")
//        {
//            QString random_name = generateRandomString(10);
//            while(QSqlDatabase::contains(random_name))
//            {
//                random_name = generateRandomString(10);
//            }
//            m_database = QSqlDatabase::addDatabase("QMYSQL", random_name);
//        }
//        else
//        {
//            m_database = QSqlDatabase::database("server_mysql");
//        }
//    }
//    else
//    {
//        m_database = QSqlDatabase::addDatabase("QMYSQL", "server_mysql");
//    }
    // 下面这几行改成了：每个数据库对象都使用不同的连接名
    QString random_name = generateRandomString(10);
    while(QSqlDatabase::contains(random_name))
    {
        random_name = generateRandomString(10);
    }
    m_database = QSqlDatabase::addDatabase("QMYSQL", random_name);
    m_database.setDatabaseName(m_databaseInfo->database_name);
    m_database.setHostName(m_databaseInfo->host_name);
    m_database.setUserName(m_databaseInfo->user_name);
    m_database.setPassword(m_databaseInfo->password);
    // m_database.setConnectOptions("MYSQL_OPT_RECONNECT=1");

    m_query = QSqlQuery(m_database);

    if(m_database.open())
    {
        qDebug() << "database" << m_databaseInfo->database_name << "connected, connection name:" << m_database.connectionName();
        return true;
    }
    else
    {
        qDebug() << "database open failed.";
        return false;
    }
}

bool DatabaseManager::m_getInitFlag() const
{
    return m_initFlag;
}

bool DatabaseManager::m_queryUserInfo(QString account, sttClientInfo* client_info)
{
    m_query.prepare("SELECT * FROM user WHERE account = :account");
    m_query.bindValue(":account", account);
    if(m_query.exec() && m_query.next())
    {
        if(client_info != nullptr)
        {
            client_info->id = m_query.value("id").toInt();
            client_info->account = m_query.value("account").toString();
            client_info->password = m_query.value("password").toString();
            client_info->name = m_query.value("name").toString();
            client_info->level = m_query.value("level").toInt();
            client_info->signature = m_query.value("signature").toString();
            client_info->sex = m_query.value("sex").toString();
            client_info->age = m_query.value("age").toInt();
            // client_info->last_online = m_query.value("last_online").toString();
            QString last_online = m_query.value("last_online").toString();
            QDateTime date_time = QDateTime::fromString(last_online, Qt::ISODate);
            QString formatted_last_online = date_time.toString("yyyy-MM-dd hh:mm:ss");
            client_info->last_online = formatted_last_online;
        }
        return true;
    }
    return false;
}

bool DatabaseManager::m_queryUserInfo(quint32 user_id, sttClientInfo *client_info)
{
    m_query.prepare("SELECT * FROM user WHERE id = :id");
    m_query.bindValue(":id", user_id);
    if(m_query.exec() && m_query.next())
    {
        if(client_info != nullptr)
        {
            client_info->id = m_query.value("id").toInt();
            client_info->account = m_query.value("account").toString();
            client_info->password = m_query.value("password").toString();
            client_info->name = m_query.value("name").toString();
            client_info->level = m_query.value("level").toInt();
            client_info->signature = m_query.value("signature").toString();
            client_info->sex = m_query.value("sex").toString();
            client_info->age = m_query.value("age").toInt();
            // client_info->last_online = m_query.value("last_online").toString();
            QString last_online = m_query.value("last_online").toString();
            QDateTime date_time = QDateTime::fromString(last_online, Qt::ISODate);
            QString formatted_last_online = date_time.toString("yyyy-MM-dd hh:mm:ss");
            client_info->last_online = formatted_last_online;
        }
        return true;
    }
    return false;
}

bool DatabaseManager::m_insertUserInfo(const sttClientInfo user_info, quint32* user_id)      // 插入用户
{
    m_query.prepare("INSERT INTO user"
                    " (account, password, name, level, signature, sex, age, last_online)"
                    " VALUES (:account, :password, :name, :level, :signature, :sex, :age, :last_online)");
    m_query.bindValue(":account", user_info.account);
    m_query.bindValue(":password", user_info.password);
    m_query.bindValue(":name", user_info.name);
    m_query.bindValue(":level", user_info.level);
    m_query.bindValue(":signature", user_info.signature);
    m_query.bindValue(":sex", user_info.sex);
    m_query.bindValue(":age", user_info.age);
    m_query.bindValue(":last_online", user_info.last_online);

    if(m_query.exec())
    {
        if(user_id!=nullptr)
        {
            QVariant last_insert_id = m_query.lastInsertId();
            if(!last_insert_id.isNull())
            {
                *user_id = last_insert_id.toUInt();
            }
        }
        return true;
    }
    qDebug() << "Error from m_insertUserInfo: " << m_query.lastError().text();
    return false;
}

bool DatabaseManager::m_modifyUserInfo(const quint32 id, const QString item_name, const QVariant value)     // 修改用户信息
{
    // 支持修改的项名称，只有level和age的类型是quint8，其他都是QString
    QStringList item_list = {"password", "name", "level", "signature", "sex", "age", "last_online", "head_path"};
    if(!item_list.contains(item_name))
    {
        return false;
    }

    m_query.prepare(QString("UPDATE user SET %1 = :value WHERE id = :id").arg(item_name));
    m_query.bindValue(":value", value);
    m_query.bindValue(":id", id);

    if(m_query.exec())
    {
        return true;
    }
    QSqlError sql_error = m_query.lastError();
    qDebug() << "Error from m_modifyUserInfo: " << sql_error.text();
    return false;
}

bool DatabaseManager::m_queryUserAllGroups(const quint32 id, QMap<quint32, sttGroupInfo> *all_group_infos)     // 查询得到用户所有的分组信息
{
    if(all_group_infos == nullptr)
        return false;
    if(!all_group_infos->isEmpty())
        all_group_infos->clear();

    // 先得到group id和名称
    QMap<quint32, QString> group_id2name;
    m_query.prepare("SELECT * FROM friendgroup WHERE account_id = :id");
    m_query.bindValue(":id", id);
    if(m_query.exec() == false)
        return false;
    while(m_query.next())
    {
        quint32 cur_group_id = m_query.value("group_id").toInt();
        QString cur_group_name = m_query.value("group_name").toString();
        group_id2name.insert(cur_group_id, cur_group_name);
    }
    if(group_id2name.isEmpty())     // 说明用户没有任何的分组信息
    {
        return true;
    }

    // 再根据group id查询分组里的好友信息
    for(QMap<quint32, QString>::const_iterator ite = group_id2name.begin(); ite!=group_id2name.end(); ++ite)
    {
        m_query.prepare("SELECT * FROM user WHERE id IN (SELECT friend_id FROM friend WHERE group_id = :group_id);");
        m_query.bindValue(":group_id", ite.key());
        if(m_query.exec() == false)
        {
            qDebug() << "An error occured when query friend info from" << ite.value();
        }

        sttGroupInfo cur_group_info;
        cur_group_info.user_id = id;
        cur_group_info.group_name = ite.value();
        quint8 friend_num = 0;
        while(m_query.next())
        {
            sttFriendInfo cur_friend_info;
            cur_friend_info.id = m_query.value("id").toInt();
            cur_friend_info.group_id = ite.key();
            cur_friend_info.account = m_query.value("account").toString();
            cur_friend_info.name = m_query.value("name").toString();
            cur_friend_info.level = m_query.value("level").toInt();
            cur_friend_info.signature = m_query.value("signature").toString();
            cur_friend_info.sex = m_query.value("sex").toString();
            cur_friend_info.age = m_query.value("age").toInt();
            QString last_online = m_query.value("last_online").toString();
            QDateTime date_time = QDateTime::fromString(last_online, Qt::ISODate);
            QString formatted_last_online = date_time.toString("yyyy-MM-dd hh:mm:ss");
            cur_friend_info.last_online = formatted_last_online;
            cur_group_info.friend_list.append(cur_friend_info);
            friend_num++;
        }
        cur_group_info.friend_num = friend_num;
        all_group_infos->insert(ite.key(), cur_group_info);
    }
    return true;
}

bool DatabaseManager::m_queryUserAllFriends(const quint32 id, QVector<quint32> *friend_id_list)
{
    if(friend_id_list == nullptr)
        return false;
    if(!friend_id_list->isEmpty())
        friend_id_list->clear();

    m_query.prepare("SELECT friend_id FROM friend WHERE account_id = :id");
    m_query.bindValue(":id", id);
    if(m_query.exec() == false)
        return false;

    while(m_query.next())
    {
        quint32 cur_friend_id = m_query.value("friend_id").toUInt();
        friend_id_list->append(cur_friend_id);
    }
    return true;
}

bool DatabaseManager::m_userAddGroup(const quint32 id, const QString group_name, quint32* group_id)
{
    m_query.prepare("INSERT INTO friendgroup (group_name, account_id) VALUES (:group_name, :id)");
    m_query.bindValue(":group_name", group_name);
    m_query.bindValue(":id", id);
    if(m_query.exec())
    {
        if(group_id!=nullptr)
        {
            QVariant last_insert_id = m_query.lastInsertId();
            if(!last_insert_id.isNull())
            {
                *group_id = last_insert_id.toUInt();
            }
        }
        return true;
    }
    QSqlError sql_error = m_query.lastError();
    qDebug() << "Error from m_userAddGroup: " << sql_error.text();
    return false;
}

bool DatabaseManager::m_userRenameGroup(const quint32 id, const quint32 group_id, const QString group_new_name)
{
    m_query.prepare("UPDATE friendgroup SET group_name = :new_name WHERE group_id = :group_id AND account_id = :id");
    m_query.bindValue(":new_name", group_new_name);
    m_query.bindValue(":group_id", group_id);
    m_query.bindValue(":id", id);

    return m_query.exec();
}

bool DatabaseManager::m_queryIsFriendOrNot(const quint32 id, const quint32 other_id, bool *is_friend, quint32* group_id)
{
    QSqlQuery _query(m_database);
    _query.prepare("SELECT friendShip_id, group_id FROM friend WHERE friend_id = :other_id AND account_id = :id");
    _query.bindValue(":other_id", other_id);
    _query.bindValue(":id", id);
    bool _query_success = _query.exec();
    if(_query_success == false)
    {
        QSqlError sql_error = _query.lastError();
        qDebug() << "Error from m_queryIsFriendOrNot: " << sql_error.text();
        return false;
    }
    *is_friend = false;
    *group_id = 0;
    if(_query.next())
    {
        *is_friend = true;
        *group_id = _query.value("group_id").toUInt();
    }
    return true;
}

bool DatabaseManager::m_searchSimilarUser(const quint32 user_from_id, const QString search_text, QVector<sttFriendInfo>* search_res)
/*
    查询规则：search_text可以是账号，也可以是昵称
            当search_text全为数字时，认为是根据账号来查询，否则认为根据昵称来查询
            查询支持模糊匹配，例如search_text为 "133" ，那么会查询出所有账号以 133 开头的记录
            查询条目中如果含有搜索者自己，就排除掉
            查询条目只返回按id排序后的前10条
*/
{
    QString search_index;
    bool _text_is_allDigits;    // 是否全是数字
    search_text.toInt(&_text_is_allDigits);
    search_index = _text_is_allDigits ? "account" : "name";

    if(search_index.isEmpty())
        return false;
    if(search_res == nullptr)
        return false;
    m_query.prepare("SELECT * FROM user WHERE " + search_index + " LIKE :search_text AND id != :user_from_id ORDER BY id ASC LIMIT 10");
    m_query.bindValue(":search_text", search_text+"%");
    m_query.bindValue(":user_from_id", user_from_id);
    if(m_query.exec() == false)
    {
        QSqlError sql_error = m_query.lastError();
        qDebug() << "Error from m_searchSimilarUser: " << sql_error.text();
        return false;
    }
    // 把查询到的记录添加到search_res
    search_res->clear();
    while(m_query.next())
    {
        sttFriendInfo cur_user_info;
        cur_user_info.id = m_query.value("id").toUInt();
        cur_user_info.account = m_query.value("account").toString();
        cur_user_info.name = m_query.value("name").toString();
        cur_user_info.level = m_query.value("level").toUInt();
        cur_user_info.signature = m_query.value("signature").toString();
        cur_user_info.sex = m_query.value("sex").toString();
        cur_user_info.age = m_query.value("age").toUInt();
        // cur_user_info.last_online = m_query.value("last_online").toString();
        QString last_online = m_query.value("last_online").toString();
        QDateTime date_time = QDateTime::fromString(last_online, Qt::ISODate);
        QString formatted_last_online = date_time.toString("yyyy-MM-dd hh:mm:ss");
        cur_user_info.last_online = formatted_last_online;

        bool cur_user_is_friend = false;
        quint32 _group_id = 0;
        m_queryIsFriendOrNot(user_from_id, cur_user_info.id, &cur_user_is_friend, &_group_id);
        cur_user_info.group_id = _group_id;

        search_res->append(cur_user_info);
    }

    return true;
}

bool DatabaseManager::m_buildFriendShip(const quint32 user1, const quint32 user1_group, const quint32 user2, const quint32 user2_group)
{
    // 开始事务
    if(m_query.exec("START TRANSACTION"))
    {
        QString _build_time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");

        m_query.prepare("INSERT INTO friend"
                        "(friend_id, group_id, account_id, build_time)"
                        "VALUES (:friend_id, :group_id, :account_id, :build_time);");
        m_query.bindValue(":friend_id", user2);
        m_query.bindValue(":group_id", user1_group);
        m_query.bindValue(":account_id", user1);
        m_query.bindValue(":build_time", _build_time);
        m_query.exec();

        m_query.prepare("INSERT INTO friend"
                        "(friend_id, group_id, account_id, build_time)"
                        "VALUES (:friend_id, :group_id, :account_id, :build_time);");
        m_query.bindValue(":friend_id", user1);
        m_query.bindValue(":group_id", user2_group);
        m_query.bindValue(":account_id", user2);
        m_query.bindValue(":build_time", _build_time);
        m_query.exec();

        if(m_query.lastError().isValid())
        {
            qDebug() << "Error from m_buildFriendShip:" << m_query.lastError().text();
            m_query.exec("rollback");
            return false;
        }
        else
        {
            bool _success = m_query.exec("commit");
            return _success;
        }
    }
    qDebug() << "Error: transaction not start.";
    return false;
}

bool DatabaseManager::m_queryFriendInfo(const quint32 user_id, const quint32 friend_id, sttFriendInfo *friend_info)
{
    // 先查询是否是好友
    bool _is_friend;
    quint32 group_of_friend_in_user;        // 好友在用户的哪个分组里
    bool _query_is_friend_success = this->m_queryIsFriendOrNot(user_id, friend_id, &_is_friend, &group_of_friend_in_user);
    if(_query_is_friend_success==false || _is_friend == false)
    {
        return false;
    }

    if(friend_info)
    {
        // 把好友信息写入friend_info
        sttClientInfo _friend_client_info;
        bool _query_info_success = this->m_queryUserInfo(friend_id, &_friend_client_info);
        if(_query_info_success == false)
            return false;

        friend_info->id = _friend_client_info.id;
        friend_info->group_id = group_of_friend_in_user;
        friend_info->account = _friend_client_info.account;
        friend_info->name = _friend_client_info.name;
        friend_info->level = _friend_client_info.level;
        friend_info->signature = _friend_client_info.signature;
        friend_info->sex = _friend_client_info.sex;
        friend_info->age = _friend_client_info.age;
        friend_info->last_online = _friend_client_info.last_online;
    }
    return true;
}

bool DatabaseManager::m_queryHeadPath(const quint32 user_id, QString *head_path)
{ 
    qDebug() << "start m_queryHeadPath...";
    m_checkDatabaseValid();
    QSqlQuery _query(m_database);
    _query.prepare("SELECT head_path FROM user WHERE id = :id");
    _query.bindValue(":id", user_id);
    if(_query.exec() && _query.next())
    {
        if(head_path)
        {
            QVariant _path = _query.value("head_path");
            if(_path.isNull())
                *head_path = "";
            else
                *head_path = _path.toString();
        }
        return true;
    }
    QSqlError sql_error = _query.lastError();
    qDebug() << "Error from m_queryHeadPath: " << sql_error.text() << ", current database connection name:" << m_database.connectionName();
    return false;
}

bool DatabaseManager::m_checkDatabaseValid()
{
    bool is_valid = false;
    try{
        QSqlQuery _query("SELECT account FROM user WHERE id = 1", m_database);
        if(_query.exec())
        {
            qDebug() << "database connection" << m_database.connectionName() << "is valid.";
            is_valid = true;
        }
        else
        {
            qDebug() << "Error from m_checkDatabaseValid:" << _query.lastError().text();
            is_valid = false;
        }
    }
    catch(...)
    {
        is_valid = false;
    }
    if(is_valid == false)
    {
        qDebug() << "database connection" << m_database.connectionName() << "is not valid.";
        bool reconnect_success = m_init();
        return reconnect_success;
    }
    return is_valid;
}

bool DatabaseManager::m_modifyUserFriendGroup(const quint32 user_id, const quint32 friend_id, const quint32 group_id)
{
    m_query.prepare("UPDATE friend SET group_id = :group_id WHERE friend_id = :friend_id AND account_id = :user_id");
    m_query.bindValue(":friend_id", friend_id);
    m_query.bindValue(":user_id", user_id);
    m_query.bindValue(":group_id", group_id);

    if(m_query.exec())
    {
        return true;
    }
    QSqlError sql_error = m_query.lastError();
    qDebug() << "Error from m_modifyUserFriendGroup: " << sql_error.text();
    return false;
}
