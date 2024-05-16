#include "FriendListWidget.h"

FriendListWidget::FriendListWidget(QWidget *parent) :
    QTreeWidget(parent),
    m_groupMenu(new QMenu(this)),
    m_currentGroupItem(nullptr)
{
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);     // 关闭水平滚动条
    this->setExpandsOnDoubleClick(false);                           // 关闭双击展开

    // 下拉框箭头
    m_rightArrow.load(":/qqicons/qrc/right_expand.svg");
    m_rightArrow = m_rightArrow.scaled(QSize(20, 20), Qt::KeepAspectRatio, Qt::SmoothTransformation);
    m_downArrow.load(":/qqicons/qrc/119-down-arrow.svg");
    m_downArrow = m_downArrow.scaled(QSize(20, 20), Qt::KeepAspectRatio, Qt::SmoothTransformation);

    // 创建分组的右键菜单的action
    QAction* action_addGroup = new QAction(QStringLiteral("添加分组"), this);
    QPixmap add_group_icon;
    add_group_icon.load(":/qqicons/qrc/plus_icon.svg");
    add_group_icon = add_group_icon.scaled(QSize(20, 20), Qt::KeepAspectRatio, Qt::SmoothTransformation);
    action_addGroup->setIcon(QIcon(add_group_icon));
    QAction* action_renameGroup = new QAction(QStringLiteral("重命名该组"), this);
    QPixmap rename_group_icon;
    rename_group_icon.load(":/qqicons/qrc/rename_icon.svg");
    rename_group_icon = rename_group_icon.scaled(QSize(20, 20), Qt::KeepAspectRatio, Qt::SmoothTransformation);
    action_renameGroup->setIcon(QIcon(rename_group_icon));
    QAction* action_deleteGroup = new QAction(QStringLiteral("删除分组"), this);
    QPixmap delete_group_icon;
    delete_group_icon.load(":/qqicons/qrc/delete.svg");
    delete_group_icon = delete_group_icon.scaled(QSize(20, 20), Qt::KeepAspectRatio, Qt::SmoothTransformation);
    action_deleteGroup->setIcon(QIcon(delete_group_icon));
    m_groupMenu->addAction(action_addGroup);
    m_groupMenu->addAction(action_renameGroup);
    m_groupMenu->addAction(action_deleteGroup);
    connect(action_addGroup, &QAction::triggered, this, &FriendListWidget::slot_addGroup_query);
    connect(action_renameGroup, &QAction::triggered, this, &FriendListWidget::slot_renameGroup);
    connect(action_deleteGroup, &QAction::triggered, this, &FriendListWidget::slot_deleteGroup);

    connect(this, &FriendListWidget::itemClicked, this, &FriendListWidget::slot_itemClicked);
    connect(this, &FriendListWidget::signal_addGroup_query, AssembleBytes::getInstance(), &AssembleBytes::slot_asmAddGroup);
    connect(this, &FriendListWidget::signal_renameGroup_query, AssembleBytes::getInstance(), &AssembleBytes::slot_asmRenameGroup);
    connect(this, &FriendListWidget::signal_queryOnlineState, AssembleBytes::getInstance(), &AssembleBytes::slot_asmQueryOnlineState);
    connect(this, &FriendListWidget::signal_queryHeadPic, AssembleBytes::getInstance(), &AssembleBytes::slot_asmRequestUserHeadPic);

    m_init_groups();
}

FriendListWidget::~FriendListWidget()
{
    m_groups.clear();
    m_friendID2box.clear();
}

void FriendListWidget::contextMenuEvent(QContextMenuEvent *event)
{
    QTreeWidgetItem* cur_item = this->itemAt(mapFromGlobal(QCursor::pos()));
    if(cur_item == nullptr)
        return;
    // qDebug() << "cur_item->parent(): " << cur_item->parent();

    // 右键点击分组时进入分组菜单
    if(cur_item->parent() == nullptr)
    {
        m_currentGroupItem = cur_item;
        QTreeWidget::contextMenuEvent(event);
        m_groupMenu->exec(QCursor::pos());
    }
}

