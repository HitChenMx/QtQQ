#ifndef FRIENDLISTWIDGET_H
#define FRIENDLISTWIDGET_H

#include <QObject>
#include <QWidget>
#include <QString>
#include <QLabel>
#include <QFont>
#include <QPushButton>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QPainter>
#include <QPixmap>
#include <QHash>
#include <QStringList>
#include <QMenu>
#include <QTextCodec>
#include <QInputDialog>
#include <QMessageBox>
#include <QDebug>
#include <QResizeEvent>
#include "global.h"
#include "FriendLittleBox.h"
#include "LocalDatabase.h"
#include "AssembleBytes.h"

class FriendListWidget : public QTreeWidget
{
    Q_OBJECT
public:
    explicit FriendListWidget(QWidget *parent = nullptr);
    ~FriendListWidget();

    void contextMenuEvent(QContextMenuEvent* event);        // 右键菜单
    bool m_setFriendOnlineState(const quint32 friend_id, FriendLittleBox::OnlineState online_state);    // 设置某个好友的在线状态
    FriendLittleBox::OnlineState m_getFriendOnlineState(const quint32 friend_id) const;                 // 获取某个好友的在线状态
    bool m_setFriendBoxInfo(const quint32 friend_id, const QString name, const QString signature);      // 设置某个好友的朋友框显示信息
    void m_addFriendBox2group(const sttFriendInfo friend_info,
                              const FriendLittleBox::OnlineState online_state = FriendLittleBox::Offline);      // 添加朋友框到一个分组里
    void m_queryAllFriendOnlineState();                                                                 // 向服务端查询所有好友的在线状态
    void m_queryAllFriendHeadPic();                     // 向服务端查询所有好友的头像
    void m_querySingleFriendHeadPic(const quint32 user_id);       // 向服务端查询某个用户的头像
    void m_setFriendHead(const quint32 friend_id, const QString head_path);     // 设置某个好友的头像
    void m_moveFriendToGroup(const quint32 friend_id, const quint32 group_id);  // 移动好友至指定分组


private:
    QPixmap m_rightArrow;
    QPixmap m_downArrow;
    QMenu* m_groupMenu;                                 // 分组相关的右键菜单
    QTreeWidgetItem* m_currentGroupItem;                // 当前鼠标点击的分组项
    QHash<quint32, QTreeWidgetItem*> m_groups;          // 保存group_id和QTreeWidgetItem*的对应关系
    QHash<quint32, FriendLittleBox*> m_friendID2box;    // 好友的id对应的朋友框

    void resizeEvent(QResizeEvent* event) override;
    void m_updateWidgetSize();
    void m_init_groups();                                  // 初始化分组
    void m_addFriendBox2group(QTreeWidgetItem* group, const sttFriendInfo friend_info,
                              const FriendLittleBox::OnlineState online_state = FriendLittleBox::Offline);     // 添加朋友框到一个分组里
    QTreeWidgetItem* m_createGroup(const quint32& group_id, const QString& group_name, const QString count_text);        // 创建一个分组

signals:
    void signal_friendBox_clicked(const quint32 friend_id);     // 信号：点击了朋友框
    void signal_addGroup_query(const quint32 user_id, const QString group_name);       // 信号：添加分组请求
    void signal_renameGroup_query(const quint32 user_id, const quint32 group_id, const QString new_name);      // 信号：重命名分组请求
    void signal_queryOnlineState(const quint32 friend_id);                              // 信号：查询好友在线状态
    void signal_queryHeadPic(const quint32 friend_id);                                    // 信号：查询用户头像

public slots:
    void slot_addGroup_query();     // 添加分组
    void slot_addGroup_success(const quint32 new_group_id, const QString group_name);
    void slot_addGroup_failed();
    void slot_renameGroup();        // 重命名分组
    void slot_deleteGroup();        // 删除分组
    void slot_itemClicked(QTreeWidgetItem *item, int column);
};






class ExpandButton : public QPushButton
{
    Q_OBJECT
public:
    explicit ExpandButton(QWidget *parent = nullptr);
    ~ExpandButton();

    void m_setUnreadNum(int num);           // 设置未读消息个数为num
    void m_setUnreadNum();
    void m_appendUnreadNum(int num);        // 未读消息个数加num

private:
    void paintEvent(QPaintEvent* event) override;

    int m_unreadNum;        // 未读消息的计数
    QLabel* m_unreadPic;
};










#endif // FRIENDLISTWIDGET_H
