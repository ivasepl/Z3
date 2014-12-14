#include<iostream>

using namespace std;
struct klijent{
       int ai, bi, ci, di;
       char ime[30], prezime[30];
       int dan, mj, god;
       char spol;     
};
struct qu {
       klijent element[10000];
       int front,rear;
};
typedef struct qu red;
 
int AddOne(int n) {
    return((n+1)%10000);
}
bool IsEmptyQ(red *Q){
     if(AddOne(Q->rear)==Q->front) return true;
     else return false;
     
     }
klijent FrontQ(red *Q){
        if(!IsEmptyQ(Q))
             return Q->element[Q->front];
        
                     
}
void EnQueueQ(klijent X, red *Q){
     if(AddOne(AddOne(Q->rear))!=Q->front){
          Q->rear=AddOne(Q->rear);                               
          Q->element[Q->rear]=X;     
     }
     else {
           
           return;
     }
}
void DeQueueQ(red *Q){
     if(!IsEmptyQ(Q))
         Q->front=AddOne(Q->front);
     else {
           
           return;
     }          
}
 
red *InitQ(red *Q){
    Q=new red;
    Q->front=0;
    Q->rear=9999;
    return Q;   
}