void FriendListWidget::resizeEvent(QResizeEvent *event)
{
    QTreeWidget::resizeEvent(event);

    m_updateWidgetSize();
}

void FriendListWidget::m_updateWidgetSize()
{
    // qDebug() << "FriendListWidget::m_updateWidgetSize, width:" << this->width();
    this->setColumnCount(2);
    this->setColumnWidth(0, this->width()*0.85);
    this->setColumnWidth(1, this->width()*0.15);

    // 重设朋友框大小
    for(int i=0; i<topLevelItemCount(); ++i)
    {
        QTreeWidgetItem *topLevelItem = this->topLevelItem(i);
        for(int j=0; j<topLevelItem->childCount(); ++j)
        {
            QTreeWidgetItem* childItem = topLevelItem->child(j);
            FriendLittleBox* cur_widget = qobject_cast<FriendLittleBox*>(this->itemWidget(childItem, 0));
            if(cur_widget)
            {
                cur_widget->resize(this->width(), cur_widget->height());
                childItem->setSizeHint(0, QSize(this->width(), cur_widget->height()));
            }
        }
    }
}

QTreeWidgetItem* FriendListWidget::m_createGroup(const quint32& group_id, const QString &group_name, const QString count_text)
{
    if(m_groups.contains(group_id))
    {
        return m_groups.value(group_id);
    }
    QTreeWidgetItem* new_item = new QTreeWidgetItem(this);
    new_item->setIcon(0, QIcon(m_rightArrow));
    new_item->setText(0, group_name);
    new_item->setText(1, count_text);
    new_item->setTextAlignment(0, Qt::AlignLeft|Qt::AlignVCenter);
    new_item->setTextAlignment(1, Qt::AlignLeft|Qt::AlignVCenter);
    this->addTopLevelItem(new_item);
    m_groups.insert(group_id, new_item);

    return new_item;
}

void FriendListWidget::m_init_groups()        // 初始化分组
{
    this->clear();
    QMap<quint32, sttGroupInfo> group_infos;
    bool _query_group_success = LocalDatabase::getInstance()->m_queryAllGroups(&group_infos);
    if(_query_group_success)
    {
        for(QMap<quint32, sttGroupInfo>::const_iterator ite = group_infos.begin(); ite!=group_infos.end(); ++ite)
        {
            QTreeWidgetItem* new_item = m_createGroup(ite.key(), ite.value().group_name, "0/0");
            for(int i=0; i<ite.value().friend_num; ++i)
            {
                sttFriendInfo cur_friend_info = ite.value().friend_list.at(i);
                this->m_addFriendBox2group(new_item, cur_friend_info);
            }
        }
    }
}

void FriendListWidget::slot_addGroup_query()      // 添加分组
{
    bool add_ok = false;
    QString group_name = QInputDialog::getText(this, QStringLiteral("添加分组"), QStringLiteral("请输入分组名"), QLineEdit::Normal,
                                               QStringLiteral("我的好友"), &add_ok, Qt::MSWindowsFixedSizeDialogHint);
    if(add_ok == false || group_name.isEmpty())
        return;
    emit signal_addGroup_query(Config::getInstance()->m_getLoginClientId(), group_name);
}

void FriendListWidget::slot_addGroup_success(const quint32 new_group_id, const QString group_name)
{
    m_createGroup(new_group_id, group_name, "0/0");
}

void FriendListWidget::slot_addGroup_failed()
{
    QMessageBox::information(this, QStringLiteral("提示"), QStringLiteral("服务端拒绝了您的添加分组请求"));
}

void FriendListWidget::slot_renameGroup()       // 重命名分组
{
    if(m_currentGroupItem == nullptr)
        return;
    QString current_group_name = m_currentGroupItem->text(0);
    bool modify_ok = false;
    QString modify_group_name = QInputDialog::getText(this, QStringLiteral("重命名该组"), QStringLiteral("重命名该组"), QLineEdit::Normal,
                                                      current_group_name, &modify_ok, Qt::MSWindowsFixedSizeDialogHint);
    if(modify_ok ==false || modify_group_name.isEmpty())
        return;
    m_currentGroupItem->setText(0, modify_group_name);

    quint32 _current_group_id = m_groups.key(m_currentGroupItem);
    LocalDatabase::getInstance()->m_replaceIntotGroupInfo(_current_group_id, modify_group_name);      // 本地进行修改
    emit signal_renameGroup_query(Config::getInstance()->m_getLoginClientId(), _current_group_id, modify_group_name);
}

