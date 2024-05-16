#include "LeftBar.h"

LeftBar::LeftBar(QWidget *parent) :
    QFrame(parent),
    m_PsnDataShow(nullptr),
    m_PsnDataSet(nullptr)
{
    setWindowFlag(Qt::FramelessWindowHint);     // 必须要有这句以及最后的layout->setContentsMargins(0,0,0,0);
    setFixedWidth(91);      // 注意和mainwindow.ui中被提升的控件所设置的固定宽度要一致
    setFrameShape(QFrame::Box);

    m_lblHeadPic = new QLabel(this);
    QPixmap head_pic;
    QSize head_size(58, 58);
    head_pic.load(":/qqicons/qrc/QQicon.svg");
    head_pic = pixmaptoRound(head_pic, head_size);
    m_lblHeadPic->setPixmap(head_pic);
    m_lblHeadPic->setFixedSize(head_size);
    m_lblHeadPic->installEventFilter(this);

    m_btnInformation = new InfoButton(this);
    m_btnInformation->setToolTip(QStringLiteral("消息"));
    m_btnInformation->setCheckable(true);
    m_btnInformation->setStyleSheet("QPushButton{                              "
                                    "    border: none;                         "
                                    "}                                         "
                                    "                                          "
                                    "QPushButton:checked{                      "
                                    "    border-radius: 10px;                  "
                                    "    background-color: rgb(229, 229, 229); "
                                    "}");
    m_btnInformation->setIcon(QIcon(":/qqicons/qrc/information.svg"));
    m_btnInformation->setIconSize(QSize(40, 40));
    m_btnInformation->setObjectName("btnInformation");
    m_btnInformation->setFixedSize(86, 62);

    m_btnFriends = new InfoButton(this);
    m_btnFriends->setToolTip(QStringLiteral("联系人"));
    m_btnFriends->setCheckable(true);
    m_btnFriends->setStyleSheet("QPushButton{                              "
                                "    border: none;                         "
                                "}                                         "
                                "                                          "
                                "QPushButton:checked{                      "
                                "    border-radius: 10px;                  "
                                "    background-color: rgb(229, 229, 229); "
                                "}");
    m_btnFriends->setIcon(QIcon(":/qqicons/qrc/friends.svg"));
    m_btnFriends->setIconSize(QSize(40, 40));
    m_btnFriends->setObjectName("btnFriends");
    m_btnFriends->setFixedSize(86, 62);

    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addStretch(1);
    layout->addWidget(m_lblHeadPic, 0, Qt::AlignCenter);
    layout->addStretch(1);
    layout->addWidget(m_btnInformation, 0, Qt::AlignCenter);
    layout->addStretch(1);
    layout->addWidget(m_btnFriends, 0, Qt::AlignCenter);
    layout->addStretch(30);
    layout->setSpacing(0);
    layout->setContentsMargins(0,0,0,0);

    // 信号与槽
    connect(m_btnInformation, &InfoButton::clicked, this, &LeftBar::slot_buildTabwidget);
    connect(m_btnFriends, &InfoButton::clicked, this, &LeftBar::slot_buildTabwidget);
    connect(m_btnInformation, &InfoButton::clicked, this, &LeftBar::slot_btnInformation_clicked);
    connect(m_btnFriends, &InfoButton::clicked, this, &LeftBar::slot_btnFriends_clicked);
    connect(this, &LeftBar::signal_queryUserHeadPic, AssembleBytes::getInstance(), &AssembleBytes::slot_asmRequestUserHeadPic);

    m_btnInformation->click();      // 初始处于消息界面
}

bool LeftBar::eventFilter(QObject *watched, QEvent *event)
{
    if(watched==m_lblHeadPic && event->type() == QEvent::MouseButtonPress)
    {
        // 鼠标点击头像，弹出用户信息界面
        this->slot_lblHeadPic_clicked();
    }

    return QWidget::eventFilter(watched, event);
}

void LeftBar::m_informationAppendUnreadNum(const int &num)
{
    m_btnInformation->m_appendUnreadNum(num);
}

void LeftBar::m_friendsAppendUnreadNum(const int &num)
{
    m_btnFriends->m_appendUnreadNum(num);
}

void LeftBar::m_informationSetUnreadNum(const int &num)
{
    m_btnInformation->m_setUnreadNum(num);
}

void LeftBar::m_friendsSetUnreadNum(const int &num)
{
    m_btnFriends->m_setUnreadNum(num);
}

void LeftBar::m_clickInformation()
{
    m_btnInformation->click();
}

void LeftBar::m_clickFriends()
{
    m_btnFriends->click();
}

