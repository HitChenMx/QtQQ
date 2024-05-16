#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QSharedPointer<TcpSocketManager> socket_manager, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_socketManager(socket_manager),
    m_searchFriend(nullptr)
{
    ui->setupUi(this);
    // 让界面显示在显示屏1的中间
    int screenWidth = QApplication::desktop()->screenGeometry(0).width();
    int screenHeight = QApplication::desktop()->screenGeometry(0).height();
    this->move(screenWidth/2-this->width()/2, screenHeight/2-this->height()/2);

    m_init();
    ui->trFriendLists->m_queryAllFriendOnlineState();       // 查询所有好友的在线状态
    ui->frmTab->m_querySelfHeadPic();                       // 查询登录用户的头像
    ui->trFriendLists->m_queryAllFriendHeadPic();           // 查询所有好友的头像
}

MainWindow::~MainWindow()
{
    qDebug() << QThread::currentThread() << " ========================================================== " << "~MainWindow()";
    // 等待socket和线程先被释放掉
    emit signal_closeSocketThread();
    m_socketManager->thread()->wait(2000);
    m_socketManager.reset();
    // 清除临时文件夹tmp
    QString tmp_folder_path = Config::getInstance()->m_getLocalTmpPath();
    if(!tmp_folder_path.isEmpty() && QDir(tmp_folder_path).exists())
    {
        bool remove_success = QDir(tmp_folder_path).removeRecursively();
        if(remove_success)
            QDir().mkdir(tmp_folder_path);
    }

    delete ui;
}