void FriendListWidget::slot_deleteGroup()     // 删除分组
{
    // TODO 删除分组
}

void FriendListWidget::m_addFriendBox2group(QTreeWidgetItem *group, const sttFriendInfo friend_info,
                                            const FriendLittleBox::OnlineState online_state)
{
    if(group == nullptr)
    {
        qDebug() << "the parameter 'group' is nullptr.";
        return;
    }
    if(group->parent() != nullptr)
    {
        qDebug() << "the parameter 'group' is not a group, add failed.";
        return;
    }
    if(!m_friendID2box.contains(friend_info.id))
    {
        group->setExpanded(true);

        // 添加朋友框
        FriendLittleBox* friend_box = new FriendLittleBox(this, friend_info.id, ":/qqicons/qrc/QQicon.svg",
                                                       friend_info.name, online_state,
                                                       friend_info.signature);
        qDebug() << friend_info.name << "is added to" << group->text(0);
        QTreeWidgetItem* new_friend = new QTreeWidgetItem(group);
        group->addChild(new_friend);
        this->setItemWidget(new_friend, 0, friend_box);
        m_friendID2box.insert(friend_info.id, friend_box);

        // 更新当前分组的好友总个数以及在线人数
        QString count_text = group->text(1);
        int online_num = count_text.split("/").at(0).toInt();
        int friend_num = count_text.split("/").at(1).toInt();
        friend_num++;
        if(online_state == FriendLittleBox::Online)
            online_num = std::min(online_num+1, friend_num);
        group->setText(1, QString::number(online_num)+"/"+QString::number(friend_num));

        group->setExpanded(false);
    }
}

void FriendListWidget::m_addFriendBox2group(const sttFriendInfo friend_info,
                                            const FriendLittleBox::OnlineState online_state)
{
    quint32 group_id = friend_info.group_id;
    if(m_groups.contains(group_id))
    {
        m_addFriendBox2group(m_groups.value(group_id), friend_info, online_state);
    }
}

void FriendListWidget::slot_itemClicked(QTreeWidgetItem *item, int column)
{
    if(item == nullptr)
        return;
    if(item->parent() == nullptr)
    {
        if(item->isExpanded())
        {
            item->setIcon(0, QIcon(m_rightArrow));
            item->setExpanded(false);
        }
        else
        {
            item->setIcon(0, QIcon(m_downArrow));
            item->setExpanded(true);
            m_updateWidgetSize();
        }
    }
    else
    {
        FriendLittleBox* friend_clicked = qobject_cast<FriendLittleBox*>(this->itemWidget(item, 0));
        emit signal_friendBox_clicked(friend_clicked->m_getFriendID());
    }
}

bool FriendListWidget::m_setFriendOnlineState(const quint32 friend_id, FriendLittleBox::OnlineState online_state)
{
    if(!m_friendID2box.contains(friend_id))
        return false;

    FriendLittleBox::OnlineState last_online_state = m_getFriendOnlineState(friend_id);     // 旧的在线状态
    FriendLittleBox* friend_box = m_friendID2box.value(friend_id);
    friend_box->m_setOnlineState(online_state);     // 设置为新的在线状态
    // 更新所属分组的在线人数
    quint32 group_id;
    bool _query_success = LocalDatabase::getInstance()->m_queryFriendInWhichGroup(friend_id, &group_id);
    if(_query_success)
    {
        QTreeWidgetItem* group_item = m_groups.value(group_id);
        if(group_item)
        {
            QString count_text = group_item->text(1);
            int online_num = count_text.split("/").at(0).toInt();
            int friend_num = count_text.split("/").at(1).toInt();
            // 必须要检查旧的在线状态和新的在线状态，确保是真的上线/下线
            if(online_state == FriendLittleBox::Online && last_online_state == FriendLittleBox::Offline)
                online_num = std::min(online_num+1, friend_num);
            else if(online_state == FriendLittleBox::Offline && last_online_state == FriendLittleBox::Online)
                online_num = std::max(online_num-1, 0);
            count_text = QString::number(online_num)+"/"+QString::number(friend_num);
            group_item->setText(1, count_text);
        }
    }

    return true;
}

