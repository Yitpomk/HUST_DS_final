#include "dpll_widget.h"
#include "ui_dpll_widget.h"
#include "Clause.h"

DPLL_Widget::DPLL_Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DPLL_Widget)
{
    ui->setupUi(this);
    //懒得做好看了(主要是不会)  数独再考虑一下

    //打开文件按钮
    connect(ui->pushButton_3,&QPushButton::clicked,this,[=](){
        QString filename = QFileDialog::getOpenFileName(NULL,"cnf文件","C:\\Users\\lenovo\\Desktop\\DS_CourseDesign\\Qt\\DPLL-SAT\\测试集\\助教课设演示检查要求","*.cnf");
        ui->lineEdit->setText(filename);
    });
    //OK按钮dpll
    connect(ui->pushButton,&QPushButton::clicked,this,[=](){
        QTime qtime;
        qtime.start();
        if(!ui->lineEdit->text().endsWith(".cnf")){
            QMessageBox::critical(this,"error","错误文件");
            ui->lineEdit->clear();
        }
        else{
            Clause A(ui->lineEdit->text(),this);
            //DPLL崩了 数组越界似乎   已修复
            //这里检查是否优化
            int optim = 0;      //默认没优化
            if(ui->radioButton->isChecked()){
                optim = 1;
            }
            //结果文件
            QFile outfile("C:\\Users\\lenovo\\Desktop\\DS_CourseDesign\\Qt\\DPLL-SAT\\测试集\\助教课设演示检查要求\\result.res");
            if(!outfile.open(QIODevice::WriteOnly|QIODevice::Truncate))
                qDebug() << "Failed to open temp.txt"<<endl;
            QTextStream outstream(&outfile);
            //结果
            if(A.DPLL(optim)){
                ui->textBrowser->setText("succeed!");
                outstream << "s 1" << endl;
                outstream << "v";
                for(int i = 1;i <= A.variable_num;i++){
                    QString str;
                    if(A.result[i]){
                        str = "TRUE";
                        outstream << " " << i;
                    }
                    else{
                        str = "FALSE";
                        outstream << " " << -i;
                    }
                    QString text = "The Variable ";
                    QString num = QString::number(i,10);
                    text+=num;
                    text.append(" is ");
                    text.append(str);
                    ui->textBrowser->append(text);

                }
                //文件输出
                outstream <<" "<<endl;

            }
            else{
                ui->textBrowser->setText("unsatisfiled!");
                outstream << "s 0" << endl;
            }
            QString str0 = "Time: ";
            QString time = QString::number(qtime.elapsed(),10);
            str0 += time;
            str0 += "ms";
            outstream << "t "<<time;
            ui->textBrowser->append(str0);
        }
    });
    //cancel就清空吧
    connect(ui->pushButton_2,&QPushButton::clicked,this,[=](){
        ui->lineEdit->clear();
    });
}

DPLL_Widget::~DPLL_Widget()
{
    delete ui;
}
