/********************************************************************************
** Form generated from reading UI file 'InfoLittlebox.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INFOLITTLEBOX_H
#define UI_INFOLITTLEBOX_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InfoLittleBox
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_3;
    QLabel *lblHead;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *lblName;
    QLabel *lblDate;
    QHBoxLayout *horizontalLayout_2;
    QLabel *lblInfo;
    QLabel *lblUnread;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QWidget *InfoLittleBox)
    {
        if (InfoLittleBox->objectName().isEmpty())
            InfoLittleBox->setObjectName(QStringLiteral("InfoLittleBox"));
        InfoLittleBox->resize(367, 92);
        InfoLittleBox->setStyleSheet(QStringLiteral(""));
        gridLayout = new QGridLayout(InfoLittleBox);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(5, 0, 5, 0);
        verticalSpacer = new QSpacerItem(20, 5, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(1, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(5);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        lblHead = new QLabel(InfoLittleBox);
        lblHead->setObjectName(QStringLiteral("lblHead"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lblHead->sizePolicy().hasHeightForWidth());
        lblHead->setSizePolicy(sizePolicy);
        lblHead->setMinimumSize(QSize(90, 90));
        lblHead->setMaximumSize(QSize(90, 90));
        lblHead->setStyleSheet(QLatin1String("QLabel{\n"
"	background-color: rgba(255, 255, 255, 0);\n"
"}"));
        lblHead->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(lblHead);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        lblName = new QLabel(InfoLittleBox);
        lblName->setObjectName(QStringLiteral("lblName"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lblName->sizePolicy().hasHeightForWidth());
        lblName->setSizePolicy(sizePolicy1);
        lblName->setMinimumSize(QSize(170, 0));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(11);
        lblName->setFont(font);
        lblName->setStyleSheet(QLatin1String("QLabel{\n"
"	background-color: rgba(255, 255, 255, 0);\n"
"}"));
        lblName->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout->addWidget(lblName);

        lblDate = new QLabel(InfoLittleBox);
        lblDate->setObjectName(QStringLiteral("lblDate"));
        sizePolicy1.setHeightForWidth(lblDate->sizePolicy().hasHeightForWidth());
        lblDate->setSizePolicy(sizePolicy1);
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(8);
        lblDate->setFont(font1);
        lblDate->setStyleSheet(QLatin1String("QLabel{\n"
"	color: gray;\n"
"	background-color: rgba(255, 255, 255, 0);\n"
"}"));
        lblDate->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(lblDate);

        horizontalLayout->setStretch(0, 2);
        horizontalLayout->setStretch(1, 1);

        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        lblInfo = new QLabel(InfoLittleBox);
        lblInfo->setObjectName(QStringLiteral("lblInfo"));
        sizePolicy1.setHeightForWidth(lblInfo->sizePolicy().hasHeightForWidth());
        lblInfo->setSizePolicy(sizePolicy1);
        lblInfo->setMinimumSize(QSize(210, 0));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(10);
        lblInfo->setFont(font2);
        lblInfo->setStyleSheet(QLatin1String("QLabel{\n"
"	color: gray;	\n"
"	background-color: rgba(255, 255, 255, 0);\n"
"}"));
        lblInfo->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(lblInfo);

        lblUnread = new QLabel(InfoLittleBox);
        lblUnread->setObjectName(QStringLiteral("lblUnread"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(lblUnread->sizePolicy().hasHeightForWidth());
        lblUnread->setSizePolicy(sizePolicy2);
        lblUnread->setMinimumSize(QSize(38, 38));
        lblUnread->setMaximumSize(QSize(38, 38));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font3.setPointSize(9);
        font3.setBold(true);
        font3.setWeight(75);
        font3.setStyleStrategy(QFont::PreferDefault);
        lblUnread->setFont(font3);
        lblUnread->setStyleSheet(QLatin1String("QLabel{\n"
"	color: rgb(255, 255, 255);\n"
"	margin-left:  5px;\n"
"	margin-right: 5px;\n"
"	margin-top:   5px;\n"
"	margin-bottom:5px;\n"
"	border-image: url(:/qqicons/qrc/red_circle.svg) ;\n"
"	background-color: rgba(255, 255, 255, 0);\n"
"}"));
        lblUnread->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(lblUnread);

        horizontalLayout_2->setStretch(0, 30);
        horizontalLayout_2->setStretch(1, 6);

        verticalLayout->addLayout(horizontalLayout_2);


        horizontalLayout_3->addLayout(verticalLayout);

        horizontalLayout_3->setStretch(0, 5);
        horizontalLayout_3->setStretch(1, 15);

        gridLayout->addLayout(horizontalLayout_3, 1, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(1, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 2, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 48, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 2, 1, 1, 1);

        gridLayout->setRowStretch(0, 1);
        gridLayout->setRowStretch(1, 1000);
        gridLayout->setRowStretch(2, 1);
        gridLayout->setColumnStretch(0, 1);
        gridLayout->setColumnStretch(1, 1000);
        gridLayout->setColumnStretch(2, 1);

        retranslateUi(InfoLittleBox);

        QMetaObject::connectSlotsByName(InfoLittleBox);
    } // setupUi

    void retranslateUi(QWidget *InfoLittleBox)
    {
        InfoLittleBox->setWindowTitle(QApplication::translate("InfoLittleBox", "Form", Q_NULLPTR));
        lblHead->setText(QApplication::translate("InfoLittleBox", "\345\244\264\345\203\217", Q_NULLPTR));
        lblName->setText(QApplication::translate("InfoLittleBox", "\345\220\215\345\255\227", Q_NULLPTR));
        lblDate->setText(QApplication::translate("InfoLittleBox", "2024/01/01", Q_NULLPTR));
        lblInfo->setText(QApplication::translate("InfoLittleBox", "\346\266\210\346\201\257...", Q_NULLPTR));
        lblUnread->setText(QApplication::translate("InfoLittleBox", "99", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class InfoLittleBox: public Ui_InfoLittleBox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INFOLITTLEBOX_H