FriendLittleBox::OnlineState FriendListWidget::m_getFriendOnlineState(const quint32 friend_id) const
{
    if(!m_friendID2box.contains(friend_id))
        return FriendLittleBox::Offline;
    return m_friendID2box[friend_id]->m_getOnlineState();
}

bool FriendListWidget::m_setFriendBoxInfo(const quint32 friend_id, const QString name, const QString signature)
{
    if(!m_friendID2box.contains(friend_id))
        return false;
    FriendLittleBox* friend_box = m_friendID2box.value(friend_id);
    friend_box->m_setFriendName(name);
    friend_box->m_setFriendSignature(signature);
    return true;
}

void FriendListWidget::m_queryAllFriendOnlineState()
{
    QVector<quint32> all_friend_id;
    bool _query_success = LocalDatabase::getInstance()->m_queryAllFriendId(&all_friend_id);
    if(_query_success)
    {
        for(quint32 cur_friend_id : all_friend_id)
        {
            emit signal_queryOnlineState(cur_friend_id);
        }
    }
}

void FriendListWidget::m_queryAllFriendHeadPic()
{
    QVector<quint32> all_friend_id;
    bool _query_success = LocalDatabase::getInstance()->m_queryAllFriendId(&all_friend_id);
    if(_query_success)
    {
        for(quint32 cur_friend_id : all_friend_id)
        {
            m_querySingleFriendHeadPic(cur_friend_id);
        }
    }
}

void FriendListWidget::m_querySingleFriendHeadPic(const quint32 user_id)
{
    emit signal_queryHeadPic(user_id);
}

void FriendListWidget::m_setFriendHead(const quint32 friend_id, const QString head_path)
{
    if(!m_friendID2box.contains(friend_id))
        return;
    FriendLittleBox* friend_box = m_friendID2box.value(friend_id);
    friend_box->m_setFriendHead(head_path);
}

void FriendListWidget::m_moveFriendToGroup(const quint32 friend_id, const quint32 group_id)
{
    if(!m_friendID2box.contains(friend_id) || !m_groups.contains(group_id))
        return;

    // 找到对应的分组item和好友item
    QTreeWidgetItem* old_group_item = nullptr;
    QTreeWidgetItem* old_friend_item = nullptr;
    bool _should_break = false;
    for(int i=0; i<this->topLevelItemCount(); ++i)
    {
        QTreeWidgetItem* cur_group_item = this->topLevelItem(i);
        for(int j=0; j<cur_group_item->childCount(); ++j)
        {
            QTreeWidgetItem* cur_friend_item = cur_group_item->child(j);
            if(cur_friend_item)
            {
                QWidget* cur_widget = this->itemWidget(cur_friend_item, 0);
                if(cur_widget)
                {
                    FriendLittleBox* cur_friend_widget = qobject_cast<FriendLittleBox*>(cur_widget);
                    if(cur_friend_widget!=nullptr && cur_friend_widget->m_getFriendID()==friend_id)
                    {
                        old_group_item = cur_group_item;
                        old_friend_item = cur_friend_item;
                        _should_break = true;
                        break;
                    }
                }
            }
        }
        if(_should_break)
            break;
    }

    // 朋友框添加到指定分组里
    if(old_group_item==nullptr || old_friend_item==nullptr)
        return;
    FriendLittleBox* friend_box = m_friendID2box.value(friend_id);
    QTreeWidgetItem* new_group_item = m_groups.value(group_id);
    if(new_group_item == old_group_item)
    {
        // qDebug() << "no need to move friend.";
        return;
    }
    QTreeWidgetItem* new_friend_item = new QTreeWidgetItem(new_group_item);
    new_group_item->addChild(new_friend_item);
    this->setItemWidget(new_friend_item, 0, friend_box);    // friend_box和new_friend_item绑定后，就自动和old_friend_item解绑了
    // 更新新分组的好友总个数
    {
        QString count_text = new_group_item->text(1);
        int online_num = count_text.split("/").at(0).toInt();
        int friend_num = count_text.split("/").at(1).toInt();
        friend_num++;
        new_group_item->setText(1, QString::number(online_num)+"/"+QString::number(friend_num));
    }

    // 从旧分组中移除朋友框
    old_group_item->removeChild(old_friend_item);
    delete old_friend_item;
    // 更新旧分组的好友总个数
    {
        QString count_text = old_group_item->text(1);
        int online_num = count_text.split("/").at(0).toInt();
        int friend_num = count_text.split("/").at(1).toInt();
        friend_num--;
        friend_num = qMax(friend_num, 0);
        old_group_item->setText(1, QString::number(online_num)+"/"+QString::number(friend_num));
    }
    if(old_group_item->childCount() == 0)
    {
        old_group_item->setIcon(0, QIcon(m_rightArrow));
        old_group_item->setExpanded(false);
    }
}