void MainWindow::m_init()
{
    qDebug() << QThread::currentThread() << " ========================================================== " << "MainWindow thread";
    ui->stkwThumbnail->setCurrentIndex(0);
    ui->stkwDetail->setCurrentIndex(0);
    QFile style_scrollBar(":/setfile/setup/scrollbar.qss");
    if(style_scrollBar.open(QFile::ReadOnly))
    {
        ui->trFriendLists->setStyleSheet(style_scrollBar.readAll());
        style_scrollBar.close();
    }

    // ------------------ 界面控件相关的信号与槽 ------------------
    connect(ui->frmTab, &LeftBar::signal_openInfomationPage, [this](){          // 打开消息页面
        ui->stkwThumbnail->setCurrentIndex(0);
        if(ui->frmInfoList->m_getFriendIdOfChatting() == 0)
        {
            ui->stkwDetail->setCurrentIndex(0);
        }
        else
        {
            ui->stkwDetail->setCurrentIndex(1);
        }
    });
    connect(ui->frmTab, &LeftBar::signal_openFriendsPage, [this](){             // 打开好友页面
        ui->stkwThumbnail->setCurrentIndex(1);
        ui->stkwDetail->setCurrentIndex(0);
        // 刷新好友通知的未读消息个数，防止显示位置错误
        ui->btnFriendsInfo->m_setUnreadNum();
    });
    connect(ui->frmInfoList, &InfoListWidget::signal_InfoLittleBox_clicked, [this](const quint32 friend_id, const int already_read_msg_num){      // 点击消息框
        ui->frmTab->m_clickInformation();
        ui->stkwThumbnail->setCurrentIndex(0);
        ui->stkwDetail->setCurrentIndex(1);
        // 设置和哪个好友聊天
        ui->pageChatMessage->m_setChatFriend(friend_id);
        // 更新未读消息
        ui->frmTab->m_informationAppendUnreadNum(-already_read_msg_num);
        // 显示历史消息
        int show_chat_log_num = 100;
        ui->pageChatMessage->m_showChatLogMsg(&show_chat_log_num);
    });
    connect(ui->pageChatMessage, &ChatMessageWidget::signal_newMessage, [this](const QDateTime time, const QString msg){       // 新的聊天消息
        // 更新正在聊天的消息框的显示文本
        ui->frmInfoList->m_updateInfoBoxOfChatting(time, msg);
    });
    connect(ui->trFriendLists, &FriendListWidget::signal_friendBox_clicked, [this](const quint32 friend_id){       // 点击朋友框
        ui->stkwDetail->setCurrentIndex(2);
        ui->pageFriendInfo->m_setChatFriend(friend_id, ui->trFriendLists->m_getFriendOnlineState(friend_id));
    });
    connect(ui->pageFriendInfo, &FriendInfoWidget::signal_reqOpenChatWithFriend, [this](const quint32 friend_id){      // 打开与该好友的聊天页面
        ui->frmInfoList->m_clickInfoLittleBox(friend_id);
    });
    connect(ui->trFriendLists, &FriendListWidget::signal_renameGroup_query, [this](){
        emit signal_updateGroupNames();
    });
    connect(ui->btnAddFriend, &QPushButton::clicked, this, &MainWindow::slot_btnAddFriend_clicked);
    connect(ui->btnFriendsInfo, &ExpandButton::clicked, this, &MainWindow::slot_btnFriendsInfo_clicked);
    connect(ui->pageFriendNotice, &FriendNoticeWidget::signal_newUnreadNotice, [this](){            // 新的未读好友通知
        ui->frmTab->m_friendsAppendUnreadNum(1);
        ui->btnFriendsInfo->m_appendUnreadNum(1);
        if(ui->stkwDetail->currentIndex() == 3)
        {
            ui->frmTab->m_friendsSetUnreadNum(0);
            ui->btnFriendsInfo->m_setUnreadNum(0);
        }
    });
    connect(ui->pageFriendNotice, &FriendNoticeWidget::signal_newFriend, [this](const quint32 friend_id){       // 新的好友
        sttFriendInfo new_friend_info;
        bool _query_success = LocalDatabase::getInstance()->m_queryFriendInfo(friend_id, &new_friend_info);
        if(_query_success)
        {
            // 添加到好友列表，创建一个消息框提示已添加为好友
            ui->trFriendLists->m_addFriendBox2group(new_friend_info, FriendLittleBox::Online);
            InfoLittleBox* new_friend_info_box = ui->frmInfoList->m_addInfoboxIfNotExist(0, friend_id);
            new_friend_info_box->m_setInfoPreview(QStringLiteral("你们已成功添加为好友"));
            new_friend_info_box->m_setDate(QDateTime::currentDateTime());

            // 向服务端请求新的好友
            ui->trFriendLists->m_querySingleFriendHeadPic(friend_id);
        }
    });
    connect(ui->pageFriendInfo, &FriendInfoWidget::signal_reqMoveFriendToGroup, [this](const quint32 user_id, const quint32 friend_id, const quint32 group_id){        // 移动好友至指定分组
        if(user_id != Config::getInstance()->m_getLoginClientId())
            return;
        ui->trFriendLists->m_moveFriendToGroup(friend_id, group_id);
        // 更新到本地数据库
        LocalDatabase::getInstance()->m_modifyFriendInWhichGroup(friend_id, group_id);
    });
    connect(this, &MainWindow::signal_updateGroupNames, ui->pageFriendInfo, &FriendInfoWidget::slot_updateGroupNames);




    // ------------------ socket管理对象相关的信号与槽 ------------------
    connect(this, &MainWindow::signal_closeSocketThread, m_socketManager.data(), &TcpSocketManager::slot_closeSocket);
    // 组数据包完毕直接交由socket管理对象发出去
    connect(AssembleBytes::getInstance(), &AssembleBytes::signal_assembleBytesDone, m_socketManager.data(), &TcpSocketManager::slot_socketWrite);
    connect(m_socketManager.data(), &TcpSocketManager::signal_modifyUserInfoSuccess, [](const sttClientInfo client_info){
        Config::getInstance()->m_setLoginClientInfo(client_info);
        qDebug() << "modify user info successfully.";
    });
    connect(m_socketManager.data(), &TcpSocketManager::signal_modifyUserInfoFailed, [](){
        qDebug() << "modify user info failed.";
    });
    connect(m_socketManager.data(), &TcpSocketManager::signal_receiveChatMsg, this, &MainWindow::slot_receiveChatMessage);
    connect(m_socketManager.data(), &TcpSocketManager::signal_addGroupSuccess, ui->trFriendLists, &FriendListWidget::slot_addGroup_success);
    connect(m_socketManager.data(), &TcpSocketManager::signal_addGroupSuccess, [this](const quint32 new_group_id, const QString group_name){
        LocalDatabase::getInstance()->m_replaceIntotGroupInfo(new_group_id, group_name);
        emit signal_updateGroupNames();
    });
    connect(m_socketManager.data(), &TcpSocketManager::signal_userOnline, [this](const quint32 user_id){
        ui->trFriendLists->m_setFriendOnlineState(user_id, FriendLittleBox::Online);
        ui->pageFriendInfo->m_setFriendOnlineState(user_id, FriendLittleBox::Online);
    });
    connect(m_socketManager.data(), &TcpSocketManager::signal_userOffline, [this](const quint32 user_id){
        ui->trFriendLists->m_setFriendOnlineState(user_id, FriendLittleBox::Offline);
        ui->pageFriendInfo->m_setFriendOnlineState(user_id, FriendLittleBox::Offline);
    });
    connect(m_socketManager.data(), &TcpSocketManager::signal_receiveUpdateFriendInfo, this, &MainWindow::slot_updateFriendInfo);
    connect(m_socketManager.data(), &TcpSocketManager::signal_receiveAddFriendRequest, this, &MainWindow::slot_receiveAddFriendRequest);
    connect(m_socketManager.data(), &TcpSocketManager::signal_receiveRejectAddFriendRequest, ui->pageFriendNotice, &FriendNoticeWidget::slot_receiveRejectAddFriendRequest);
    connect(m_socketManager.data(), &TcpSocketManager::signal_receiveAgreeAddFriendRequest, ui->pageFriendNotice, &FriendNoticeWidget::slot_receiveAgreeAddFriendRequest);
    connect(m_socketManager.data(), &TcpSocketManager::signal_receiveUserHeadPic, this, &MainWindow::slot_receiveUserHeadPic);
    connect(m_socketManager.data(), &TcpSocketManager::signal_receiveChatPic, this, &MainWindow::slot_receiveChatPicture);
}

