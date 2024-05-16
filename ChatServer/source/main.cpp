#include "mainwindow.h"
#include <QApplication>
#include <QCoreApplication>
#include <QDir>
#include "log.h"
#include "global.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QString _current_path = QCoreApplication::applicationDirPath();
    QString setup_path = _current_path.split("ChatServer").at(0) + "ChatServer" + "/setup.ini";
    Config::getInstance()->m_readIni(setup_path);
    Config::getInstance()->m_setUserFilePath(QCoreApplication::applicationDirPath().split("ChatServer").at(0) + "ChatServer" + "/UserFile");
    //输入一个日志文件名字
    // logSysInit(_current_path.split("ChatServer").at(0) + "ChatServer" + "/log.txt");

    MainWindow w(nullptr);
    w.show();

    return a.exec();
}