ExpandButton::ExpandButton(QWidget *parent) :
    QPushButton(parent),
    m_unreadPic(new QLabel(this))
{
    m_setUnreadNum(0);
    m_unreadPic->setStyleSheet("QLabel{ background-color: rgba(255, 255, 255, 0);"
                                        "border: none;"
                                        "}");
    QFont font;
    font.setFamily("Microsoft YaHei");
    font.setPointSize(8);
    font.setBold(true);
    m_unreadPic->setFont(font);
    // m_unreadPic->resize(35, 35);
    QSize unread_pic_size(35, 35);
    m_unreadPic->setFixedSize(unread_pic_size);
    m_unreadPic->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
}

ExpandButton::~ExpandButton()
{

}

void ExpandButton::paintEvent(QPaintEvent *event)
{
    QPushButton::paintEvent(event);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setRenderHint(QPainter::SmoothPixmapTransform, true);
    QPixmap right_expand_icon;
    right_expand_icon.load(":/qqicons/qrc/right_expand.svg");
    right_expand_icon = right_expand_icon.scaled(QSize(20, 20), Qt::KeepAspectRatio, Qt::SmoothTransformation);
    int x = this->rect().width() / 8 * 7;       // 7/8宽的位置
    int y = this->rect().center().y() - right_expand_icon.height()/2;
    if(y < 0)
        y = 0;
    painter.drawPixmap(x, y, right_expand_icon);
}

void ExpandButton::m_setUnreadNum(int num)
{
    m_unreadNum = num > 0? num : 0;
    if(m_unreadNum > 0)
    {
        m_unreadPic->setStyleSheet("QLabel{"
                                   "color: rgb(255, 255, 255);"
                                   "margin-left:  5px;"
                                   "margin-right: 5px;"
                                   "margin-top:   5px;"
                                   "margin-bottom:5px;"
                                   "border-image: url(:/qqicons/qrc/red_circle.svg) ;"
                                   "background-color: rgba(255, 255, 255, 0);"
                                   "border: none;"
                                   "}");
        m_unreadPic->setText(QString::number(m_unreadNum));
        int x = this->rect().width()*0.75;
        int y = this->rect().center().y() - m_unreadPic->height()/2;
        m_unreadPic->move(x, y);

        // qDebug() << "this->rect().width(): " << this->rect().width();
        // qDebug() << "unread_pic:" << x << y;
    }
    else
    {
        m_unreadPic->clear();
        m_unreadPic->setStyleSheet("QLabel{ background-color: rgba(255, 255, 255, 0);"
                                   "border: none;"
                                   "}");
    }
}

void ExpandButton::m_appendUnreadNum(int num)
{
    m_setUnreadNum(m_unreadNum + num);
}

void ExpandButton::m_setUnreadNum()
{
    m_setUnreadNum(m_unreadNum);
}
