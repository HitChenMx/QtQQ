#include "LocalDatabase.h"

LocalDatabase* LocalDatabase::m_instance = nullptr;
QMutex LocalDatabase::m_mutex;

LocalDatabase::LocalDatabase(QObject *parent, QString db_path) :
    QObject(parent),
    m_initFlag(false)
{
    // 连接数据库
    if(QSqlDatabase::contains("local_sqlite"))
    {
        m_database = QSqlDatabase::database("local_sqlite");
    }
    else
    {
        m_database = QSqlDatabase::addDatabase("QSQLITE", "local_sqlite");
    }
    m_database.setDatabaseName(db_path);

    m_query = QSqlQuery(m_database);

    if(!m_database.open())
    {
        m_initFlag = false;
        return;
    }

    // 创建本地表
    bool _create_table_success = m_createTableIfNotExist();
    m_initFlag = _create_table_success;
    if(m_initFlag)
        qDebug() << "local database:" << db_path << "init successfully.";
}

LocalDatabase* LocalDatabase::getInstance()
{
    // 先检查数据库路径是否为空
    QString _db_path = Config::getInstance()->m_getLocalDbPath();
    if(_db_path.isEmpty())
    {
        qDebug() << "local database path is not inited.";
        return nullptr;
    }

    // 双检锁
    if(m_instance == nullptr)
    {
        QMutexLocker locker(&m_mutex);
        if(m_instance == nullptr)
        {
            LocalDatabase* tmp = new LocalDatabase(nullptr, _db_path);
            m_instance = tmp;
        }
    }
    return m_instance;
}

void LocalDatabase::deleteInstance()
{
    QMutexLocker locker(&m_mutex);
    if(m_instance)
    {
        delete m_instance;
        m_instance = nullptr;
    }
}

LocalDatabase::~LocalDatabase()
{

}

bool LocalDatabase::m_createTableIfNotExist()
{
    if(m_database.transaction())
    {
        m_query.exec("CREATE TABLE IF NOT EXISTS chatlog ("
                     "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                     "senderID INTEGER NOT NULL, "
                     "receiverID INTEGER NOT NULL, "
                     "time DATETIME DEFAULT CURRENT_TIMESTAMP NOT NULL, "
                     "message_type VARCHAR(10) CHECK(message_type IN ('text', 'file')), "
                     "message TEXT NOT NULL"
                     ")");

        m_query.exec("CREATE TABLE IF NOT EXISTS friendgroup("
                     "group_id INT NOT NULL,"
                     "group_name VARCHAR(255) NOT NULL,"
                     "PRIMARY KEY (group_id)"
                     ")");

        m_query.exec("CREATE TABLE IF NOT EXISTS friend("
                     "friend_id INT NOT NULL,"
                     "group_id INT NOT NULL,"
                     "account VARCHAR(20) NOT NULL,"
                     "name VARCHAR(255) NOT NULL,"
                     "level TINYINT NOT NULL,"
                     "signature VARCHAR(255) DEFAULT NULL,"
                     "sex VARCHAR(20) DEFAULT NULL,"
                     "age TINYINT DEFAULT NULL,"
                     "last_online DATETIME DEFAULT NULL,"
                     "head_path VARCHAR(255) DEFAULT NULL,"
                     "PRIMARY KEY (friend_id)"
                     ")");

        if(m_query.lastError().isValid())
        {
            qDebug() << "Error from LocalDatabase::m_createTableIfNotExist:" << m_query.lastError().text();
            // m_query.exec("rollback");
            m_database.rollback();
            return false;
        }
        else
        {
            // bool _success = m_query.exec("commit");
            bool _success = m_database.commit();
            return _success;
        }
    }
    qDebug() << "Error from LocalDatabase::m_createTableIfNotExist: transaction not start.";
    return false;
}

bool LocalDatabase::m_replaceIntotGroupInfo(const quint32 &group_id, const QString &group_name)
{
    m_query.prepare("REPLACE INTO friendgroup "
                    "(group_id, group_name) "
                    "VALUES (:group_id, :group_name)");
    m_query.bindValue(":group_id", group_id);
    m_query.bindValue(":group_name", group_name);

    bool _insert_success = m_query.exec();
    if(_insert_success == false)
    {
        qDebug() << "Error from LocalDatabase::m_replaceIntotGroupInfo: " << m_query.lastError().text();
    }
    return _insert_success;
}

