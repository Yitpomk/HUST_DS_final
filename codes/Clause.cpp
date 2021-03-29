#include"Clause.h"
Clause::Clause(QString filepath , QWidget *parent) : QWidget(parent)
{
    QString path = filepath;
    QFile file(path);
    QTextStream instream( &file );
    if(!file.open(QIODevice::ReadOnly)){
        qDebug()<<"Failed  to open "<<path<<endl;
    }
    else{
        qDebug()<<"succeed to open file"<<endl;
    }

    char ch1;
    instream>>ch1;
    while(ch1!='p'){        //找个开头
        instream >> ch1;
    }
    QString str1;
    instream >> str1;
    if(QString::compare(str1,"cnf")!=0)
        qDebug()<<"Not cnf! Choose another file"<<endl;
    instream >> this->variable_num;
//  qDebug() << this->variable_num;
    instream >> this->line_num;
//    qDebug() << this->line_num<<endl;
//    qDebug() << "  " <<endl;

    //初始化一下变量vector
    for(int j = 0; j < this->variable_num +1; j++){
        this->variables.push_back(0);        //变量编号从1开始
    }

    while(!instream.atEnd()){

        QVector<int> vec;       //嵌套vector
        int var;
        instream >> var;
//        qDebug() << var <<" ";
        while(var!=0){
            vec.push_back(var);
            this->variables[abs(var)]++;     //初始统计
            instream >> var;
//            qDebug() << var << " ";
        }
        this->clause.push_back(vec);
        qDebug()<<vec;
    }
//    qDebug()<<clause.count()<<endl;
//    qDebug()<<clause[0].count()<<endl;
//    qDebug()<<clause[clause.count()-1].count()<<endl;
//    qDebug() << "  " <<endl;
    for(int j = 0; j < this->variable_num +1; j++){
        this->result.push_back(0);        //标记为-1的变量则真假都可  变量编号从1开始
    }
    qDebug()<<result.count()<<endl;
}
Clause::Clause(const Clause &A , QWidget *parent) : QWidget(parent)
{        //拷贝
    this->line_num = A.line_num;
    this->variable_num = A.variable_num;
    for(int i = 0 ;i<A.clause.count();i++){
        this->clause.push_back(QVector<int>(A.clause[i]));      //不知道能不能这么调用构造函数
    }
    for(int j = 0; j < this->variable_num +1; j++){
        this->result.push_back(A.result[j]);       //复制一份
        this->variables.push_back(A.variables[j]);
    }
}
int Clause::FindSingleClause(){
    int size = this->clause.count();
    for(int i = 0;i<size;i++){
        if(this->clause[i].count()==1)
            return i;
    }
    return -1;
}
status Clause::FindEmptyClause(){      //只要有空子句就结束了，所以返回布尔即可
    int size = this->clause.count();
    for(int i = 0;i<size;i++){
        if(this->clause[i].count()==0)
            return TRUE;
    }
    return FALSE;
}
void Clause::DeleteNode(int data){      //跑出死循环，大概是没删成功  结果并不是，是传错参数了，传变量传成了子句序号
    int size = this->clause.count();
    for(int i = 0;i<size;i++){
//        if(this->clause[i].count(data)&&this->clause[i].count(-data))
//            return TRUE;
        if(this->clause[i].count(data)){
            //这里要处理一下variable的数目
            for(int j = 0;j<this->clause[i].count();j++){
                this->variables[abs(this->clause[i][j])]--;
            }
            this->clause.remove(i);
            size--;                     //忘了--结果数组越界了
            i--;                        //这个又忘了，难怪总不对
        }
        else if(this->clause[i].count(-data)){
            //这里也是
            while(this->clause[i].count(-data)){
                this->variables[abs(data)]--;
                this->clause[i].remove(this->clause[i].indexOf(-data));     //有多个也得删  改进
            }
        }
        else{
            continue;
        }
    }
    this->UpdateLineNum();
}
void Clause::AddSingelClause(int var){
    QVector<int> tmp;
    tmp.push_back(var);
    this->clause.push_back(tmp);
    this->UpdateLineNum();
    //这里也要处理数目
}
void Clause::UpdateLineNum(){
    this->line_num = this->clause.count();      //尽量还是用count保险，但更新也无妨
}
/*
Clause::~Clause(){
    //似乎也没什么好析构的
    for(int i = 0;i<this->clause.count();i++){
        this->clause[i].~QVector();
    }
    this->clause.~QVector();
    this->line_num = 0;
    this->variable_num = 0;
}
*/
