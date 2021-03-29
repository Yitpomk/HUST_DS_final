#include "sudoku_dialog.h"
#include "ui_sudoku_dialog.h"

sudoku_dialog::sudoku_dialog(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::sudoku_dialog)
{
    ui->setupUi(this);
    this->btn1 = ui->pushButton;
    this->btn2 = ui->pushButton_2;
    this->setWindowFlags(this->windowFlags()|Qt::WindowStaysOnTopHint);
}

sudoku_dialog::~sudoku_dialog()
{
    delete ui;
}
