#include "Config.h"

Config* Config::m_instance = nullptr;
QMutex Config::m_mutex;

Config::Config(QObject *parent) :
    QObject(parent),
    m_iniPath(QString()),
    m_serverAddress(QHostAddress()),
    m_serverMsgPort(0),
    m_serverMaxConnectTime(3000),
    m_localDataPath(QString()),
    m_localTmpPath(QString()),
    m_localAccountPath(QString()),
    m_localDbPath(QString()),
    m_loginClientInfo(sttClientInfo()),
    m_loginClientHead(QString())
{

}

Config* Config::getInstance()
{
    // 双检锁
    if(m_instance == nullptr)
    {
        QMutexLocker locker(&m_mutex);
        if(m_instance == nullptr)
        {
            Config* tmp = new Config;
            m_instance = tmp;
        }
    }
    return m_instance;
}

void Config::deleteInstance()
{
    QMutexLocker locker(&m_mutex);
    if(m_instance)
    {
        delete m_instance;
        m_instance = nullptr;
    }
}

Config::~Config()
{

}

void Config::m_readIni(const QString &ini_path)
{
    m_iniPath = ini_path;

    QSettings _setting(m_iniPath, QSettings::IniFormat);
    m_serverAddress = QHostAddress(_setting.value("ServerConnect/address").toString());
    m_serverMsgPort = _setting.value("ServerConnect/msg-port").toString().toUInt();
    m_serverMaxConnectTime = _setting.value("ServerConnect/max-connect-time").toString().toFloat();
    m_localDataPath = _setting.value("LocalData/local-data-path").toString();
    m_localDataPath.replace("\\", "/");
    if(!m_localDataPath.isEmpty() && m_localDataPath.endsWith('/'))
    {
        m_localDataPath.chop(1);
    }
    // 如果ini_path是相对路径，就把本地资源路径设置为和ini文件同级的文件夹
    if(!QDir(m_localDataPath).isAbsolute())
    {
        m_localDataPath = QFileInfo(ini_path).path() + "/" + m_localDataPath;
    }
    // 检查文件夹是否存在，不存在则创建
    if(!QDir(m_localDataPath).exists())
    {
        QDir().mkdir(m_localDataPath);
    }
    m_localTmpPath += m_localDataPath + "/tmp";
    if(!QDir(m_localTmpPath).exists())
    {
        QDir().mkdir(m_localTmpPath);
    }
}

QHostAddress Config::m_getServerAddress() const
{
    return m_serverAddress;
}

quint16 Config::m_getServerMsgPort() const
{
    return m_serverMsgPort;
}

float Config::m_getServerMaxConnectTime() const
{
    return m_serverMaxConnectTime;
}

QString Config::m_getLocalDataPath() const
{
    return m_localDataPath;
}

QString Config::m_getLocalTmpPath() const
{
    return m_localTmpPath;
}

QString Config::m_getLocalChatPicsPath() const
{
    return m_localChatPicsPath;
}

void Config::m_setLocalDbPath(const QString& db_name)
{
    m_localDbPath = m_getLocalAccountPath() + "/" + db_name;
    // 检查文件夹和.db文件是否存在，不存在则创建
    QFileInfo db_path_info(m_localDbPath);
    QString folder_path = db_path_info.absolutePath();
    if(!QDir(folder_path).exists())
    {
        QDir().mkpath(folder_path);
    }
    if(!QFile::exists(m_localDbPath))
    {
        QFile _db_file(m_localDbPath);
        if(_db_file.open(QIODevice::ReadWrite))
        {
            qDebug() << "create" << m_localDbPath << "successfully.";
            _db_file.close();
        }
        else
        {
            qDebug() << "create" << m_localDbPath << "failed.";
        }
    }
}

QString Config::m_getLocalDbPath() const
{
    return m_localDbPath;
}

void Config::m_setLocalAccountPath(const QString& account)
{
    m_localAccountPath = m_localDataPath + "/" + account;
    if(!QDir(m_localAccountPath).exists())
    {
        QDir().mkdir(m_localAccountPath);
    }
    m_localChatPicsPath += m_localAccountPath + "/chat_pics";
    if(!QDir(m_localChatPicsPath).exists())
    {
        QDir().mkdir(m_localChatPicsPath);
    }
}

QString Config::m_getLocalAccountPath() const
{
    return m_localAccountPath;
}

void Config::m_setLoginClientInfo(const sttClientInfo &client_info)
{
    m_loginClientInfo = client_info;
}

sttClientInfo Config::m_getLoginClientInfo() const
{
    return m_loginClientInfo;
}

quint32 Config::m_getLoginClientId() const
{
    return m_loginClientInfo.id;
}

void Config::m_setLoginClientHead(const QString &head_path)
{
    m_loginClientHead = head_path;
}

QString Config::m_getLoginClientHead() const
{
    return m_loginClientHead;
}

void Config::m_debugPrint() const
{
    qDebug() << this->m_getLocalDataPath();
    qDebug() << this->m_getServerAddress();
    qDebug() << this->m_getServerMsgPort();
    qDebug() << this->m_getServerMaxConnectTime();
}
