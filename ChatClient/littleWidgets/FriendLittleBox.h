#ifndef FRIENDLITTLEBOX_H
#define FRIENDLITTLEBOX_H

#include <QWidget>
#include <QString>
#include <QPixmap>
#include <QPainter>
#include <QTextCodec>
#include <QDebug>
#include "Helper.h"

namespace Ui {
class FriendLittleBox;
}

class FriendLittleBox : public QWidget
{
    Q_OBJECT

public:
    enum OnlineState{
        Online,
        Offline
    };

    explicit FriendLittleBox(QWidget *parent = 0, quint32 friend_id=-1, QString head_path = ":/qqicons/qrc/QQicon.svg", QString name = "",
                             FriendLittleBox::OnlineState online_state = Offline, QString signature = "", int size = 70);
    ~FriendLittleBox();

//    QSize sizeHint() const override
//    {
//        return QSize(362, 92);
//    }
    void resizeEvent(QResizeEvent* event) override;

    QString m_getFriendName() const;                                // 获取朋友的名字
    quint32 m_getFriendID() const;                                  // 获取朋友的id
    void m_setOnlineState(OnlineState online_state);                // 设置在线状态
    FriendLittleBox::OnlineState m_getOnlineState() const;          // 获取在线状态
    void m_setFriendName(const QString& name);                      // 设置朋友的名字
    void m_setFriendSignature(const QString& signature);            // 设置朋友的签名
    void m_setFriendHead(const QString& head_path);                 // 设置朋友的头像

private:
    Ui::FriendLittleBox *ui;
    QString m_name;
    OnlineState m_onlineState;
    QString m_signature;
    QSize m_headSize;
    quint32 m_friendID;

};

#endif // FRIENDLITTLEBOX_H
