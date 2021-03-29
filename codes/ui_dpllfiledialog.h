/********************************************************************************
** Form generated from reading UI file 'dpllfiledialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DPLLFILEDIALOG_H
#define UI_DPLLFILEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>

QT_BEGIN_NAMESPACE

class Ui_DPLLFileDialog
{
public:
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DPLLFileDialog)
    {
        if (DPLLFileDialog->objectName().isEmpty())
            DPLLFileDialog->setObjectName(QString::fromUtf8("DPLLFileDialog"));
        DPLLFileDialog->resize(400, 300);
        buttonBox = new QDialogButtonBox(DPLLFileDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        retranslateUi(DPLLFileDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), DPLLFileDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DPLLFileDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(DPLLFileDialog);
    } // setupUi

    void retranslateUi(QDialog *DPLLFileDialog)
    {
        DPLLFileDialog->setWindowTitle(QApplication::translate("DPLLFileDialog", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DPLLFileDialog: public Ui_DPLLFileDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DPLLFILEDIALOG_H
