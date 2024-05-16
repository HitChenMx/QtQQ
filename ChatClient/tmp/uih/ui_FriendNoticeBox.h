/********************************************************************************
** Form generated from reading UI file 'FriendNoticeBox.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRIENDNOTICEBOX_H
#define UI_FRIENDNOTICEBOX_H

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
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <twoclickareabutton.h>

QT_BEGIN_NAMESPACE

class Ui_FriendNoticeBox
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *mainContentHLayout;
    QLabel *lblHeadPic;
    QVBoxLayout *textShowVLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnUserName;
    QLabel *lblUserRequest;
    QLabel *lblTime;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *lblLeaveWords;
    TwoClickAreaButton *btnReply;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QWidget *FriendNoticeBox)
    {
        if (FriendNoticeBox->objectName().isEmpty())
            FriendNoticeBox->setObjectName(QStringLiteral("FriendNoticeBox"));
        FriendNoticeBox->resize(927, 129);
        FriendNoticeBox->setMinimumSize(QSize(0, 129));
        FriendNoticeBox->setMaximumSize(QSize(16777215, 129));
        FriendNoticeBox->setStyleSheet(QStringLiteral(""));
        gridLayout = new QGridLayout(FriendNoticeBox);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalSpacer = new QSpacerItem(20, 8, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(6, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        mainContentHLayout = new QHBoxLayout();
        mainContentHLayout->setObjectName(QStringLiteral("mainContentHLayout"));
        lblHeadPic = new QLabel(FriendNoticeBox);
        lblHeadPic->setObjectName(QStringLiteral("lblHeadPic"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lblHeadPic->sizePolicy().hasHeightForWidth());
        lblHeadPic->setSizePolicy(sizePolicy);
        lblHeadPic->setMinimumSize(QSize(80, 80));
        lblHeadPic->setMaximumSize(QSize(80, 80));
        lblHeadPic->setStyleSheet(QStringLiteral(""));
        lblHeadPic->setAlignment(Qt::AlignCenter);

        mainContentHLayout->addWidget(lblHeadPic);

        textShowVLayout = new QVBoxLayout();
        textShowVLayout->setSpacing(0);
        textShowVLayout->setObjectName(QStringLiteral("textShowVLayout"));
        textShowVLayout->setContentsMargins(-1, 0, -1, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(15);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        btnUserName = new QPushButton(FriendNoticeBox);
        btnUserName->setObjectName(QStringLiteral("btnUserName"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(btnUserName->sizePolicy().hasHeightForWidth());
        btnUserName->setSizePolicy(sizePolicy1);
        btnUserName->setMinimumSize(QSize(20, 0));
        btnUserName->setMaximumSize(QSize(16777215, 16777215));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(10);
        btnUserName->setFont(font);
        btnUserName->setStyleSheet(QLatin1String("QPushButton{\n"
"	border: none;	\n"
"	background-color: rgba(255, 255, 255, 0);\n"
"	color: rgb(85, 170, 255);\n"
"}"));

        horizontalLayout->addWidget(btnUserName);

        lblUserRequest = new QLabel(FriendNoticeBox);
        lblUserRequest->setObjectName(QStringLiteral("lblUserRequest"));
        sizePolicy1.setHeightForWidth(lblUserRequest->sizePolicy().hasHeightForWidth());
        lblUserRequest->setSizePolicy(sizePolicy1);
        lblUserRequest->setMinimumSize(QSize(120, 0));
        lblUserRequest->setMaximumSize(QSize(16777215, 16777215));
        lblUserRequest->setFont(font);
        lblUserRequest->setStyleSheet(QStringLiteral(""));
        lblUserRequest->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout->addWidget(lblUserRequest);

        lblTime = new QLabel(FriendNoticeBox);
        lblTime->setObjectName(QStringLiteral("lblTime"));
        sizePolicy1.setHeightForWidth(lblTime->sizePolicy().hasHeightForWidth());
        lblTime->setSizePolicy(sizePolicy1);
        lblTime->setMinimumSize(QSize(140, 0));
        lblTime->setMaximumSize(QSize(16777215, 16777215));
        lblTime->setFont(font);
        lblTime->setStyleSheet(QStringLiteral(""));
        lblTime->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout->addWidget(lblTime);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);


        textShowVLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        lblLeaveWords = new QLabel(FriendNoticeBox);
        lblLeaveWords->setObjectName(QStringLiteral("lblLeaveWords"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(lblLeaveWords->sizePolicy().hasHeightForWidth());
        lblLeaveWords->setSizePolicy(sizePolicy2);
        lblLeaveWords->setFont(font);
        lblLeaveWords->setStyleSheet(QStringLiteral(""));
        lblLeaveWords->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(lblLeaveWords);


        textShowVLayout->addLayout(horizontalLayout_2);


        mainContentHLayout->addLayout(textShowVLayout);

        btnReply = new TwoClickAreaButton(FriendNoticeBox);
        btnReply->setObjectName(QStringLiteral("btnReply"));
        btnReply->setMinimumSize(QSize(127, 38));
        btnReply->setMaximumSize(QSize(127, 38));
        btnReply->setFont(font);

        mainContentHLayout->addWidget(btnReply);

        mainContentHLayout->setStretch(0, 5);
        mainContentHLayout->setStretch(1, 40);
        mainContentHLayout->setStretch(2, 8);

        gridLayout->addLayout(mainContentHLayout, 1, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(6, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 2, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 78, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 2, 1, 1, 1);

        gridLayout->setRowStretch(0, 1);
        gridLayout->setRowStretch(1, 100);
        gridLayout->setRowStretch(2, 1);
        gridLayout->setColumnStretch(0, 1);
        gridLayout->setColumnStretch(1, 100);
        gridLayout->setColumnStretch(2, 1);

        retranslateUi(FriendNoticeBox);

        QMetaObject::connectSlotsByName(FriendNoticeBox);
    } // setupUi

    void retranslateUi(QWidget *FriendNoticeBox)
    {
        FriendNoticeBox->setWindowTitle(QApplication::translate("FriendNoticeBox", "Form", Q_NULLPTR));
        lblHeadPic->setText(QApplication::translate("FriendNoticeBox", "\345\244\264\345\203\217", Q_NULLPTR));
        btnUserName->setText(QApplication::translate("FriendNoticeBox", "\346\235\216\345\215\216", Q_NULLPTR));
        lblUserRequest->setText(QApplication::translate("FriendNoticeBox", "<html><head/><body><p>\350\257\267\346\261\202\345\212\240\344\270\272\345\245\275\345\217\213</p></body></html>", Q_NULLPTR));
        lblTime->setText(QApplication::translate("FriendNoticeBox", "<html><head/><body><p><span style=\" color:#999999;\">\346\230\237\346\234\237\344\272\214 10:56:07</span></p></body></html>", Q_NULLPTR));
        lblLeaveWords->setText(QApplication::translate("FriendNoticeBox", "<html><head/><body><p><span style=\" color:#999999;\">\347\225\231\350\250\200\357\274\232\346\210\221\346\230\257\346\235\216\345\215\216</span></p></body></html>", Q_NULLPTR));
        btnReply->setText(QApplication::translate("FriendNoticeBox", "\345\220\214\346\204\217", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class FriendNoticeBox: public Ui_FriendNoticeBox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRIENDNOTICEBOX_H