bool LocalDatabase::m_replaceIntoFriendInfo(const sttFriendInfo &friend_info)
{
    // 防止头像路径被清除
    QString head_path_save = "";
    m_queryFriendHead(friend_info.id, &head_path_save);

    m_query.prepare("REPLACE INTO friend "
                    "(friend_id, group_id, account, name, level, signature, sex, age, last_online) "
                    "VALUES (:friend_id, :group_id, :account, :name, :level, :signature, :sex, :age, :last_online)");
    m_query.bindValue(":friend_id", friend_info.id);
    m_query.bindValue(":group_id", friend_info.group_id);
    m_query.bindValue(":account", friend_info.account);
    m_query.bindValue(":name", friend_info.name);
    m_query.bindValue(":level", friend_info.level);
    m_query.bindValue(":signature", friend_info.signature);
    m_query.bindValue(":sex", friend_info.sex);
    m_query.bindValue(":age", friend_info.age);
    m_query.bindValue(":last_online", friend_info.last_online);

    bool _insert_success = m_query.exec();
    if(_insert_success == false)
    {
        qDebug() << "Error from LocalDatabase::m_replaceIntoFriendInfo: " << m_query.lastError().text();
        return false;
    }
    if(!head_path_save.isEmpty())
    {
        m_modifyFriendHead(friend_info.id, head_path_save);
    }
    return true;;
}

bool LocalDatabase::m_queryFriendName(const quint32 &friend_id, QString *friend_name)
{
    m_query.prepare("SELECT name FROM friend WHERE friend_id = :id");
    m_query.bindValue(":id", friend_id);

    if(m_query.exec() && m_query.next())
    {
        if(friend_name)
        {
            *friend_name = m_query.value("name").toString();
        }
        return true;
    }
    qDebug() << "Error from LocalDatabase::m_queryFriendName: " << m_query.lastError().text();
    return false;
}

bool LocalDatabase::m_queryFriendInWhichGroup(const quint32 &friend_id, quint32 *group_id)
{
    m_query.prepare("SELECT group_id FROM friend WHERE friend_id = :friend_id");
    m_query.bindValue(":friend_id", friend_id);
    if(m_query.exec() && m_query.next())
    {
        if(group_id)
        {
            *group_id = m_query.value("group_id").toInt();
        }
        return true;
    }
    qDebug() << "Error from LocalDatabase::m_queryFriendInWhichGroup: " << m_query.lastError().text();
    return false;
}

bool LocalDatabase::m_queryFriendInfo(const quint32 &friend_id, sttFriendInfo *friend_info)
{
    if(friend_info == nullptr)
        return false;

    m_query.prepare("SELECT * FROM friend WHERE friend_id = :friend_id");
    m_query.bindValue(":friend_id", friend_id);
    if(m_query.exec() && m_query.next())
    {
        friend_info->id = friend_id;
        friend_info->group_id = m_query.value("group_id").toInt();
        friend_info->account = m_query.value("account").toString();
        friend_info->name = m_query.value("name").toString();
        friend_info->level = m_query.value("level").toInt();
        friend_info->signature = m_query.value("signature").toString();
        friend_info->sex = m_query.value("sex").toString();
        friend_info->age = m_query.value("age").toInt();
        QString last_online = m_query.value("last_online").toString();
        QDateTime date_time = QDateTime::fromString(last_online, Qt::ISODate);
        QString formatted_last_online = date_time.toString("yyyy-MM-dd hh:mm:ss");
        friend_info->last_online = formatted_last_online;
        return true;
    }
    qDebug() << "Error from LocalDatabase::m_queryFriendInfo: " << m_query.lastError().text();
    return false;
}

