#ifndef CHATMESSAGEWIDGET_H
#define CHATMESSAGEWIDGET_H

#include <QWidget>
#include <QFontMetrics>
#include <QDateTime>
#include <QVector>
#include <QFileDialog>
#include <QMessageBox>
#include "Config.h"
#include "LocalDatabase.h"
#include "AssembleBytes.h"

namespace Ui {
class ChatMessageWidget;
}

class ChatMessageWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ChatMessageWidget(QWidget *parent = 0);
    ~ChatMessageWidget();

    void m_setChatFriend(const quint32 friend_id);          // --- 设置和哪个聊天好友聊天 ---
    void m_showChatLogMsg();                                // 显示所有的聊天记录
    void m_showChatLogMsg(const int* const log_num);        // 显示最近的几条聊天记录


private:
    Ui::ChatMessageWidget *ui;
    quint32 m_friendId;

    void m_appendChatMsgToUI(const sttChatMsgInfo& chat_log);             // 在聊天界面添加一条聊天消息

signals:
    void signal_newMessage(const QDateTime time, const QString msg);      // 新的聊天消息（自己发送的和自己收到的都算是新消息）
    void signal_reqAsmSendChatMsg(const quint32 send_id, const quint32 rcv_id, const QString chat_msg);     // 请求组包：发送聊天消息
    void signal_reqAsmSendChatPic(const quint32 send_id, const quint32 rcv_id, const QString chat_pic_path);// 请求组包：发送聊天图片

private slots:
    void slot_btnChatMessageSend_clicked();         // 按下“发送”
    void slot_btnChatPicture_clicked();             // 发送聊天图片
};

#endif // CHATMESSAGEWIDGET_H
