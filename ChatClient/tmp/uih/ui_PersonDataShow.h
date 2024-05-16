/********************************************************************************
** Form generated from reading UI file 'PersonDataShow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PERSONDATASHOW_H
#define UI_PERSONDATASHOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_PersonDataShow
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_3;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *headHLayout;
    QLabel *lblHeadPic;
    QVBoxLayout *verticalLayout;
    QLabel *lblName;
    QLabel *lblAccount;
    QHBoxLayout *horizontalLayout;
    QLabel *lblStatePic;
    QLabel *lblState;
    QGridLayout *infoGridLayout;
    QLabel *label_6;
    QLabel *lblSignature;
    QLabel *label_7;
    QLabel *lblLevel;
    QLabel *label_8;
    QLabel *lblAge;
    QLabel *label_9;
    QLabel *lblLastLogin;
    QHBoxLayout *editHLayout;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btnEditInfo;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QDialog *PersonDataShow)
    {
        if (PersonDataShow->objectName().isEmpty())
            PersonDataShow->setObjectName(QStringLiteral("PersonDataShow"));
        PersonDataShow->resize(460, 505);
        PersonDataShow->setStyleSheet(QStringLiteral(""));
        gridLayout = new QGridLayout(PersonDataShow);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(10, 10, 10, 10);
        verticalSpacer = new QSpacerItem(20, 2, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 0, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(1, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 1, 0, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        headHLayout = new QHBoxLayout();
        headHLayout->setSpacing(30);
        headHLayout->setObjectName(QStringLiteral("headHLayout"));
        headHLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        lblHeadPic = new QLabel(PersonDataShow);
        lblHeadPic->setObjectName(QStringLiteral("lblHeadPic"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lblHeadPic->sizePolicy().hasHeightForWidth());
        lblHeadPic->setSizePolicy(sizePolicy);
        lblHeadPic->setMinimumSize(QSize(119, 119));
        lblHeadPic->setMaximumSize(QSize(119, 119));
        lblHeadPic->setAlignment(Qt::AlignCenter);

        headHLayout->addWidget(lblHeadPic);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        lblName = new QLabel(PersonDataShow);
        lblName->setObjectName(QStringLiteral("lblName"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(13);
        lblName->setFont(font);

        verticalLayout->addWidget(lblName);

        lblAccount = new QLabel(PersonDataShow);
        lblAccount->setObjectName(QStringLiteral("lblAccount"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(10);
        lblAccount->setFont(font1);
        lblAccount->setStyleSheet(QStringLiteral(""));

        verticalLayout->addWidget(lblAccount);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        lblStatePic = new QLabel(PersonDataShow);
        lblStatePic->setObjectName(QStringLiteral("lblStatePic"));
        lblStatePic->setFont(font1);
        lblStatePic->setStyleSheet(QLatin1String("QLabel{\n"
"	min-width: 22px; \n"
"	max-width: 22px;\n"
"	min-height: 22px;\n"
"	max-height: 22px;\n"
"	border-image: url(:/qqicons/qrc/online.svg);\n"
"}"));

        horizontalLayout->addWidget(lblStatePic);

        lblState = new QLabel(PersonDataShow);
        lblState->setObjectName(QStringLiteral("lblState"));
        lblState->setFont(font1);

        horizontalLayout->addWidget(lblState);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 1);

        verticalLayout->addLayout(horizontalLayout);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 1);
        verticalLayout->setStretch(2, 1);

        headHLayout->addLayout(verticalLayout);

        headHLayout->setStretch(0, 1);
        headHLayout->setStretch(1, 3);

        verticalLayout_2->addLayout(headHLayout);

        infoGridLayout = new QGridLayout();
        infoGridLayout->setObjectName(QStringLiteral("infoGridLayout"));
        label_6 = new QLabel(PersonDataShow);
        label_6->setObjectName(QStringLiteral("label_6"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(11);
        label_6->setFont(font2);

        infoGridLayout->addWidget(label_6, 0, 0, 1, 1);

        lblSignature = new QLabel(PersonDataShow);
        lblSignature->setObjectName(QStringLiteral("lblSignature"));
        lblSignature->setFont(font1);

        infoGridLayout->addWidget(lblSignature, 0, 1, 1, 1);

        label_7 = new QLabel(PersonDataShow);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setFont(font2);

        infoGridLayout->addWidget(label_7, 1, 0, 1, 1);

        lblLevel = new QLabel(PersonDataShow);
        lblLevel->setObjectName(QStringLiteral("lblLevel"));
        lblLevel->setFont(font1);

        infoGridLayout->addWidget(lblLevel, 1, 1, 1, 1);

        label_8 = new QLabel(PersonDataShow);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setFont(font2);

        infoGridLayout->addWidget(label_8, 2, 0, 1, 1);

        lblAge = new QLabel(PersonDataShow);
        lblAge->setObjectName(QStringLiteral("lblAge"));
        lblAge->setFont(font1);

        infoGridLayout->addWidget(lblAge, 2, 1, 1, 1);

        label_9 = new QLabel(PersonDataShow);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setFont(font2);

        infoGridLayout->addWidget(label_9, 3, 0, 1, 1);

        lblLastLogin = new QLabel(PersonDataShow);
        lblLastLogin->setObjectName(QStringLiteral("lblLastLogin"));
        lblLastLogin->setFont(font1);

        infoGridLayout->addWidget(lblLastLogin, 3, 1, 1, 1);

        infoGridLayout->setRowStretch(0, 1);
        infoGridLayout->setRowStretch(1, 1);
        infoGridLayout->setRowStretch(2, 1);
        infoGridLayout->setRowStretch(3, 1);
        infoGridLayout->setColumnStretch(0, 1);
        infoGridLayout->setColumnStretch(1, 3);

        verticalLayout_2->addLayout(infoGridLayout);

        editHLayout = new QHBoxLayout();
        editHLayout->setObjectName(QStringLiteral("editHLayout"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        editHLayout->addItem(horizontalSpacer_2);

        btnEditInfo = new QPushButton(PersonDataShow);
        btnEditInfo->setObjectName(QStringLiteral("btnEditInfo"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(btnEditInfo->sizePolicy().hasHeightForWidth());
        btnEditInfo->setSizePolicy(sizePolicy1);
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font3.setPointSize(12);
        btnEditInfo->setFont(font3);
        btnEditInfo->setStyleSheet(QLatin1String("QPushButton{\n"
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

        editHLayout->addWidget(btnEditInfo);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        editHLayout->addItem(horizontalSpacer);

        editHLayout->setStretch(0, 2);
        editHLayout->setStretch(1, 4);
        editHLayout->setStretch(2, 2);

        verticalLayout_2->addLayout(editHLayout);

        verticalLayout_2->setStretch(0, 8);
        verticalLayout_2->setStretch(1, 19);
        verticalLayout_2->setStretch(2, 3);

        gridLayout->addLayout(verticalLayout_2, 1, 1, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(1, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 1, 2, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 2, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 2, 1, 1, 1);

        gridLayout->setRowStretch(0, 1);
        gridLayout->setRowStretch(1, 100);
        gridLayout->setRowStretch(2, 1);
        gridLayout->setColumnStretch(0, 1);
        gridLayout->setColumnStretch(1, 100);
        gridLayout->setColumnStretch(2, 1);

        retranslateUi(PersonDataShow);

        QMetaObject::connectSlotsByName(PersonDataShow);
    } // setupUi

    void retranslateUi(QDialog *PersonDataShow)
    {
        PersonDataShow->setWindowTitle(QApplication::translate("PersonDataShow", "Dialog", Q_NULLPTR));
        lblHeadPic->setText(QApplication::translate("PersonDataShow", "\345\244\264\345\203\217", Q_NULLPTR));
        lblName->setText(QApplication::translate("PersonDataShow", "\346\210\221\347\232\204\346\230\265\347\247\260", Q_NULLPTR));
        lblAccount->setText(QApplication::translate("PersonDataShow", "QQ 12345", Q_NULLPTR));
        lblStatePic->setText(QString());
        lblState->setText(QApplication::translate("PersonDataShow", "<html><head/><body><p>\345\234\250\347\272\277</p></body></html>", Q_NULLPTR));
        label_6->setText(QApplication::translate("PersonDataShow", "<html><head/><body><p align=\"center\">\344\270\252\346\200\247\347\255\276\345\220\215</p></body></html>", Q_NULLPTR));
        lblSignature->setText(QApplication::translate("PersonDataShow", "<html><head/><body><p align=\"center\"><br/></p></body></html>", Q_NULLPTR));
        label_7->setText(QApplication::translate("PersonDataShow", "<html><head/><body><p align=\"center\">\347\255\211\347\272\247</p></body></html>", Q_NULLPTR));
        lblLevel->setText(QApplication::translate("PersonDataShow", "<html><head/><body><p align=\"center\">\346\234\252\350\256\276\347\275\256</p></body></html>", Q_NULLPTR));
        label_8->setText(QApplication::translate("PersonDataShow", "<html><head/><body><p align=\"center\">\345\271\264\351\276\204</p></body></html>", Q_NULLPTR));
        lblAge->setText(QApplication::translate("PersonDataShow", "<html><head/><body><p align=\"center\">\346\234\252\350\256\276\347\275\256</p></body></html>", Q_NULLPTR));
        label_9->setText(QApplication::translate("PersonDataShow", "<html><head/><body><p align=\"center\">\347\231\273\345\275\225\346\227\266\351\227\264</p></body></html>", Q_NULLPTR));
        lblLastLogin->setText(QApplication::translate("PersonDataShow", "<html><head/><body><p align=\"center\"><span style=\" color:#000000;\">2024-02-07 16:43:28</span></p></body></html>", Q_NULLPTR));
        btnEditInfo->setText(QApplication::translate("PersonDataShow", "\347\274\226\350\276\221\350\265\204\346\226\231", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class PersonDataShow: public Ui_PersonDataShow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PERSONDATASHOW_H
