#ifndef DPLLFILEDIALOG_H
#define DPLLFILEDIALOG_H

#include <QDialog>
#include <QAction>
namespace Ui {
class DPLLFileDialog;
}

class DPLLFileDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DPLLFileDialog(QWidget *parent = nullptr);
    ~DPLLFileDialog();

private:
    Ui::DPLLFileDialog *ui;
};

#endif // DPLLFILEDIALOG_H
