#include "FriendNoticeWidget.h"
#include "ui_FriendNoticeWidget.h"

FriendNoticeWidget::FriendNoticeWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FriendNoticeWidget),
    m_friendNoticeVLayout(nullptr),
    m_noticeUserIds(QVector<quint32>())
{
    ui->setupUi(this);

    // 好友通知垂直布局
    m_friendNoticeVLayout = new QVBoxLayout(ui->wFriendNoticeList);
    m_friendNoticeVLayout->setSpacing(20);
    m_friendNoticeVLayout->setContentsMargins(40, 0, 40, 10);
    QSpacerItem* noticeListVSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);
    m_friendNoticeVLayout->addItem(noticeListVSpacer);
    ui->stkwNoticeResult->setCurrentIndex(0);

    connect(ui->btnClearFriendNotice, &QPushButton::clicked, this, &FriendNoticeWidget::slot_btnClearFriendNotice_clicked);
}

FriendNoticeWidget::~FriendNoticeWidget()
{
    delete ui;
}

QVector<quint32> FriendNoticeWidget::m_getNoticeUserIds() const
{
    return m_noticeUserIds;
}

void FriendNoticeWidget::m_setNoticeUserHead(const quint32& user_id, const QString &head_path)
{
    if(!m_noticeUserIds.contains(user_id))
        return;
    if(head_path.isEmpty() || !QFile(head_path).exists())
        return;

    // 需要把所有与该用户有关的通知都更新头像
    int user_num = m_noticeUserIds.count(user_id);
    int find_num = 0;
    for(int i=0; i<m_friendNoticeVLayout->count(); ++i)
    {
        QLayoutItem* cur_item = m_friendNoticeVLayout->itemAt(i);
        if(cur_item)
        {
            FriendNoticeBox* cur_notice_box = qobject_cast<FriendNoticeBox*>(cur_item->widget());
            if(cur_notice_box)
            {
                quint32 _cur_client_id = cur_notice_box->m_getClientId();
                if(_cur_client_id == user_id)
                {
                    cur_notice_box->m_setHeadPic(head_path);
                    ++find_num;
                    if(find_num >= user_num)
                    {
                        break;
                    }
                }
            }
        }
    }
}

void FriendNoticeWidget::m_replaceIntoFriendNoticeBox(const quint32& send_id, const sttClientInfo& client_info,
                                                      const QString& verify_msg, const quint32& group_id,
                                                      const QPixmap& head_pic)
{
    bool _other2Self = false;
    quint32 self_id = Config::getInstance()->m_getLoginClientId();
    if(send_id == self_id)                  // 自己发送添加好友请求给对方
    {
        _other2Self = false;
    }
    else if(send_id == client_info.id)      // 对方发送添加好友请求给自己
    {
        _other2Self = true;
    }
    else
        return;

    ui->stkwNoticeResult->setCurrentIndex(1);
    // 查询是否已有该用户的好友通知
    FriendNoticeBox* friend_new_notice = nullptr;
    for(int i=0; i<m_friendNoticeVLayout->count(); ++i)
    {
        QLayoutItem* cur_item = m_friendNoticeVLayout->itemAt(i);
        if(cur_item)
        {
            FriendNoticeBox* cur_notice_box = qobject_cast<FriendNoticeBox*>(cur_item->widget());
            if(cur_notice_box)
            {
                quint32 _cur_client_id = cur_notice_box->m_getClientId();
                // 条件：是该用户的好友通知，并且没有回复，并且流向也一致
                if(_cur_client_id==client_info.id && cur_notice_box->m_getIsReplyed()==false && cur_notice_box->m_getIsOther2Self()==_other2Self)
                {
                    friend_new_notice = cur_notice_box;
                    break;
                }
            }
        }
    }
    if(friend_new_notice != nullptr)            // 如果已有该用户的好友通知，就更新验证消息、通知时间、添加进哪个分组
    {

        friend_new_notice->m_setVerifyMsg(verify_msg);
        friend_new_notice->m_setTime(QDateTime::currentDateTime());
        friend_new_notice->m_setGroupId(group_id);
        if(friend_new_notice->m_getIsRead() == true)
        {
            // 如果当前消息已读，才让未读好友通知+1
            emit signal_newUnreadNotice();
        }
    }
    else                                       // 否则新增好友通知
    {
        QPixmap new_head_pic = head_pic;
        if(new_head_pic.isNull())
        {
            new_head_pic.load(":/qqicons/qrc/QQicon.svg");
            new_head_pic = pixmaptoRound(new_head_pic, QSize(70, 70));
        }
        friend_new_notice = new FriendNoticeBox(client_info, _other2Self, verify_msg, group_id, this, new_head_pic);
        // 对方发给自己的好友请求，就是未读消息；而自己发给对方的好友请求，就不显示未读消息了
        if(_other2Self)
        {
            emit signal_newUnreadNotice();
        }
        friend_new_notice->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        m_friendNoticeVLayout->insertWidget(m_friendNoticeVLayout->count()-1, friend_new_notice);
        m_noticeUserIds.append(client_info.id);
    }
}

