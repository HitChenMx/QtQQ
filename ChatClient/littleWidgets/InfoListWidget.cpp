#include "InfoListWidget.h"

InfoListWidget::InfoListWidget(QWidget *parent) :
    QWidget(parent),
    m_infoListVLayout(nullptr),
    m_whoIsChatting(nullptr)
{
    m_infoListVLayout = new QVBoxLayout(this);
    m_infoListVLayout->setSpacing(0);
    m_infoListVLayout->setContentsMargins(0, 0, 0, 0);
    QSpacerItem* infoListVSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);
    m_infoListVLayout->addItem(infoListVSpacer);
}

quint32 InfoListWidget::m_getFriendIdOfChatting() const
{
    if(m_whoIsChatting)
        return m_whoIsChatting->m_getFriendID();
    // qDebug() << "Error from InfoListWidget::m_getFriendIdOfChatting: There are currently no users chatting.";
    return 0;
}

void InfoListWidget::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);

    if(m_infoListVLayout->count()<=1)
    {
        // 白色背景+qq图案
        QPainter painter(this);
        painter.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
        painter.save();
        painter.setPen(QColor(Qt::white));
        painter.setBrush(QColor(Qt::white));
        painter.drawRect(this->rect());
        painter.restore();

        QPixmap pic;
        QSize pic_size(128, 128);
        pic.load(":/qqicons/qrc/qq_pure.svg");
        pic = pic.scaled(pic_size, Qt::KeepAspectRatio, Qt::SmoothTransformation);
        QRect pic_rect(this->rect().center().x()-pic_size.width()/2, this->rect().center().y()-pic_size.height()/2,
                       pic_size.width(), pic_size.height());
        painter.drawPixmap(pic_rect, pic);
    }
    else
    {
        // 白色背景
        QPainter painter(this);
        painter.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
        painter.setPen(QColor(Qt::white));
        painter.setBrush(QColor(Qt::white));
        painter.drawRect(this->rect());
    }
}

InfoLittleBox* InfoListWidget::m_addInfoboxIfNotExist(const int& insert_pos, const quint32& friend_id)       // 向消息列表插入一个消息框（如果不存在的话）
{
    // 查询是否已有与该好友的消息框
    InfoLittleBox* friend_info_box = nullptr;
    for(int i=0; i<m_infoListVLayout->count(); ++i)
    {
        QLayoutItem* cur_item = m_infoListVLayout->itemAt(i);
        if(cur_item)
        {
            InfoLittleBox* cur_info_box = qobject_cast<InfoLittleBox*>(cur_item->widget());
            if(cur_info_box)
            {
                if(cur_info_box->m_getFriendID() == friend_id)
                {
                    friend_info_box = cur_info_box;
                    break;
                }
            }
        }
    }
    if(friend_info_box == nullptr)      // 如果不存在，就创建一个与该好友的消息框，并添加到指定位置
    {
        QString friend_name;
        LocalDatabase::getInstance()->m_queryFriendName(friend_id, &friend_name);
        QString head_path;
        LocalDatabase::getInstance()->m_queryFriendHead(friend_id, &head_path);
        if(head_path.isEmpty() || !QFile(head_path).exists())
            head_path = ":/qqicons/qrc/QQicon.svg";
        friend_info_box = new InfoLittleBox(this, friend_id, head_path,
                                            friend_name, "", "");
        connect(friend_info_box, &InfoLittleBox::signal_clicked, this, &InfoListWidget::slot_InfoLittleBox_clicked);
        int insert_real_pos = insert_pos;
        int info_nums = m_infoListVLayout->count();
        if(insert_real_pos<0 || insert_real_pos>info_nums)
        {
            insert_real_pos = info_nums-1;
        }

        friend_info_box->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        m_infoListVLayout->insertWidget(insert_real_pos, friend_info_box);
    }
    return friend_info_box;
}

void InfoListWidget::slot_InfoLittleBox_clicked()       // 点击消息框
{
    InfoLittleBox* object_sender = qobject_cast<InfoLittleBox*>(sender());
    if(m_whoIsChatting != nullptr)      // 把上一个消息框的聊天状态设置为false
    {
        m_whoIsChatting->m_setChattingState(false);
    }
    m_whoIsChatting = object_sender;
    m_whoIsChatting->m_setChattingState(true);
    emit signal_InfoLittleBox_clicked(m_whoIsChatting->m_getFriendID(), m_whoIsChatting->m_getUnreadNum());
    m_whoIsChatting->m_setUnreadPic(0);
}

void InfoListWidget::m_updateInfoBoxOfChatting(const QString &name, const QDateTime &date_time, const QString &info_preview)
{
    if(m_whoIsChatting)
    {
        m_whoIsChatting->m_setChatName(name);
        m_updateInfoBoxOfChatting(date_time, info_preview);
    }
}

void InfoListWidget::m_updateInfoBoxOfChatting(const QDateTime &date_time, const QString &info_preview)
{
    if(m_whoIsChatting)
    {
        m_whoIsChatting->m_setDate(date_time);
        m_whoIsChatting->m_setInfoPreview(info_preview);
    }
}

void InfoListWidget::m_clickInfoLittleBox(const quint32 &friend_id)
{
    InfoLittleBox* info_box_of_friend = m_addInfoboxIfNotExist(-1, friend_id);
    info_box_of_friend->m_clickSelf();
}

void InfoListWidget::m_doReceiveNewMessage(const quint32 &friend_id, const QDateTime &date_time, const QString &chat_msg,
                                           const bool& is_in_chat_page)
{
    InfoLittleBox* friend_info_box = m_addInfoboxIfNotExist(0, friend_id);
    friend_info_box->m_setDate(date_time);
    friend_info_box->m_setInfoPreview(chat_msg);
    if(QFileInfo(chat_msg).exists() && QFileInfo(chat_msg).isFile())
        friend_info_box->m_setInfoPreview(QStringLiteral("[图片]"));
    friend_info_box->m_setUnreadPic();

    if(friend_info_box == m_whoIsChatting && is_in_chat_page)
    {
        m_whoIsChatting->m_clickSelf();
    }
}

void InfoListWidget::m_checkUpdateInfoBox(const quint32 &friend_id)
{
    // 查询是否已有与该好友的消息框，如果有，就更新该好友的名字、头像
    for(int i=0; i<m_infoListVLayout->count(); ++i)
    {
        QLayoutItem* cur_item = m_infoListVLayout->itemAt(i);
        if(cur_item)
        {
            InfoLittleBox* cur_info_box = qobject_cast<InfoLittleBox*>(cur_item->widget());
            if(cur_info_box)
            {
                if(cur_info_box->m_getFriendID() == friend_id)
                {
                    QString friend_new_name;
                    bool _query_success = LocalDatabase::getInstance()->m_queryFriendName(friend_id, &friend_new_name);
                    if(_query_success)
                    {
                        cur_info_box->m_setChatName(friend_new_name);
                    }
                    QString friend_head_path;
                    LocalDatabase::getInstance()->m_queryFriendHead(friend_id, &friend_head_path);
                    if(!friend_head_path.isEmpty() && QFile(friend_head_path).exists())
                        cur_info_box->m_setHeadPic(friend_head_path);
                    break;
                }
            }
        }
    }
}
