/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_startListen;
    QAction *action_stopListen;
    QAction *action_clearOutput;
    QAction *action_exit;
    QWidget *centralWidget;
    QGridLayout *gridLayout_3;
    QSpacerItem *verticalSpacer_5;
    QSpacerItem *horizontalSpacer_5;
    QHBoxLayout *horizontalLayout_3;
    QGroupBox *gbListen;
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *lblAddress;
    QComboBox *cmbIPAddress;
    QLabel *lblPort;
    QSpinBox *spbPort;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *edtMessage;
    QPushButton *btnSendMessage;
    QPlainTextEdit *edtOutputShow;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_2;
    QGroupBox *gbClient;
    QGridLayout *gridLayout_2;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *horizontalSpacer_3;
    QListView *lstClientView;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *verticalSpacer_6;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(859, 1063);
        QIcon icon;
        icon.addFile(QStringLiteral(":/icon/qrc/tcpserver.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        action_startListen = new QAction(MainWindow);
        action_startListen->setObjectName(QStringLiteral("action_startListen"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/icon/qrc/620.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        action_startListen->setIcon(icon1);
        action_stopListen = new QAction(MainWindow);
        action_stopListen->setObjectName(QStringLiteral("action_stopListen"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/icon/qrc/624.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        action_stopListen->setIcon(icon2);
        action_clearOutput = new QAction(MainWindow);
        action_clearOutput->setObjectName(QStringLiteral("action_clearOutput"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/icon/qrc/212.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        action_clearOutput->setIcon(icon3);
        action_exit = new QAction(MainWindow);
        action_exit->setObjectName(QStringLiteral("action_exit"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/icon/qrc/132.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        action_exit->setIcon(icon4);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_3 = new QGridLayout(centralWidget);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(-1, -1, -1, 0);
        verticalSpacer_5 = new QSpacerItem(20, 6, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_5, 0, 1, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(7, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_5, 1, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        gbListen = new QGroupBox(centralWidget);
        gbListen->setObjectName(QStringLiteral("gbListen"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(12);
        gbListen->setFont(font);
        gbListen->setStyleSheet(QLatin1String("QGroupBox:title { \n"
"	color: rgb(96, 107, 255);\n"
"}\n"
"\n"
"QComboBox{\n"
"	font: 12pt \"Times New Roman\";\n"
"}\n"
"\n"
"QSpinBox{\n"
"	font: 12pt \"Times New Roman\";\n"
"}"));
        gridLayout = new QGridLayout(gbListen);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 10, 0, 0);
        verticalSpacer = new QSpacerItem(20, 4, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(3, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(12);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        lblAddress = new QLabel(gbListen);
        lblAddress->setObjectName(QStringLiteral("lblAddress"));
        QFont font1;
        font1.setPointSize(10);
        lblAddress->setFont(font1);

        horizontalLayout->addWidget(lblAddress);

        cmbIPAddress = new QComboBox(gbListen);
        cmbIPAddress->setObjectName(QStringLiteral("cmbIPAddress"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(cmbIPAddress->sizePolicy().hasHeightForWidth());
        cmbIPAddress->setSizePolicy(sizePolicy);
        QFont font2;
        font2.setFamily(QStringLiteral("Times New Roman"));
        font2.setPointSize(12);
        cmbIPAddress->setFont(font2);
        cmbIPAddress->setEditable(true);

        horizontalLayout->addWidget(cmbIPAddress);

        lblPort = new QLabel(gbListen);
        lblPort->setObjectName(QStringLiteral("lblPort"));
        lblPort->setFont(font1);

        horizontalLayout->addWidget(lblPort);

        spbPort = new QSpinBox(gbListen);
        spbPort->setObjectName(QStringLiteral("spbPort"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(spbPort->sizePolicy().hasHeightForWidth());
        spbPort->setSizePolicy(sizePolicy1);
        QFont font3;
        font3.setFamily(QStringLiteral("Times New Roman"));
        font3.setPointSize(12);
        font3.setBold(false);
        font3.setItalic(false);
        font3.setWeight(50);
        spbPort->setFont(font3);
        spbPort->setMinimum(1);
        spbPort->setMaximum(65535);
        spbPort->setValue(8000);

        horizontalLayout->addWidget(spbPort);

        horizontalLayout->setStretch(0, 5);
        horizontalLayout->setStretch(1, 10);
        horizontalLayout->setStretch(2, 5);
        horizontalLayout->setStretch(3, 8);

        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        edtMessage = new QLineEdit(gbListen);
        edtMessage->setObjectName(QStringLiteral("edtMessage"));
        QFont font4;
        font4.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font4.setPointSize(10);
        edtMessage->setFont(font4);

        horizontalLayout_2->addWidget(edtMessage);

        btnSendMessage = new QPushButton(gbListen);
        btnSendMessage->setObjectName(QStringLiteral("btnSendMessage"));
        QFont font5;
        font5.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font5.setPointSize(11);
        btnSendMessage->setFont(font5);

        horizontalLayout_2->addWidget(btnSendMessage);


        verticalLayout->addLayout(horizontalLayout_2);

        edtOutputShow = new QPlainTextEdit(gbListen);
        edtOutputShow->setObjectName(QStringLiteral("edtOutputShow"));
        edtOutputShow->setFont(font4);
        edtOutputShow->setReadOnly(true);

        verticalLayout->addWidget(edtOutputShow);


        gridLayout->addLayout(verticalLayout, 1, 1, 1, 1);

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

        horizontalLayout_3->addWidget(gbListen);

        gbClient = new QGroupBox(centralWidget);
        gbClient->setObjectName(QStringLiteral("gbClient"));
        gbClient->setFont(font);
        gbClient->setStyleSheet(QLatin1String("QGroupBox:title { \n"
"	color: rgb(96, 107, 255);\n"
"}"));
        gridLayout_2 = new QGridLayout(gbClient);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 10, 0, 0);
        verticalSpacer_3 = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_3, 0, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(0, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_3, 1, 0, 1, 1);

        lstClientView = new QListView(gbClient);
        lstClientView->setObjectName(QStringLiteral("lstClientView"));
        lstClientView->setFont(font2);

        gridLayout_2->addWidget(lstClientView, 1, 1, 1, 1);

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

        horizontalLayout_3->addWidget(gbClient);

        horizontalLayout_3->setStretch(0, 90);
        horizontalLayout_3->setStretch(1, 40);

        gridLayout_3->addLayout(horizontalLayout_3, 1, 1, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_6, 1, 2, 1, 1);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_6, 2, 1, 1, 1);

        gridLayout_3->setRowStretch(0, 1);
        gridLayout_3->setRowStretch(1, 1000);
        gridLayout_3->setRowStretch(2, 1);
        gridLayout_3->setColumnStretch(0, 1);
        gridLayout_3->setColumnStretch(1, 1000);
        gridLayout_3->setColumnStretch(2, 1);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 859, 30));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        mainToolBar->setFont(font4);
        mainToolBar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        mainToolBar->addAction(action_startListen);
        mainToolBar->addAction(action_stopListen);
        mainToolBar->addAction(action_clearOutput);
        mainToolBar->addSeparator();
        mainToolBar->addAction(action_exit);

        retranslateUi(MainWindow);

        cmbIPAddress->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\346\234\215\345\212\241\347\253\257", Q_NULLPTR));
        action_startListen->setText(QApplication::translate("MainWindow", "\345\274\200\345\247\213\347\233\221\345\220\254", Q_NULLPTR));
        action_stopListen->setText(QApplication::translate("MainWindow", "\345\201\234\346\255\242\347\233\221\345\220\254", Q_NULLPTR));
        action_clearOutput->setText(QApplication::translate("MainWindow", "\346\270\205\347\251\272\346\226\207\346\234\254\346\241\206", Q_NULLPTR));
        action_exit->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272", Q_NULLPTR));
        gbListen->setTitle(QApplication::translate("MainWindow", "\347\233\221\345\220\254\346\203\205\345\206\265", Q_NULLPTR));
        lblAddress->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:11pt;\">\347\233\221\345\220\254\345\234\260\345\235\200</span></p></body></html>", Q_NULLPTR));
        cmbIPAddress->clear();
        cmbIPAddress->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "127.0.0.1", Q_NULLPTR)
        );
#ifndef QT_NO_STATUSTIP
        cmbIPAddress->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
        cmbIPAddress->setCurrentText(QApplication::translate("MainWindow", "127.0.0.1", Q_NULLPTR));
        lblPort->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:11pt;\">\347\233\221\345\220\254\347\253\257\345\217\243</span></p></body></html>", Q_NULLPTR));
#ifndef QT_NO_STATUSTIP
        edtMessage->setStatusTip(QApplication::translate("MainWindow", "\345\217\221\351\200\201\345\206\205\345\256\271", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_STATUSTIP
        btnSendMessage->setStatusTip(QApplication::translate("MainWindow", "\345\217\221\351\200\201\344\277\241\346\201\257", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        btnSendMessage->setText(QApplication::translate("MainWindow", "\345\217\221\351\200\201", Q_NULLPTR));
        gbClient->setTitle(QApplication::translate("MainWindow", "\345\256\242\346\210\267\345\210\227\350\241\250", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
