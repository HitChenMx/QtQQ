#include "SearchUserLittleBox.h"
#include "ui_searchuserlittlebox.h"
#include "mainwindow.h"                 // 在cpp文件里include，不会有循环引用的问题


SearchUserLittleBox::SearchUserLittleBox(QWidget *parent, const sttFriendInfo user_info,
                                         const QString search_text, const QString head_path) :
    QWidget(parent),
    ui(new Ui::SearchUserLittleBox),
    m_userInfo(user_info),
    m_searchText(search_text),
    m_mouseIn(false),
    m_headPic(QPixmap())
{
    ui->setupUi(this);

    // 显示用户信息
    if(m_searchText.isEmpty())
    {
        ui->lblName->setText(m_userInfo.name);
        ui->lblAccount->setText(m_userInfo.account);
    }
    else
    {
        ui->lblName->setText(m_userInfo.name);
        ui->lblAccount->setText(m_userInfo.account);
        bool _text_is_allDigits;    // 是否全是数字
        m_searchText.toInt(&_text_is_allDigits);
        if(_text_is_allDigits)
        {
            // 对account中的搜索文本高亮
            QString account_text = m_userInfo.account;
            if(account_text.contains(m_searchText))
            {
                int start_pos = account_text.indexOf(search_text);
                int end_pos = start_pos + search_text.size();
                QString account_rich_text = "<html><head/><body><p><span style=\" color:#55aaff;\">";
                account_rich_text += search_text;
                account_rich_text += "</span>";
                account_rich_text += account_text.right(account_text.size() - end_pos);
                account_rich_text += "</p></body></html>";
                ui->lblAccount->setText(account_rich_text);
            }
        }
        else
        {
            // 对name中的搜索文本高亮
            QString name_text = m_userInfo.name;
            if(name_text.contains(m_searchText))
            {
                int start_pos = name_text.indexOf(search_text);
                int end_pos = start_pos + search_text.size();
                QString name_rich_text = "<html><head/><body><p><span style=\" color:#55aaff;\">";
                name_rich_text += search_text;
                name_rich_text += "</span>";
                name_rich_text += name_text.right(name_text.size() - end_pos);
                name_rich_text += "</p></body></html>";
                ui->lblName->setText(name_rich_text);
            }
        }
    }
    QPixmap head_pic;
    head_pic.load(head_path);
    head_pic = pixmaptoRound(head_pic, QSize(70, 70));
    m_headPic = head_pic;
    ui->lblHeadPic->setPixmap(head_pic);
    int stkw_page_index = m_userInfo.group_id == 0? 0:1;
    ui->stkwButtonSelect->setCurrentIndex(stkw_page_index);

    // 信号与槽
    connect(ui->btnAddFriend, &QPushButton::clicked, this, &SearchUserLittleBox::slot_btnAddFriend_clicked);
    connect(ui->btnSendMessage, &QPushButton::clicked, this, &SearchUserLittleBox::slot_btnSendMessage_clicked);
}

SearchUserLittleBox::~SearchUserLittleBox()
{
    delete ui;
}

quint32 SearchUserLittleBox::m_getFriendId() const
{
    return m_userInfo.id;
}

void SearchUserLittleBox::m_setHeadPic(const QString &head_path)
{
    if(head_path.isEmpty() || !QFile(head_path).exists())
        return;

    QPixmap head_pic;
    head_pic.load(head_path);
    head_pic = pixmaptoRound(head_pic, QSize(70, 70));
    m_headPic = head_pic;
    ui->lblHeadPic->setPixmap(head_pic);
}

bool SearchUserLittleBox::event(QEvent *event)
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

void SearchUserLittleBox::paintEvent(QPaintEvent *event)
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
    QWidget::paintEvent(event);
}

void SearchUserLittleBox::slot_btnAddFriend_clicked()
{
    // 找到主界面mainwindow
    MainWindow* main_window;
    for(QWidget* w_traceTop = this; (main_window = qobject_cast<MainWindow*>(w_traceTop->parentWidget()))==nullptr; )
    {
        if(w_traceTop->parentWidget() == nullptr)
            break;
        w_traceTop=w_traceTop->parentWidget();
    }
    if(main_window == nullptr)
        return;

    // 创建添加好友界面，并显示
    sttClientInfo _client_info;
    _client_info.id = m_userInfo.id;
    _client_info.account = m_userInfo.account;
    _client_info.name = m_userInfo.name;
    _client_info.level = m_userInfo.level;
    _client_info.signature = m_userInfo.signature;
    _client_info.sex = m_userInfo.sex;
    _client_info.age = m_userInfo.age;
    _client_info.last_online = m_userInfo.last_online;
    AddFriendRequestWidget* wAddFriend = new AddFriendRequestWidget(main_window, _client_info, m_headPic);
    wAddFriend->setAttribute(Qt::WA_DeleteOnClose);
    connect(wAddFriend, &AddFriendRequestWidget::destroyed, [wAddFriend]() mutable {
        wAddFriend->deleteLater();
        wAddFriend = nullptr;
    });
    connect(wAddFriend, &AddFriendRequestWidget::signal_tryAddFriend, AssembleBytes::getInstance(), &AssembleBytes::slot_asmAddFriend);
    connect(wAddFriend, &AddFriendRequestWidget::signal_tryAddFriend, main_window, &MainWindow::slot_launchAddFriendRequest);
    connect(main_window, &MainWindow::signal_updateGroupNames, wAddFriend, &AddFriendRequestWidget::slot_updateGroupNames);
    wAddFriend->show();
}

void SearchUserLittleBox::slot_btnSendMessage_clicked()
{
    emit signal_sendMsgToFriend(m_userInfo.id);
}
