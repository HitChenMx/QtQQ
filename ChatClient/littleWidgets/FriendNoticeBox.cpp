#include "friendnoticebox.h"
#include "ui_friendnoticebox.h"

FriendNoticeBox::FriendNoticeBox(const sttClientInfo& client_info,
                                 const bool& client_is_sender,
                                 const QString& verify_msg,
                                 quint32 group_id,
                                 QWidget *parent,
                                 const QPixmap& head_pic) :
    QWidget(parent),
    ui(new Ui::FriendNoticeBox),
    m_clientInfo(client_info),
    m_verifyMsg(verify_msg.trimmed().replace("\n", " ")),
    m_clientIsSender(client_is_sender),
    m_groupId(group_id),
    m_isRead(false),
    m_lblReplyShow(nullptr),
    m_isReplyed(false),
    m_headPic(head_pic)
{
    ui->setupUi(this);
    ui->lblTime->setTextInteractionFlags(Qt::TextSelectableByMouse);
    ui->lblLeaveWords->setTextInteractionFlags(Qt::TextSelectableByMouse);
    // 信号与槽
    connect(ui->btnReply, &TwoClickAreaButton::signal_leftPart_clicked, this, &FriendNoticeBox::slot_replyAgree_clicked);
    connect(ui->btnReply, &TwoClickAreaButton::signal_expandAction_triggered, this, &FriendNoticeBox::slot_replyReject_clicked);
    connect(ui->btnUserName, &QPushButton::clicked, this, &FriendNoticeBox::slot_showClientInfo);
    connect(this, &FriendNoticeBox::signal_replyAddFriendRequest, AssembleBytes::getInstance(), &AssembleBytes::slot_asmReplyAddFriend);


    ui->lblHeadPic->installEventFilter(this);           // 事件过滤器
    // 头像
    if(m_headPic.isNull())
    {
        m_headPic.load(":/qqicons/qrc/QQicon.svg");
        m_headPic = pixmaptoRound(m_headPic, QSize(70, 70));
    }
    ui->lblHeadPic->setPixmap(m_headPic);

    // 名字
//    ui->btnUserName->setText(m_clientInfo.name);
    ui->btnUserName->setToolTip(m_clientInfo.name);
//    ui->btnUserName->adjustSize();
    // “请求加为好友”/“正在验证你的邀请”
    QString request_text = m_clientIsSender? QStringLiteral("请求加为好友") : QStringLiteral("正在验证你的邀请");
    ui->lblUserRequest->setText(request_text);
    ui->lblUserRequest->adjustSize();
    // 时间
    ui->lblTime->setText(QDateTime::currentDateTime().toString("dddd hh:mm:ss"));
    ui->lblTime->adjustSize();
    // 留言
    m_verifyMsg = QStringLiteral("留言：") + m_verifyMsg;
//    ui->lblLeaveWords->setText(m_verifyMsg);
    ui->lblLeaveWords->setToolTip(m_verifyMsg);

    // 设置下拉菜单的text
    ui->btnReply->setActionName(QStringLiteral("拒绝"));
    // 如果是自己发送的添加好友请求，就把button替换为“等待验证”
    if(m_clientIsSender == false)
    {
        m_setReplytext(QStringLiteral("等待验证"));
    }
}

FriendNoticeBox::~FriendNoticeBox()
{
    delete ui;
}

void FriendNoticeBox::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setBrush(QColor(255, 255, 255, 255));
    painter.drawRoundedRect(this->rect(), 10, 10);
}

void FriendNoticeBox::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);

    QFontMetrics name_fontWidth(ui->btnUserName->font());
    QString name_elideNote = name_fontWidth.elidedText(m_clientInfo.name, Qt::ElideRight, this->width()*0.25);
    ui->btnUserName->setText(name_elideNote);


    QFontMetrics msg_fontWidth(ui->lblLeaveWords->font());
    QString msg_elideNote = msg_fontWidth.elidedText(m_verifyMsg, Qt::ElideRight, ui->lblLeaveWords->width());
    ui->lblLeaveWords->setText(msg_elideNote);
}

void FriendNoticeBox::m_setHeadPic(const QString &head_path)
{
    QPixmap head_pic;
    head_pic.load(head_path);
    head_pic = pixmaptoRound(head_pic, QSize(70, 70));
    m_headPic = head_pic;
    ui->lblHeadPic->setPixmap(head_pic);
}

