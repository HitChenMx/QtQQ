#ifndef SEARCHUSERLITTLEBOX_H
#define SEARCHUSERLITTLEBOX_H

#include <QWidget>
#include <QDebug>
#include <QString>
#include <QPixmap>
#include <QPainter>
#include <QSharedPointer>
#include <QMap>
#include "global.h"
#include "AddFriendRequestWidget.h"
#include "AssembleBytes.h"
#include "Helper.h"

namespace Ui {
class SearchUserLittleBox;
}


class SearchUserLittleBox : public QWidget
{
    Q_OBJECT

public:
    explicit SearchUserLittleBox(QWidget *parent = 0, const sttFriendInfo user_info = sttFriendInfo(),
                                 const QString search_text = QString(), const QString head_path = ":/qqicons/qrc/QQicon.svg");
    ~SearchUserLittleBox();

    quint32 m_getFriendId() const;      // 获取当前widget的用户id
    void m_setHeadPic(const QString& head_path);    // 设置头像

private:
    Ui::SearchUserLittleBox *ui;
    const QString m_searchText;               // 搜索文本
    const sttFriendInfo m_userInfo;           // 当前widget所显示的用户信息
    QPixmap m_headPic;                        // 头像
    bool m_mouseIn;                           // 鼠标是否移入当前widget

    bool event(QEvent *event) override;
    void paintEvent(QPaintEvent* event) override;

signals:
    void signal_sendMsgToFriend(const quint32 friend_id);       // 信号：与搜索到的用户进行聊天

private slots:
    void slot_btnAddFriend_clicked();        // 点击“添加”
    void slot_btnSendMessage_clicked();      // 点击“发消息”
};

#endif // SEARCHUSERLITTLEBOX_H
