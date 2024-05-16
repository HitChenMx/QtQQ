#include "AddFriendRequestWidget.h"
#include "ui_addfriendrequestwidget.h"

AddFriendRequestWidget::AddFriendRequestWidget(QWidget *parent, const sttClientInfo& client_info,
                                               const QPixmap& head_pic) :
    QWidget(parent),
    ui(new Ui::AddFriendRequestWidget),
    m_clientInfo(client_info),
    m_headPic(head_pic)
{
    ui->setupUi(this);
    LocalDatabase::getInstance()->m_queryAllGroupIdNames(&m_allGroupNames);

    // 把用户信息和分组信息显示在界面上
    if(m_headPic.isNull())
    {
        m_headPic.load(":/qqicons/qrc/QQicon.svg");
        m_headPic = pixmaptoRound(m_headPic, QSize(70, 70));
    }
    ui->lblHeadPic->setPixmap(m_headPic);
    ui->lblName->setText(m_clientInfo.name);
    ui->lblName->setToolTip(m_clientInfo.name);
    ui->lblAccount->setText(m_clientInfo.account);
    ui->lblAccount->setToolTip(m_clientInfo.account);

    for(QMap<quint32, QString>::const_iterator ite = m_allGroupNames.begin(); ite!=m_allGroupNames.end(); ++ite)
    {
        ui->cmbGroupSelect->addItem(ite.value());
    }

    // 信号与槽
    connect(ui->btnSend, &QPushButton::clicked, this, &AddFriendRequestWidget::slot_btnSend_clicked);
    connect(ui->btnCancel, &QPushButton::clicked, this, &AddFriendRequestWidget::slot_btnCancel_clicked);

    this->setWindowFlags(Qt::Window);
}

AddFriendRequestWidget::~AddFriendRequestWidget()
{
    delete ui;
}

QPixmap AddFriendRequestWidget::m_getHeadPic() const
{
    return m_headPic;
}

void AddFriendRequestWidget::slot_btnSend_clicked()
{
    if(m_allGroupNames.isEmpty())      // 没有分组，无法添加好友
    {
        this->close();
        return;
    }
    int _index = ui->cmbGroupSelect->currentIndex();
    if(_index >= m_allGroupNames.size())
        return;
    quint32 select_group_id = (m_allGroupNames.begin()+_index).key();

    emit signal_tryAddFriend(Config::getInstance()->m_getLoginClientId(), m_clientInfo, ui->edtAuthInfo->toPlainText().trimmed(), select_group_id);
    this->close();
}

void AddFriendRequestWidget::slot_btnCancel_clicked()
{
    this->close();
}

void AddFriendRequestWidget::slot_updateGroupNames()
{
    LocalDatabase::getInstance()->m_queryAllGroupIdNames(&m_allGroupNames);

    ui->cmbGroupSelect->clear();
    for(QMap<quint32, QString>::const_iterator ite = m_allGroupNames.begin(); ite!=m_allGroupNames.end(); ++ite)
    {
        ui->cmbGroupSelect->addItem(ite.value());
    }
}
