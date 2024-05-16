/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <ChatMessageWidget.h>
#include <FriendInfoWidget.h>
#include <FriendListWidget.h>
#include <FriendNoticeWidget.h>
#include <InfoListWidget.h>
#include <LeftBar.h>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_11;
    QSpacerItem *verticalSpacer_21;
    QSpacerItem *horizontalSpacer_35;
    QHBoxLayout *majorSectionHLayout;
    LeftBar *frmTab;
    QStackedWidget *stkwThumbnail;
    QWidget *pageInfoList;
    QGridLayout *gridLayout_7;
    QSpacerItem *verticalSpacer_12;
    QSpacerItem *horizontalSpacer_18;
    QSpacerItem *horizontalSpacer_20;
    QSpacerItem *verticalSpacer_13;
    QScrollArea *sldInfoList;
    InfoListWidget *frmInfoList;
    QWidget *pageFriends;
    QGridLayout *gridLayout_9;
    QSpacerItem *verticalSpacer_17;
    QSpacerItem *horizontalSpacer_24;
    QVBoxLayout *verticalLayout_6;
    QWidget *wFriendsFunc;
    QGridLayout *gridLayout_8;
    QSpacerItem *verticalSpacer_15;
    QSpacerItem *horizontalSpacer_22;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_19;
    QPushButton *btnAddFriend;
    QSpacerItem *horizontalSpacer_21;
    ExpandButton *btnFriendsInfo;
    QSpacerItem *horizontalSpacer_23;
    QSpacerItem *verticalSpacer_14;
    FriendListWidget *trFriendLists;
    QSpacerItem *horizontalSpacer_26;
    QSpacerItem *verticalSpacer_16;
    QStackedWidget *stkwDetail;
    QWidget *pageNull;
    ChatMessageWidget *pageChatMessage;
    FriendInfoWidget *pageFriendInfo;
    FriendNoticeWidget *pageFriendNotice;
    QSpacerItem *horizontalSpacer_36;
    QSpacerItem *verticalSpacer_22;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1461, 971);
        MainWindow->setMinimumSize(QSize(0, 960));
        QIcon icon;
        icon.addFile(QStringLiteral(":/qqicons/qrc/QQicon.svg"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_11 = new QGridLayout(centralWidget);
        gridLayout_11->setSpacing(0);
        gridLayout_11->setContentsMargins(11, 11, 11, 11);
        gridLayout_11->setObjectName(QStringLiteral("gridLayout_11"));
        gridLayout_11->setContentsMargins(0, 0, 0, 0);
        verticalSpacer_21 = new QSpacerItem(20, 7, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_11->addItem(verticalSpacer_21, 0, 1, 1, 1);

        horizontalSpacer_35 = new QSpacerItem(12, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_11->addItem(horizontalSpacer_35, 1, 0, 1, 1);

        majorSectionHLayout = new QHBoxLayout();
        majorSectionHLayout->setSpacing(0);
        majorSectionHLayout->setObjectName(QStringLiteral("majorSectionHLayout"));
        frmTab = new LeftBar(centralWidget);
        frmTab->setObjectName(QStringLiteral("frmTab"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frmTab->sizePolicy().hasHeightForWidth());
        frmTab->setSizePolicy(sizePolicy);
        frmTab->setMinimumSize(QSize(91, 600));
        frmTab->setMaximumSize(QSize(91, 16777215));
        frmTab->setFrameShape(QFrame::Box);

        majorSectionHLayout->addWidget(frmTab);

        stkwThumbnail = new QStackedWidget(centralWidget);
        stkwThumbnail->setObjectName(QStringLiteral("stkwThumbnail"));
        sizePolicy.setHeightForWidth(stkwThumbnail->sizePolicy().hasHeightForWidth());
        stkwThumbnail->setSizePolicy(sizePolicy);
        stkwThumbnail->setMinimumSize(QSize(441, 0));
        stkwThumbnail->setMaximumSize(QSize(441, 16777215));
        stkwThumbnail->setStyleSheet(QStringLiteral(""));
        pageInfoList = new QWidget();
        pageInfoList->setObjectName(QStringLiteral("pageInfoList"));
        gridLayout_7 = new QGridLayout(pageInfoList);
        gridLayout_7->setSpacing(0);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        gridLayout_7->setContentsMargins(0, 0, 0, 0);
        verticalSpacer_12 = new QSpacerItem(20, 6, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_7->addItem(verticalSpacer_12, 0, 1, 1, 1);

        horizontalSpacer_18 = new QSpacerItem(1, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_7->addItem(horizontalSpacer_18, 1, 0, 1, 1);

        horizontalSpacer_20 = new QSpacerItem(48, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_7->addItem(horizontalSpacer_20, 1, 2, 1, 1);

        verticalSpacer_13 = new QSpacerItem(20, 98, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_7->addItem(verticalSpacer_13, 2, 1, 1, 1);

        sldInfoList = new QScrollArea(pageInfoList);
        sldInfoList->setObjectName(QStringLiteral("sldInfoList"));
        sldInfoList->setStyleSheet(QStringLiteral(""));
        sldInfoList->setFrameShape(QFrame::Box);
        sldInfoList->setWidgetResizable(true);
        frmInfoList = new InfoListWidget();
        frmInfoList->setObjectName(QStringLiteral("frmInfoList"));
        frmInfoList->setGeometry(QRect(0, 0, 437, 961));
        frmInfoList->setStyleSheet(QStringLiteral(""));
        sldInfoList->setWidget(frmInfoList);

        gridLayout_7->addWidget(sldInfoList, 1, 1, 1, 1);

        gridLayout_7->setRowStretch(0, 1);
        gridLayout_7->setRowStretch(1, 1000);
        gridLayout_7->setRowStretch(2, 1);
        gridLayout_7->setColumnStretch(0, 1);
        gridLayout_7->setColumnStretch(1, 1000);
        gridLayout_7->setColumnStretch(2, 1);
        stkwThumbnail->addWidget(pageInfoList);
        pageFriends = new QWidget();
        pageFriends->setObjectName(QStringLiteral("pageFriends"));
        gridLayout_9 = new QGridLayout(pageFriends);
        gridLayout_9->setSpacing(0);
        gridLayout_9->setContentsMargins(11, 11, 11, 11);
        gridLayout_9->setObjectName(QStringLiteral("gridLayout_9"));
        gridLayout_9->setContentsMargins(0, 0, 0, 0);
        verticalSpacer_17 = new QSpacerItem(20, 6, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_9->addItem(verticalSpacer_17, 0, 1, 1, 1);

        horizontalSpacer_24 = new QSpacerItem(1, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_9->addItem(horizontalSpacer_24, 1, 0, 1, 1);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(0);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        wFriendsFunc = new QWidget(pageFriends);
        wFriendsFunc->setObjectName(QStringLiteral("wFriendsFunc"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(wFriendsFunc->sizePolicy().hasHeightForWidth());
        wFriendsFunc->setSizePolicy(sizePolicy1);
        wFriendsFunc->setMinimumSize(QSize(0, 148));
        wFriendsFunc->setMaximumSize(QSize(16777215, 148));
        wFriendsFunc->setStyleSheet(QLatin1String("QWidget{\n"
"	border-top: 1px solid black;\n"
"	border-bottom: 1px solid black;\n"
"	border-left: 1px solid black;\n"
"	border-right:1px solid black;\n"
"	background-color: rgb(255, 255, 255);\n"
"}"));
        gridLayout_8 = new QGridLayout(wFriendsFunc);
        gridLayout_8->setSpacing(0);
        gridLayout_8->setContentsMargins(11, 11, 11, 11);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        gridLayout_8->setContentsMargins(0, 5, 0, 0);
        verticalSpacer_15 = new QSpacerItem(20, 6, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_8->addItem(verticalSpacer_15, 0, 1, 1, 1);

        horizontalSpacer_22 = new QSpacerItem(1, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_8->addItem(horizontalSpacer_22, 1, 0, 1, 1);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(8);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalSpacer_19 = new QSpacerItem(38, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_19);

        btnAddFriend = new QPushButton(wFriendsFunc);
        btnAddFriend->setObjectName(QStringLiteral("btnAddFriend"));
        sizePolicy1.setHeightForWidth(btnAddFriend->sizePolicy().hasHeightForWidth());
        btnAddFriend->setSizePolicy(sizePolicy1);
        btnAddFriend->setMinimumSize(QSize(0, 59));
        btnAddFriend->setMaximumSize(QSize(16777215, 59));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(12);
        btnAddFriend->setFont(font);
        btnAddFriend->setStyleSheet(QLatin1String("QPushButton{\n"
"	color: rgb(35, 35, 35);\n"
"	background-color: rgb(255, 255, 255);\n"
"	border: 1px solid;\n"
"	border-color: rgb(211, 211, 211);\n"
"	border-radius: 10px;\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"	background-color: rgb(236, 236, 236);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"	color: rgb(108, 108, 108);\n"
"	background-color: rgb(224, 224, 224);\n"
"}"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/qqicons/qrc/add_friend.svg"), QSize(), QIcon::Normal, QIcon::Off);
        btnAddFriend->setIcon(icon1);

        horizontalLayout_6->addWidget(btnAddFriend);

        horizontalSpacer_21 = new QSpacerItem(38, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_21);

        horizontalLayout_6->setStretch(0, 1);
        horizontalLayout_6->setStretch(1, 6);
        horizontalLayout_6->setStretch(2, 1);

        verticalLayout_5->addLayout(horizontalLayout_6);

        btnFriendsInfo = new ExpandButton(wFriendsFunc);
        btnFriendsInfo->setObjectName(QStringLiteral("btnFriendsInfo"));
        sizePolicy1.setHeightForWidth(btnFriendsInfo->sizePolicy().hasHeightForWidth());
        btnFriendsInfo->setSizePolicy(sizePolicy1);
        btnFriendsInfo->setMinimumSize(QSize(0, 61));
        btnFriendsInfo->setMaximumSize(QSize(16777215, 61));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(11);
        btnFriendsInfo->setFont(font1);
        btnFriendsInfo->setStyleSheet(QLatin1String("QPushButton{\n"
"	text-align: left;\n"
"	border-top: none;\n"
"	border-bottom: none;\n"
"	padding: 0px 20px 0px 20px;\n"
"	color: rgb(42, 42, 42);\n"
"	background-color: rgb(255, 255, 255);\n"
"	/*border-radius: 5px;*/\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"	\n"
"	background-color: rgb(240, 240, 240);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"	background-color: rgb(224, 224, 224);\n"
"}"));

        verticalLayout_5->addWidget(btnFriendsInfo);


        gridLayout_8->addLayout(verticalLayout_5, 1, 1, 1, 1);

        horizontalSpacer_23 = new QSpacerItem(38, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_8->addItem(horizontalSpacer_23, 1, 2, 1, 1);

        verticalSpacer_14 = new QSpacerItem(20, 3, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_8->addItem(verticalSpacer_14, 2, 1, 1, 1);

        gridLayout_8->setRowStretch(0, 8);
        gridLayout_8->setRowStretch(1, 100);
        gridLayout_8->setRowStretch(2, 1);
        gridLayout_8->setColumnStretch(0, 1);
        gridLayout_8->setColumnStretch(1, 1000);
        gridLayout_8->setColumnStretch(2, 1);

        verticalLayout_6->addWidget(wFriendsFunc);

        trFriendLists = new FriendListWidget(pageFriends);
        trFriendLists->setObjectName(QStringLiteral("trFriendLists"));
        trFriendLists->setFont(font1);
        trFriendLists->setStyleSheet(QStringLiteral(""));
        trFriendLists->setIndentation(0);
        trFriendLists->setColumnCount(2);
        trFriendLists->header()->setVisible(false);

        verticalLayout_6->addWidget(trFriendLists);

        verticalLayout_6->setStretch(0, 10);
        verticalLayout_6->setStretch(1, 55);

        gridLayout_9->addLayout(verticalLayout_6, 1, 1, 1, 1);

        horizontalSpacer_26 = new QSpacerItem(68, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_9->addItem(horizontalSpacer_26, 1, 2, 1, 1);

        verticalSpacer_16 = new QSpacerItem(20, 58, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_9->addItem(verticalSpacer_16, 2, 1, 1, 1);

        gridLayout_9->setRowStretch(0, 1);
        gridLayout_9->setRowStretch(1, 1000);
        gridLayout_9->setRowStretch(2, 1);
        gridLayout_9->setColumnStretch(0, 1);
        gridLayout_9->setColumnStretch(1, 1000);
        gridLayout_9->setColumnStretch(2, 1);
        stkwThumbnail->addWidget(pageFriends);

        majorSectionHLayout->addWidget(stkwThumbnail);

        stkwDetail = new QStackedWidget(centralWidget);
        stkwDetail->setObjectName(QStringLiteral("stkwDetail"));
        stkwDetail->setMinimumSize(QSize(900, 0));
        stkwDetail->setFrameShape(QFrame::Box);
        pageNull = new QWidget();
        pageNull->setObjectName(QStringLiteral("pageNull"));
        pageNull->setStyleSheet(QLatin1String("QWidget{\n"
"	background-color: rgb(242, 242, 242);\n"
"	background-image: url(:/qqicons/qrc/qq_pure.svg);\n"
"	background-repeat: no-repeat;\n"
"	background-position: center;\n"
"}"));
        stkwDetail->addWidget(pageNull);
        pageChatMessage = new ChatMessageWidget();
        pageChatMessage->setObjectName(QStringLiteral("pageChatMessage"));
        stkwDetail->addWidget(pageChatMessage);
        pageFriendInfo = new FriendInfoWidget();
        pageFriendInfo->setObjectName(QStringLiteral("pageFriendInfo"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pageFriendInfo->sizePolicy().hasHeightForWidth());
        pageFriendInfo->setSizePolicy(sizePolicy2);
        pageFriendInfo->setMinimumSize(QSize(0, 0));
        pageFriendInfo->setMaximumSize(QSize(16777215, 16777215));
        pageFriendInfo->setStyleSheet(QStringLiteral(""));
        stkwDetail->addWidget(pageFriendInfo);
        pageFriendNotice = new FriendNoticeWidget();
        pageFriendNotice->setObjectName(QStringLiteral("pageFriendNotice"));
        stkwDetail->addWidget(pageFriendNotice);

        majorSectionHLayout->addWidget(stkwDetail);


        gridLayout_11->addLayout(majorSectionHLayout, 1, 1, 1, 1);

        horizontalSpacer_36 = new QSpacerItem(118, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_11->addItem(horizontalSpacer_36, 1, 2, 1, 1);

        verticalSpacer_22 = new QSpacerItem(20, 68, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_11->addItem(verticalSpacer_22, 2, 1, 1, 1);

        gridLayout_11->setRowStretch(0, 1);
        gridLayout_11->setRowStretch(1, 1000);
        gridLayout_11->setRowStretch(2, 1);
        gridLayout_11->setColumnStretch(0, 1);
        gridLayout_11->setColumnStretch(1, 1000);
        gridLayout_11->setColumnStretch(2, 1);
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        stkwThumbnail->setCurrentIndex(0);
        stkwDetail->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "QQ", Q_NULLPTR));
        btnAddFriend->setText(QApplication::translate("MainWindow", "\346\267\273\345\212\240\345\245\275\345\217\213", Q_NULLPTR));
        btnFriendsInfo->setText(QApplication::translate("MainWindow", "\345\245\275\345\217\213\351\200\232\347\237\245", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem = trFriendLists->headerItem();
        ___qtreewidgetitem->setText(1, QApplication::translate("MainWindow", "count", Q_NULLPTR));
        ___qtreewidgetitem->setText(0, QApplication::translate("MainWindow", "name", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
