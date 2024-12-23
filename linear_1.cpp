#include<iostream>
using namespace std;
#define N 100

typedef int datatype;
typedef struct slNode{
    datatype data[N];
    int len;
    slNode():len(0){}
}seqList; 

void sl_insert(seqList &sl,int p,datatype x){
    if(sl.len>=N){
        cout<<"表满，插入失败！"<<endl;
        return;
    }
    if(p>=sl.len){
        sl.data[sl.len]=x;
    }
    else{
        if(p<0)p=0;
        for(int i=sl.len;i>=p;i--){
            sl.data[i]=sl.data[i-1];
        }
        sl.data[p]=x;
    }
    sl.len++;
}

void sl_mergeList(const seqList &sl1,const seqList &sl2,seqList &mergeList){
    int i=0,j=0;
    while(i<sl1.len&&j<sl2.len){
        if(sl1.data[i]<=sl2.data[j]){
            sl_insert(mergeList,mergeList.len,sl1.data[i++]);
        }
        else if(sl1.data[i]>sl2.data[j]){
            sl_insert(mergeList,mergeList.len,sl2.data[j++]);
        }
    }
    while(i<sl1.len)
        sl_insert(mergeList,mergeList.len,sl1.data[i++]);
    while(j<sl2.len)
        sl_insert(mergeList,mergeList.len,sl2.data[j++]);
}

int main(){
    seqList sl1;
    seqList sl2;
    seqList merged_list;
    sl_insert(sl1,0,1);
    sl_insert(sl1,1,4);
    sl_insert(sl1,2,10);
    sl_insert(sl1,3,23);
    sl_insert(sl2,1,5);
    sl_insert(sl2,2,10);
    sl_insert(sl2,3,14);
    sl_insert(sl2,4,29);
    cout<<"合并前：\nseq1：";
    for(int i=0;i<sl1.len;i++)
    {
        cout<<sl1.data[i]<<" ";
    }
    cout<<"\nseq2：";
    for(int i=0;i<sl2.len;i++)
    {
        cout<<sl2.data[i]<<" ";
    }
    sl_mergeList(sl1,sl2,merged_list);
    cout<<"\n合并后：\nmerged_list：";
    for(int i=0;i<merged_list.len;i++)
    {
        cout<<merged_list.data[i]<<" ";
    }
}