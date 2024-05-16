#include "InfoLittleBox.h"
#include "ui_infolittlebox.h"

InfoLittleBox::InfoLittleBox(QWidget *parent, quint32 friend_id, QString head_path,
                             QString name, QString message, QString date, int size) :
    QWidget(parent),
    ui(new Ui::InfoLittleBox),
    m_headPath(head_path),
    m_name(name),
    m_message(message),
    m_date(date),
    m_headSize(QSize(size, size)),
    m_mouseIn(false),
    m_isChatting(false),
    m_friendID(friend_id),
    m_unreadNum(0)
{
    ui->setupUi(this);
    this->setMouseTracking(true);
    m_init();
}

InfoLittleBox::~InfoLittleBox()
{
    delete ui;
}

void InfoLittleBox::m_init()
{
    this->adjustSize();
    QPixmap head_pic;
    head_pic.load(m_headPath);
    head_pic = pixmaptoRound(head_pic, m_headSize);
    ui->lblHead->setPixmap(head_pic);
    QFontMetrics name_fontWidth(ui->lblName->font());
    QString name_elideNote = name_fontWidth.elidedText(m_name, Qt::ElideRight, ui->lblName->width());
    ui->lblName->setText(name_elideNote);
    QFontMetrics msg_fontWidth(ui->lblInfo->font());
    QString msg_elideNote = msg_fontWidth.elidedText(m_message.trimmed().replace('\n', ' '), Qt::ElideRight, ui->lblInfo->width());
    ui->lblInfo->setText(msg_elideNote);
    ui->lblDate->setText(m_date);
    this->m_setUnreadPic(0);
}

QString InfoLittleBox::m_getChatName() const
{
    return m_name;
}

void InfoLittleBox::m_setChatName(const QString &name)
{
    m_name = name;
    QFontMetrics name_fontWidth(ui->lblName->font());
    QString name_elideNote = name_fontWidth.elidedText(m_name, Qt::ElideRight, ui->lblName->width());
    ui->lblName->setText(name_elideNote);
}

quint32 InfoLittleBox::m_getFriendID() const
{
    return m_friendID;
}

int InfoLittleBox::m_getUnreadNum() const
{
    return m_unreadNum;
}

void InfoLittleBox::m_setUnreadPic(const int unread_num)
{
    m_unreadNum = unread_num;
    if(unread_num > 0)
    {
        ui->lblUnread->setStyleSheet("QLabel{"
                                     "color: rgb(255, 255, 255);"
                                     "margin-left:  5px;"
                                     "margin-right: 5px;"
                                     "margin-top:   5px;"
                                     "margin-bottom:5px;"
                                     "border-image: url(:/qqicons/qrc/red_circle.svg) ;"
                                     "background-color: rgba(255, 255, 255, 0);"
                                     "}");
        ui->lblUnread->setText(QString::number(unread_num));
    }
    else
    {
        ui->lblUnread->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
        ui->lblUnread->clear();
    }
}

void InfoLittleBox::m_setUnreadPic()
{
    m_unreadNum++;
    this->m_setUnreadPic(m_unreadNum);
}

void InfoLittleBox::m_setChattingState(bool is_chatting)
{
    m_isChatting = is_chatting;
    if(m_isChatting)
    {
        ui->lblName->setStyleSheet("color: white; background-color: rgba(255, 255, 255, 0);");
        ui->lblDate->setStyleSheet("color: white;  background-color: rgba(255, 255, 255, 0);");
        ui->lblInfo->setStyleSheet("color: white;  background-color: rgba(255, 255, 255, 0);");
    }
    else
    {
        ui->lblName->setStyleSheet("color: black; background-color: rgba(255, 255, 255, 0);");
        ui->lblDate->setStyleSheet("color: gray;  background-color: rgba(255, 255, 255, 0);");
        ui->lblInfo->setStyleSheet("color: gray;  background-color: rgba(255, 255, 255, 0);");
    }
    this->update();
}

void InfoLittleBox::mousePressEvent(QMouseEvent *event)
{
    QWidget::mousePressEvent(event);
    if(event->button() == Qt::LeftButton)
    {
        m_isChatting = true;
        emit signal_clicked();
    }
}

void InfoLittleBox::m_clickSelf()
{
    emit signal_clicked();
}

bool InfoLittleBox::event(QEvent *event)
{
    if(event->type() == QEvent::Enter)
    {
        m_mouseIn = true;
        this->update();
    }
    else if(event->type() == QEvent::Leave)
    {
        m_mouseIn = false;
        this->update();
    }
    return QWidget::event(event);
}

void InfoLittleBox::paintEvent(QPaintEvent *event)
{
    if(m_isChatting)
    {
        QPainter painter(this);
        painter.fillRect(this->rect(), QColor(0, 153, 255));
    }
    else
    {
        if(m_mouseIn)
        {
            QPainter painter(this);
            painter.fillRect(this->rect(), QColor(246, 246, 246));
        }
        else
        {
            QPainter painter(this);
            painter.fillRect(this->rect(), QColor(255, 255, 255));
        }
    }
    QWidget::paintEvent(event);
}

void InfoLittleBox::m_setDate(const QDateTime date)
{
    QString date_text = date.toString("dddd hh:mm:ss");
    m_date = date_text;
    ui->lblDate->setText(date_text);
}

void InfoLittleBox::m_setInfoPreview(const QString info)
{
    m_message = info;
    QFontMetrics info_fontWidth(ui->lblInfo->font());
    QString info_elideNote = info_fontWidth.elidedText(info.trimmed().replace('\n', ' '), Qt::ElideRight, ui->lblInfo->width());
    ui->lblInfo->setText(info_elideNote);
}

void InfoLittleBox::m_setHeadPic(const QString &path)
{
    m_headPath = path;
    QPixmap head_pic;
    head_pic.load(m_headPath);
    head_pic = pixmaptoRound(head_pic, m_headSize);
    ui->lblHead->setPixmap(head_pic);
}
