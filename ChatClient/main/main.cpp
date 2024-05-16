#include "mainwindow.h"
#include <QApplication>
#include <QDebug>
#include "Config.h"
#include "Login.h"
#include "LocalDatabase.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // 读取配置文件
    Config::getInstance()->m_readIni(":/setfile/setup/setup.ini");
    // Config::getInstance()->m_debugPrint();

    Login* login = new Login;
    if(login->exec() == QDialog::Accepted)
    {
        LocalDatabase::getInstance();
        MainWindow w(login->m_getSocketManager());
        w.show();

        // login已无用，释放掉
        login->deleteLater();
        login = nullptr;
        return a.exec();
    }
    return 0;
}
