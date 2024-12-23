#include<iostream>
using namespace std;

// 单链表
typedef int datatype;
typedef struct clNode{
    datatype data;
    clNode *next;
    clNode():next(NULL){}
}*chainList;

// 插入操作
void cl_insert(chainList p,datatype x){
    chainList q=new clNode;
    if(q==NULL){
        cout<<"插入结点失败！"<<endl;
        return;
    }
    q->data=x;
    q->next=p->next;
    p->next=q;
}

