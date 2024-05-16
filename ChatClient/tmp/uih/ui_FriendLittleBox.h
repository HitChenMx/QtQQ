/********************************************************************************
** Form generated from reading UI file 'FriendLittleBox.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRIENDLITTLEBOX_H
#define UI_FRIENDLITTLEBOX_H

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

class Ui_FriendLittleBox
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QLabel *lblHead;
    QVBoxLayout *verticalLayout;
    QLabel *lblName;
    QHBoxLayout *horizontalLayout;
    QLabel *lblOnlineState;
    QLabel *lblSignature;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QWidget *FriendLittleBox)
    {
        if (FriendLittleBox->objectName().isEmpty())
            FriendLittleBox->setObjectName(QStringLiteral("FriendLittleBox"));
        FriendLittleBox->resize(355, 92);
        FriendLittleBox->setMinimumSize(QSize(355, 92));
        FriendLittleBox->setMaximumSize(QSize(16777215, 92));
        gridLayout = new QGridLayout(FriendLittleBox);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        verticalSpacer = new QSpacerItem(20, 5, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(0, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(9);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        lblHead = new QLabel(FriendLittleBox);
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

        horizontalLayout_2->addWidget(lblHead);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        lblName = new QLabel(FriendLittleBox);
        lblName->setObjectName(QStringLiteral("lblName"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lblName->sizePolicy().hasHeightForWidth());
        lblName->setSizePolicy(sizePolicy1);
        lblName->setMinimumSize(QSize(250, 0));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(11);
        lblName->setFont(font);
        lblName->setStyleSheet(QLatin1String("QLabel{\n"
"	background-color: rgba(255, 255, 255, 0);\n"
"}"));
        lblName->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout->addWidget(lblName);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        lblOnlineState = new QLabel(FriendLittleBox);
        lblOnlineState->setObjectName(QStringLiteral("lblOnlineState"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(lblOnlineState->sizePolicy().hasHeightForWidth());
        lblOnlineState->setSizePolicy(sizePolicy2);
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(10);
        lblOnlineState->setFont(font1);
        lblOnlineState->setStyleSheet(QLatin1String("QLabel{\n"
"	color: gray;\n"
"	background-color: rgba(255, 255, 255, 0);\n"
"}"));
        lblOnlineState->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(lblOnlineState);

        lblSignature = new QLabel(FriendLittleBox);
        lblSignature->setObjectName(QStringLiteral("lblSignature"));
        sizePolicy1.setHeightForWidth(lblSignature->sizePolicy().hasHeightForWidth());
        lblSignature->setSizePolicy(sizePolicy1);
        lblSignature->setMinimumSize(QSize(190, 0));
        lblSignature->setFont(font1);
        lblSignature->setStyleSheet(QLatin1String("QLabel{\n"
"	color: gray;\n"
"	background-color: rgba(255, 255, 255, 0);\n"
"}"));
        lblSignature->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout->addWidget(lblSignature);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 5);

        verticalLayout->addLayout(horizontalLayout);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 1);

        horizontalLayout_2->addLayout(verticalLayout);

        horizontalLayout_2->setStretch(0, 5);
        horizontalLayout_2->setStretch(1, 15);

        gridLayout->addLayout(horizontalLayout_2, 1, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(38, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 2, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 38, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 2, 1, 1, 1);

        gridLayout->setRowStretch(0, 1);
        gridLayout->setRowStretch(1, 1000);
        gridLayout->setRowStretch(2, 1);
        gridLayout->setColumnStretch(0, 1);
        gridLayout->setColumnStretch(1, 1000);
        gridLayout->setColumnStretch(2, 1);

        retranslateUi(FriendLittleBox);

        QMetaObject::connectSlotsByName(FriendLittleBox);
    } // setupUi

    void retranslateUi(QWidget *FriendLittleBox)
    {
        FriendLittleBox->setWindowTitle(QApplication::translate("FriendLittleBox", "Form", Q_NULLPTR));
        lblHead->setText(QApplication::translate("FriendLittleBox", "\345\244\264\345\203\217", Q_NULLPTR));
        lblName->setText(QApplication::translate("FriendLittleBox", "\345\220\215\345\255\227", Q_NULLPTR));
        lblOnlineState->setText(QApplication::translate("FriendLittleBox", "[\345\234\250\347\272\277]", Q_NULLPTR));
        lblSignature->setText(QApplication::translate("FriendLittleBox", "\344\270\252\346\200\247\347\255\276\345\220\215", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class FriendLittleBox: public Ui_FriendLittleBox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRIENDLITTLEBOX_H