void MainWindow::slot_receiveChatMessage(const quint32 send_id, const quint32 rcv_id, const QString chat_msg)
{
    if(rcv_id != Config::getInstance()->m_getLoginClientId())
        return;

    // 聊天记录写入本地数据库
    QDateTime _cur_dateTime = QDateTime::currentDateTime();
    QString _receive_msg_time = _cur_dateTime.toString("yyyy-MM-dd hh:mm:ss");
    sttChatMsgInfo chat_log;
    chat_log.send_id = send_id;
    chat_log.receiver_id = rcv_id;
    chat_log.time = _receive_msg_time;
    chat_log.msg_type = ChatType::IsTextMsg;
    chat_log.message = chat_msg;
    LocalDatabase::getInstance()->m_insertChatLog(chat_log);

    // 直接让左侧tab栏的“消息”的未读消息+1，然后frmInfoList再根据如果正处于与该好友的聊天界面，就点击一下消息框，这样就会再次更新未读消息个数
    ui->frmTab->m_informationAppendUnreadNum(1);
    bool _is_in_chat_page = ui->stkwDetail->currentIndex() == 1;
    ui->frmInfoList->m_doReceiveNewMessage(send_id, _cur_dateTime, chat_msg, _is_in_chat_page);
}

void MainWindow::slot_updateFriendInfo(const quint32& friend_id, const sttFriendInfo& friend_update_info)
{
    LocalDatabase::getInstance()->m_replaceIntoFriendInfo(friend_update_info);
    ui->trFriendLists->m_setFriendBoxInfo(friend_id, friend_update_info.name, friend_update_info.signature);
    if(ui->pageFriendInfo->m_getFriendId() == friend_id)
    {
        ui->pageFriendInfo->m_setChatFriend(friend_id, ui->trFriendLists->m_getFriendOnlineState(friend_id));
    }
    ui->frmInfoList->m_checkUpdateInfoBox(friend_id);
}

