/********************************************************************************
** Form generated from reading UI file 'FriendInfoWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRIENDINFOWIDGET_H
#define UI_FRIENDINFOWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FriendInfoWidget
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_2;
    QWidget *wFriendInfo;
    QGridLayout *gridLayout_2;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *horizontalSpacer_3;
    QVBoxLayout *friendInfoVLayout;
    QHBoxLayout *horizontalLayout_5;
    QLabel *lblFriendHeadPic;
    QVBoxLayout *verticalLayout_2;
    QLabel *lblFriendName;
    QLabel *lblFriendAccount;
    QHBoxLayout *horizontalLayout_7;
    QLabel *lblFriendOnlinePic;
    QLabel *lblFriendOnlineState;
    QGridLayout *gridLayout_13;
    QLabel *label_13;
    QLabel *lblFriendAge;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *lblFriendSignature;
    QLabel *lblFriendLevel;
    QLabel *label_12;
    QLabel *label_14;
    QLabel *lblFriendLastLogin;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_6;
    QComboBox *cmbFriendGroup;
    QSpacerItem *horizontalSpacer_7;
    QSpacerItem *verticalSpacer_24;
    QHBoxLayout *horizontalLayout_9;
    QSpacerItem *horizontalSpacer_34;
    QPushButton *btnFriendReadySend;
    QSpacerItem *horizontalSpacer_37;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer_4;

    void setupUi(QWidget *FriendInfoWidget)
    {
        if (FriendInfoWidget->objectName().isEmpty())
            FriendInfoWidget->setObjectName(QStringLiteral("FriendInfoWidget"));
        FriendInfoWidget->resize(923, 965);
        gridLayout = new QGridLayout(FriendInfoWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalSpacer = new QSpacerItem(20, 112, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(99, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(99, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 2, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 112, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 2, 1, 1, 1);

        wFriendInfo = new QWidget(FriendInfoWidget);
        wFriendInfo->setObjectName(QStringLiteral("wFriendInfo"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(wFriendInfo->sizePolicy().hasHeightForWidth());
        wFriendInfo->setSizePolicy(sizePolicy);
        wFriendInfo->setMinimumSize(QSize(675, 691));
        wFriendInfo->setMaximumSize(QSize(675, 691));
        gridLayout_2 = new QGridLayout(wFriendInfo);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalSpacer_3 = new QSpacerItem(20, 5, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_3, 0, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(5, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_3, 1, 0, 1, 1);

        friendInfoVLayout = new QVBoxLayout();
        friendInfoVLayout->setSpacing(30);
        friendInfoVLayout->setObjectName(QStringLiteral("friendInfoVLayout"));
        friendInfoVLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(12);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        lblFriendHeadPic = new QLabel(wFriendInfo);
        lblFriendHeadPic->setObjectName(QStringLiteral("lblFriendHeadPic"));
        sizePolicy.setHeightForWidth(lblFriendHeadPic->sizePolicy().hasHeightForWidth());
        lblFriendHeadPic->setSizePolicy(sizePolicy);
        lblFriendHeadPic->setMinimumSize(QSize(170, 170));
        lblFriendHeadPic->setMaximumSize(QSize(170, 170));
        lblFriendHeadPic->setStyleSheet(QLatin1String("QLabel{\n"
"	\n"
"}"));
        lblFriendHeadPic->setAlignment(Qt::AlignCenter);

        horizontalLayout_5->addWidget(lblFriendHeadPic);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(5);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        lblFriendName = new QLabel(wFriendInfo);
        lblFriendName->setObjectName(QStringLiteral("lblFriendName"));
        lblFriendName->setMinimumSize(QSize(450, 50));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(15);
        lblFriendName->setFont(font);
        lblFriendName->setStyleSheet(QLatin1String("QLabel{\n"
"	\n"
"}"));

        verticalLayout_2->addWidget(lblFriendName);

        lblFriendAccount = new QLabel(wFriendInfo);
        lblFriendAccount->setObjectName(QStringLiteral("lblFriendAccount"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(12);
        lblFriendAccount->setFont(font1);
        lblFriendAccount->setStyleSheet(QLatin1String("QLabel{\n"
"	\n"
"}"));

        verticalLayout_2->addWidget(lblFriendAccount);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        lblFriendOnlinePic = new QLabel(wFriendInfo);
        lblFriendOnlinePic->setObjectName(QStringLiteral("lblFriendOnlinePic"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(10);
        lblFriendOnlinePic->setFont(font2);
        lblFriendOnlinePic->setStyleSheet(QStringLiteral(""));

        horizontalLayout_7->addWidget(lblFriendOnlinePic);

        lblFriendOnlineState = new QLabel(wFriendInfo);
        lblFriendOnlineState->setObjectName(QStringLiteral("lblFriendOnlineState"));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font3.setPointSize(11);
        lblFriendOnlineState->setFont(font3);

        horizontalLayout_7->addWidget(lblFriendOnlineState);

        horizontalLayout_7->setStretch(0, 1);
        horizontalLayout_7->setStretch(1, 8);

        verticalLayout_2->addLayout(horizontalLayout_7);

        verticalLayout_2->setStretch(0, 8);
        verticalLayout_2->setStretch(1, 7);
        verticalLayout_2->setStretch(2, 6);

        horizontalLayout_5->addLayout(verticalLayout_2);

        horizontalLayout_5->setStretch(0, 4);
        horizontalLayout_5->setStretch(1, 14);

        friendInfoVLayout->addLayout(horizontalLayout_5);

        gridLayout_13 = new QGridLayout();
        gridLayout_13->setObjectName(QStringLiteral("gridLayout_13"));
        label_13 = new QLabel(wFriendInfo);
        label_13->setObjectName(QStringLiteral("label_13"));
        QFont font4;
        font4.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font4.setPointSize(13);
        label_13->setFont(font4);
        label_13->setStyleSheet(QLatin1String("QLabel{\n"
"\n"
"}"));

        gridLayout_13->addWidget(label_13, 3, 0, 1, 1);

        lblFriendAge = new QLabel(wFriendInfo);
        lblFriendAge->setObjectName(QStringLiteral("lblFriendAge"));
        lblFriendAge->setFont(font1);
        lblFriendAge->setStyleSheet(QLatin1String("QLabel{\n"
"	\n"
"}"));
        lblFriendAge->setAlignment(Qt::AlignCenter);

        gridLayout_13->addWidget(lblFriendAge, 2, 1, 1, 1);

        label_10 = new QLabel(wFriendInfo);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setFont(font4);
        label_10->setStyleSheet(QLatin1String("QLabel{\n"
"	\n"
"}"));

        gridLayout_13->addWidget(label_10, 0, 0, 1, 1);

        label_11 = new QLabel(wFriendInfo);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setFont(font4);
        label_11->setStyleSheet(QLatin1String("QLabel{\n"
"	\n"
"}"));

        gridLayout_13->addWidget(label_11, 1, 0, 1, 1);

        lblFriendSignature = new QLabel(wFriendInfo);
        lblFriendSignature->setObjectName(QStringLiteral("lblFriendSignature"));
        lblFriendSignature->setMinimumSize(QSize(500, 50));
        lblFriendSignature->setFont(font1);
        lblFriendSignature->setStyleSheet(QLatin1String("QLabel{\n"
"	\n"
"}"));
        lblFriendSignature->setAlignment(Qt::AlignCenter);

        gridLayout_13->addWidget(lblFriendSignature, 0, 1, 1, 1);

        lblFriendLevel = new QLabel(wFriendInfo);
        lblFriendLevel->setObjectName(QStringLiteral("lblFriendLevel"));
        lblFriendLevel->setFont(font1);
        lblFriendLevel->setStyleSheet(QLatin1String("QLabel{\n"
"	\n"
"}"));
        lblFriendLevel->setAlignment(Qt::AlignCenter);

        gridLayout_13->addWidget(lblFriendLevel, 1, 1, 1, 1);

        label_12 = new QLabel(wFriendInfo);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setFont(font4);
        label_12->setStyleSheet(QLatin1String("QLabel{\n"
"	\n"
"}"));

        gridLayout_13->addWidget(label_12, 2, 0, 1, 1);

        label_14 = new QLabel(wFriendInfo);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setFont(font4);
        label_14->setStyleSheet(QLatin1String("QLabel{\n"
"	\n"
"}"));

        gridLayout_13->addWidget(label_14, 4, 0, 1, 1);

        lblFriendLastLogin = new QLabel(wFriendInfo);
        lblFriendLastLogin->setObjectName(QStringLiteral("lblFriendLastLogin"));
        lblFriendLastLogin->setFont(font1);
        lblFriendLastLogin->setStyleSheet(QLatin1String("QLabel{\n"
"	\n"
"}"));
        lblFriendLastLogin->setAlignment(Qt::AlignCenter);

        gridLayout_13->addWidget(lblFriendLastLogin, 4, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_6);

        cmbFriendGroup = new QComboBox(wFriendInfo);
        cmbFriendGroup->setObjectName(QStringLiteral("cmbFriendGroup"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(cmbFriendGroup->sizePolicy().hasHeightForWidth());
        cmbFriendGroup->setSizePolicy(sizePolicy1);
        QFont font5;
        font5.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font5.setPointSize(12);
        font5.setBold(false);
        font5.setItalic(false);
        font5.setWeight(50);
        cmbFriendGroup->setFont(font5);
        cmbFriendGroup->setStyleSheet(QString::fromUtf8("QComboBox{\n"
"	border: 1px solid gray;\n"
"	border-radius: 10px;\n"
"	padding-left: 10px;/*\345\267\246\344\276\247\350\276\271\350\267\235*/\n"
"}\n"
"\n"
"QComboBox::drop-down{\n"
"	subcontrol-origin: padding;\n"
"	subcontrol-position: top right;\n"
"	width: 15px;\n"
"	border:none;\n"
"	margin-right: 20px;\n"
"}\n"
"\n"
"QComboBox::down-arrow{\n"
"	image: url(:/qqicons/qrc/119-down-arrow.svg);\n"
"}\n"
""));

        horizontalLayout->addWidget(cmbFriendGroup);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_7);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 2);
        horizontalLayout->setStretch(2, 1);

        gridLayout_13->addLayout(horizontalLayout, 3, 1, 1, 1);

        gridLayout_13->setRowStretch(0, 1);
        gridLayout_13->setRowStretch(1, 1);
        gridLayout_13->setRowStretch(2, 1);
        gridLayout_13->setRowStretch(3, 1);
        gridLayout_13->setRowStretch(4, 1);
        gridLayout_13->setColumnStretch(0, 1);
        gridLayout_13->setColumnStretch(1, 4);

        friendInfoVLayout->addLayout(gridLayout_13);

        verticalSpacer_24 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        friendInfoVLayout->addItem(verticalSpacer_24);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        horizontalSpacer_34 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_34);

        btnFriendReadySend = new QPushButton(wFriendInfo);
        btnFriendReadySend->setObjectName(QStringLiteral("btnFriendReadySend"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(btnFriendReadySend->sizePolicy().hasHeightForWidth());
        btnFriendReadySend->setSizePolicy(sizePolicy2);
        btnFriendReadySend->setFont(font4);
        btnFriendReadySend->setStyleSheet(QLatin1String("QPushButton{\n"
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

        horizontalLayout_9->addWidget(btnFriendReadySend);

        horizontalSpacer_37 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_37);

        horizontalLayout_9->setStretch(0, 6);
        horizontalLayout_9->setStretch(1, 10);
        horizontalLayout_9->setStretch(2, 6);

        friendInfoVLayout->addLayout(horizontalLayout_9);

        friendInfoVLayout->setStretch(0, 16);
        friendInfoVLayout->setStretch(1, 30);
        friendInfoVLayout->setStretch(2, 3);
        friendInfoVLayout->setStretch(3, 6);

        gridLayout_2->addLayout(friendInfoVLayout, 1, 1, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_4, 1, 2, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_4, 2, 1, 1, 1);

        gridLayout_2->setRowStretch(0, 1);
        gridLayout_2->setRowStretch(1, 1000);
        gridLayout_2->setRowStretch(2, 1);
        gridLayout_2->setColumnStretch(0, 1);
        gridLayout_2->setColumnStretch(1, 1000);
        gridLayout_2->setColumnStretch(2, 1);

        gridLayout->addWidget(wFriendInfo, 1, 1, 1, 1);

        gridLayout->setRowStretch(0, 1);
        gridLayout->setRowStretch(1, 6);
        gridLayout->setRowStretch(2, 1);
        gridLayout->setColumnStretch(0, 1);
        gridLayout->setColumnStretch(1, 6);
        gridLayout->setColumnStretch(2, 1);

        retranslateUi(FriendInfoWidget);

        QMetaObject::connectSlotsByName(FriendInfoWidget);
    } // setupUi

    void retranslateUi(QWidget *FriendInfoWidget)
    {
        FriendInfoWidget->setWindowTitle(QApplication::translate("FriendInfoWidget", "Form", Q_NULLPTR));
        lblFriendHeadPic->setText(QApplication::translate("FriendInfoWidget", "\345\244\264\345\203\217", Q_NULLPTR));
        lblFriendName->setText(QApplication::translate("FriendInfoWidget", "\346\210\221\347\232\204\346\230\265\347\247\260", Q_NULLPTR));
        lblFriendAccount->setText(QApplication::translate("FriendInfoWidget", "QQ 12345", Q_NULLPTR));
        lblFriendOnlinePic->setText(QString());
        lblFriendOnlineState->setText(QApplication::translate("FriendInfoWidget", "<html><head/><body><p>\345\234\250\347\272\277</p></body></html>", Q_NULLPTR));
        label_13->setText(QApplication::translate("FriendInfoWidget", "<html><head/><body><p align=\"center\">\345\245\275\345\217\213\345\210\206\347\273\204</p></body></html>", Q_NULLPTR));
        lblFriendAge->setText(QApplication::translate("FriendInfoWidget", "<html><head/><body><p align=\"center\">\346\234\252\350\256\276\347\275\256</p></body></html>", Q_NULLPTR));
        label_10->setText(QApplication::translate("FriendInfoWidget", "<html><head/><body><p align=\"center\">\344\270\252\346\200\247\347\255\276\345\220\215</p></body></html>", Q_NULLPTR));
        label_11->setText(QApplication::translate("FriendInfoWidget", "<html><head/><body><p align=\"center\">\347\255\211\347\272\247</p></body></html>", Q_NULLPTR));
        lblFriendSignature->setText(QApplication::translate("FriendInfoWidget", "<html><head/><body><p align=\"center\"><br/></p></body></html>", Q_NULLPTR));
        lblFriendLevel->setText(QApplication::translate("FriendInfoWidget", "<html><head/><body><p align=\"center\">\346\234\252\350\256\276\347\275\256</p></body></html>", Q_NULLPTR));
        label_12->setText(QApplication::translate("FriendInfoWidget", "<html><head/><body><p align=\"center\">\345\271\264\351\276\204</p></body></html>", Q_NULLPTR));
        label_14->setText(QApplication::translate("FriendInfoWidget", "<html><head/><body><p align=\"center\">\347\231\273\345\275\225\346\227\266\351\227\264</p></body></html>", Q_NULLPTR));
        lblFriendLastLogin->setText(QApplication::translate("FriendInfoWidget", "<html><head/><body><p align=\"center\"><span style=\" color:#000000;\">2024-02-07 16:43:28</span></p></body></html>", Q_NULLPTR));
        cmbFriendGroup->clear();
        cmbFriendGroup->insertItems(0, QStringList()
         << QApplication::translate("FriendInfoWidget", "1", Q_NULLPTR)
         << QApplication::translate("FriendInfoWidget", "2", Q_NULLPTR)
        );
        btnFriendReadySend->setText(QApplication::translate("FriendInfoWidget", "\345\217\221\346\266\210\346\201\257", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class FriendInfoWidget: public Ui_FriendInfoWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRIENDINFOWIDGET_H