bool LocalDatabase::m_queryAllGroups(QMap<quint32, sttGroupInfo> *all_group_infos)          // 查询得到所有的分组信息
{
    if(all_group_infos == nullptr)
        return false;
    if(!all_group_infos->isEmpty())
        all_group_infos->clear();

    // 先得到group id和名称
    QMap<quint32, QString> group_id2name;
    if(m_query.exec("SELECT * FROM friendgroup") == false)
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
        m_query.prepare("SELECT * FROM friend WHERE group_id = :group_id");
        m_query.bindValue(":group_id", ite.key());
        if(m_query.exec() == false)
        {
            qDebug() << "An error occured when query friend info from" << ite.value();
            continue;
        }

        sttGroupInfo cur_group_info;
        cur_group_info.user_id = Config::getInstance()->m_getLoginClientId();
        cur_group_info.group_name = ite.value();
        quint8 friend_num = 0;
        while(m_query.next())
        {
            sttFriendInfo cur_friend_info;
            cur_friend_info.id = m_query.value("friend_id").toInt();
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

bool LocalDatabase::m_queryAllGroupIdNames(QMap<quint32, QString>* all_group_names)
{
    if(m_initFlag == false)
        return false;
    if(m_query.exec("SELECT group_id, group_name FROM friendgroup ORDER BY group_id") == false)
    {
        qDebug() << "Error from LocalDatabase::m_queryAllGroupIdNames:" << m_query.lastError().text();
        return false;
    }
    if(all_group_names)
    {
        if(!all_group_names->isEmpty())
        {
            all_group_names->clear();
        }
        while(m_query.next())
        {
            quint32 cur_group_id = m_query.value("group_id").toInt();
            QString cur_group_name = m_query.value("group_name").toString();
            all_group_names->insert(cur_group_id, cur_group_name);
        }
    }
    return true;
}

bool LocalDatabase::m_insertChatLog(const sttChatMsgInfo& chat_log)
{
    if(m_initFlag == false)
        return false;

    m_query.prepare("INSERT INTO chatlog "
                    "(senderID, receiverID, time, message_type, message) "
                    "VALUES (:send_id, :receiver_id, :time, :type, :chat_msg)");
    m_query.bindValue(":send_id", chat_log.send_id);
    m_query.bindValue(":receiver_id", chat_log.receiver_id);
    m_query.bindValue(":time", chat_log.time);
    QString msg_type = chat_log.msg_type==ChatType::IsTextMsg? "text" : "file";
    m_query.bindValue(":type", msg_type);
    m_query.bindValue(":chat_msg", chat_log.message);

    if(m_query.exec() == false)
    {
        qDebug() << "Error from LocalDatabase::m_insertChatLog:" << m_query.lastError().text();
        return false;
    }
    else
        return true;
}

bool LocalDatabase::m_queryChatLog(const quint32 &user1_id, const quint32 &user2_id, QVector<sttChatMsgInfo> *chat_logs, const int* const log_num)
{
    if(m_initFlag == false)
        return false;

    // 查询user1和user2之间的聊天记录
    if(log_num == nullptr)
    {
        m_query.prepare("SELECT senderID, receiverID, time, message_type, message "
                        "FROM chatlog "
                        "WHERE (senderID=:user1 AND receiverID=:user2) OR (senderID=:user2 AND receiverID=:user1) "
                        "ORDER BY id ASC");
    }
    else
    {
        m_query.prepare("SELECT senderID, receiverID, time, message_type, message "
                        "FROM chatlog "
                        "WHERE (senderID=:user1 AND receiverID=:user2) OR (senderID=:user2 AND receiverID=:user1) "
                        "ORDER BY id ASC "
                        "LIMIT :log_num");
        m_query.bindValue(":log_num", *log_num);
    }
    m_query.bindValue(":user1", user1_id);
    m_query.bindValue(":user2", user2_id);
    if(m_query.exec() == false)
    {
        qDebug() << "query chatlog error:" << m_query.lastError().text();
        return false;
    }

    // 把聊天记录保存到chat_logs
    if(chat_logs != nullptr)
    {
        if(!chat_logs->isEmpty())
            chat_logs->clear();
        while(m_query.next())
        {
            sttChatMsgInfo _chat_info;
            _chat_info.send_id = m_query.value("senderID").toUInt();
            _chat_info.receiver_id = m_query.value("receiverID").toUInt();
            _chat_info.time = m_query.value("time").toString();
            QString msg_type = m_query.value("message_type").toString();
            _chat_info.msg_type = msg_type=="text"? ChatType::IsTextMsg : ChatType::IsFileMsg;
            _chat_info.message = m_query.value("message").toString();
            chat_logs->append(_chat_info);
        }
    }
    return true;
}

bool LocalDatabase::m_queryAllFriendId(QVector<quint32> *all_friend_id)
{
    if(m_initFlag == false)
        return false;

    if(m_query.exec("SELECT friend_id FROM friend ORDER BY friend_id") == false)
    {
        qDebug() << "Error from LocalDatabase::m_queryAllFriendId:" << m_query.lastError().text();
        return false;
    }

    if(all_friend_id)
    {
        if(!all_friend_id->isEmpty())
            all_friend_id->clear();
        while(m_query.next())
        {
            quint32 cur_friend_id = m_query.value("friend_id").toInt();
            all_friend_id->append(cur_friend_id);
        }
    }
    return true;
}

bool LocalDatabase::m_queryFriendHead(const quint32 &friend_id, QString *head_path)
{
    QSqlQuery _query(m_database);
    _query.prepare("SELECT head_path FROM friend WHERE friend_id = :id");
    _query.bindValue(":id", friend_id);
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
    qDebug() << "Error from LocalDatabase::m_queryFriendHead:" << _query.lastError().text();
    return false;
}

bool LocalDatabase::m_modifyFriendHead(const quint32 &friend_id, const QString &head_path)
{
    m_query.prepare("UPDATE friend SET head_path = :path WHERE friend_id = :id");
    m_query.bindValue(":id", friend_id);
    m_query.bindValue(":path", head_path);

    if(m_query.exec())
    {
        return true;
    }
    QSqlError sql_error = m_query.lastError();
    qDebug() << "Error from m_modifyFriendHead: " << sql_error.text();
    return false;
}

bool LocalDatabase::m_modifyFriendInWhichGroup(const quint32 &friend_id, const quint32 &group_id)
{
    m_query.prepare("UPDATE friend SET group_id = :group_id WHERE friend_id = :id");
    m_query.bindValue(":id", friend_id);
    m_query.bindValue(":group_id", group_id);

    if(m_query.exec())
    {
        return true;
    }
    QSqlError sql_error = m_query.lastError();
    qDebug() << "Error from m_modifyFriendInWhichGroup: " << sql_error.text();
    return false;
}
