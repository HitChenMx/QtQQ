#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSharedPointer>
#include <QDesktopWidget>
#include <QFile>
#include "TcpSocketManager.h"
#include "FriendLittleBox.h"
#include "LeftBar.h"
#include "SearchFriendWidget.h"
#include "AssembleBytes.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QSharedPointer<TcpSocketManager> socket_manager, QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QSharedPointer<TcpSocketManager> m_socketManager;       // socket管理对象
    SearchFriendWidget* m_searchFriend;                     // 搜索用户界面

    void m_init();                      // 初始化

signals:
    void signal_closeSocketThread();                                // 信号：关闭socket和socket所在的线程
    void signal_updateGroupNames();                                 // 信号：分组名字已发生更新

public slots:
    void slot_launchAddFriendRequest(const quint32 send_id, const sttClientInfo rcv_client_info,    // 把自己发送的添加好友请求添加到好友通知页面
                                     const QString verify_msg, const quint32 which_group_id);

private slots:
    void slot_receiveChatMessage(const quint32 send_id, const quint32 rcv_id, const QString chat_msg);      // 收到聊天消息
    void slot_updateFriendInfo(const quint32& friend_id, const sttFriendInfo& friend_update_info);          // 更新好友的个人资料
    void slot_btnAddFriend_clicked();           // 添加好友
    void slot_btnFriendsInfo_clicked();         // 打开好友通知页面
    void slot_receiveAddFriendRequest(const quint32 rcv_id, const sttClientInfo send_user_info,     // 收到添加好友请求，负责更新该通知到好友通知页面
                                      const QString verify_msg, const quint32 group_id);
    void slot_receiveUserHeadPic(const quint32 user_id, const QString pic_path);                    // 收到用户头像
    void slot_receiveChatPicture(const quint32 send_id, const quint32 rcv_id, const QString chat_pic_path);     // 收到聊天图片

};

#endif // MAINWINDOW_H
