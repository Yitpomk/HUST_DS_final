#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Clause.h"
#include "dpll_widget.h"
#include"sudoku_widget.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //背景图
    QPixmap pixmap = QPixmap(":/Images/files/5.jpg").scaled(this->size());
    QPalette palette(this->palette());
    palette.setBrush(QPalette::Background, QBrush(pixmap));
    this->setPalette(palette);
    //按钮透明
    ui->pushButton->setFlat(true);
    ui->pushButton_2->setFlat(true);
    //按钮文本字体字号变大加粗
    ui->pushButton->setStyleSheet(
                "QPushButton{font-family:'宋体';font-size:24px;color:rgb(255,255,255,255);font-weight: bold}}"
                                    );
    ui->pushButton_2->setStyleSheet(
                "QPushButton{font-family:'宋体';font-size:24px;color:rgb(255,255,255,255);font-weight: bold}}"
                                    );
    //提示文本字体字号等
    ui->label->setStyleSheet(
                "QLabel{font-family:'宋体';font-size:24px;color:rgb(255,255,255,255);font-weight: bold}}"
                                    );
    //以上会有一串提示但是不懂也懒得管了0.0
    connect(ui->pushButton,&QPushButton::clicked,this,[=](){        //值传递跟引用传递应该差不多的吧
        DPLL_Widget *dp;
        dp = new DPLL_Widget;
        dp->show();      //闪烁咋办呢  得修改成指针new一下，因为这样才创建在heap上(不太懂)，如果只是声明变量就创建在stack上生命期是个大括号内
    });
    connect(ui->pushButton_2,&QPushButton::clicked,this,[=](){
        Sudoku_Widget *sudo;
        sudo = new Sudoku_Widget;
        sudo->show();
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