void LeftBar::m_querySelfHeadPic()
{
    emit signal_queryUserHeadPic(Config::getInstance()->m_getLoginClientId());
}

void LeftBar::m_setHeadPic(const QString &head_path)
{
    QPixmap head_pic;
    QSize head_size = m_lblHeadPic->size();
    head_pic.load(head_path);
    head_pic = pixmaptoRound(head_pic, head_size);
    m_lblHeadPic->setPixmap(head_pic);
}

void LeftBar::slot_btnInformation_clicked()      // 点击消息
{
    emit signal_openInfomationPage();
}

void LeftBar::slot_btnFriends_clicked()          // 点击朋友
{
    emit signal_openFriendsPage();
}

void LeftBar::slot_buildTabwidget()          // 手动构建tab标签页
{
    QStringList objName_list = {"btnInformation", "btnFriends"};
    QPushButton* object = qobject_cast<QPushButton*>(sender());
    QString _object_name = object->objectName();                    // 按下的button对象名称
    object->setChecked(true);
    QString icon_path = ":qqicons/qrc/" + _object_name.split("btn").at(1).toLower() + "_blue.svg";
    object->setIcon(QIcon(icon_path));

    // 要求objName_list必须包含_object_name
    if(!objName_list.contains(_object_name))
    {
        QMessageBox::critical(this, "error", QString("Error: objName_list must contains %2, please check mainwindow.cpp.").arg(_object_name));
        abort();
    }

    for(const QString _iter_obj : objName_list)
    {
        if(_object_name != _iter_obj)
        {
            // 其他的button都不被选中
            QPushButton* btnOther = this->findChild<QPushButton*>(_iter_obj, Qt::FindChildrenRecursively);
            if(btnOther)
            {
                btnOther->setChecked(false);
                QString iconOther_path = ":qqicons/qrc/" + _iter_obj.split("btn").at(1).toLower() + ".svg";
                btnOther->setIcon(QIcon(iconOther_path));
            }
        }
    }
}

void LeftBar::slot_lblHeadPic_clicked()         // 点击头像
{
    if(m_PsnDataShow == nullptr)
    {
        m_PsnDataShow = new PersonDataShow(this);
        m_PsnDataShow->setAttribute(Qt::WA_DeleteOnClose);
        connect(m_PsnDataShow, &PersonDataShow::destroyed, [this](){
            m_PsnDataShow->deleteLater();
            m_PsnDataShow = nullptr;
        });
        connect(m_PsnDataShow, &PersonDataShow::signal_userInfoEdit, this, &LeftBar::slot_editUserInfo);
    }
    bool _success = m_PsnDataShow->m_setUserInfoToUI(Config::getInstance()->m_getLoginClientInfo(),
                                                     Config::getInstance()->m_getLoginClientHead());     // 界面刷新用户信息
    if(_success == false)
    {
        QMessageBox::warning(this, "提示", "用户信息刷新失败");
    }
    QPoint _pos = m_lblHeadPic->mapToGlobal(QPoint(0, 0)) + QPoint(m_lblHeadPic->rect().width()-2, 0);
    // qDebug() << "popup window's position: " << _pos;
    m_PsnDataShow->move(_pos);
    m_PsnDataShow->show();
}

void LeftBar::slot_editUserInfo()               // 修改用户信息
{
    if(m_PsnDataSet == nullptr)
    {
        m_PsnDataSet = new PersonDataSet(this);
        m_PsnDataSet->setAttribute(Qt::WA_DeleteOnClose);
        connect(m_PsnDataSet, &PersonDataSet::destroyed, [this](){
            m_PsnDataSet->deleteLater();
            m_PsnDataSet = nullptr;
        });
        connect(m_PsnDataSet, &PersonDataSet::signal_userInfoSave, AssembleBytes::getInstance(), &AssembleBytes::slot_asmModifyUserInfo);
        connect(m_PsnDataSet, &PersonDataSet::signal_userHeadSave, [this](const quint32 user_id, const QString head_path){
            this->m_setHeadPic(head_path);
        });
        connect(m_PsnDataSet, &PersonDataSet::signal_userHeadSave, AssembleBytes::getInstance(), &AssembleBytes::slot_asmModifyUserHead);
    }
    bool _success = m_PsnDataSet->m_setUserInfoToUI(Config::getInstance()->m_getLoginClientInfo());      // 界面刷新用户信息
    if(_success == false)
    {
        QMessageBox::warning(this, "提示", "用户信息刷新失败");
    }
//    QPoint _pos = this->mapToGlobal(this->rect().center()) - QPoint(m_PsnDataSet->width()/2, m_PsnDataSet->height()/2);
//    m_PsnDataSet->move(_pos);
    m_PsnDataSet->show();
}
