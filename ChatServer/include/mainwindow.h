#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QMessageBox>
#include <QList>
#include <QHash>
#include <QStringListModel>
#include <QItemSelectionModel>
#include <QDebug>
#include <QHostInfo>
#include <QSettings>
#include <QDesktopWidget>
#include "global.h"
#include "tcpservermanager.h"
#include "databasemanager.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    QLabel* m_listenState;          // 界面上显示监听状态
    QLabel* m_socketState;          // 界面上显示socket状态

    QStringListModel* m_modelClient;                    // 客户列表的模型
    TcpServerManager* m_serverManager;                  // TCP服务端管理对象

    bool m_init();                  // 初始化
    bool m_serverManager_init();    // TCP服务端管理对象进行初始化
    QString getLocalIP();           // 得到本机IPv4地址

private slots:
    void slot_action_startListen_triggered();       // 点击“开始监听”
    void slot_action_stopListen_triggered();        // 点击“停止监听”
    void slot_action_clearOutput_triggered();       // 点击“清空文本框”
    void slot_action_exit_triggered();              // 点击“退出”
    void slot_btnSendMessage_clicked();             // 点击“发送”，向客户端发送消息
    void slot_lstClientView_clicked(const QModelIndex& index);             // 点击了客户在线列表中的某一项

    void slot_clientDatabaseConnectFailed(qintptr socketDescriptor);
    void slot_clientConnected(const QHostAddress address, const quint16 port);                    // 有用户成功连接
    void slot_clientDisconnected(const QHostAddress address, const quint16 port);                 // 有用户断开连接
    void slot_receiveClientMessage(const QHostAddress address, const quint16 port, const QByteArray message);      // 接收到用户发来的消息
    void slot_sendClientMessageFinished(const QHostAddress address, const quint16 port, const quint64 send_bytes);      // 向用户发送消息完毕
};

#endif // MAINWINDOW_H
