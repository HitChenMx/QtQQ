#ifndef FRIENDINFOWIDGET_H
#define FRIENDINFOWIDGET_H

#include <QWidget>
#include <QPainter>
#include <QMap>
#include "FriendLittleBox.h"
#include "LocalDatabase.h"
#include "AssembleBytes.h"
#include "Helper.h"

namespace Ui {
class FriendInfoWidget;
}

class FriendInfoWidget : public QWidget
{
    Q_OBJECT

public:
    explicit FriendInfoWidget(QWidget *parent = 0);
    ~FriendInfoWidget();

    void m_setChatFriend(const quint32& friend_id, const FriendLittleBox::OnlineState& online_state);          // --- 设置是哪个聊天好友的信息界面，刷新好友信息 ---
    quint32 m_getFriendId() const;          // 获取当前信息界面所属的好友id
    void m_setFriendOnlineState(const quint32& friend_id, const FriendLittleBox::OnlineState& online_state);    // 设置在线状态

private:
    Ui::FriendInfoWidget *ui;
    quint32 m_friendId;                 // 当前页面的好友id
    QMap<quint32, QString> m_allGroupNames;     // 分组id和分组名称

    void paintEvent(QPaintEvent* event) override;

signals:
    void signal_reqOpenChatWithFriend(const quint32 friend_id);     // 信号：请求打开与该好友的聊天页面
    void signal_reqMoveFriendToGroup(const quint32 user_id, const quint32 friend_id, const quint32 group_id);       // 信号：请求把该好友移动至指定的分组中

public slots:
    void slot_updateGroupNames();       // 更新分组

private slots:
    void slot_cmbFriendGroup_currentIndexChanged(int index);
};

#endif // FRIENDINFOWIDGET_H
