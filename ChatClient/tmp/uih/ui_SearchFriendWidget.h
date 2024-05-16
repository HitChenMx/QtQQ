/********************************************************************************
** Form generated from reading UI file 'SearchFriendWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCHFRIENDWIDGET_H
#define UI_SEARCHFRIENDWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SearchFriendWidget
{
public:
    QGridLayout *gridLayout_4;
    QSpacerItem *verticalSpacer_7;
    QSpacerItem *horizontalSpacer_9;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_7;
    QLineEdit *edtSearch;
    QSpacerItem *horizontalSpacer_8;
    QStackedWidget *stkwResultShow;
    QWidget *pageNoSearch;
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout;
    QLabel *lblNoSearchPic;
    QLabel *lblNoSearchTip;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_2;
    QWidget *pageSearchResult;
    QGridLayout *gridLayout_3;
    QSpacerItem *verticalSpacer_5;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *verticalSpacer_6;
    QScrollArea *sldSearchResult;
    QWidget *wSearchResult;
    QWidget *pageSearchIsNull;
    QGridLayout *gridLayout_2;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *horizontalSpacer_3;
    QVBoxLayout *verticalLayout_2;
    QLabel *lblSearchNullPic;
    QLabel *lblSearchNullTip;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *horizontalSpacer_10;
    QSpacerItem *verticalSpacer_8;

    void setupUi(QWidget *SearchFriendWidget)
    {
        if (SearchFriendWidget->objectName().isEmpty())
            SearchFriendWidget->setObjectName(QStringLiteral("SearchFriendWidget"));
        SearchFriendWidget->resize(1010, 1030);
        SearchFriendWidget->setMinimumSize(QSize(505, 515));
        SearchFriendWidget->setStyleSheet(QLatin1String("QWidget#SearchFriendWidget{\n"
"	background-color: rgb(255, 255, 255);\n"
"}"));
        gridLayout_4 = new QGridLayout(SearchFriendWidget);
        gridLayout_4->setSpacing(0);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 20, 0, 0);
        verticalSpacer_7 = new QSpacerItem(20, 6, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_4->addItem(verticalSpacer_7, 0, 1, 1, 1);

        horizontalSpacer_9 = new QSpacerItem(6, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_9, 1, 0, 1, 1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(20);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer_7 = new QSpacerItem(38, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_7);

        edtSearch = new QLineEdit(SearchFriendWidget);
        edtSearch->setObjectName(QStringLiteral("edtSearch"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(edtSearch->sizePolicy().hasHeightForWidth());
        edtSearch->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(10);
        edtSearch->setFont(font);
        edtSearch->setStyleSheet(QLatin1String("QLineEdit{\n"
"	border: none;\n"
"	background-color: rgb(240, 240, 240, 200);\n"
"	border-radius: 7px;\n"
"}\n"
"\n"
"QLineEdit:focus{\n"
"	border: 1px solid;\n"
"	border-color: rgb(0, 153, 255);\n"
"	background-color: rgb(240, 240, 240, 160);\n"
"}"));
        edtSearch->setClearButtonEnabled(true);

        horizontalLayout->addWidget(edtSearch);

        horizontalSpacer_8 = new QSpacerItem(38, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_8);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 40);
        horizontalLayout->setStretch(2, 1);

        verticalLayout_3->addLayout(horizontalLayout);

        stkwResultShow = new QStackedWidget(SearchFriendWidget);
        stkwResultShow->setObjectName(QStringLiteral("stkwResultShow"));
        stkwResultShow->setStyleSheet(QStringLiteral(""));
        pageNoSearch = new QWidget();
        pageNoSearch->setObjectName(QStringLiteral("pageNoSearch"));
        pageNoSearch->setStyleSheet(QLatin1String("QWidget{\n"
"	background-color: rgb(255, 255, 255);\n"
"}"));
        gridLayout = new QGridLayout(pageNoSearch);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        verticalSpacer = new QSpacerItem(20, 305, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(195, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        lblNoSearchPic = new QLabel(pageNoSearch);
        lblNoSearchPic->setObjectName(QStringLiteral("lblNoSearchPic"));
        lblNoSearchPic->setMinimumSize(QSize(130, 130));
        lblNoSearchPic->setMaximumSize(QSize(6000, 6000));
        lblNoSearchPic->setStyleSheet(QLatin1String("QLabel{\n"
"	background-color: rgb(255, 255, 255, 0);\n"
"}"));
        lblNoSearchPic->setPixmap(QPixmap(QString::fromUtf8(":/qqicons/qrc/no_search.svg")));
        lblNoSearchPic->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(lblNoSearchPic);

        lblNoSearchTip = new QLabel(pageNoSearch);
        lblNoSearchTip->setObjectName(QStringLiteral("lblNoSearchTip"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(13);
        lblNoSearchTip->setFont(font1);
        lblNoSearchTip->setStyleSheet(QLatin1String("QLabel{\n"
"	background-color: rgb(255, 255, 255, 0);\n"
"}"));
        lblNoSearchTip->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(lblNoSearchTip);

        verticalLayout->setStretch(0, 3);
        verticalLayout->setStretch(1, 1);

        gridLayout->addLayout(verticalLayout, 1, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(195, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 2, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 305, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 2, 1, 1, 1);

        gridLayout->setRowStretch(0, 1);
        gridLayout->setRowStretch(1, 1);
        gridLayout->setRowStretch(2, 1);
        gridLayout->setColumnStretch(0, 1);
        gridLayout->setColumnStretch(1, 3);
        gridLayout->setColumnStretch(2, 1);
        stkwResultShow->addWidget(pageNoSearch);
        pageSearchResult = new QWidget();
        pageSearchResult->setObjectName(QStringLiteral("pageSearchResult"));
        gridLayout_3 = new QGridLayout(pageSearchResult);
        gridLayout_3->setSpacing(0);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalSpacer_5 = new QSpacerItem(20, 4, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_5, 0, 1, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(5, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_5, 1, 0, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(38, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_6, 1, 2, 1, 1);

        verticalSpacer_6 = new QSpacerItem(20, 38, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_6, 2, 1, 1, 1);

        sldSearchResult = new QScrollArea(pageSearchResult);
        sldSearchResult->setObjectName(QStringLiteral("sldSearchResult"));
        sldSearchResult->setStyleSheet(QStringLiteral(""));
        sldSearchResult->setFrameShape(QFrame::NoFrame);
        sldSearchResult->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        sldSearchResult->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        sldSearchResult->setWidgetResizable(true);
        sldSearchResult->setAlignment(Qt::AlignCenter);
        wSearchResult = new QWidget();
        wSearchResult->setObjectName(QStringLiteral("wSearchResult"));
        wSearchResult->setGeometry(QRect(0, 0, 1004, 939));
        wSearchResult->setStyleSheet(QLatin1String("QWidget#wSearchResult{\n"
"	background-color: rgb(255, 255, 255);\n"
"}"));
        sldSearchResult->setWidget(wSearchResult);

        gridLayout_3->addWidget(sldSearchResult, 1, 1, 1, 1);

        gridLayout_3->setRowStretch(0, 1);
        gridLayout_3->setRowStretch(1, 1000);
        gridLayout_3->setRowStretch(2, 1);
        gridLayout_3->setColumnStretch(0, 1);
        gridLayout_3->setColumnStretch(1, 1000);
        gridLayout_3->setColumnStretch(2, 1);
        stkwResultShow->addWidget(pageSearchResult);
        pageSearchIsNull = new QWidget();
        pageSearchIsNull->setObjectName(QStringLiteral("pageSearchIsNull"));
        pageSearchIsNull->setStyleSheet(QLatin1String("QWidget{\n"
"	background-color: rgb(255, 255, 255);\n"
"}"));
        gridLayout_2 = new QGridLayout(pageSearchIsNull);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalSpacer_3 = new QSpacerItem(20, 279, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_3, 0, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(172, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_3, 1, 0, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        lblSearchNullPic = new QLabel(pageSearchIsNull);
        lblSearchNullPic->setObjectName(QStringLiteral("lblSearchNullPic"));
        lblSearchNullPic->setMinimumSize(QSize(140, 120));
        lblSearchNullPic->setMaximumSize(QSize(7000, 6000));
        lblSearchNullPic->setStyleSheet(QLatin1String("QLabel{\n"
"	background-color: rgb(255, 255, 255, 0);\n"
"}"));
        lblSearchNullPic->setPixmap(QPixmap(QString::fromUtf8(":/qqicons/qrc/search_is_null.svg")));
        lblSearchNullPic->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(lblSearchNullPic);

        lblSearchNullTip = new QLabel(pageSearchIsNull);
        lblSearchNullTip->setObjectName(QStringLiteral("lblSearchNullTip"));
        lblSearchNullTip->setFont(font1);
        lblSearchNullTip->setStyleSheet(QLatin1String("QLabel{\n"
"	background-color: rgb(255, 255, 255, 0);\n"
"}"));
        lblSearchNullTip->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(lblSearchNullTip);

        verticalLayout_2->setStretch(0, 3);
        verticalLayout_2->setStretch(1, 1);

        gridLayout_2->addLayout(verticalLayout_2, 1, 1, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(172, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_4, 1, 2, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 279, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_4, 2, 1, 1, 1);

        gridLayout_2->setRowStretch(0, 1);
        gridLayout_2->setRowStretch(1, 1);
        gridLayout_2->setRowStretch(2, 1);
        gridLayout_2->setColumnStretch(0, 1);
        gridLayout_2->setColumnStretch(1, 3);
        gridLayout_2->setColumnStretch(2, 1);
        stkwResultShow->addWidget(pageSearchIsNull);

        verticalLayout_3->addWidget(stkwResultShow);

        verticalLayout_3->setStretch(0, 1);
        verticalLayout_3->setStretch(1, 21);

        gridLayout_4->addLayout(verticalLayout_3, 1, 1, 1, 1);

        horizontalSpacer_10 = new QSpacerItem(38, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_10, 1, 2, 1, 1);

        verticalSpacer_8 = new QSpacerItem(20, 58, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_4->addItem(verticalSpacer_8, 2, 1, 1, 1);

        gridLayout_4->setRowStretch(0, 1);
        gridLayout_4->setRowStretch(1, 1000);
        gridLayout_4->setRowStretch(2, 1);
        gridLayout_4->setColumnStretch(0, 1);
        gridLayout_4->setColumnStretch(1, 1000);
        gridLayout_4->setColumnStretch(2, 1);

        retranslateUi(SearchFriendWidget);

        stkwResultShow->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(SearchFriendWidget);
    } // setupUi

    void retranslateUi(QWidget *SearchFriendWidget)
    {
        SearchFriendWidget->setWindowTitle(QApplication::translate("SearchFriendWidget", "\346\267\273\345\212\240\345\245\275\345\217\213", Q_NULLPTR));
        edtSearch->setPlaceholderText(QApplication::translate("SearchFriendWidget", "\350\276\223\345\205\245\346\220\234\347\264\242\345\205\263\351\224\256\350\257\215", Q_NULLPTR));
        lblNoSearchPic->setText(QString());
        lblNoSearchTip->setText(QApplication::translate("SearchFriendWidget", "\350\276\223\345\205\245\345\205\263\351\224\256\350\257\215\346\220\234\347\264\242", Q_NULLPTR));
        lblSearchNullPic->setText(QString());
        lblSearchNullTip->setText(QApplication::translate("SearchFriendWidget", "\346\232\202\346\227\240\346\220\234\347\264\242\347\273\223\346\236\234", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SearchFriendWidget: public Ui_SearchFriendWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCHFRIENDWIDGET_H
