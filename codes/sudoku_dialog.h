#ifndef SUDOKU_DIALOG_H
#define SUDOKU_DIALOG_H

#include <QWidget>
#include "Clause.h"
namespace Ui {
class sudoku_dialog;
}

class sudoku_dialog : public QWidget
{
    Q_OBJECT

public:
    QPushButton *btn1;
    QPushButton *btn2;
    explicit sudoku_dialog(QWidget *parent = nullptr);
    ~sudoku_dialog();

private:
    Ui::sudoku_dialog *ui;
};

#endif // SUDOKU_DIALOG_H
