#include "ChatBubbleList.h"

ChatBubbleList::ChatBubbleList(QWidget *parent) : QListWidget(parent)
{
    QFile style_scrollBar(":/setfile/setup/scrollbar.qss");
    QString qss_scrollBar = "";
    if(style_scrollBar.open(QFile::ReadOnly))
    {
        qss_scrollBar = style_scrollBar.readAll();
        style_scrollBar.close();
    }
    this->setStyleSheet(qss_scrollBar);
    this->setFocusPolicy(Qt::NoFocus);                          // 屏蔽焦点
    this->setSelectionMode(QAbstractItemView::NoSelection);     // 屏蔽选中

    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
}

void ChatBubbleList::resizeEvent(QResizeEvent *event)
{
    QListWidget::resizeEvent(event);

    // 当自己大小改变时，需要重设聊天气泡的大小
    for(int i=0; i<this->count(); ++i)
    {
        QListWidgetItem* cur_item = this->item(i);
        QWidget* cur_widget = this->itemWidget(cur_item);
        if(cur_widget)
        {
            ChatBubbleBox* cur_bubble_box = qobject_cast<ChatBubbleBox*>(cur_widget);
            if(cur_bubble_box)
            {
                cur_bubble_box->resize(this->width(), 0);
                QSize bubble_size = cur_bubble_box->m_setRect();
                cur_bubble_box->resize(bubble_size);
                cur_item->setSizeHint(bubble_size);
            }
        }
    }
}

QDateTime ChatBubbleList::m_getLastMsgTime() const
{
    QDateTime res(QDate(2000, 1, 1));       // 如果当前消息列表是空的，最后会返回一个默认值：2000年1月1日
    for(int i=this->count(); i>=0; --i)
    {
        QListWidgetItem* cur_item = this->item(i);
        QWidget* cur_widget = this->itemWidget(cur_item);
        if(cur_widget)
        {
            ChatBubbleBox* cur_bubble_box = qobject_cast<ChatBubbleBox*>(cur_widget);
            if(cur_bubble_box)
            {
                sttBubbleInfo _cur_bubble_info = cur_bubble_box->m_getBubbleInfo();
                res = _cur_bubble_info.time;
                break;
            }
        }
    }
    return res;
}

void ChatBubbleList::m_addChatBubbleBox(const sttChatMsgInfo& chat_log)
{
    sttBubbleInfo bubble_info;
    bubble_info.sender = (chat_log.send_id==Config::getInstance()->m_getLoginClientId())? Sender::Me : Sender::Peer;
    bubble_info.time = QDateTime::fromString(chat_log.time, Qt::ISODate);
    bubble_info.user_id = chat_log.send_id;
    bubble_info.msg_text = chat_log.message;
    bubble_info.msg_type = chat_log.msg_type;

    this->m_addBubbleBox(bubble_info);
}

void ChatBubbleList::m_addSystemNotice(const QDateTime &time, const QString &msg_text)
{
    sttBubbleInfo bubble_info;
    bubble_info.sender = Sender::System;
    bubble_info.time = time;
    bubble_info.msg_text = msg_text;
    bubble_info.msg_type = ChatType::IsTextMsg;

    this->m_addBubbleBox(bubble_info);
}

void ChatBubbleList::m_addBubbleBox(const sttBubbleInfo& bubble_info)
{
    ChatBubbleBox* new_bubble_box = new ChatBubbleBox(bubble_info, this);
    new_bubble_box->resize(this->width(), 0);
    QSize bubble_size = new_bubble_box->m_setRect();
    new_bubble_box->resize(bubble_size);

    QListWidgetItem* new_item = new QListWidgetItem(this);
    this->addItem(new_item);
    new_item->setSizeHint(bubble_size);
    this->setItemWidget(new_item, new_bubble_box);
}

//void ChatBubbleList::mouseMoveEvent(QMouseEvent *event)
//{

//}

//void ChatBubbleList::mousePressEvent(QMouseEvent *event)
//{
//    event->ignore();
//}
