/********************************************************************************
** Form generated from reading UI file 'ChatMessageWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATMESSAGEWIDGET_H
#define UI_CHATMESSAGEWIDGET_H

#include <ChatBubbleList.h>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChatMessageWidget
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *chatMsgVLayout;
    QHBoxLayout *chatMsgInfoHLayout;
    QSpacerItem *horizontalSpacer_25;
    QLabel *lblChatFriendName;
    QSpacerItem *horizontalSpacer_27;
    ChatBubbleList *lstChatMsgShow;
    QHBoxLayout *chatButtonsHLayout;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *btnChatPicture;
    QSpacerItem *horizontalSpacer_28;
    QTextEdit *edtChatMessageInput;
    QSpacerItem *verticalSpacer_20;
    QHBoxLayout *sendMsgButtonHLayout;
    QSpacerItem *horizontalSpacer_29;
    QPushButton *btnChatMessageSend;
    QSpacerItem *horizontalSpacer_30;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QWidget *ChatMessageWidget)
    {
        if (ChatMessageWidget->objectName().isEmpty())
            ChatMessageWidget->setObjectName(QStringLiteral("ChatMessageWidget"));
        ChatMessageWidget->resize(923, 965);
        gridLayout = new QGridLayout(ChatMessageWidget);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 10, 0, 20);
        verticalSpacer = new QSpacerItem(20, 8, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(8, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        chatMsgVLayout = new QVBoxLayout();
        chatMsgVLayout->setSpacing(0);
        chatMsgVLayout->setObjectName(QStringLiteral("chatMsgVLayout"));
        chatMsgInfoHLayout = new QHBoxLayout();
        chatMsgInfoHLayout->setObjectName(QStringLiteral("chatMsgInfoHLayout"));
        horizontalSpacer_25 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        chatMsgInfoHLayout->addItem(horizontalSpacer_25);

        lblChatFriendName = new QLabel(ChatMessageWidget);
        lblChatFriendName->setObjectName(QStringLiteral("lblChatFriendName"));
        lblChatFriendName->setMinimumSize(QSize(600, 30));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(12);
        lblChatFriendName->setFont(font);
        lblChatFriendName->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        chatMsgInfoHLayout->addWidget(lblChatFriendName);

        horizontalSpacer_27 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        chatMsgInfoHLayout->addItem(horizontalSpacer_27);

        chatMsgInfoHLayout->setStretch(0, 1);
        chatMsgInfoHLayout->setStretch(1, 60);
        chatMsgInfoHLayout->setStretch(2, 1);

        chatMsgVLayout->addLayout(chatMsgInfoHLayout);

        lstChatMsgShow = new ChatBubbleList(ChatMessageWidget);
        lstChatMsgShow->setObjectName(QStringLiteral("lstChatMsgShow"));
        lstChatMsgShow->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        chatMsgVLayout->addWidget(lstChatMsgShow);

        chatButtonsHLayout = new QHBoxLayout();
        chatButtonsHLayout->setObjectName(QStringLiteral("chatButtonsHLayout"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        chatButtonsHLayout->addItem(horizontalSpacer_3);

        btnChatPicture = new QPushButton(ChatMessageWidget);
        btnChatPicture->setObjectName(QStringLiteral("btnChatPicture"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(btnChatPicture->sizePolicy().hasHeightForWidth());
        btnChatPicture->setSizePolicy(sizePolicy);
        btnChatPicture->setMinimumSize(QSize(40, 40));
        btnChatPicture->setMaximumSize(QSize(40, 40));
        btnChatPicture->setStyleSheet(QLatin1String("QPushButton{\n"
"	border-image: url(:/qqicons/qrc/picture.svg);\n"
"	border: none;	\n"
"	background-color: rgba(255, 255, 255, 0);\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"	border-image: url(:/qqicons/qrc/picture_blue.svg);\n"
"}"));
        btnChatPicture->setIconSize(QSize(35, 35));

        chatButtonsHLayout->addWidget(btnChatPicture);

        horizontalSpacer_28 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        chatButtonsHLayout->addItem(horizontalSpacer_28);

        chatButtonsHLayout->setStretch(0, 1);
        chatButtonsHLayout->setStretch(1, 1);
        chatButtonsHLayout->setStretch(2, 50);

        chatMsgVLayout->addLayout(chatButtonsHLayout);

        edtChatMessageInput = new QTextEdit(ChatMessageWidget);
        edtChatMessageInput->setObjectName(QStringLiteral("edtChatMessageInput"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(edtChatMessageInput->sizePolicy().hasHeightForWidth());
        edtChatMessageInput->setSizePolicy(sizePolicy1);
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(11);
        edtChatMessageInput->setFont(font1);
        edtChatMessageInput->setStyleSheet(QLatin1String("QTextEdit{\n"
"	border-top: 1px solid black;\n"
"	border-bottom: 1px solid black;\n"
"}"));

        chatMsgVLayout->addWidget(edtChatMessageInput);

        verticalSpacer_20 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        chatMsgVLayout->addItem(verticalSpacer_20);

        sendMsgButtonHLayout = new QHBoxLayout();
        sendMsgButtonHLayout->setObjectName(QStringLiteral("sendMsgButtonHLayout"));
        horizontalSpacer_29 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        sendMsgButtonHLayout->addItem(horizontalSpacer_29);

        btnChatMessageSend = new QPushButton(ChatMessageWidget);
        btnChatMessageSend->setObjectName(QStringLiteral("btnChatMessageSend"));
        sizePolicy.setHeightForWidth(btnChatMessageSend->sizePolicy().hasHeightForWidth());
        btnChatMessageSend->setSizePolicy(sizePolicy);
        btnChatMessageSend->setMinimumSize(QSize(172, 41));
        btnChatMessageSend->setMaximumSize(QSize(172, 41));
        btnChatMessageSend->setFont(font);
        btnChatMessageSend->setStyleSheet(QLatin1String("QPushButton{\n"
"	color: rgb(255, 255, 255);\n"
"	background-color: rgb(0, 170, 255);\n"
"	border-radius: 10px;\n"
"}\n"
"\n"
"QPushButton:hover{	\n"
"	background-color: rgb(0, 161, 242);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"	color: rgb(226, 226, 226);\n"
"	background-color: rgb(0, 151, 226);\n"
"}\n"
"\n"
"QPushButton:disabled{\n"
"	color: rgb(255, 255, 255);\n"
"	background-color: rgb(179, 212, 255);\n"
"}"));

        sendMsgButtonHLayout->addWidget(btnChatMessageSend);

        horizontalSpacer_30 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        sendMsgButtonHLayout->addItem(horizontalSpacer_30);

        sendMsgButtonHLayout->setStretch(0, 20);
        sendMsgButtonHLayout->setStretch(1, 5);
        sendMsgButtonHLayout->setStretch(2, 1);

        chatMsgVLayout->addLayout(sendMsgButtonHLayout);

        chatMsgVLayout->setStretch(0, 12);
        chatMsgVLayout->setStretch(1, 160);
        chatMsgVLayout->setStretch(2, 12);
        chatMsgVLayout->setStretch(3, 60);
        chatMsgVLayout->setStretch(4, 5);
        chatMsgVLayout->setStretch(5, 12);

        gridLayout->addLayout(chatMsgVLayout, 1, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 2, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 2, 1, 1, 1);

        gridLayout->setRowStretch(0, 1);
        gridLayout->setRowStretch(1, 1000);
        gridLayout->setRowStretch(2, 1);
        gridLayout->setColumnStretch(0, 1);
        gridLayout->setColumnStretch(1, 1000);
        gridLayout->setColumnStretch(2, 1);

        retranslateUi(ChatMessageWidget);

        QMetaObject::connectSlotsByName(ChatMessageWidget);
    } // setupUi

    void retranslateUi(QWidget *ChatMessageWidget)
    {
        ChatMessageWidget->setWindowTitle(QApplication::translate("ChatMessageWidget", "Form", Q_NULLPTR));
        lblChatFriendName->setText(QApplication::translate("ChatMessageWidget", "\345\245\275\345\217\213\345\220\215\345\255\227", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        btnChatPicture->setToolTip(QApplication::translate("ChatMessageWidget", "\345\233\276\347\211\207", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        btnChatPicture->setText(QString());
        btnChatMessageSend->setText(QApplication::translate("ChatMessageWidget", "\345\217\221\351\200\201", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ChatMessageWidget: public Ui_ChatMessageWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATMESSAGEWIDGET_H
