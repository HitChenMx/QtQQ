#ifndef CHATBUBBLELIST_H
#define CHATBUBBLELIST_H

#include <QWidget>
#include <QListWidget>
#include <QDateTime>
#include "Config.h"
#include "ChatBubbleBox.h"

class ChatBubbleList : public QListWidget
{
    Q_OBJECT
public:
    explicit ChatBubbleList(QWidget *parent = nullptr);
    QDateTime m_getLastMsgTime() const;                     // 获取上一条消息的时刻
    void m_addChatBubbleBox(const sttChatMsgInfo& chat_log);        // 添加一条聊天消息气泡
    void m_addSystemNotice(const QDateTime& time, const QString& msg_text);         // 添加一条系统通知

private:
    void m_addBubbleBox(const sttBubbleInfo& bubble_info);      // 添加气泡
    void resizeEvent(QResizeEvent* event) override;
//    void mouseMoveEvent(QMouseEvent* event) override;
//    void mousePressEvent(QMouseEvent* event) override;

signals:

public slots:
};

#endif // CHATBUBBLELIST_H
