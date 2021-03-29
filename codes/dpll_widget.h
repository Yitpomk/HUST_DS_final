#ifndef DPLL_WIDGET_H
#define DPLL_WIDGET_H

#include <QWidget>

namespace Ui {
class DPLL_Widget;
}

class DPLL_Widget : public QWidget
{
    Q_OBJECT

public:
    explicit DPLL_Widget(QWidget *parent = nullptr);
    ~DPLL_Widget();

private:
    Ui::DPLL_Widget *ui;
};

#endif // DPLL_WIDGET_H
