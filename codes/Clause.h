#ifndef CLAUSE_H
#define CLAUSE_H

#include<iostream>
#include<QFile>
#include<QList>
#include<QString>
#include<QTextStream>
#include<QtDebug>
#include<QPainter>
#include<QPaintEvent>
#include<QPixmap>
#include<QPalette>
#include<QBrush>
#include<QLabel>
#include<QCursor>
#include<QMouseEvent>
#include<QWidget>
#include<QAction>
#include<QFileDialog>
#include<QErrorMessage>
#include<QMessageBox>
#include<QTimer>
#include<QTime>
#include<QRadioButton>
#include<QButtonGroup>
#include<QtGlobal>

#define TRUE 1
#define FALSE 0
#define ROW 8
#define COL 8

typedef int status ;

using namespace std;

class Clause : public QWidget
{
public:
    QVector<QVector<int>>clause;
    int line_num;
    int variable_num;
    QVector<int>result;     //变量结果真假值，0为假，1为真
    QVector<int>variables;  //存变量数优化算法

    Clause(QString filepath , QWidget *parent = nullptr);
    Clause(const Clause &A , QWidget *parent = nullptr);
    int FindSingleClause();
    status FindEmptyClause();
    void DeleteNode(int data);
    void AddSingelClause(int var);
    void UpdateLineNum();
    status DPLL(int optimize);
    //~Clause();        //不知道需不需要
};

#endif // CLAUSE_H