void MainWindow::slot_btnAddFriend_clicked()
{
    if(m_searchFriend == nullptr)
    {
        m_searchFriend = new SearchFriendWidget(this);
        m_searchFriend->setAttribute(Qt::WA_DeleteOnClose);
        connect(m_searchFriend, &SearchFriendWidget::destroyed, [this](){
            m_searchFriend->deleteLater();
            m_searchFriend = nullptr;
        });
        connect(m_socketManager.data(), &TcpSocketManager::signal_receiveSearchUserRecords, m_searchFriend, &SearchFriendWidget::slot_updateSearchRecords);
        connect(m_searchFriend, &SearchFriendWidget::signal_sendMsgToFriend, [this](const quint32 friend_id){
            ui->frmInfoList->m_clickInfoLittleBox(friend_id);
        });
    }

    m_searchFriend->show();
}

void MainWindow::slot_launchAddFriendRequest(const quint32 send_id, const sttClientInfo rcv_client_info,
                                             const QString verify_msg, const quint32 which_group_id)
{
    // 把添加好友请求 添加到 好友通知页面中，此时发送字节流由assemblebytes组完数据包发送
    QPixmap head_pic = QPixmap();
    head_pic.load(":/qqicons/qrc/QQicon.svg");
    head_pic = pixmaptoRound(head_pic, QSize(70, 70));
    AddFriendRequestWidget* add_friend_widget = qobject_cast<AddFriendRequestWidget*>(sender());
    if(add_friend_widget)
    {
        // 好友通知框的头像取决于添加好友时的对方头像
        head_pic = add_friend_widget->m_getHeadPic();
    }
    ui->pageFriendNotice->m_replaceIntoFriendNoticeBox(send_id, rcv_client_info, verify_msg, which_group_id, head_pic);
}

void MainWindow::slot_btnFriendsInfo_clicked()
{
    ui->stkwDetail->setCurrentIndex(3);
    ui->frmTab->m_friendsSetUnreadNum(0);
    ui->btnFriendsInfo->m_setUnreadNum(0);

    // 把所有的好友通知框都设置为已读
    ui->pageFriendNotice->m_setAllNoticeAlreadyRead();
}

void MainWindow::slot_receiveAddFriendRequest(const quint32 rcv_id, const sttClientInfo send_user_info,
                                              const QString verify_msg, const quint32 group_id)
{
    if(rcv_id == Config::getInstance()->m_getLoginClientId())
    {
        ui->pageFriendNotice->m_replaceIntoFriendNoticeBox(send_user_info.id, send_user_info, verify_msg, group_id);
    }
}

