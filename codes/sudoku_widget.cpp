#include "sudoku_widget.h"
#include "ui_sudoku_widget.h"


Sudoku_Widget::Sudoku_Widget(QWidget *parent) : ClauseInSudo0(":/Images/files/sudu_rule.cnf",this),
    QWidget(parent),
    ui(new Ui::Sudoku_Widget)
{
    ui->setupUi(this);
    //把数独约束弄进来    
//    qDebug()<<ClauseInSudo.result.count()<<endl;
    Clause ClauseInSudo(ClauseInSudo0,this);
    //背景图
    QPixmap pixmap = QPixmap(":/Images/files/4.jpg").scaled(this->size());
    QPalette palette(this->palette());
    palette.setBrush(QPalette::Background, QBrush(pixmap));
    this->setPalette(palette);
    pbtns = this->findChildren<QPushButton *>();
    qDebug()<<pbtns.count();
//    int j = 0;

//    //被迫手动调整按钮顺序，具体并不知道为何
//    for(j=0;j<8;j++){
//        pbtns.swap(j,j+48);
//    }
//    for(j=8;j<16;j++){
//        pbtns.swap(j,j+40);
//    }
//    for(j=16;j<24;j++){
//        pbtns.swap(j,j+40);
//    }
//    for(j=24;j<32;j++){
//        pbtns.swap(j,j+16);
//    }
//    for(j=32;j<40;j++){
//        pbtns.swap(j,j+24);
//    }
//    for(j=48;j<56;j++){
//        pbtns.swap(j,j+8);
//    }

    //测试
//    int i =1;
    foreach(QPushButton *btn, pbtns)  //循环List中所有的按钮
    {
//        QString str = QString::number(i++,10);
//        btn->setText(str);
        btn->setStyleSheet(
                    "QPushButton{font-family:'宋体';font-size:24px;color:rgb(5,27,77,255);font-weight: bold}}"
                                        );
        //设按钮透明
        btn->setFlat(true);
        btn->setAutoFillBackground(true);
        QPalette palette = btn->palette();
        palette.setColor(QPalette::Button,QColor(255,255,255,100));
        btn->setPalette(palette);

        //这么写成不成我也不知道
        connect(btn,&QPushButton::clicked,this,[=](){   //每一个按钮连接槽函数
            sudoku_dialog *a;
            a = new sudoku_dialog;
            a->show();
            //为啥不能置顶 略烦
            //a->setWindowFlags(this->windowFlags()|Qt::WindowStaysOnTopHint);

            connect(a->btn1,&QPushButton::clicked,this,[=](){
                btn->setText("0");
                a->close();

            });
            connect(a->btn2,&QPushButton::clicked,this,[=](){
                btn->setText("1");
                a->close();

            });
        });
    }
    //调一下Label
    ui->label->setStyleSheet(
                "QLabel{font-family:'宋体';font-size:24px;color:rgb(255,255,255,255);font-weight: bold}}"
                                    );
    ui->label_2->setStyleSheet(
                "QLabel{font-family:'宋体';font-size:24px;color:rgb(255,255,255,255);font-weight: bold}}"
                                    );
//    QPixmap *pixmap1 = new QPixmap(":/Images/files/success.png");
//    pixmap1->scaled(ui->label->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
//    ui->label_3->setScaledContents(true);
//    ui->label_3->setPixmap(*pixmap1);

    //生成棋盘
    QPushButton *btn1 = pbtns[64];
    btn1->setText("Begin");
    btn1->disconnect();
    qDebug()<<ClauseInSudo.result.count()<<endl;

    connect(btn1,&QPushButton::clicked,this,[&](){
        Clause ClauseInSudo(ClauseInSudo0,this);
//        qDebug()<<ClauseInSudo.result.count()<<endl;
        int holes = this->ui->lineEdit->text().toInt();

        qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
        int cnt = 0;
        int flag = 1;
        while(flag){
            if(cnt != 0 ){
                ClauseInSudo.clause.remove(6537,8);
            }
            for(int i = 0; i < 8;i++ ){
                int temp = qrand()%64;      //0-63
                int seq = temp+1;           //1-64
                if(ListForRandom.count(seq)){      //查重
                    i--;
                    continue;
                }
                ListForRandom.append(seq);       //随机的序号
                int res = qrand()%2;
//                qDebug()<<seq<<endl;
//                qDebug()<<ClauseInSudo.result.count()<<endl;

                ClauseInSudo.result[seq] = res;       //直接越界，就不知道为啥穿不过
    //            QString str = QString::number(res,10);
    //            pbtns[temp]->setText(str);
                if(res>0){          //怀疑是函数问题结果不是
                    QVector<int> tmp;
                    tmp.push_back(seq);
                    ClauseInSudo.clause.push_back(tmp);
                    ClauseInSudo.UpdateLineNum();
                }
                else{
                    QVector<int> tmp;
                    tmp.push_back(-seq);
                    ClauseInSudo.clause.push_back(tmp);
                    ClauseInSudo.UpdateLineNum();
                }
                cnt++;
//                qDebug()<<ClauseInSudo.clause[ClauseInSudo.clause.count()-1][0]<<endl;
            }
            Clause SpiltClause(ClauseInSudo);
            if(SpiltClause.DPLL(1)){
                flag = 0;
                ClauseInSudo.result=SpiltClause.result;
                answer = SpiltClause.result;
            }
        };
        for(int i = 0;i<64;i++){
            QString str = QString::number(ClauseInSudo.result[i+1],10);
            pbtns[i]->setText(str);
        }
        for(int j = 0;j<holes;j++){          //挖洞
            int temp = qrand()%64;      //0-63
            if(NumofHoles.count(temp)){
                j--;
                continue;
            }
            if(ListForRandom.count(temp+1)){      //跟上面重复还得单独删下单子句  有点麻烦不想搞
                j--;
                continue;
            }
            NumofHoles.append(temp);
            pbtns[temp]->setText("");
            pbtns[temp]->disconnect();
        }
    });

    //DPLL验证
    pbtns[65]->setText("Verify");
    pbtns[65]->disconnect();
    connect(pbtns[65],&QPushButton::clicked,this,[&](){
        Clause ClauseInSudo(ClauseInSudo0,this);
        for(int i = 0; i<63;i++){
            if(ListForRandom.count(i+1))
                continue;
            pbtns[i]->text().toInt()>0?ClauseInSudo.AddSingelClause(i+1):ClauseInSudo.AddSingelClause(-(i+1));
//            qDebug()<<pbtns[NumofHoles[i]]->text().toInt();
//            qDebug()<<ClauseInSudo.clause.count()<<endl;
//            qDebug()<<ClauseInSudo.clause[6544+i][0]<<endl;
        }
        Clause SpiltClause(ClauseInSudo);
//        qDebug()<<SpiltClause.clause.count()<<endl;
        if(SpiltClause.DPLL(1)){
            QPixmap *pixmap = new QPixmap(":/Images/files/success.png");
            pixmap->scaled(ui->label->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
            ui->label_3->setScaledContents(true);
            ui->label_3->setPixmap(*pixmap);
        }
        else{
            QPixmap *pixmap = new QPixmap(":/Images/files/fail.png");
            pixmap->scaled(ui->label->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
            ui->label_3->setScaledContents(true);
            ui->label_3->setPixmap(*pixmap);

        }
    });

    pbtns[66]->setText("Answer");
    pbtns[66]->disconnect();
    connect(pbtns[66],&QPushButton::clicked,this,[&](){
        for(int i = 0; i<NumofHoles.count();i++){
            QString str = QString::number(answer[NumofHoles[i]+1],10);
            pbtns[NumofHoles[i]]->setText(str);
        }
    });
    pbtns[67]->setText("Cancel");
    pbtns[67]->disconnect();
    connect(pbtns[67],&QPushButton::clicked,this,[&](){
        ui->lineEdit->clear();
    });
//    pbtns[0]->setText("1");
//    qDebug()<<pbtns.count();

}
//残留问题：数组越界与label不显示
//怀疑：越界不清楚  label可能跟设透明有关
//结果：label没问题了，用pixmap就行，越界就是类穿不过，小编也想为啥知道

Sudoku_Widget::~Sudoku_Widget()
{
    delete ui;
}
