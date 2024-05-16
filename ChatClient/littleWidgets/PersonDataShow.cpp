#include "persondatashow.h"
#include "ui_persondatashow.h"

PersonDataShow::PersonDataShow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PersonDataShow)
{
    ui->setupUi(this);
    ui->lblName->setTextInteractionFlags(Qt::TextSelectableByMouse);
    ui->lblAccount->setTextInteractionFlags(Qt::TextSelectableByMouse);
    ui->lblSignature->setTextInteractionFlags(Qt::TextSelectableByMouse);
    ui->lblLevel->setTextInteractionFlags(Qt::TextSelectableByMouse);
    ui->lblAge->setTextInteractionFlags(Qt::TextSelectableByMouse);
    ui->lblLastLogin->setTextInteractionFlags(Qt::TextSelectableByMouse);

    m_init();       // 初始化
}

PersonDataShow::~PersonDataShow()
{
    delete ui;
}

void PersonDataShow::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    // 绘制自定义边框
    painter.setPen(Qt::black);
    painter.setBrush(QBrush(QColor(255, 255, 255, 255)));
    painter.drawRoundedRect(rect(), 20, 20);
}

void PersonDataShow::m_init()        // 初始化
{
    QPixmap head_pic;
    head_pic.load(":/qqicons/qrc/QQicon.svg");
    head_pic = pixmaptoRound(head_pic, QSize(80, 80));
    ui->lblHeadPic->setPixmap(head_pic);
    this->setWindowFlags(Qt::Popup | Qt::FramelessWindowHint | Qt::NoDropShadowWindowHint);
    this->setAttribute(Qt::WA_ShowWithoutActivating, true);
    this->setModal(false);
    this->setFixedSize(460, 505);

    connect(ui->btnEditInfo, SIGNAL(clicked()), this, SLOT(slot_btnEditInfo_clicked()));
}

bool PersonDataShow::m_setUserInfoToUI(const sttClientInfo& user_info,
                                       const QPixmap& head_pic)                // 把用户信息展示到界面上
{
    try
    {
        if(!head_pic.isNull())
        {
            ui->lblHeadPic->setPixmap(head_pic);
        }
        if(!user_info.name.isEmpty())
        {
            // 文本过长时在末尾使用省略号
            QFontMetrics fontWidth(ui->lblName->font());                                           // 得到每个字符的宽度
            QString elideNote = fontWidth.elidedText(user_info.name, Qt::ElideRight, 300);       // 最大宽度300像素
            ui->lblName->setText(elideNote);
            ui->lblName->setToolTip(user_info.name);
            ui->lblName->setAlignment(Qt::AlignLeft);
        }
        ui->lblAccount->setText("QQ " + user_info.account);
        ui->lblAccount->setAlignment(Qt::AlignLeft);
        if(!user_info.signature.isEmpty())
        {
            QFontMetrics fontWidth(ui->lblSignature->font());                                           // 得到每个字符的宽度
            QString elideNote = fontWidth.elidedText(user_info.signature, Qt::ElideRight, 300);       // 最大宽度300像素
            ui->lblSignature->setText(elideNote);
            ui->lblSignature->setAlignment(Qt::AlignCenter);
        }
        ui->lblLevel->setText(QString::number(user_info.level));
        ui->lblLevel->setToolTip(QStringLiteral("等级：") + user_info.level);
        ui->lblLevel->setAlignment(Qt::AlignCenter);
        ui->lblAge->setText(QString::number(user_info.age));
        ui->lblAge->setToolTip(QStringLiteral("年龄：") + user_info.age);
        ui->lblAge->setAlignment(Qt::AlignCenter);
        ui->lblLastLogin->setText(user_info.last_online);
        ui->lblLastLogin->setAlignment(Qt::AlignCenter);
    }
    catch(const std::exception& e)
    {
        qCritical() << "Exception caught: " << e.what();
        return false;
    }

    return true;
}

bool PersonDataShow::m_setUserInfoToUI(const sttClientInfo &user_info, const QString &head_path)
{
    if(!head_path.isEmpty() && QFile(head_path).exists())
    {
        QPixmap head_pic;
        head_pic.load(head_path);
        head_pic = pixmaptoRound(head_pic, QSize(100, 100));
        return m_setUserInfoToUI(user_info, head_pic);
    }
    return false;
}

void PersonDataShow::slot_btnEditInfo_clicked()
{
    this->hide();
    emit signal_userInfoEdit();
}

void PersonDataShow::m_setEditInfoUnvisible()
{
//    ui->btnEditInfo->setVisible(false);
//    ui->lblStatePic->setVisible(false);
//    ui->lblState->setVisible(false);
    ui->btnEditInfo->setStyleSheet("QWidget{                                    "
                                   "border: none;                               "
                                   "background-color: rgba(255, 255, 255, 0);   "
                                   "color: rgba(255, 255, 255, 0);              "
                                   "}");
    ui->lblStatePic->setStyleSheet("QWidget{                                    "
                                   "border: none;                               "
                                   "background-color: rgba(255, 255, 255, 0);   "
                                   "color: rgba(255, 255, 255, 0);              "
                                   "}");
    ui->lblState->setStyleSheet("QWidget{                                    "
                                   "border: none;                               "
                                   "background-color: rgba(255, 255, 255, 0);   "
                                   "color: rgba(255, 255, 255, 0);              "
                                   "}");
}
