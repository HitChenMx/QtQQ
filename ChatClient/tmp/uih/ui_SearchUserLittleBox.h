/********************************************************************************
** Form generated from reading UI file 'SearchUserLittleBox.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCHUSERLITTLEBOX_H
#define UI_SEARCHUSERLITTLEBOX_H

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
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SearchUserLittleBox
{
public:
    QGridLayout *gridLayout_3;
    QSpacerItem *verticalSpacer_5;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout;
    QLabel *lblHeadPic;
    QVBoxLayout *verticalLayout;
    QLabel *lblName;
    QLabel *lblAccount;
    QStackedWidget *stkwButtonSelect;
    QWidget *pageAddButton;
    QGridLayout *gridLayout_2;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *btnAddFriend;
    QSpacerItem *horizontalSpacer_5;
    QWidget *pageSendButton;
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnSendMessage;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *verticalSpacer_6;

    void setupUi(QWidget *SearchUserLittleBox)
    {
        if (SearchUserLittleBox->objectName().isEmpty())
            SearchUserLittleBox->setObjectName(QStringLiteral("SearchUserLittleBox"));
        SearchUserLittleBox->resize(714, 92);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SearchUserLittleBox->sizePolicy().hasHeightForWidth());
        SearchUserLittleBox->setSizePolicy(sizePolicy);
        SearchUserLittleBox->setMinimumSize(QSize(513, 92));
        SearchUserLittleBox->setMaximumSize(QSize(16777215, 92));
        gridLayout_3 = new QGridLayout(SearchUserLittleBox);
        gridLayout_3->setSpacing(0);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalSpacer_5 = new QSpacerItem(20, 13, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_5, 0, 1, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(4, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_4, 1, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(4);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(10, -1, 20, -1);
        lblHeadPic = new QLabel(SearchUserLittleBox);
        lblHeadPic->setObjectName(QStringLiteral("lblHeadPic"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lblHeadPic->sizePolicy().hasHeightForWidth());
        lblHeadPic->setSizePolicy(sizePolicy1);
        lblHeadPic->setMinimumSize(QSize(90, 90));
        lblHeadPic->setMaximumSize(QSize(90, 90));
        lblHeadPic->setStyleSheet(QLatin1String("QLabel{\n"
"	background-color: rgba(255, 255, 255, 0);\n"
"}"));
        lblHeadPic->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(lblHeadPic);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(4);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(-1, 6, -1, 6);
        lblName = new QLabel(SearchUserLittleBox);
        lblName->setObjectName(QStringLiteral("lblName"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(11);
        lblName->setFont(font);
        lblName->setStyleSheet(QLatin1String("QLabel{\n"
"	background-color: rgba(255, 255, 255, 0);\n"
"}"));
        lblName->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout->addWidget(lblName);

        lblAccount = new QLabel(SearchUserLittleBox);
        lblAccount->setObjectName(QStringLiteral("lblAccount"));
        lblAccount->setFont(font);
        lblAccount->setStyleSheet(QLatin1String("QLabel{\n"
"	background-color: rgba(255, 255, 255, 0);\n"
"}"));
        lblAccount->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout->addWidget(lblAccount);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 1);

        horizontalLayout->addLayout(verticalLayout);

        stkwButtonSelect = new QStackedWidget(SearchUserLittleBox);
        stkwButtonSelect->setObjectName(QStringLiteral("stkwButtonSelect"));
        sizePolicy1.setHeightForWidth(stkwButtonSelect->sizePolicy().hasHeightForWidth());
        stkwButtonSelect->setSizePolicy(sizePolicy1);
        stkwButtonSelect->setMinimumSize(QSize(111, 90));
        stkwButtonSelect->setMaximumSize(QSize(111, 90));
        stkwButtonSelect->setStyleSheet(QLatin1String("QWidget{\n"
"	background-color: rgba(255, 255, 255, 0);\n"
"}"));
        stkwButtonSelect->setFrameShape(QFrame::NoFrame);
        pageAddButton = new QWidget();
        pageAddButton->setObjectName(QStringLiteral("pageAddButton"));
        gridLayout_2 = new QGridLayout(pageAddButton);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalSpacer_4 = new QSpacerItem(20, 23, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_4, 2, 1, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 23, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_3, 0, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(35, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_3, 1, 0, 1, 1);

        btnAddFriend = new QPushButton(pageAddButton);
        btnAddFriend->setObjectName(QStringLiteral("btnAddFriend"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(btnAddFriend->sizePolicy().hasHeightForWidth());
        btnAddFriend->setSizePolicy(sizePolicy2);
        btnAddFriend->setFont(font);
        btnAddFriend->setStyleSheet(QLatin1String("QPushButton{\n"
"	color: rgb(35, 35, 35);\n"
"	background-color: rgb(255, 255, 255);\n"
"	border: 1px solid;\n"
"	border-color: rgb(191,191,191);\n"
"	border-radius: 6px;\n"
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

        gridLayout_2->addWidget(btnAddFriend, 1, 1, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(34, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_5, 1, 2, 1, 1);

        gridLayout_2->setRowStretch(0, 10);
        gridLayout_2->setRowStretch(1, 15);
        gridLayout_2->setRowStretch(2, 10);
        gridLayout_2->setColumnStretch(0, 1);
        gridLayout_2->setColumnStretch(1, 100);
        gridLayout_2->setColumnStretch(2, 1);
        stkwButtonSelect->addWidget(pageAddButton);
        pageSendButton = new QWidget();
        pageSendButton->setObjectName(QStringLiteral("pageSendButton"));
        gridLayout = new QGridLayout(pageSendButton);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        verticalSpacer = new QSpacerItem(20, 22, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(0, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        btnSendMessage = new QPushButton(pageSendButton);
        btnSendMessage->setObjectName(QStringLiteral("btnSendMessage"));
        sizePolicy2.setHeightForWidth(btnSendMessage->sizePolicy().hasHeightForWidth());
        btnSendMessage->setSizePolicy(sizePolicy2);
        btnSendMessage->setFont(font);
        btnSendMessage->setStyleSheet(QLatin1String("QPushButton{\n"
"	color: rgb(35, 35, 35);\n"
"	background-color: rgb(255, 255, 255);\n"
"	border: 1px solid;\n"
"	border-color: rgb(191,191,191);\n"
"	border-radius: 6px;\n"
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

        gridLayout->addWidget(btnSendMessage, 1, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(0, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 2, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 22, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 2, 1, 1, 1);

        gridLayout->setRowStretch(0, 10);
        gridLayout->setRowStretch(1, 15);
        gridLayout->setRowStretch(2, 10);
        gridLayout->setColumnStretch(0, 1);
        gridLayout->setColumnStretch(1, 100);
        gridLayout->setColumnStretch(2, 1);
        stkwButtonSelect->addWidget(pageSendButton);

        horizontalLayout->addWidget(stkwButtonSelect);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 3);
        horizontalLayout->setStretch(2, 1);

        gridLayout_3->addLayout(horizontalLayout, 1, 1, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(38, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_6, 1, 2, 1, 1);

        verticalSpacer_6 = new QSpacerItem(20, 68, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_6, 2, 1, 1, 1);

        gridLayout_3->setRowStretch(0, 1);
        gridLayout_3->setRowStretch(1, 1000);
        gridLayout_3->setRowStretch(2, 1);
        gridLayout_3->setColumnStretch(0, 1);
        gridLayout_3->setColumnStretch(1, 1000);
        gridLayout_3->setColumnStretch(2, 1);

        retranslateUi(SearchUserLittleBox);

        stkwButtonSelect->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(SearchUserLittleBox);
    } // setupUi

    void retranslateUi(QWidget *SearchUserLittleBox)
    {
        SearchUserLittleBox->setWindowTitle(QApplication::translate("SearchUserLittleBox", "Form", Q_NULLPTR));
        lblHeadPic->setText(QApplication::translate("SearchUserLittleBox", "\345\244\264\345\203\217", Q_NULLPTR));
        lblName->setText(QApplication::translate("SearchUserLittleBox", "\346\230\265\347\247\260", Q_NULLPTR));
        lblAccount->setText(QApplication::translate("SearchUserLittleBox", "\350\264\246\345\217\267", Q_NULLPTR));
        btnAddFriend->setText(QApplication::translate("SearchUserLittleBox", "\346\267\273\345\212\240", Q_NULLPTR));
        btnSendMessage->setText(QApplication::translate("SearchUserLittleBox", "\345\217\221\346\266\210\346\201\257", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SearchUserLittleBox: public Ui_SearchUserLittleBox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCHUSERLITTLEBOX_H
