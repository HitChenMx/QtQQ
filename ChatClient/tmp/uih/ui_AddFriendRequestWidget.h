/********************************************************************************
** Form generated from reading UI file 'AddFriendRequestWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDFRIENDREQUESTWIDGET_H
#define UI_ADDFRIENDREQUESTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddFriendRequestWidget
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *lblHeadPic;
    QVBoxLayout *verticalLayout;
    QLabel *lblName;
    QLabel *lblAccount;
    QLabel *lblAuthInfoTip;
    QPlainTextEdit *edtAuthInfo;
    QLabel *lblGroupTip;
    QComboBox *cmbGroupSelect;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnSend;
    QPushButton *btnCancel;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QWidget *AddFriendRequestWidget)
    {
        if (AddFriendRequestWidget->objectName().isEmpty())
            AddFriendRequestWidget->setObjectName(QStringLiteral("AddFriendRequestWidget"));
        AddFriendRequestWidget->resize(485, 593);
        AddFriendRequestWidget->setMinimumSize(QSize(485, 593));
        AddFriendRequestWidget->setMaximumSize(QSize(485, 593));
        QIcon icon;
        icon.addFile(QStringLiteral(":/qqicons/qrc/QQicon.svg"), QSize(), QIcon::Normal, QIcon::Off);
        AddFriendRequestWidget->setWindowIcon(icon);
        AddFriendRequestWidget->setStyleSheet(QLatin1String("QWidget#AddFriendRequestWidget{	\n"
"	background-color: rgb(250, 250, 250);\n"
"}"));
        gridLayout = new QGridLayout(AddFriendRequestWidget);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(25, 30, 25, 30);
        verticalSpacer = new QSpacerItem(20, 2, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 0, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(2, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 0, 1, 1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(40);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(4);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(4);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        lblHeadPic = new QLabel(AddFriendRequestWidget);
        lblHeadPic->setObjectName(QStringLiteral("lblHeadPic"));
        lblHeadPic->setStyleSheet(QStringLiteral(""));
        lblHeadPic->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(lblHeadPic);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(-1, 6, -1, 6);
        lblName = new QLabel(AddFriendRequestWidget);
        lblName->setObjectName(QStringLiteral("lblName"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(11);
        lblName->setFont(font);
        lblName->setStyleSheet(QStringLiteral(""));
        lblName->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout->addWidget(lblName);

        lblAccount = new QLabel(AddFriendRequestWidget);
        lblAccount->setObjectName(QStringLiteral("lblAccount"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(10);
        font1.setBold(false);
        font1.setWeight(50);
        lblAccount->setFont(font1);
        lblAccount->setStyleSheet(QLatin1String("QLabel{\n"
"	font-weight: 400;\n"
"	color: rgb(153, 153, 153);\n"
"}"));
        lblAccount->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout->addWidget(lblAccount);


        horizontalLayout->addLayout(verticalLayout);

        horizontalLayout->setStretch(0, 5);
        horizontalLayout->setStretch(1, 20);

        verticalLayout_2->addLayout(horizontalLayout);

        lblAuthInfoTip = new QLabel(AddFriendRequestWidget);
        lblAuthInfoTip->setObjectName(QStringLiteral("lblAuthInfoTip"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(10);
        lblAuthInfoTip->setFont(font2);
        lblAuthInfoTip->setStyleSheet(QLatin1String("QLabel{\n"
"	font-weight: 400;\n"
"	color: rgb(153, 153, 153);\n"
"}"));

        verticalLayout_2->addWidget(lblAuthInfoTip);

        edtAuthInfo = new QPlainTextEdit(AddFriendRequestWidget);
        edtAuthInfo->setObjectName(QStringLiteral("edtAuthInfo"));
        edtAuthInfo->setFont(font2);
        edtAuthInfo->setStyleSheet(QLatin1String("QPlainTextEdit{\n"
"	border: 1px solid grey;  \n"
"	border-radius: 8px;\n"
"	padding: 2px 2px 2px 2px;\n"
"}\n"
"\n"
"QPlainTextEdit:focus{\n"
"	border-color: rgb(0, 153, 255);\n"
"}"));

        verticalLayout_2->addWidget(edtAuthInfo);

        lblGroupTip = new QLabel(AddFriendRequestWidget);
        lblGroupTip->setObjectName(QStringLiteral("lblGroupTip"));
        lblGroupTip->setFont(font2);
        lblGroupTip->setStyleSheet(QLatin1String("QLabel{\n"
"	font-weight: 400;\n"
"	color: rgb(153, 153, 153);\n"
"}"));

        verticalLayout_2->addWidget(lblGroupTip);

        cmbGroupSelect = new QComboBox(AddFriendRequestWidget);
        cmbGroupSelect->setObjectName(QStringLiteral("cmbGroupSelect"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(cmbGroupSelect->sizePolicy().hasHeightForWidth());
        cmbGroupSelect->setSizePolicy(sizePolicy);
        cmbGroupSelect->setStyleSheet(QString::fromUtf8("QComboBox{\n"
"	border: 1px solid grey;\n"
"	border-radius: 10px;\n"
"	padding-left: 10px;/*\345\267\246\344\276\247\350\276\271\350\267\235*/\n"
"	font: 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}\n"
"\n"
"QComboBox:focus{\n"
"	border-color: rgb(0, 153, 255);\n"
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

        verticalLayout_2->addWidget(cmbGroupSelect);

        verticalLayout_2->setStretch(0, 30);
        verticalLayout_2->setStretch(1, 15);
        verticalLayout_2->setStretch(2, 50);
        verticalLayout_2->setStretch(3, 15);
        verticalLayout_2->setStretch(4, 18);

        verticalLayout_3->addLayout(verticalLayout_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(20);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        btnSend = new QPushButton(AddFriendRequestWidget);
        btnSend->setObjectName(QStringLiteral("btnSend"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(btnSend->sizePolicy().hasHeightForWidth());
        btnSend->setSizePolicy(sizePolicy1);
        btnSend->setFont(font2);
        btnSend->setStyleSheet(QLatin1String("QPushButton{\n"
"	color: rgb(255, 255, 255);\n"
"	background-color: rgb(0, 170, 255);\n"
"	border-radius: 5px;\n"
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

        horizontalLayout_2->addWidget(btnSend);

        btnCancel = new QPushButton(AddFriendRequestWidget);
        btnCancel->setObjectName(QStringLiteral("btnCancel"));
        sizePolicy1.setHeightForWidth(btnCancel->sizePolicy().hasHeightForWidth());
        btnCancel->setSizePolicy(sizePolicy1);
        btnCancel->setFont(font2);
        btnCancel->setStyleSheet(QLatin1String("QPushButton{\n"
"	color: rgb(0, 0, 0);\n"
"	background-color: rgb(255, 255, 255);\n"
"	border: 1px solid grey;\n"
"	border-radius: 5px;\n"
"}\n"
"\n"
"QPushButton:hover{	\n"
"	background-color: rgb(233, 233, 233);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"	color: rgb(97, 97, 97);\n"
"	background-color: rgb(214, 214, 214);\n"
"}\n"
""));

        horizontalLayout_2->addWidget(btnCancel);

        horizontalLayout_2->setStretch(0, 100);
        horizontalLayout_2->setStretch(1, 70);
        horizontalLayout_2->setStretch(2, 70);

        verticalLayout_3->addLayout(horizontalLayout_2);

        verticalLayout_3->setStretch(0, 361);
        verticalLayout_3->setStretch(1, 40);

        gridLayout->addLayout(verticalLayout_3, 1, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(38, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 1, 2, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 2, 1, 1, 1);

        gridLayout->setRowStretch(0, 1);
        gridLayout->setRowStretch(1, 1000);
        gridLayout->setRowStretch(2, 1);
        gridLayout->setColumnStretch(0, 1);
        gridLayout->setColumnStretch(1, 1000);
        gridLayout->setColumnStretch(2, 1);

        retranslateUi(AddFriendRequestWidget);

        QMetaObject::connectSlotsByName(AddFriendRequestWidget);
    } // setupUi

    void retranslateUi(QWidget *AddFriendRequestWidget)
    {
        AddFriendRequestWidget->setWindowTitle(QApplication::translate("AddFriendRequestWidget", "\347\224\263\350\257\267\345\212\240\345\245\275\345\217\213", Q_NULLPTR));
        lblHeadPic->setText(QApplication::translate("AddFriendRequestWidget", "\345\244\264\345\203\217", Q_NULLPTR));
        lblName->setText(QApplication::translate("AddFriendRequestWidget", "\346\230\265\347\247\260", Q_NULLPTR));
        lblAccount->setText(QApplication::translate("AddFriendRequestWidget", "\350\264\246\345\217\267", Q_NULLPTR));
        lblAuthInfoTip->setText(QApplication::translate("AddFriendRequestWidget", "\345\241\253\345\206\231\351\252\214\350\257\201\344\277\241\346\201\257", Q_NULLPTR));
        lblGroupTip->setText(QApplication::translate("AddFriendRequestWidget", "\345\210\206\347\273\204", Q_NULLPTR));
        btnSend->setText(QApplication::translate("AddFriendRequestWidget", "\345\217\221\351\200\201", Q_NULLPTR));
        btnCancel->setText(QApplication::translate("AddFriendRequestWidget", "\345\217\226\346\266\210", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AddFriendRequestWidget: public Ui_AddFriendRequestWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDFRIENDREQUESTWIDGET_H
