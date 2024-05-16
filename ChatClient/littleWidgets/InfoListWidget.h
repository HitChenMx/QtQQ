#ifndef INFOLISTWIDGET_H
#define INFOLISTWIDGET_H

#include <QObject>
#include <QWidget>
#include <QVBoxLayout>
#include <QPainter>
#include <QPixmap>
#include "InfoLittleBox.h"
#include "LocalDatabase.h"
#include "global.h"

class InfoListWidget : public QWidget
{
    Q_OBJECT
public:
    explicit InfoListWidget(QWidget *parent = nullptr);
    quint32 m_getFriendIdOfChatting() const;                                               // 获取当前正在聊天的用户id
    InfoLittleBox* m_addInfoboxIfNotExist(const int& insert_pos, const quint32& friend_id);          // 向消息列表插入一个消息框（如果不存在的话）
    void m_updateInfoBoxOfChatting(const QString& name, const QDateTime& date_time,
                                   const QString& info_preview);                           // 更新当前正在聊天的消息框的显示文本
    void m_updateInfoBoxOfChatting(const QDateTime& date_time,
                                   const QString& info_preview);                           // 更新当前正在聊天的消息框的显示文本
    void m_clickInfoLittleBox(const quint32& friend_id);                                   // 点击指定好友的消息框
    void m_doReceiveNewMessage(const quint32& friend_id, const QDateTime& date_time, const QString& chat_msg,
                               const bool& is_in_chat_page);                               // 收到了新的聊天消息
    void m_checkUpdateInfoBox(const quint32& friend_id);                                   // 检查是否有该好友的消息框，如果有，就更新该消息框显示的好友信息

private:
    QVBoxLayout* m_infoListVLayout;             // 消息列表的垂直布局
    InfoLittleBox* m_whoIsChatting;             // 保存是哪个消息框正在聊天

    void paintEvent(QPaintEvent* event) override;

signals:
    void signal_InfoLittleBox_clicked(const quint32 friend_id, const int already_read_msg_num);   // 信号：点击了消息框，好友id、点击后已读的消息个数

public slots:


private slots:
    void slot_InfoLittleBox_clicked();              // 点击消息框
};

#endif // INFOLISTWIDGET_H
