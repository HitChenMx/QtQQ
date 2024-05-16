/********************************************************************************
** Form generated from reading UI file 'PersonDataSet.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PERSONDATASET_H
#define UI_PERSONDATASET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PersonDataSet
{
public:
    QWidget *wSetInfo;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_7;
    QLabel *lblHeadPic;
    QSpacerItem *horizontalSpacer_8;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_2;
    QComboBox *cmbSetSex;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_5;
    QSpinBox *spbSetAge;
    QLineEdit *edtSetName;
    QLineEdit *edtSetSignature;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *btnSaveSet;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *btnCancelSet;
    QSpacerItem *horizontalSpacer_6;

    void setupUi(QWidget *PersonDataSet)
    {
        if (PersonDataSet->objectName().isEmpty())
            PersonDataSet->setObjectName(QStringLiteral("PersonDataSet"));
        PersonDataSet->resize(661, 661);
        wSetInfo = new QWidget(PersonDataSet);
        wSetInfo->setObjectName(QStringLiteral("wSetInfo"));
        wSetInfo->setGeometry(QRect(20, 20, 621, 621));
        layoutWidget = new QWidget(wSetInfo);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 20, 581, 571));
        verticalLayout_3 = new QVBoxLayout(layoutWidget);
        verticalLayout_3->setSpacing(30);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_7);

        lblHeadPic = new QLabel(layoutWidget);
        lblHeadPic->setObjectName(QStringLiteral("lblHeadPic"));
        lblHeadPic->setStyleSheet(QLatin1String("QLabel{\n"
"	min-width:  120px; \n"
"    min-height: 120px;\n"
"	max-width: 	120px;\n"
"	max-height:	120px;\n"
"\n"
"    border-radius: 80px;\n"
"    border-width: 20 20 20 20;\n"
"	\n"
"	border-image: url(:/qqicons/qrc/QQicon.svg) 0 0 0 0;\n"
"	\n"
"	background-color: rgb(255, 255, 255);\n"
"}"));

        horizontalLayout_4->addWidget(lblHeadPic);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_8);


        verticalLayout_3->addLayout(horizontalLayout_4);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setHorizontalSpacing(20);
        gridLayout->setVerticalSpacing(40);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(20);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        cmbSetSex = new QComboBox(layoutWidget);
        cmbSetSex->setObjectName(QStringLiteral("cmbSetSex"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(cmbSetSex->sizePolicy().hasHeightForWidth());
        cmbSetSex->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(12);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        cmbSetSex->setFont(font);
        cmbSetSex->setStyleSheet(QString::fromUtf8("QComboBox{\n"
"	border-radius: 10px;\n"
"	padding-left: 10px;/*\345\267\246\344\276\247\350\276\271\350\267\235*/\n"
"	font: 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}\n"
"\n"
"QComboBox::drop-down{\n"
"	subcontrol-origin: padding;\n"
"	subcontrol-position: top right;\n"
"	width: 15px;\n"
"	border:none;\n"
"	margin-right: 15px;\n"
"}\n"
"\n"
"QComboBox::down-arrow{\n"
"	image: url(:/qqicons/qrc/119-down-arrow.svg);\n"
"}\n"
""));

        horizontalLayout_2->addWidget(cmbSetSex);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(12);
        label_5->setFont(font1);

        horizontalLayout_2->addWidget(label_5);

        spbSetAge = new QSpinBox(layoutWidget);
        spbSetAge->setObjectName(QStringLiteral("spbSetAge"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(spbSetAge->sizePolicy().hasHeightForWidth());
        spbSetAge->setSizePolicy(sizePolicy1);
        QFont font2;
        font2.setFamily(QStringLiteral("Times New Roman"));
        font2.setPointSize(13);
        spbSetAge->setFont(font2);
        spbSetAge->setStyleSheet(QLatin1String("QSpinBox{\n"
"	border-radius: 10px;\n"
"}\n"
"\n"
"QSpinBox:up-button{\n"
"	image: url(:/qqicons/qrc/icon_up_arrow.svg);\n"
"	margin-right: 5px;\n"
"}\n"
"\n"
"QSpinBox:down-button{\n"
"	image: url(:/qqicons/qrc/icon_down_arrow.svg);\n"
"	margin-right: 5px;\n"
"}\n"
"\n"
"QSpinBox::up-button:pressed {\n"
"	margin-top:3px;\n"
"}\n"
"\n"
"QSpinBox::down-button:pressed {\n"
"	margin-bottom:3px;\n"
"}"));
        spbSetAge->setMaximum(150);

        horizontalLayout_2->addWidget(spbSetAge);

        horizontalLayout_2->setStretch(0, 6);
        horizontalLayout_2->setStretch(1, 2);
        horizontalLayout_2->setStretch(2, 2);
        horizontalLayout_2->setStretch(3, 4);

        gridLayout->addLayout(horizontalLayout_2, 2, 1, 1, 1);

        edtSetName = new QLineEdit(layoutWidget);
        edtSetName->setObjectName(QStringLiteral("edtSetName"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(edtSetName->sizePolicy().hasHeightForWidth());
        edtSetName->setSizePolicy(sizePolicy2);
        edtSetName->setFont(font1);
        edtSetName->setStyleSheet(QLatin1String("QLineEdit{\n"
"	border-radius: 5px;\n"
"}"));
        edtSetName->setClearButtonEnabled(true);

        gridLayout->addWidget(edtSetName, 0, 1, 1, 1);

        edtSetSignature = new QLineEdit(layoutWidget);
        edtSetSignature->setObjectName(QStringLiteral("edtSetSignature"));
        sizePolicy2.setHeightForWidth(edtSetSignature->sizePolicy().hasHeightForWidth());
        edtSetSignature->setSizePolicy(sizePolicy2);
        edtSetSignature->setFont(font1);
        edtSetSignature->setStyleSheet(QLatin1String("QLineEdit{\n"
"	border-radius: 5px;\n"
"}"));
        edtSetSignature->setClearButtonEnabled(true);

        gridLayout->addWidget(edtSetSignature, 1, 1, 1, 1);

        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font3.setPointSize(13);
        label->setFont(font3);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font3);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font3);

        gridLayout->addWidget(label_3, 2, 0, 1, 1);


        verticalLayout_3->addLayout(gridLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);

        btnSaveSet = new QPushButton(layoutWidget);
        btnSaveSet->setObjectName(QStringLiteral("btnSaveSet"));
        sizePolicy.setHeightForWidth(btnSaveSet->sizePolicy().hasHeightForWidth());
        btnSaveSet->setSizePolicy(sizePolicy);
        btnSaveSet->setFont(font1);
        btnSaveSet->setStyleSheet(QLatin1String("QPushButton{\n"
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

        horizontalLayout_3->addWidget(btnSaveSet);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);

        btnCancelSet = new QPushButton(layoutWidget);
        btnCancelSet->setObjectName(QStringLiteral("btnCancelSet"));
        sizePolicy.setHeightForWidth(btnCancelSet->sizePolicy().hasHeightForWidth());
        btnCancelSet->setSizePolicy(sizePolicy);
        btnCancelSet->setFont(font1);
        btnCancelSet->setStyleSheet(QLatin1String("QPushButton{\n"
"	color: rgb(0, 0, 0);\n"
"	border: 1px solid black;	\n"
"	background-color: rgb(241, 241, 241);\n"
"	border-radius: 10px;\n"
"}\n"
"\n"
"QPushButton:hover{	\n"
"	background-color: rgb(224, 224, 224);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"	color: rgb(0, 0, 0);	\n"
"	background-color: rgb(212, 212, 212);\n"
"}"));

        horizontalLayout_3->addWidget(btnCancelSet);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_6);

        horizontalLayout_3->setStretch(0, 2);
        horizontalLayout_3->setStretch(1, 6);
        horizontalLayout_3->setStretch(2, 2);
        horizontalLayout_3->setStretch(3, 6);
        horizontalLayout_3->setStretch(4, 2);

        verticalLayout_3->addLayout(horizontalLayout_3);

        verticalLayout_3->setStretch(0, 20);
        verticalLayout_3->setStretch(1, 80);
        verticalLayout_3->setStretch(2, 10);
        verticalLayout_3->setStretch(3, 18);

        retranslateUi(PersonDataSet);

        QMetaObject::connectSlotsByName(PersonDataSet);
    } // setupUi

    void retranslateUi(QWidget *PersonDataSet)
    {
        PersonDataSet->setWindowTitle(QApplication::translate("PersonDataSet", "\347\274\226\350\276\221\344\270\252\344\272\272\350\265\204\346\226\231", Q_NULLPTR));
        lblHeadPic->setText(QString());
        cmbSetSex->clear();
        cmbSetSex->insertItems(0, QStringList()
         << QApplication::translate("PersonDataSet", "\346\234\252\350\256\276\347\275\256", Q_NULLPTR)
         << QApplication::translate("PersonDataSet", "\347\224\267", Q_NULLPTR)
         << QApplication::translate("PersonDataSet", "\345\245\263", Q_NULLPTR)
         << QApplication::translate("PersonDataSet", "\345\205\266\344\273\226", Q_NULLPTR)
        );
        label_5->setText(QApplication::translate("PersonDataSet", "<html><head/><body><p align=\"center\">\345\271\264\351\276\204</p></body></html>", Q_NULLPTR));
        label->setText(QApplication::translate("PersonDataSet", "<html><head/><body><p align=\"center\">\346\230\265\347\247\260</p></body></html>", Q_NULLPTR));
        label_2->setText(QApplication::translate("PersonDataSet", "<html><head/><body><p align=\"center\">\344\270\252\346\200\247\347\255\276\345\220\215</p></body></html>", Q_NULLPTR));
        label_3->setText(QApplication::translate("PersonDataSet", "<html><head/><body><p align=\"center\">\346\200\247\345\210\253</p></body></html>", Q_NULLPTR));
        btnSaveSet->setText(QApplication::translate("PersonDataSet", "\344\277\235\345\255\230", Q_NULLPTR));
        btnCancelSet->setText(QApplication::translate("PersonDataSet", "\345\217\226\346\266\210", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class PersonDataSet: public Ui_PersonDataSet {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PERSONDATASET_H
