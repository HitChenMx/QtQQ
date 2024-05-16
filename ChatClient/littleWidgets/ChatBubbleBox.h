#ifndef CHATBUBBLEBOX_H
#define CHATBUBBLEBOX_H

#include <QWidget>
#include <QLabel>
#include <QStringList>
#include <QRect>
#include <QFontMetrics>
#include <QPixmap>
#include <QPainter>
#include <QDateTime>
#include <QResizeEvent>
#include <QDebug>
#include "Config.h"
#include "LocalDatabase.h"
#include "Helper.h"

enum Sender{
    Me,
    Peer,
    System
};

struct sttBubbleInfo{
    Sender sender;                      // 消息发送者是谁
    QString msg_text;                   // 消息文本
    quint32 user_id;                    // 消息发送者的id
    QDateTime time;                     // 这条消息的时刻
    ChatType::ChatMsgType msg_type;     // 消息的类型
};

class ChatBubbleBox : public QWidget
{
    Q_OBJECT
public:
    explicit ChatBubbleBox(const sttBubbleInfo& bubble_info, QWidget *parent = nullptr);
    sttBubbleInfo m_getBubbleInfo() const;
    QSize m_setRect();      // 获取合适大小的宽高

private:
    sttBubbleInfo m_bubbleInfo;         // 存储当前聊天气泡的各项信息
    QLabel* m_lblHeadPic;       // 头像控件
    QRect m_rectHeadPic;        // 头像框
    QRect m_rectBubbleFrame;    // 气泡框
    QRect m_rectBubbleText;     // 气泡里的文字框

    void paintEvent(QPaintEvent* event) override;
    QSize m_getRealTextSize(QString text) const;        // 得到显示文本的宽高
    QSize m_getContentSize(const ChatType::ChatMsgType& msg_type, QString* msg_text);

//    void mouseMoveEvent(QMouseEvent* event) override;
//    void mousePressEvent(QMouseEvent* event) override;

signals:

public slots:
};

#endif // CHATBUBBLEBOX_H
