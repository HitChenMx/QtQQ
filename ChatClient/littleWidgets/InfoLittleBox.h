#ifndef INFOLITTLEBOX_H
#define INFOLITTLEBOX_H

#include <QWidget>
#include <QSize>
#include <QString>
#include <QPixmap>
#include <QBitmap>
#include <QPainter>
#include <QFont>
#include <QDateTime>
#include <QMouseEvent>
#include <QDebug>
#include "Helper.h"

namespace Ui {
class InfoLittleBox;
}

class InfoLittleBox : public QWidget
{
    Q_OBJECT

public:
    explicit InfoLittleBox(QWidget *parent = 0, quint32 friend_id=-1, QString head_path = ":/qqicons/qrc/QQicon.svg",
                           QString name = "", QString message = "", QString date = "", int size = 70);
    ~InfoLittleBox();

    QSize sizeHint() const override
    {
        return QSize(362, 92);
    }

    QString m_getChatName() const;                  // 获取聊天对象的名字
    quint32 m_getFriendID() const;                  // 获取当前消息框的好友ID
    int m_getUnreadNum() const;                     // 获取当前消息框的未读消息个数
    void m_setChattingState(bool is_chatting);      // 设置当前聊天框是否正在聊天
    void m_clickSelf();                             // 发出signal_clicked信号
    void m_setUnreadPic(const int unread_num);      // 设置未读消息的红色圆框，自己指定未读消息个数
    void m_setUnreadPic();                          // 设置未读消息的红色圆框，未读消息个数自增1
    void m_setDate(const QDateTime date);           // 设置发消息的时间
    void m_setInfoPreview(const QString info);      // 设置消息预览
    void m_setChatName(const QString& name);        // 设置聊天对象的名字
    void m_setHeadPic(const QString& path);         // 设置聊天对象的头像

private:
    Ui::InfoLittleBox *ui;
    QString m_headPath;     // 头像路径
    QString m_name;         // 名字
    QString m_message;      // 消息
    QString m_date;         // 时间
    QSize m_headSize;       // 头像大小
    bool m_mouseIn;         // true：鼠标悬停在本控件内，false：鼠标移出本控件
    bool m_isChatting;      // 当前消息框是否正在聊天
    quint32 m_friendID;     // 朋友的id
    int m_unreadNum;        // 未读消息计数

    void m_init();
    void mousePressEvent(QMouseEvent* event) override;
    bool event(QEvent *event) override;
    void paintEvent(QPaintEvent* event) override;

signals:
    void signal_clicked();
};

#endif // INFOLITTLEBOX_H
