#include "persondataset.h"
#include "ui_persondataset.h"

PersonDataSet::PersonDataSet(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PersonDataSet),
    m_headPic(QPixmap()),
    m_headSize(QSize(160, 160)),
    m_changeHeadPath(QString())
{
    ui->setupUi(this);
    m_init();
}

PersonDataSet::~PersonDataSet()
{
    delete ui;
}

void PersonDataSet::m_init()
{
    this->setWindowFlags(windowFlags() | Qt::Window);
    this->setWindowModality(Qt::ApplicationModal);      // 模态
    ui->lblHeadPic->installEventFilter(this);

    connect(ui->btnSaveSet, &QPushButton::clicked, this, &PersonDataSet::slot_btnSaveSet_clicked);
    connect(ui->btnCancelSet, &QPushButton::clicked, this, &PersonDataSet::slot_btnCancelSet_clicked);
}

bool PersonDataSet::eventFilter(QObject *watched, QEvent *event)
{
    if(watched==ui->lblHeadPic && event->type()==QEvent::Enter)
    {
        // 检查是否有新头像，如果有，就显示新头像移入/移出效果；如果没有，仍显示原头像的移入/移出效果。
        if(!m_changeHeadPath.isEmpty() && QFile(m_changeHeadPath).exists())
        {
            QPixmap head_pic;
            head_pic.load(m_changeHeadPath);
            QPixmap dark_head = pixmaptoRound(darkenImage(head_pic, 0.5), m_headSize);
            QPainter painter(&dark_head);
            painter.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
            QPixmap white_camera;
            white_camera.load(":/qqicons/qrc/white_camera.svg");
            painter.drawPixmap(dark_head.width()/2-30, dark_head.height()/2-30,
                               60, 60, white_camera);

            ui->lblHeadPic->setPixmap(dark_head);
        }
        else if(!m_headPic.isNull())
        {
            QPixmap dark_head = pixmaptoRound(darkenImage(m_headPic, 0.5), m_headSize);
            QPainter painter(&dark_head);
            painter.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
            QPixmap white_camera;
            white_camera.load(":/qqicons/qrc/white_camera.svg");
            painter.drawPixmap(dark_head.width()/2-30, dark_head.height()/2-30,
                               60, 60, white_camera);

            ui->lblHeadPic->setPixmap(dark_head);
        }
    }
    else if(watched==ui->lblHeadPic && event->type()==QEvent::Leave)
    {
        // 检查是否有新头像，如果有，就显示新头像移入/移出效果；如果没有，仍显示原头像的移入/移出效果。
        if(!m_changeHeadPath.isEmpty() && QFile(m_changeHeadPath).exists())
        {
            QPixmap head_pic;
            head_pic.load(m_changeHeadPath);
            head_pic = pixmaptoRound(head_pic, m_headSize);
            ui->lblHeadPic->setPixmap(head_pic);
        }
        else if(!m_headPic.isNull())
        {
            ui->lblHeadPic->setPixmap(m_headPic);
        }
    }
    else if(watched==ui->lblHeadPic && event->type()==QEvent::MouseButtonPress)
    {
        // 点击头像进行修改头像
        QString pic_path = QFileDialog::getOpenFileName(this, QStringLiteral("打开"),
                                                        QDir::homePath(),
                                                        QStringLiteral("图片(*.jpg *.jpeg *.png *.bmp *.svg)"));
        if(!pic_path.isEmpty())
        {
            QString tmp_new_head_path = Config::getInstance()->m_getLocalTmpPath() + "tmp_" +
                                        QString::number(Config::getInstance()->m_getLoginClientId()) + "." +
                                        QFileInfo(pic_path).suffix();
            if(QFile(tmp_new_head_path).exists())
                QFile(tmp_new_head_path).remove();
            QFile::copy(pic_path, tmp_new_head_path);       // 临时文件保存该图片
            if(!tmp_new_head_path.isEmpty())
            {
                QPixmap head_pic;
                head_pic.load(tmp_new_head_path);
                head_pic = pixmaptoRound(head_pic, m_headSize);
                ui->lblHeadPic->setPixmap(head_pic);
                m_changeHeadPath = tmp_new_head_path;
            }
        }
    }

    return QWidget::eventFilter(watched, event);
}

void PersonDataSet::slot_btnSaveSet_clicked()       // 按下“保存”
{
    if(ui->edtSetName->text().trimmed().isEmpty() || ui->edtSetSignature->text().trimmed().isEmpty())
    {
        QMessageBox::information(this, QStringLiteral("提示"), QStringLiteral("修改项不可为空！"));
        return;
    }
    QMap<QString, QVariant> _user_info;
    _user_info.insert("name", ui->edtSetName->text().trimmed().replace('\n', ' '));
    _user_info.insert("signature", ui->edtSetSignature->text().trimmed().replace('\n', ' '));
    _user_info.insert("age", ui->spbSetAge->value());
    QVariant cur_sex_text;
    if(ui->cmbSetSex->currentIndex() == 0)
    {
        cur_sex_text = QVariant::fromValue(nullptr);            // 未设置->NULL
    }
    else
    {
        cur_sex_text = ui->cmbSetSex->currentText().trimmed().replace('\n', ' ');  // 男、女、其他
    }
    _user_info.insert("sex", cur_sex_text);

    emit signal_userInfoSave(Config::getInstance()->m_getLoginClientId(), _user_info);
    // 更改了头像
    if(!m_changeHeadPath.isEmpty())
    {
        QPixmap head_pic;
        head_pic.load(m_changeHeadPath);
        head_pic = pixmaptoRound(head_pic, m_headSize);
        m_headPic = head_pic;
        QString head_path = Config::getInstance()->m_getLocalAccountPath() + "/head." + QFileInfo(m_changeHeadPath).suffix();
        Config::getInstance()->m_setLoginClientHead(head_path);
        if(QFile(head_path).exists())
            QFile(head_path).remove();
        QFile(m_changeHeadPath).rename(head_path);
        emit signal_userHeadSave(Config::getInstance()->m_getLoginClientId(), head_path);
        m_changeHeadPath.clear();
    }

    this->close();
}

void PersonDataSet::slot_btnCancelSet_clicked()     // 按下“取消”
{
    m_changeHeadPath.clear();
    this->close();
}

bool PersonDataSet::m_setUserInfoToUI(const sttClientInfo user_info)        // 刷新用户信息到界面
{
    try
    {
        QString head_path = Config::getInstance()->m_getLoginClientHead();
        if(!head_path.isEmpty())
        {
            ui->lblHeadPic->setStyleSheet("");
            QPixmap head_pic;
            head_pic.load(head_path);
            head_pic = pixmaptoRound(head_pic, m_headSize);
            m_headPic = head_pic;
            ui->lblHeadPic->setPixmap(m_headPic);
        }
        ui->edtSetName->setText(user_info.name);
        ui->edtSetSignature->setText(user_info.signature);
        if(user_info.sex.isEmpty())
        {
            ui->cmbSetSex->setCurrentIndex(0);
        }
        else
        {
            QString _sex = user_info.sex;
            if(_sex == QStringLiteral("男"))
                ui->cmbSetSex->setCurrentIndex(1);
            else if(_sex == QStringLiteral("女"))
                ui->cmbSetSex->setCurrentIndex(2);
            else if(_sex == QStringLiteral("其他"))
                ui->cmbSetSex->setCurrentIndex(3);
            else
                return false;
        }
        ui->spbSetAge->setValue(user_info.age);
    }
    catch(const std::exception& e)
    {
        qCritical() << "Exception caught: " << e.what();
        return false;
    }
    return true;
}

