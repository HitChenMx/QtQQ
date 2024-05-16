#include "ChatMessageWidget.h"
#include "ui_ChatMessageWidget.h"

ChatMessageWidget::ChatMessageWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChatMessageWidget)
{
    ui->setupUi(this);
    connect(ui->btnChatMessageSend, &QPushButton::clicked, this, &ChatMessageWidget::slot_btnChatMessageSend_clicked);
    connect(ui->btnChatPicture, &QPushButton::clicked, this, &ChatMessageWidget::slot_btnChatPicture_clicked);
    connect(this, &ChatMessageWidget::signal_reqAsmSendChatMsg, AssembleBytes::getInstance(), &AssembleBytes::slot_asmSendChatMsg);
    connect(this, &ChatMessageWidget::signal_reqAsmSendChatPic, AssembleBytes::getInstance(), &AssembleBytes::slot_asmSendChatPic);
}

ChatMessageWidget::~ChatMessageWidget()
{
    delete ui;
}

void ChatMessageWidget::m_setChatFriend(const quint32 friend_id)
{
    m_friendId = friend_id;
    QString chat_name;
    bool _query_success = LocalDatabase::getInstance()->m_queryFriendName(m_friendId, &chat_name);
    if(_query_success)
    {
        QFontMetrics name_fontWidth(ui->lblChatFriendName->font());
        QString name_elideNote = name_fontWidth.elidedText(chat_name, Qt::ElideRight, ui->lblChatFriendName->width()-10);
        ui->lblChatFriendName->setText(name_elideNote);
    }
}

void ChatMessageWidget::m_appendChatMsgToUI(const sttChatMsgInfo& chat_log)
{
    QDateTime date_time = QDateTime::fromString(chat_log.time, Qt::ISODate);
    // 计算上一条消息和当前消息的时间差，从而决定是否要添加一条系统消息来显示时间
    QDateTime last_time = ui->lstChatMsgShow->m_getLastMsgTime();
    int secs_past = std::abs(last_time.secsTo(date_time));
    if(secs_past >= 5*60)
    {
        // 再根据当前消息时间和当前时刻，来决定以哪种格式来显示时间
        QString time_str = date_time.toString("yyyy/MM/dd hh:mm");
        QDateTime time_now = QDateTime::currentDateTime();
        if(date_time.date().year() == time_now.date().year())
        {
            // 如果是同一年：月/日 时/分
            time_str = date_time.toString("MM/dd hh:mm");
            if(date_time.date() == time_now.date())
            {
                // 如果是同一天：时/分
                time_str = date_time.toString("hh:mm");
            }
        }
        ui->lstChatMsgShow->m_addSystemNotice(date_time, time_str);
    }
    ui->lstChatMsgShow->m_addChatBubbleBox(chat_log);
}

void ChatMessageWidget::slot_btnChatMessageSend_clicked()
{
    // QString msg_send = ui->edtChatMessageInput->toHtml();
    QString msg_send = ui->edtChatMessageInput->toPlainText();
    if(msg_send.isEmpty())
    {
        return;
    }

    QDateTime _cur_dateTime = QDateTime::currentDateTime();
    QString _send_msg_time = _cur_dateTime.toString("yyyy-MM-dd hh:mm:ss");
    sttChatMsgInfo chat_log;
    chat_log.send_id = Config::getInstance()->m_getLoginClientId();
    chat_log.receiver_id = m_friendId;
    chat_log.time = _send_msg_time;
    chat_log.msg_type = ChatType::IsTextMsg;
    chat_log.message = msg_send;

    // 把发送的消息显示在界面上
    m_appendChatMsgToUI(chat_log);
    ui->edtChatMessageInput->clear();
    ui->edtChatMessageInput->setFocus();

    // 写入本地数据库
    LocalDatabase::getInstance()->m_insertChatLog(chat_log);

    emit signal_reqAsmSendChatMsg(Config::getInstance()->m_getLoginClientId(), m_friendId, msg_send);
    emit signal_newMessage(_cur_dateTime, msg_send);
}

void ChatMessageWidget::m_showChatLogMsg()
{
    m_showChatLogMsg(nullptr);
}

void ChatMessageWidget::m_showChatLogMsg(const int* const log_num)
{
    QVector<sttChatMsgInfo> chat_logs;
    bool _query_success = LocalDatabase::getInstance()->m_queryChatLog(Config::getInstance()->m_getLoginClientId(), m_friendId, &chat_logs, log_num);
    if(_query_success)
    {
        ui->lstChatMsgShow->clear();
        for(QVector<sttChatMsgInfo>::const_iterator ite = chat_logs.begin(); ite!=chat_logs.end(); ++ite)
        {
            m_appendChatMsgToUI(*ite);
        }
    }
}

void ChatMessageWidget::slot_btnChatPicture_clicked()
{
    QString chat_img_path = QFileDialog::getOpenFileName(this, QStringLiteral("打开"),
                                                         QDir::homePath(),
                                                         QStringLiteral("图片(*.jpg *.jpeg *.png *.bmp *.svg)"));
    if(chat_img_path.isEmpty())
        return;
    int pic_max_MB = ChatType::PicMaxSize / 1024 / 1024;
    if(QFile(chat_img_path).size() > ChatType::PicMaxSize)
    {
        QMessageBox::information(this, QStringLiteral("提示"), QStringLiteral("无法发送超过")+QString::number(pic_max_MB)+QStringLiteral("MB的文件"));
        return;
    }

    QDateTime _cur_dateTime = QDateTime::currentDateTime();
    QString _send_msg_time = _cur_dateTime.toString("yyyy-MM-dd hh:mm:ss");
    sttChatMsgInfo chat_log;
    chat_log.send_id = Config::getInstance()->m_getLoginClientId();
    chat_log.receiver_id = m_friendId;
    chat_log.time = _send_msg_time;
    chat_log.msg_type = ChatType::IsFileMsg;
    QString new_chat_img_path = Config::getInstance()->m_getLocalChatPicsPath() + "/" + QString::number(chat_log.send_id) +
                                "_" + _cur_dateTime.toString("yyyy_MM_dd_hh_mm_ss") + "." + QFileInfo(chat_img_path).suffix();
    QFile(chat_img_path).copy(new_chat_img_path);
    chat_log.message = new_chat_img_path;

    // 把发送的图片显示在界面上
    m_appendChatMsgToUI(chat_log);
    ui->edtChatMessageInput->clear();
    ui->edtChatMessageInput->setFocus();

    // 写入本地数据库
    LocalDatabase::getInstance()->m_insertChatLog(chat_log);

    emit signal_reqAsmSendChatPic(Config::getInstance()->m_getLoginClientId(), m_friendId, new_chat_img_path);
}
