/********************************************************************************
** Form generated from reading UI file 'Login.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QGridLayout *gridLayout_4;
    QSpacerItem *verticalSpacer_7;
    QSpacerItem *horizontalSpacer_20;
    QSpacerItem *horizontalSpacer_21;
    QSpacerItem *verticalSpacer_8;
    QStackedWidget *stackedWidget;
    QWidget *pageLoginMain;
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_12;
    QVBoxLayout *allVLayout;
    QHBoxLayout *qqHLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *lblQQIcon;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *inputVLayout;
    QComboBox *cmbAccounts;
    QLineEdit *edtPassword;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *btnLogin;
    QHBoxLayout *registerHLayout;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *btnRegisterPage;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer_13;
    QSpacerItem *verticalSpacer_2;
    QWidget *pageRegister;
    QGridLayout *gridLayout_2;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *horizontalSpacer_14;
    QSpacerItem *horizontalSpacer_15;
    QSpacerItem *verticalSpacer_3;
    QVBoxLayout *verticalLayout;
    QGridLayout *regGridLayout;
    QLabel *label_2;
    QLineEdit *edtRegisterAccount;
    QLabel *label_3;
    QLineEdit *edtRegisterPassword;
    QLabel *label_4;
    QLineEdit *edtConfirmPassword;
    QHBoxLayout *regHLayout;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *btnReturn;
    QPushButton *btnRegister;
    QSpacerItem *horizontalSpacer_6;
    QWidget *pageLoginLoad;
    QGridLayout *gridLayout_5;
    QSpacerItem *horizontalSpacer_18;
    QSpacerItem *verticalSpacer_9;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer_6;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_16;
    QLabel *lblQQIconLoad;
    QSpacerItem *horizontalSpacer_17;
    QSpacerItem *verticalSpacer_5;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_8;
    QLabel *lblLoginLoadText;
    QSpacerItem *horizontalSpacer_9;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_10;
    QPushButton *btnCancelLogin;
    QSpacerItem *horizontalSpacer_11;
    QSpacerItem *horizontalSpacer_19;
    QSpacerItem *verticalSpacer_10;

    void setupUi(QDialog *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName(QStringLiteral("Login"));
        Login->resize(450, 600);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Login->sizePolicy().hasHeightForWidth());
        Login->setSizePolicy(sizePolicy);
        Login->setMinimumSize(QSize(450, 600));
        Login->setMaximumSize(QSize(450, 600));
        QIcon icon;
        icon.addFile(QStringLiteral(":/qqicons/qrc/QQicon.svg"), QSize(), QIcon::Normal, QIcon::Off);
        Login->setWindowIcon(icon);
        Login->setStyleSheet(QStringLiteral(""));
        gridLayout_4 = new QGridLayout(Login);
        gridLayout_4->setSpacing(0);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        verticalSpacer_7 = new QSpacerItem(20, 4, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_4->addItem(verticalSpacer_7, 0, 1, 1, 1);

        horizontalSpacer_20 = new QSpacerItem(4, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_20, 1, 0, 1, 1);

        horizontalSpacer_21 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_21, 1, 2, 1, 1);

        verticalSpacer_8 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_4->addItem(verticalSpacer_8, 2, 1, 1, 1);

        stackedWidget = new QStackedWidget(Login);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        pageLoginMain = new QWidget();
        pageLoginMain->setObjectName(QStringLiteral("pageLoginMain"));
        gridLayout = new QGridLayout(pageLoginMain);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(20, 10, 20, 10);
        verticalSpacer = new QSpacerItem(20, 2, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 0, 1, 1, 1);

        horizontalSpacer_12 = new QSpacerItem(1, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_12, 1, 0, 1, 1);

        allVLayout = new QVBoxLayout();
        allVLayout->setSpacing(35);
        allVLayout->setObjectName(QStringLiteral("allVLayout"));
        qqHLayout = new QHBoxLayout();
        qqHLayout->setObjectName(QStringLiteral("qqHLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        qqHLayout->addItem(horizontalSpacer);

        lblQQIcon = new QLabel(pageLoginMain);
        lblQQIcon->setObjectName(QStringLiteral("lblQQIcon"));
        sizePolicy.setHeightForWidth(lblQQIcon->sizePolicy().hasHeightForWidth());
        lblQQIcon->setSizePolicy(sizePolicy);
        lblQQIcon->setStyleSheet(QLatin1String("QLabel{\n"
"	min-width:  96px; \n"
"    min-height: 96px;\n"
"\n"
"    border-radius: 68px;\n"
"    border-width: 20 20 20 20;\n"
"	\n"
"	border-image: url(:/qqicons/qrc/QQicon.svg) 0 0 0 0;\n"
"	\n"
"	background-color: rgb(255, 255, 255);\n"
"}"));

        qqHLayout->addWidget(lblQQIcon);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        qqHLayout->addItem(horizontalSpacer_2);


        allVLayout->addLayout(qqHLayout);

        inputVLayout = new QVBoxLayout();
        inputVLayout->setSpacing(25);
        inputVLayout->setObjectName(QStringLiteral("inputVLayout"));
        cmbAccounts = new QComboBox(pageLoginMain);
        cmbAccounts->setObjectName(QStringLiteral("cmbAccounts"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(cmbAccounts->sizePolicy().hasHeightForWidth());
        cmbAccounts->setSizePolicy(sizePolicy1);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(13);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        cmbAccounts->setFont(font);
        cmbAccounts->setStyleSheet(QString::fromUtf8("QComboBox{\n"
"	border-radius: 10px;\n"
"	padding-left: 10px;/*\345\267\246\344\276\247\350\276\271\350\267\235*/\n"
"	font: 13pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
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
        cmbAccounts->setEditable(true);

        inputVLayout->addWidget(cmbAccounts);

        edtPassword = new QLineEdit(pageLoginMain);
        edtPassword->setObjectName(QStringLiteral("edtPassword"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(edtPassword->sizePolicy().hasHeightForWidth());
        edtPassword->setSizePolicy(sizePolicy2);
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(13);
        edtPassword->setFont(font1);
        edtPassword->setStyleSheet(QLatin1String("QLineEdit{\n"
"	border-radius: 10px;\n"
"}"));
        edtPassword->setAlignment(Qt::AlignCenter);

        inputVLayout->addWidget(edtPassword);


        allVLayout->addLayout(inputVLayout);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        allVLayout->addItem(horizontalSpacer_5);

        btnLogin = new QPushButton(pageLoginMain);
        btnLogin->setObjectName(QStringLiteral("btnLogin"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(btnLogin->sizePolicy().hasHeightForWidth());
        btnLogin->setSizePolicy(sizePolicy3);
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(12);
        btnLogin->setFont(font2);
        btnLogin->setStyleSheet(QLatin1String("QPushButton{\n"
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

        allVLayout->addWidget(btnLogin);

        registerHLayout = new QHBoxLayout();
        registerHLayout->setObjectName(QStringLiteral("registerHLayout"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        registerHLayout->addItem(horizontalSpacer_3);

        btnRegisterPage = new QPushButton(pageLoginMain);
        btnRegisterPage->setObjectName(QStringLiteral("btnRegisterPage"));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font3.setPointSize(11);
        btnRegisterPage->setFont(font3);
        btnRegisterPage->setStyleSheet(QLatin1String("QPushButton{\n"
"	border: none;\n"
"	color: rgb(0, 170, 255);\n"
"	background-color: rgba(0, 0, 0, 0);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"	color: rgb(226, 226, 226);\n"
"}"));

        registerHLayout->addWidget(btnRegisterPage);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        registerHLayout->addItem(horizontalSpacer_4);

        registerHLayout->setStretch(0, 1);
        registerHLayout->setStretch(1, 1);
        registerHLayout->setStretch(2, 1);

        allVLayout->addLayout(registerHLayout);

        allVLayout->setStretch(0, 32);
        allVLayout->setStretch(1, 14);
        allVLayout->setStretch(2, 4);
        allVLayout->setStretch(3, 6);
        allVLayout->setStretch(4, 8);

        gridLayout->addLayout(allVLayout, 1, 1, 1, 1);

        horizontalSpacer_13 = new QSpacerItem(58, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_13, 1, 2, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 48, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 2, 1, 1, 1);

        gridLayout->setRowStretch(0, 1);
        gridLayout->setRowStretch(1, 1000);
        gridLayout->setRowStretch(2, 1);
        gridLayout->setColumnStretch(0, 1);
        gridLayout->setColumnStretch(1, 1000);
        gridLayout->setColumnStretch(2, 1);
        stackedWidget->addWidget(pageLoginMain);
        pageRegister = new QWidget();
        pageRegister->setObjectName(QStringLiteral("pageRegister"));
        gridLayout_2 = new QGridLayout(pageRegister);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 100, 0, 100);
        verticalSpacer_4 = new QSpacerItem(20, 2, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_4, 0, 1, 1, 1);

        horizontalSpacer_14 = new QSpacerItem(48, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_14, 1, 0, 1, 1);

        horizontalSpacer_15 = new QSpacerItem(48, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_15, 1, 2, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_3, 2, 1, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(50);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        regGridLayout = new QGridLayout();
        regGridLayout->setObjectName(QStringLiteral("regGridLayout"));
        regGridLayout->setHorizontalSpacing(20);
        regGridLayout->setVerticalSpacing(30);
        label_2 = new QLabel(pageRegister);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font1);

        regGridLayout->addWidget(label_2, 0, 0, 1, 1);

        edtRegisterAccount = new QLineEdit(pageRegister);
        edtRegisterAccount->setObjectName(QStringLiteral("edtRegisterAccount"));
        sizePolicy2.setHeightForWidth(edtRegisterAccount->sizePolicy().hasHeightForWidth());
        edtRegisterAccount->setSizePolicy(sizePolicy2);
        edtRegisterAccount->setFont(font1);
        edtRegisterAccount->setStyleSheet(QLatin1String("QLineEdit{\n"
"	border-radius: 10px;\n"
"}"));
        edtRegisterAccount->setAlignment(Qt::AlignCenter);

        regGridLayout->addWidget(edtRegisterAccount, 0, 1, 1, 1);

        label_3 = new QLabel(pageRegister);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font1);

        regGridLayout->addWidget(label_3, 1, 0, 1, 1);

        edtRegisterPassword = new QLineEdit(pageRegister);
        edtRegisterPassword->setObjectName(QStringLiteral("edtRegisterPassword"));
        sizePolicy2.setHeightForWidth(edtRegisterPassword->sizePolicy().hasHeightForWidth());
        edtRegisterPassword->setSizePolicy(sizePolicy2);
        edtRegisterPassword->setFont(font1);
        edtRegisterPassword->setStyleSheet(QLatin1String("QLineEdit{\n"
"	border-radius: 10px;\n"
"}"));
        edtRegisterPassword->setAlignment(Qt::AlignCenter);

        regGridLayout->addWidget(edtRegisterPassword, 1, 1, 1, 1);

        label_4 = new QLabel(pageRegister);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font1);

        regGridLayout->addWidget(label_4, 2, 0, 1, 1);

        edtConfirmPassword = new QLineEdit(pageRegister);
        edtConfirmPassword->setObjectName(QStringLiteral("edtConfirmPassword"));
        sizePolicy2.setHeightForWidth(edtConfirmPassword->sizePolicy().hasHeightForWidth());
        edtConfirmPassword->setSizePolicy(sizePolicy2);
        edtConfirmPassword->setFont(font1);
        edtConfirmPassword->setStyleSheet(QLatin1String("QLineEdit{\n"
"	border-radius: 10px;\n"
"}"));
        edtConfirmPassword->setAlignment(Qt::AlignCenter);

        regGridLayout->addWidget(edtConfirmPassword, 2, 1, 1, 1);


        verticalLayout->addLayout(regGridLayout);

        regHLayout = new QHBoxLayout();
        regHLayout->setSpacing(50);
        regHLayout->setObjectName(QStringLiteral("regHLayout"));
        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        regHLayout->addItem(horizontalSpacer_7);

        btnReturn = new QPushButton(pageRegister);
        btnReturn->setObjectName(QStringLiteral("btnReturn"));
        sizePolicy3.setHeightForWidth(btnReturn->sizePolicy().hasHeightForWidth());
        btnReturn->setSizePolicy(sizePolicy3);
        btnReturn->setFont(font2);
        btnReturn->setStyleSheet(QLatin1String("QPushButton{\n"
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

        regHLayout->addWidget(btnReturn);

        btnRegister = new QPushButton(pageRegister);
        btnRegister->setObjectName(QStringLiteral("btnRegister"));
        sizePolicy3.setHeightForWidth(btnRegister->sizePolicy().hasHeightForWidth());
        btnRegister->setSizePolicy(sizePolicy3);
        btnRegister->setFont(font2);
        btnRegister->setStyleSheet(QLatin1String("QPushButton{\n"
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

        regHLayout->addWidget(btnRegister);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        regHLayout->addItem(horizontalSpacer_6);

        regHLayout->setStretch(0, 1);
        regHLayout->setStretch(1, 10);
        regHLayout->setStretch(2, 10);
        regHLayout->setStretch(3, 1);

        verticalLayout->addLayout(regHLayout);

        verticalLayout->setStretch(0, 50);
        verticalLayout->setStretch(1, 10);

        gridLayout_2->addLayout(verticalLayout, 1, 1, 1, 1);

        gridLayout_2->setRowStretch(0, 1);
        gridLayout_2->setRowStretch(1, 1000);
        gridLayout_2->setRowStretch(2, 1);
        gridLayout_2->setColumnStretch(0, 1);
        gridLayout_2->setColumnStretch(1, 1000);
        gridLayout_2->setColumnStretch(2, 1);
        stackedWidget->addWidget(pageRegister);
        pageLoginLoad = new QWidget();
        pageLoginLoad->setObjectName(QStringLiteral("pageLoginLoad"));
        gridLayout_5 = new QGridLayout(pageLoginLoad);
        gridLayout_5->setSpacing(0);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        gridLayout_5->setContentsMargins(0, 50, 0, 100);
        horizontalSpacer_18 = new QSpacerItem(5, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_18, 1, 0, 1, 1);

        verticalSpacer_9 = new QSpacerItem(20, 4, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_5->addItem(verticalSpacer_9, 0, 1, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(20);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_6);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer_16 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_16);

        lblQQIconLoad = new QLabel(pageLoginLoad);
        lblQQIconLoad->setObjectName(QStringLiteral("lblQQIconLoad"));
        sizePolicy.setHeightForWidth(lblQQIconLoad->sizePolicy().hasHeightForWidth());
        lblQQIconLoad->setSizePolicy(sizePolicy);
        lblQQIconLoad->setMaximumSize(QSize(136, 136));
        lblQQIconLoad->setStyleSheet(QLatin1String("QLabel{\n"
"	min-width:  96px; \n"
"    min-height: 96px;\n"
"\n"
"    border-radius: 68px;\n"
"    border-width: 20 20 20 20;\n"
"	\n"
"	border-image: url(:/qqicons/qrc/QQicon.svg) 0 0 0 0;\n"
"	\n"
"	background-color: rgb(255, 255, 255);\n"
"}"));

        horizontalLayout_3->addWidget(lblQQIconLoad);

        horizontalSpacer_17 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_17);


        verticalLayout_2->addLayout(horizontalLayout_3);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_5);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_8);

        lblLoginLoadText = new QLabel(pageLoginLoad);
        lblLoginLoadText->setObjectName(QStringLiteral("lblLoginLoadText"));
        QFont font4;
        font4.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font4.setPointSize(14);
        lblLoginLoadText->setFont(font4);

        horizontalLayout->addWidget(lblLoginLoadText);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_9);

        horizontalLayout->setStretch(0, 5);
        horizontalLayout->setStretch(1, 8);
        horizontalLayout->setStretch(2, 5);

        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_10);

        btnCancelLogin = new QPushButton(pageLoginLoad);
        btnCancelLogin->setObjectName(QStringLiteral("btnCancelLogin"));
        sizePolicy1.setHeightForWidth(btnCancelLogin->sizePolicy().hasHeightForWidth());
        btnCancelLogin->setSizePolicy(sizePolicy1);
        btnCancelLogin->setFont(font4);

        horizontalLayout_2->addWidget(btnCancelLogin);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_11);

        horizontalLayout_2->setStretch(0, 5);
        horizontalLayout_2->setStretch(1, 8);
        horizontalLayout_2->setStretch(2, 5);

        verticalLayout_2->addLayout(horizontalLayout_2);

        verticalLayout_2->setStretch(0, 10);
        verticalLayout_2->setStretch(1, 50);
        verticalLayout_2->setStretch(2, 1);
        verticalLayout_2->setStretch(3, 20);
        verticalLayout_2->setStretch(4, 10);

        gridLayout_5->addLayout(verticalLayout_2, 1, 1, 1, 1);

        horizontalSpacer_19 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_19, 1, 2, 1, 1);

        verticalSpacer_10 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_5->addItem(verticalSpacer_10, 2, 1, 1, 1);

        gridLayout_5->setRowStretch(0, 1);
        gridLayout_5->setRowStretch(1, 1000);
        gridLayout_5->setRowStretch(2, 1);
        gridLayout_5->setColumnStretch(0, 1);
        gridLayout_5->setColumnStretch(1, 1000);
        gridLayout_5->setColumnStretch(2, 1);
        stackedWidget->addWidget(pageLoginLoad);

        gridLayout_4->addWidget(stackedWidget, 1, 1, 1, 1);

        gridLayout_4->setRowStretch(0, 1);
        gridLayout_4->setRowStretch(1, 1000);
        gridLayout_4->setRowStretch(2, 1);
        gridLayout_4->setColumnStretch(0, 1);
        gridLayout_4->setColumnStretch(1, 1000);
        gridLayout_4->setColumnStretch(2, 1);

        retranslateUi(Login);

        stackedWidget->setCurrentIndex(0);
        cmbAccounts->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QDialog *Login)
    {
        Login->setWindowTitle(QApplication::translate("Login", "QQ", Q_NULLPTR));
        lblQQIcon->setText(QApplication::translate("Login", "<html><head/><body><p align=\"center\"><br/></p></body></html>", Q_NULLPTR));
        edtPassword->setPlaceholderText(QApplication::translate("Login", "\350\276\223\345\205\245QQ\345\257\206\347\240\201", Q_NULLPTR));
        btnLogin->setText(QApplication::translate("Login", "\347\231\273\345\275\225", Q_NULLPTR));
        btnRegisterPage->setText(QApplication::translate("Login", "\346\263\250\345\206\214\350\264\246\345\217\267", Q_NULLPTR));
        label_2->setText(QApplication::translate("Login", "<html><head/><body><p align=\"center\">\350\264\246\345\217\267</p></body></html>", Q_NULLPTR));
        edtRegisterAccount->setPlaceholderText(QApplication::translate("Login", "\350\276\223\345\205\245\346\263\250\345\206\214\350\264\246\345\217\267", Q_NULLPTR));
        label_3->setText(QApplication::translate("Login", "<html><head/><body><p align=\"center\">\345\257\206\347\240\201</p></body></html>", Q_NULLPTR));
        edtRegisterPassword->setPlaceholderText(QApplication::translate("Login", "\350\276\223\345\205\245\346\263\250\345\206\214\345\257\206\347\240\201", Q_NULLPTR));
        label_4->setText(QApplication::translate("Login", "<html><head/><body><p align=\"center\">\347\241\256\350\256\244\345\257\206\347\240\201</p></body></html>", Q_NULLPTR));
        edtConfirmPassword->setPlaceholderText(QApplication::translate("Login", "\347\241\256\350\256\244\345\257\206\347\240\201", Q_NULLPTR));
        btnReturn->setText(QApplication::translate("Login", "\350\277\224\345\233\236", Q_NULLPTR));
        btnRegister->setText(QApplication::translate("Login", "\346\263\250\345\206\214", Q_NULLPTR));
        lblQQIconLoad->setText(QApplication::translate("Login", "<html><head/><body><p align=\"center\"><br/></p></body></html>", Q_NULLPTR));
        lblLoginLoadText->setText(QApplication::translate("Login", "<html><head/><body><p align=\"center\">\347\231\273\345\275\225\344\270\255</p></body></html>", Q_NULLPTR));
        btnCancelLogin->setText(QApplication::translate("Login", "\345\217\226\346\266\210", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