void FriendNoticeBox::m_setVerifyMsg(const QString &verify_msg)
{
    m_verifyMsg = QStringLiteral("留言：") + verify_msg.trimmed().replace("\n", " ");
    ui->lblLeaveWords->setToolTip(m_verifyMsg);
    QFontMetrics msg_fontWidth(ui->lblLeaveWords->font());
    QString msg_elideNote = msg_fontWidth.elidedText(m_verifyMsg, Qt::ElideRight, ui->lblLeaveWords->width());
    ui->lblLeaveWords->setText(msg_elideNote);
}

void FriendNoticeBox::m_setTime(const QDateTime &date_time)
{
    ui->lblTime->setText(date_time.toString("dddd hh:mm:ss"));
    ui->lblTime->adjustSize();
}

void FriendNoticeBox::m_setIsReadOrNot(const bool &is_read)
{
    m_isRead = is_read;
}

bool FriendNoticeBox::m_getIsRead() const
{
    return m_isRead;
}

quint32 FriendNoticeBox::m_getGroupId() const
{
    return m_groupId;
}

void FriendNoticeBox::m_setGroupId(quint32 group_id)
{
    m_groupId = group_id;
}

quint32 FriendNoticeBox::m_getClientId() const
{
    return m_clientInfo.id;
}

bool FriendNoticeBox::m_getIsReplyed() const
{
    return m_isReplyed;
}

bool FriendNoticeBox::m_getIsOther2Self() const
{
    return m_clientIsSender;
}

void FriendNoticeBox::m_setReplytext(const QString &text)
{
    // 按钮已没有作用，释放掉
    if(ui->btnReply)
    {
        disconnect(ui->btnReply, &TwoClickAreaButton::signal_leftPart_clicked, this, &FriendNoticeBox::slot_replyAgree_clicked);
        disconnect(ui->btnReply, &TwoClickAreaButton::signal_expandAction_triggered, this, &FriendNoticeBox::slot_replyReject_clicked);
        ui->btnReply->setParent(nullptr);
        ui->btnReply->deleteLater();
        ui->btnReply = nullptr;
    }

    if(m_lblReplyShow == nullptr)
    {
        m_lblReplyShow = new QLabel(this);
        m_lblReplyShow->resize(71, 31);
        m_lblReplyShow->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        m_lblReplyShow->setFont(QFont("Microsoft YaHei", 10));
        ui->mainContentHLayout->addWidget(m_lblReplyShow, 8);
    }
    m_lblReplyShow->setText(text);


    if(text==QStringLiteral("已同意") || text==QStringLiteral("已拒绝"))
        m_isReplyed = true;
}

void FriendNoticeBox::slot_replyAgree_clicked()
{
    m_setReplytext(QStringLiteral("已同意"));
    m_sendReplyBytesToServer(true);
}

void FriendNoticeBox::slot_replyReject_clicked()
{
    m_setReplytext(QStringLiteral("已拒绝"));
    m_sendReplyBytesToServer(false);
}

void FriendNoticeBox::m_sendReplyBytesToServer(bool reply_is_agree)
{
    quint32 _other_id = m_getClientId();
    quint32 _other_group_id = m_getGroupId();
    QMap<quint32, QString> self_all_groups;
    LocalDatabase::getInstance()->m_queryAllGroupIdNames(&self_all_groups);
    quint32 _self_group_id = self_all_groups.begin().key();     // 默认把好友添加到自己的第一个分组里
    emit signal_replyAddFriendRequest(Config::getInstance()->m_getLoginClientId(), _other_id,
                                      reply_is_agree,
                                      _self_group_id, _other_group_id);
}

bool FriendNoticeBox::eventFilter(QObject *watched, QEvent *event)
{
    if(watched==ui->lblHeadPic && event->type() == QEvent::MouseButtonPress)
    {
        // 鼠标点击头像，弹出该用户的用户信息界面
        this->slot_showClientInfo();
    }

    return QWidget::eventFilter(watched, event);
}

void FriendNoticeBox::slot_showClientInfo()
{
    PersonDataShow* user_data_show = new PersonDataShow(this);
    user_data_show->setAttribute(Qt::WA_DeleteOnClose);
    connect(user_data_show, &PersonDataShow::destroyed, [user_data_show]() mutable {
        user_data_show->deleteLater();
        user_data_show = nullptr;
    });
    bool _success = user_data_show->m_setUserInfoToUI(m_clientInfo, m_headPic);
    if(_success)
    {
        user_data_show->m_setEditInfoUnvisible();
        QPoint _pos = ui->lblHeadPic->mapToGlobal(QPoint(ui->lblHeadPic->width(), 0));
        // qDebug() << "popup window's position: " << _pos;
        user_data_show->move(_pos);
        user_data_show->show();
    }
}
