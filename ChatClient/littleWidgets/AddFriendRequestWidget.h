#ifndef ADDFRIENDREQUESTWIDGET_H
#define ADDFRIENDREQUESTWIDGET_H

#include <QWidget>
#include <QMap>
#include <QString>
#include <QSharedPointer>
#include <QPixmap>
#include <QPainter>
#include "Config.h"
#include "global.h"
#include "LocalDatabase.h"
#include "Helper.h"

namespace Ui {
class AddFriendRequestWidget;
}

class AddFriendRequestWidget : public QWidget
{
    Q_OBJECT

public:
    explicit AddFriendRequestWidget(QWidget *parent = 0, const sttClientInfo& client_info = sttClientInfo(),
                                    const QPixmap& head_pic = QPixmap());
    ~AddFriendRequestWidget();
    QPixmap m_getHeadPic() const;              // 获取头像路径

private:
    Ui::AddFriendRequestWidget *ui;

    sttClientInfo m_clientInfo;                 // 界面上需要显示的用户信息
    QMap<quint32, QString> m_allGroupNames;     // 分组id和分组名称
    QPixmap m_headPic;                          // 头像

signals:
    void signal_tryAddFriend(const quint32 send_id, const sttClientInfo rcv_client_info,
                             const QString verify_msg, const quint32 which_group_id);       // 信号：按下“发送”，尝试添加好友

public slots:
    void slot_updateGroupNames();     // 更新分组选择

private slots:
    void slot_btnSend_clicked();        // 按下“发送”
    void slot_btnCancel_clicked();      // 按下“取消”
};

#endif // ADDFRIENDREQUESTWIDGET_H
