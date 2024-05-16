#include "global.h"


Config* Config::m_instance = nullptr;
QMutex Config::m_mutex;

Config::Config(QObject *parent) :
    QObject(parent),
    m_iniPath(QString())
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
    // 读取配置文件
    m_iniPath = ini_path;
    qDebug() << QString("read setup file: %1").arg(m_iniPath);
    QSettings _setting(m_iniPath, QSettings::IniFormat);

    m_dbInfo.host_name = _setting.value("Database/HostName").toString();
    m_dbInfo.user_name = _setting.value("Database/UserName").toString();
    m_dbInfo.password = _setting.value("Database/Password").toString();
    m_dbInfo.database_name = _setting.value("Database/DatabaseName").toString();
}

void Config::m_setUserFilePath(const QString &path)
{
    m_userFilePath = path;
}

QString Config::m_getUserFilePath() const
{
    return m_userFilePath;
}

sttDatabaseInfo Config::m_getDatabaseInfo() const
{
    return m_dbInfo;
}
