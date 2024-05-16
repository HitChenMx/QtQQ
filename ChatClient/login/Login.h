#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <QLineEdit>
#include <QDebug>
#include <QMessageBox>
#include <QDateTime>
#include <QSettings>
#include <QSharedPointer>
#include <QThread>
#include <QByteArray>
#include <QDataStream>
#include <QRect>
#include <QPropertyAnimation>
#include <QMap>
#include <QDesktopWidget>
#include <QDesktopWidget>
#include "tcpsocketmanager.h"
#include "Config.h"
#include "LocalDatabase.h"

namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = 0);
    ~Login();

    QSharedPointer<TcpSocketManager> m_getSocketManager() const;    // 获取socket管理对象

private:
    Ui::Login *ui;

    bool m_connect_flag;                                    // 指示与服务端是否已连接
    bool m_loginLoad_flag;                                  // 指示是否处在登录加载界面
    QSharedPointer<TcpSocketManager> m_socketManager;       // socket管理对象

    void m_socketManager_init(QHostAddress address, quint16 port, float max_connect_time);

signals:
    void signal_sendMessage(const QByteArray message);              // 信号：发送字节流

private slots:
    void slot_connectionFailed();       // 连接服务端失败
    void slot_edtRemoveIllegal(const QString &text);                // 禁止用户输入非法字符：空格
    void slot_btnRegisterPage_clicked();                            // 按下“注册账号”
    void slot_btnReturn_clicked();                                  // 按下“返回”
    void slot_btnRegister_clicked();                                // 按下“注册”
    void slot_btnLogin_checkEnable();                               // 检查“登录”是否有效
    void slot_btnRegister_checkEnable();                            // 检查“注册”是否有效
    void slot_btnLogin_clicked();                                   // 按下“登录”
    void slot_btnCancelLogin_clicked();                             // 按下“取消”，取消登录

    void slot_registerSuccess();                            // 注册成功
    void slot_registerFailed(const QString reason);         // 注册失败
    void slot_loginSuccess(const sttClientInfo client_info, const QMap<quint32, sttGroupInfo> all_group_info);// 登录成功
    void slot_loginFailed(const QString reason);            // 登录失败
};

#endif // LOGIN_H
