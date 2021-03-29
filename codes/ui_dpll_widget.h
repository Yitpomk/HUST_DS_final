/********************************************************************************
** Form generated from reading UI file 'dpll_widget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DPLL_WIDGET_H
#define UI_DPLL_WIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DPLL_Widget
{
public:
    QGridLayout *gridLayout;
    QTextBrowser *textBrowser;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer;
    QRadioButton *radioButton;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *pushButton_3;

    void setupUi(QWidget *DPLL_Widget)
    {
        if (DPLL_Widget->objectName().isEmpty())
            DPLL_Widget->setObjectName(QString::fromUtf8("DPLL_Widget"));
        DPLL_Widget->resize(551, 335);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Images/files/01.png"), QSize(), QIcon::Normal, QIcon::Off);
        DPLL_Widget->setWindowIcon(icon);
        gridLayout = new QGridLayout(DPLL_Widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        textBrowser = new QTextBrowser(DPLL_Widget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));

        gridLayout->addWidget(textBrowser, 2, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButton = new QPushButton(DPLL_Widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        radioButton = new QRadioButton(DPLL_Widget);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setMaximumSize(QSize(200, 16777215));

        horizontalLayout->addWidget(radioButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        pushButton_2 = new QPushButton(DPLL_Widget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);


        gridLayout->addLayout(horizontalLayout, 3, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(DPLL_Widget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        lineEdit = new QLineEdit(DPLL_Widget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout_2->addWidget(lineEdit);

        pushButton_3 = new QPushButton(DPLL_Widget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setMinimumSize(QSize(45, 28));
        pushButton_3->setMaximumSize(QSize(45, 28));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Images/files/Directory.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_3->setIcon(icon1);

        horizontalLayout_2->addWidget(pushButton_3);


        gridLayout->addLayout(horizontalLayout_2, 1, 0, 1, 1);


        retranslateUi(DPLL_Widget);

        QMetaObject::connectSlotsByName(DPLL_Widget);
    } // setupUi

    void retranslateUi(QWidget *DPLL_Widget)
    {
        DPLL_Widget->setWindowTitle(QApplication::translate("DPLL_Widget", "DPLL", nullptr));
        pushButton->setText(QApplication::translate("DPLL_Widget", "OK", nullptr));
        radioButton->setText(QApplication::translate("DPLL_Widget", "Optimize", nullptr));
        pushButton_2->setText(QApplication::translate("DPLL_Widget", "Cancel", nullptr));
        label->setText(QApplication::translate("DPLL_Widget", "Path:", nullptr));
        pushButton_3->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class DPLL_Widget: public Ui_DPLL_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DPLL_WIDGET_H
