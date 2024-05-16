#include "FriendInfoWidget.h"
#include "ui_FriendInfoWidget.h"

FriendInfoWidget::FriendInfoWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FriendInfoWidget),
    m_friendId(0)
{
    ui->setupUi(this);
    ui->lblFriendName->setTextInteractionFlags(Qt::TextSelectableByMouse);
    ui->lblFriendAccount->setTextInteractionFlags(Qt::TextSelectableByMouse);
    ui->lblFriendSignature->setTextInteractionFlags(Qt::TextSelectableByMouse);
    ui->lblFriendLevel->setTextInteractionFlags(Qt::TextSelectableByMouse);
    ui->lblFriendAge->setTextInteractionFlags(Qt::TextSelectableByMouse);
    ui->lblFriendLastLogin->setTextInteractionFlags(Qt::TextSelectableByMouse);
    LocalDatabase::getInstance()->m_queryAllGroupIdNames(&m_allGroupNames);
    if(ui->cmbFriendGroup->count())
        ui->cmbFriendGroup->clear();
    for(QMap<quint32, QString>::const_iterator ite = m_allGroupNames.begin(); ite!=m_allGroupNames.end(); ++ite)
    {
        ui->cmbFriendGroup->addItem(ite.value());
    }

    connect(ui->btnFriendReadySend, &QPushButton::clicked, [this](){
        emit signal_reqOpenChatWithFriend(m_friendId);
    });
    connect(ui->cmbFriendGroup, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &FriendInfoWidget::slot_cmbFriendGroup_currentIndexChanged);
    connect(this, &FriendInfoWidget::signal_reqMoveFriendToGroup, AssembleBytes::getInstance(), &AssembleBytes::slot_asmMoveFriendToGroup);
}

FriendInfoWidget::~FriendInfoWidget()
{
    delete ui;
}

void FriendInfoWidget::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setBrush(QColor(255, 255, 255, 255));
    painter.drawRoundedRect(this->rect(), 0, 0);
}

void FriendInfoWidget::m_setChatFriend(const quint32& friend_id, const FriendLittleBox::OnlineState& online_state)
{
    m_friendId = friend_id;
    sttFriendInfo friend_info;
    bool _query_success = LocalDatabase::getInstance()->m_queryFriendInfo(m_friendId, &friend_info);
    if(_query_success)
    {
        quint32 in_which_group;
        LocalDatabase::getInstance()->m_queryFriendInWhichGroup(m_friendId, &in_which_group);
        ui->cmbFriendGroup->setCurrentIndex(m_allGroupNames.keys().indexOf(in_which_group));
        QPixmap head_pic;
        QString head_path;
        LocalDatabase::getInstance()->m_queryFriendHead(friend_id, &head_path);
        if(!head_path.isEmpty())
        {
            head_pic.load(head_path);
        }
        else
        {
            head_pic.load(":/qqicons/qrc/QQicon.svg");
        }
        QSize head_size = QSize(140, 140);              // 头像大小
        head_pic = pixmaptoRound(head_pic, head_size);
        ui->lblFriendHeadPic->setPixmap(head_pic);
        QFontMetrics name_fontWidth(ui->lblFriendName->font());
        QString name_elideNote = name_fontWidth.elidedText(friend_info.name, Qt::ElideRight, ui->lblFriendName->width()-5);
        ui->lblFriendName->setText(name_elideNote);
        ui->lblFriendName->setToolTip(friend_info.name);
        ui->lblFriendAccount->setText("QQ " + friend_info.account);
        if(online_state == FriendLittleBox::Online)
        {
            ui->lblFriendOnlinePic->setPixmap(QPixmap(":/qqicons/qrc/online.svg"));
            ui->lblFriendOnlineState->setText(QStringLiteral("在线"));
        }
        else
        {
            ui->lblFriendOnlinePic->setPixmap(QPixmap(":/qqicons/qrc/offline.svg"));
            ui->lblFriendOnlineState->setText(QStringLiteral("离线"));
        }
        QFontMetrics sig_fontWidth(ui->lblFriendSignature->font());
        QString sig_elideNote = sig_fontWidth.elidedText(friend_info.signature, Qt::ElideRight, ui->lblFriendSignature->width()-5);
        ui->lblFriendSignature->setText(sig_elideNote);
        ui->lblFriendSignature->setToolTip(friend_info.signature);
        ui->lblFriendLevel->setText(QString::number(friend_info.level));
        ui->lblFriendLevel->setToolTip(QStringLiteral("等级：")+QString::number(friend_info.level));
        ui->lblFriendAge->setText(QString::number(friend_info.age));
        ui->lblFriendAge->setToolTip(QStringLiteral("年龄：")+QString::number(friend_info.age));
        ui->lblFriendLastLogin->setText(friend_info.last_online);
    }
}

quint32 FriendInfoWidget::m_getFriendId() const
{
    return m_friendId;
}

void FriendInfoWidget::m_setFriendOnlineState(const quint32 &friend_id, const FriendLittleBox::OnlineState &online_state)
{
    // 检查是否是当前页面所属的好友id
    if(friend_id == m_friendId)
    {
        if(online_state == FriendLittleBox::Online)
        {
            ui->lblFriendOnlinePic->setPixmap(QPixmap(":/qqicons/qrc/online.svg"));
            ui->lblFriendOnlineState->setText(QStringLiteral("在线"));
        }
        else
        {
            ui->lblFriendOnlinePic->setPixmap(QPixmap(":/qqicons/qrc/offline.svg"));
            ui->lblFriendOnlineState->setText(QStringLiteral("离线"));
        }
    }
}

void FriendInfoWidget::slot_updateGroupNames()
{
    LocalDatabase::getInstance()->m_queryAllGroupIdNames(&m_allGroupNames);
    ui->cmbFriendGroup->clear();
    for(QMap<quint32, QString>::const_iterator ite=m_allGroupNames.begin(); ite!=m_allGroupNames.end(); ++ite)
    {
        ui->cmbFriendGroup->addItem(ite.value());
    }
}

void FriendInfoWidget::slot_cmbFriendGroup_currentIndexChanged(int index)
{
    if(m_friendId == 0)
        return;
    quint32 old_group_id;
    LocalDatabase::getInstance()->m_queryFriendInWhichGroup(m_friendId, &old_group_id);
    if(index < m_allGroupNames.keys().size())
    {
        quint32 group_id = m_allGroupNames.keys().value(index);
        if(old_group_id != group_id)
        {
            emit signal_reqMoveFriendToGroup(Config::getInstance()->m_getLoginClientId(), m_friendId, group_id);
        }
    }
}
