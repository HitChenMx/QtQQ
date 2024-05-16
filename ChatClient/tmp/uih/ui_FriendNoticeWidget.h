/********************************************************************************
** Form generated from reading UI file 'FriendNoticeWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRIENDNOTICEWIDGET_H
#define UI_FRIENDNOTICEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FriendNoticeWidget
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_8;
    QLabel *lblFriendNoticeTip;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *btnClearFriendNotice;
    QSpacerItem *horizontalSpacer_9;
    QStackedWidget *stkwNoticeResult;
    QWidget *pageNoNotice;
    QGridLayout *gridLayout_5;
    QSpacerItem *verticalSpacer_8;
    QSpacerItem *horizontalSpacer_12;
    QVBoxLayout *verticalLayout_4;
    QLabel *label;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_13;
    QSpacerItem *verticalSpacer_9;
    QWidget *pageNoticeList;
    QGridLayout *gridLayout_4;
    QSpacerItem *verticalSpacer_6;
    QSpacerItem *horizontalSpacer_10;
    QScrollArea *sldFriendNoticeList;
    QWidget *wFriendNoticeList;
    QSpacerItem *horizontalSpacer_11;
    QSpacerItem *verticalSpacer_7;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QWidget *FriendNoticeWidget)
    {
        if (FriendNoticeWidget->objectName().isEmpty())
            FriendNoticeWidget->setObjectName(QStringLiteral("FriendNoticeWidget"));
        FriendNoticeWidget->resize(923, 965);
        gridLayout = new QGridLayout(FriendNoticeWidget);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 20, 0, 20);
        verticalSpacer = new QSpacerItem(20, 6, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(6, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(30);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_8);

        lblFriendNoticeTip = new QLabel(FriendNoticeWidget);
        lblFriendNoticeTip->setObjectName(QStringLiteral("lblFriendNoticeTip"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(12);
        lblFriendNoticeTip->setFont(font);
        lblFriendNoticeTip->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(lblFriendNoticeTip);

        horizontalSpacer_5 = new QSpacerItem(13, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_5);

        btnClearFriendNotice = new QPushButton(FriendNoticeWidget);
        btnClearFriendNotice->setObjectName(QStringLiteral("btnClearFriendNotice"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(btnClearFriendNotice->sizePolicy().hasHeightForWidth());
        btnClearFriendNotice->setSizePolicy(sizePolicy);
        btnClearFriendNotice->setMinimumSize(QSize(32, 32));
        btnClearFriendNotice->setMaximumSize(QSize(32, 32));
        btnClearFriendNotice->setStyleSheet(QLatin1String("QPushButton{\n"
"	border-image: url(:/qqicons/qrc/delete.svg);\n"
"	border: none;	\n"
"	background-color: rgba(255, 255, 255, 0);\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"	border-image: url(:/qqicons/qrc/delete_blue.svg);\n"
"}"));
        btnClearFriendNotice->setIconSize(QSize(32, 32));

        horizontalLayout_4->addWidget(btnClearFriendNotice);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_9);

        horizontalLayout_4->setStretch(0, 3);
        horizontalLayout_4->setStretch(1, 100);
        horizontalLayout_4->setStretch(2, 10);
        horizontalLayout_4->setStretch(3, 10);
        horizontalLayout_4->setStretch(4, 3);

        verticalLayout_3->addLayout(horizontalLayout_4);

        stkwNoticeResult = new QStackedWidget(FriendNoticeWidget);
        stkwNoticeResult->setObjectName(QStringLiteral("stkwNoticeResult"));
        pageNoNotice = new QWidget();
        pageNoNotice->setObjectName(QStringLiteral("pageNoNotice"));
        gridLayout_5 = new QGridLayout(pageNoNotice);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        gridLayout_5->setContentsMargins(0, 0, 0, 0);
        verticalSpacer_8 = new QSpacerItem(20, 262, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_5->addItem(verticalSpacer_8, 0, 1, 1, 1);

        horizontalSpacer_12 = new QSpacerItem(182, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_12, 1, 0, 1, 1);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        label = new QLabel(pageNoNotice);
        label->setObjectName(QStringLiteral("label"));
        label->setPixmap(QPixmap(QString::fromUtf8(":/qqicons/qrc/notice.svg")));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(label);

        label_2 = new QLabel(pageNoNotice);
        label_2->setObjectName(QStringLiteral("label_2"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(13);
        label_2->setFont(font1);
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(label_2);

        verticalLayout_4->setStretch(0, 3);
        verticalLayout_4->setStretch(1, 1);

        gridLayout_5->addLayout(verticalLayout_4, 1, 1, 1, 1);

        horizontalSpacer_13 = new QSpacerItem(182, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_13, 1, 2, 1, 1);

        verticalSpacer_9 = new QSpacerItem(20, 262, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_5->addItem(verticalSpacer_9, 2, 1, 1, 1);

        gridLayout_5->setRowStretch(0, 1);
        gridLayout_5->setRowStretch(1, 1);
        gridLayout_5->setRowStretch(2, 1);
        gridLayout_5->setColumnStretch(0, 1);
        gridLayout_5->setColumnStretch(1, 3);
        gridLayout_5->setColumnStretch(2, 1);
        stkwNoticeResult->addWidget(pageNoNotice);
        pageNoticeList = new QWidget();
        pageNoticeList->setObjectName(QStringLiteral("pageNoticeList"));
        gridLayout_4 = new QGridLayout(pageNoticeList);
        gridLayout_4->setSpacing(0);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        verticalSpacer_6 = new QSpacerItem(20, 2, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_4->addItem(verticalSpacer_6, 0, 1, 1, 1);

        horizontalSpacer_10 = new QSpacerItem(5, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_10, 1, 0, 1, 1);

        sldFriendNoticeList = new QScrollArea(pageNoticeList);
        sldFriendNoticeList->setObjectName(QStringLiteral("sldFriendNoticeList"));
        sldFriendNoticeList->setFrameShape(QFrame::NoFrame);
        sldFriendNoticeList->setWidgetResizable(true);
        wFriendNoticeList = new QWidget();
        wFriendNoticeList->setObjectName(QStringLiteral("wFriendNoticeList"));
        wFriendNoticeList->setGeometry(QRect(0, 0, 917, 871));
        sldFriendNoticeList->setWidget(wFriendNoticeList);

        gridLayout_4->addWidget(sldFriendNoticeList, 1, 1, 1, 1);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_11, 1, 2, 1, 1);

        verticalSpacer_7 = new QSpacerItem(20, 38, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_4->addItem(verticalSpacer_7, 2, 1, 1, 1);

        gridLayout_4->setRowStretch(0, 1);
        gridLayout_4->setRowStretch(1, 1000);
        gridLayout_4->setRowStretch(2, 1);
        gridLayout_4->setColumnStretch(0, 1);
        gridLayout_4->setColumnStretch(1, 1000);
        gridLayout_4->setColumnStretch(2, 1);
        stkwNoticeResult->addWidget(pageNoticeList);

        verticalLayout_3->addWidget(stkwNoticeResult);

        verticalLayout_3->setStretch(0, 10);
        verticalLayout_3->setStretch(1, 150);

        gridLayout->addLayout(verticalLayout_3, 1, 1, 1, 1);

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

        retranslateUi(FriendNoticeWidget);

        stkwNoticeResult->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(FriendNoticeWidget);
    } // setupUi

    void retranslateUi(QWidget *FriendNoticeWidget)
    {
        FriendNoticeWidget->setWindowTitle(QApplication::translate("FriendNoticeWidget", "Form", Q_NULLPTR));
        lblFriendNoticeTip->setText(QApplication::translate("FriendNoticeWidget", "\345\245\275\345\217\213\351\200\232\347\237\245", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        btnClearFriendNotice->setToolTip(QApplication::translate("FriendNoticeWidget", "\346\270\205\347\251\272\345\245\275\345\217\213\351\200\232\347\237\245", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        btnClearFriendNotice->setText(QString());
        label->setText(QString());
        label_2->setText(QApplication::translate("FriendNoticeWidget", "\346\232\202\346\227\240\351\200\232\347\237\245", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class FriendNoticeWidget: public Ui_FriendNoticeWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRIENDNOTICEWIDGET_H
