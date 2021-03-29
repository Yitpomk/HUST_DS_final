#include"Clause.h"
status Clause::DPLL(int optimize){      //被迫改成类函数了，希望没事
    //单字句
    int single = this->FindSingleClause();
    while(single>=0){
//        qDebug()<<single<<endl;
//        qDebug()<<clause.count()<<endl;
//        qDebug()<<result.count()<<endl;
//        qDebug()<<clause[single][0]<<endl;

        this->clause[single][0]>0?this->result[abs(this->clause[single][0])] = TRUE : this->result[abs(this->clause[single][0])] = FALSE;
        //result最后一位是19，变量的数会达到20  考虑考虑
//        qDebug()<<"sced"<<endl;
        int data = clause[single][0];
//        qDebug()<<data<<endl;
        this->DeleteNode(data);
//        qDebug()<<clause.count()<<endl;//很离谱  数独的时候出问题  可能是DPLL两次就删删减减的出问题了  暂时想不出好的解决方案
        if(!this->clause.count())
            return TRUE;
        else if(this->FindEmptyClause())
            return FALSE;
        single = this->FindSingleClause();
    }
    //分裂  分裂选取先随机，弄成功后再考虑选取出现次数最多的变量
    //好家伙  网上的优化方法居然也就是选最多的  就没有高级一点的QAQ
    int x;
    if(optimize){
        auto max = max_element(begin(this->variables), end(this->variables));
        x = this->variables.indexOf(*max);
//        qDebug()<<*max<<" "<<x<<endl;

    }
    else{
        x = this->clause.front().front();
    }

    //为什么会出现重复选了同一个变量的情况？？  破案了  分裂策略导致好像

//    qDebug()<<x<<endl;
    Clause SplitClause(*this);
    this->AddSingelClause(x);
    if(this->DPLL(optimize)){
        return TRUE;
    }
    else{
        SplitClause.AddSingelClause(-x);
        if(SplitClause.DPLL(optimize)){
            this->result = SplitClause.result;
            return TRUE;
        }
        else{
            return FALSE;
        }
    }
}
