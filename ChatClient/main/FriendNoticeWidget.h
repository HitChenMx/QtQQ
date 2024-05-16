#ifndef FRIENDNOTICEWIDGET_H
#define FRIENDNOTICEWIDGET_H

#include <QWidget>
#include <QVector>
#include <QVBoxLayout>
#include <QMessageBox>
#include "Config.h"
#include "FriendNoticeBox.h"

namespace Ui {
class FriendNoticeWidget;
}

class FriendNoticeWidget : public QWidget
{
    Q_OBJECT

public:
    explicit FriendNoticeWidget(QWidget *parent = 0);
    ~FriendNoticeWidget();
    QVector<quint32> m_getNoticeUserIds() const;        // 获取好友通知的所有用户id
    void m_setNoticeUserHead(const quint32& user_id, const QString& head_path);     // 设置某个用户的头像

    // 检查是否存在指定用户的好友通知，如果不存在，就创建一个好友通知框；如果存在，就更新验证消息、通知时间、添加进哪个分组
    void m_replaceIntoFriendNoticeBox(const quint32& send_id, const sttClientInfo& client_info,
                                      const QString& verify_msg, const quint32& group_id,
                                      const QPixmap& head_pic = QPixmap());
    void m_setAllNoticeAlreadyRead();           // 把所有的好友通知全部设置为已读

private:
    Ui::FriendNoticeWidget *ui;
    QVBoxLayout* m_friendNoticeVLayout;         // 好友通知的垂直布局
    QVector<quint32> m_noticeUserIds;           // 记录有哪些用户的好友通知

signals:
    void signal_newUnreadNotice();          // 新的未读通知
    void signal_newFriend(const quint32 friend_id);     // 新的好友

public slots:
    void slot_receiveRejectAddFriendRequest(const quint32 rcv_id, const quint32 send_id, const quint32 rcv_group_id);
    void slot_receiveAgreeAddFriendRequest(const quint32 rcv_id, const quint32 rcv_select_group_id, const sttFriendInfo new_friend_info);

private slots:
    void slot_btnClearFriendNotice_clicked();       // 清空好友通知
};

#endif // FRIENDNOTICEWIDGET_H
