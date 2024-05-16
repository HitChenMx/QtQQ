#ifndef FRIENDNOTICEBOX_H
#define FRIENDNOTICEBOX_H

#include <QWidget>
#include <QPainter>
#include <QLabel>
#include <QTextCodec>
#include <QString>
#include <QFontMetrics>
#include <QDateTime>
#include <QPixmap>
#include <QDebug>
#include "global.h"
#include "PersonDataShow.h"
#include "LocalDatabase.h"
#include "AssembleBytes.h"
#include "Helper.h"

namespace Ui {
class FriendNoticeBox;
}

class FriendNoticeBox : public QWidget
{
    Q_OBJECT

public:
    explicit FriendNoticeBox(const sttClientInfo& client_info,
                             const bool& client_is_sender,
                             const QString& verify_msg,
                             quint32 group_id,
                             QWidget *parent = 0,
                             const QPixmap& head_pic = QPixmap()
                             );
    ~FriendNoticeBox();

    void m_setHeadPic(const QString& head_path);            // 设置头像
    void m_setVerifyMsg(const QString& verify_msg);         // 设置显示的验证消息
    void m_setTime(const QDateTime& date_time);             // 设置通知时间
    void m_setIsReadOrNot(const bool& is_read);             // 设置当前消息通知是否已读
    bool m_getIsRead() const;                               // 获取当前消息通知是否已读
    void m_setReplytext(const QString& text);               // 设置显示的回复结果
    quint32 m_getGroupId() const;                           // 获取group id
    void m_setGroupId(quint32 group_id);                    // 设置group id
    quint32 m_getClientId() const;                          // 获取对方的id
    bool m_getIsReplyed() const;                            // 获取当前好友通知是否已回复
    bool m_getIsOther2Self() const;                         // 获取好友通知的流向，即是否是对方请求添加自己为好友

private:
    Ui::FriendNoticeBox *ui;
    QPixmap m_headPic;              // 界面上的用户的头像
    sttClientInfo m_clientInfo;     // 界面上的用户的信息，也即对方的用户信息（无论是自己发起的添加好友请求，还是对方发给自己的）
    QString m_verifyMsg;            // 验证消息
    bool m_clientIsSender;          // true：对方请求添加自己为好友，false：自己请求添加对方为好友
    quint32 m_groupId;              // 如果是对方请求添加自己为好友，那么就是对方选择放入的分组id；
                                    // 如果是自己请求添加对方为好友，那么就是自己选择放入的分组id
    bool m_isRead;                  // 当前消息通知是否已读
    QLabel* m_lblReplyShow;         // 取代btnReply的位置，通知结果：“已同意”、“已拒绝”、“等待验证”
    bool m_isReplyed;               // 当前消息通知是否已回复，即是否为“已同意”或“已拒绝”

    void paintEvent(QPaintEvent* event) override;
    void resizeEvent(QResizeEvent* event) override;
    bool eventFilter(QObject *watched, QEvent *event) override;
    void m_sendReplyBytesToServer(bool reply_is_agree);

signals:
    void signal_replyAddFriendRequest(const quint32 who_reply, const quint32 reply_to_who,
                                      const bool reply_agree,
                                      const quint32 group_of_who_reply, const quint32 group_of_reply_to_who);        // 信号：回复添加好友请求，bool：1表示同意，0表示拒绝

private slots:
    void slot_replyAgree_clicked();
    void slot_replyReject_clicked();
    void slot_showClientInfo();
};

#endif // FRIENDNOTICEBOX_H
