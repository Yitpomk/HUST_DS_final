#include "dpllfiledialog.h"
#include "ui_dpllfiledialog.h"

DPLLFileDialog::DPLLFileDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DPLLFileDialog)
{
    ui->setupUi(this);
}

DPLLFileDialog::~DPLLFileDialog()
{
    delete ui;
}
