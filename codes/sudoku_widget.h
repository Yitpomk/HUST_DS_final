#ifndef SUDOKU_WIDGET_H
#define SUDOKU_WIDGET_H

#include <QWidget>
#include "Clause.h"
#include "sudoku_dialog.h"

namespace Ui {
class Sudoku_Widget;
}

class Sudoku_Widget : public QWidget
{
    Q_OBJECT

public:
    Clause ClauseInSudo0;
    QList<QPushButton *>  pbtns;
    QList<int> NumofHoles;
    QList<int> ListForRandom;
    QVector<int> answer;
    explicit Sudoku_Widget(QWidget *parent = nullptr);
    void SatToCnf();        //输出成cnf文件并调DPLL
    void RandomAdd();
    ~Sudoku_Widget();
private:
    Ui::Sudoku_Widget *ui;
};

#endif // SUDOKU_WIDGET_H