void FriendNoticeWidget::m_setAllNoticeAlreadyRead()
{
    for(int i=0; i<m_friendNoticeVLayout->count(); ++i)
    {
        QLayoutItem* cur_item = m_friendNoticeVLayout->itemAt(i);
        if(cur_item)
        {
            FriendNoticeBox* cur_notice_box = qobject_cast<FriendNoticeBox*>(cur_item->widget());
            if(cur_notice_box)
            {
                cur_notice_box->m_setIsReadOrNot(true);
            }
        }
    }
}

void FriendNoticeWidget::slot_btnClearFriendNotice_clicked()
{
    QMessageBox question_box;
    question_box.setIcon(QMessageBox::Question);
    question_box.setWindowIcon(QIcon(":/qqicons/qrc/QQicon.svg"));
    question_box.setText(QStringLiteral("确定要清空所有好友通知吗？"));
    question_box.setWindowTitle(QStringLiteral("清空好友通知"));
    question_box.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    question_box.setDefaultButton(QMessageBox::No);

    question_box.button(QMessageBox::Yes)->setText(QStringLiteral("确定"));
    question_box.button(QMessageBox::No)->setText(QStringLiteral("取消"));

    int reply = question_box.exec();
    if(reply == QMessageBox::Yes)
    {
        m_noticeUserIds.clear();
        // 先清除掉布局中所有的控件
        QLayoutItem* cur_child;
        while((cur_child = m_friendNoticeVLayout->takeAt(0)) != nullptr)
        {
            QWidget* cur_widget = cur_child->widget();
            if(cur_widget)
            {
                cur_widget->setParent(nullptr);
                cur_widget->deleteLater();
                cur_widget = nullptr;
            }
            delete cur_child;
            cur_child = nullptr;
        }

        // 然后添加一个弹簧
        QSpacerItem* noticeListVSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);
        m_friendNoticeVLayout->addItem(noticeListVSpacer);
        ui->stkwNoticeResult->setCurrentIndex(0);
    }
}

void FriendNoticeWidget::slot_receiveRejectAddFriendRequest(const quint32 rcv_id, const quint32 send_id, const quint32 rcv_group_id)
{
    if(rcv_id != Config::getInstance()->m_getLoginClientId())
        return;
    // 把对应的好友通知设置为“已拒绝”
    for(int i=0; i<m_friendNoticeVLayout->count(); ++i)
    {
        QLayoutItem* cur_item = m_friendNoticeVLayout->itemAt(i);
        if(cur_item)
        {
            FriendNoticeBox* cur_notice_box = qobject_cast<FriendNoticeBox*>(cur_item->widget());
            if(cur_notice_box)
            {
                if(cur_notice_box->m_getIsOther2Self() == false)
                {
                    quint32 _user_id = cur_notice_box->m_getClientId();
                    quint32 _self_group_id = cur_notice_box->m_getGroupId();
                    if(_user_id==send_id && _self_group_id==rcv_group_id)
                    {
                        cur_notice_box->m_setReplytext(QStringLiteral("已拒绝"));
                    }
                }
            }
        }
    }
}

void FriendNoticeWidget::slot_receiveAgreeAddFriendRequest(const quint32 rcv_id, const quint32 rcv_select_group_id, const sttFriendInfo new_friend_info)
{
    if(rcv_id != Config::getInstance()->m_getLoginClientId())
        return;

    // 把对应的好友通知设置为“已同意”
    for(int i=0; i<m_friendNoticeVLayout->count(); ++i)
    {
        QLayoutItem* cur_item = m_friendNoticeVLayout->itemAt(i);
        if(cur_item)
        {
            FriendNoticeBox* cur_notice_box = qobject_cast<FriendNoticeBox*>(cur_item->widget());
            if(cur_notice_box)
            {
                if(cur_notice_box->m_getIsOther2Self() == false)
                {
                    quint32 _user_id = cur_notice_box->m_getClientId();
                    if(_user_id==new_friend_info.id)
                    {
                        cur_notice_box->m_setReplytext(QStringLiteral("已同意"));
                    }
                }
            }
        }
    }

    LocalDatabase::getInstance()->m_replaceIntoFriendInfo(new_friend_info);
    emit signal_newFriend(new_friend_info.id);
}