void MainWindow::slot_receiveUserHeadPic(const quint32 user_id, const QString pic_path)
{
    qDebug() << "receive head picture of" << user_id;
    QVector<quint32> friend_id_lists;
    LocalDatabase::getInstance()->m_queryAllFriendId(&friend_id_lists);
    QVector<quint32> search_id_lists;
    if(m_searchFriend)
    {
        search_id_lists = m_searchFriend->m_getResultUserIds();
    }
    QVector<quint32> notice_id_lists = ui->pageFriendNotice->m_getNoticeUserIds();
    if(user_id == Config::getInstance()->m_getLoginClientId())      // --- 自己的头像 ---
    {
        qDebug() << "it is self head picture.";
        // 删除旧头像
        QString old_head_path = Config::getInstance()->m_getLoginClientHead();
        if(!old_head_path.isEmpty() && QFile(old_head_path).exists())
            QFile(old_head_path).remove();

        // 重命名、复制该图片
        QString _suffix = QFileInfo(pic_path).suffix();
        QString new_pic_path = Config::getInstance()->m_getLocalAccountPath() + "/head." + _suffix;
        QFile new_pic_file(new_pic_path);
        if(new_pic_file.exists())
            new_pic_file.remove();
        QFile(pic_path).copy(new_pic_path);

        // 头像路径保存在本地变量中
        Config::getInstance()->m_setLoginClientHead(new_pic_path);

        // 界面设置新头像
        ui->frmTab->m_setHeadPic(new_pic_path);
    }
    if(!friend_id_lists.isEmpty() && friend_id_lists.contains(user_id))          // --- 好友的头像 ---
    {
        qDebug() << "it is friend head picture.";
        // 删除旧头像
        QString old_head_path;
        LocalDatabase::getInstance()->m_queryFriendHead(user_id, &old_head_path);
        if(!old_head_path.isEmpty() && QFile(old_head_path).exists())
            QFile(old_head_path).remove();

        // 重命名、复制该图片
        QString _suffix = QFileInfo(pic_path).suffix();
        QString new_pic_path = Config::getInstance()->m_getLocalAccountPath() + "/friend_"+ QString::number(user_id)+ "." + _suffix;
        QFile new_pic_file(new_pic_path);
        if(new_pic_file.exists())
            new_pic_file.remove();
        QFile(pic_path).copy(new_pic_path);

        // 头像路径保存到数据库中
        LocalDatabase::getInstance()->m_modifyFriendHead(user_id, new_pic_path);

        // 界面设置新头像
        ui->trFriendLists->m_setFriendHead(user_id, new_pic_path);
        if(ui->pageFriendInfo->m_getFriendId() == user_id)
        {
            ui->pageFriendInfo->m_setChatFriend(user_id, ui->trFriendLists->m_getFriendOnlineState(user_id));
        }
        ui->frmInfoList->m_checkUpdateInfoBox(user_id);
        // TODO 聊天页面的头像也需要更新
    }
    if(!search_id_lists.isEmpty() && search_id_lists.contains(user_id))     // --- 搜索用户结果的头像 ---
    {
        qDebug() << "it is search user head picture.";

        // 设置头像
        m_searchFriend->m_checkSetUserHead(user_id, pic_path);
    }
    if(!notice_id_lists.isEmpty() && notice_id_lists.contains(user_id))   // --- 好友通知的用户头像 ---
    {
        qDebug() << "it is friend notice head picture.";
        ui->pageFriendNotice->m_setNoticeUserHead(user_id, pic_path);
    }


    if(QFile(pic_path).exists())
        QFile(pic_path).remove();
}

void MainWindow::slot_receiveChatPicture(const quint32 send_id, const quint32 rcv_id, const QString chat_pic_path)
{
    if(rcv_id != Config::getInstance()->m_getLoginClientId())
        return;
    if(chat_pic_path.isEmpty() || !QFile(chat_pic_path).exists())
        return;

    // 聊天记录写入本地数据库
    QDateTime _cur_dateTime = QDateTime::currentDateTime();
    QString _receive_msg_time = _cur_dateTime.toString("yyyy-MM-dd hh:mm:ss");
    sttChatMsgInfo chat_log;
    chat_log.send_id = send_id;
    chat_log.receiver_id = rcv_id;
    chat_log.time = _receive_msg_time;
    chat_log.msg_type = ChatType::IsFileMsg;
    QString new_chat_pic_path = Config::getInstance()->m_getLocalChatPicsPath() + "/" + QString::number(send_id) + "_"
                                + _cur_dateTime.toString("yyyy_MM_dd_hh_mm_ss") + "." + QFileInfo(chat_pic_path).suffix();
    QFile(chat_pic_path).copy(new_chat_pic_path);
    // qDebug() << "receive chat pic:" << chat_pic_path << new_chat_pic_path;
    chat_log.message = new_chat_pic_path;
    LocalDatabase::getInstance()->m_insertChatLog(chat_log);

    // 直接让左侧tab栏的“消息”的未读消息+1，然后frmInfoList再根据如果正处于与该好友的聊天界面，就点击一下消息框，这样就会再次更新未读消息个数
    ui->frmTab->m_informationAppendUnreadNum(1);
    bool _is_in_chat_page = ui->stkwDetail->currentIndex() == 1;
    ui->frmInfoList->m_doReceiveNewMessage(send_id, _cur_dateTime, chat_pic_path, _is_in_chat_page);
}
