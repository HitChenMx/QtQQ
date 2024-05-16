#include "FriendLittleBox.h"
#include "ui_friendlittlebox.h"

FriendLittleBox::FriendLittleBox(QWidget *parent, quint32 friend_id, QString head_path, QString name,
                                 FriendLittleBox::OnlineState online_state, QString signature, int size) :
    QWidget(parent),
    ui(new Ui::FriendLittleBox),
    m_name(name),
    m_onlineState(online_state),
    m_signature(signature),
    m_headSize(QSize(size, size)),
    m_friendID(friend_id)
{
    ui->setupUi(this);
    this->setFixedHeight(92);

    QPixmap head_pic;
    head_pic.load(head_path);
    head_pic = pixmaptoRound(head_pic, m_headSize);
    ui->lblHead->setPixmap(head_pic);
    if(m_onlineState == FriendLittleBox::Online)
    {
        ui->lblOnlineState->setText(QStringLiteral("[在线]"));
    }
    else
    {
        ui->lblOnlineState->setText(QStringLiteral("[离线]"));
    }
}

FriendLittleBox::~FriendLittleBox()
{
    delete ui;
}

void FriendLittleBox::resizeEvent(QResizeEvent* event)
{
    QWidget::resizeEvent(event);

    // 在resizeEvent中获取控件的实际宽度，然后让显示文本宽度受限于控件的当前实际宽度
    QFontMetrics name_fontWidth(ui->lblName->font());
    QString name_elideNote = name_fontWidth.elidedText(m_name, Qt::ElideRight, ui->lblName->width()-25);  // 250
    ui->lblName->setText(name_elideNote);
    ui->lblName->setToolTip(m_name);

    QFontMetrics sig_fontWidth(ui->lblSignature->font());
    QString sig_elideNote = sig_fontWidth.elidedText(m_signature, Qt::ElideRight, ui->lblSignature->width()-25);     // 190
    ui->lblSignature->setText(sig_elideNote);
    ui->lblSignature->setToolTip(m_signature);
}

QString FriendLittleBox::m_getFriendName() const
{
    return ui->lblName->text();
}

quint32 FriendLittleBox::m_getFriendID() const
{
    return m_friendID;
}

void FriendLittleBox::m_setOnlineState(OnlineState online_state)
{
    m_onlineState = online_state;
    if(m_onlineState == FriendLittleBox::Online)
    {
        ui->lblOnlineState->setText(QStringLiteral("[在线]"));
    }
    else
    {
        ui->lblOnlineState->setText(QStringLiteral("[离线]"));
    }
}

FriendLittleBox::OnlineState FriendLittleBox::m_getOnlineState() const
{
    return m_onlineState;
}

void FriendLittleBox::m_setFriendName(const QString &name)
{
    m_name = name;
    QFontMetrics name_fontWidth(ui->lblName->font());
    QString name_elideNote = name_fontWidth.elidedText(m_name, Qt::ElideRight, ui->lblName->width());  // 250
    ui->lblName->setText(name_elideNote);
    ui->lblName->setToolTip(m_name);
}

void FriendLittleBox::m_setFriendSignature(const QString &signature)
{
    m_signature = signature;
    QFontMetrics sig_fontWidth(ui->lblSignature->font());
    QString sig_elideNote = sig_fontWidth.elidedText(m_signature, Qt::ElideRight, ui->lblSignature->width());     // 190
    ui->lblSignature->setText(sig_elideNote);
    ui->lblSignature->setToolTip(m_signature);
}

void FriendLittleBox::m_setFriendHead(const QString &head_path)
{
    QPixmap head_pic;
    head_pic.load(head_path);
    head_pic = pixmaptoRound(head_pic, m_headSize);
    ui->lblHead->setPixmap(head_pic);
}
