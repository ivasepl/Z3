#include<iostream>
using namespace std;
struct klijent{
       int ai, bi, ci, di;
       char ime[30], prezime[30];
       int dan, mj, god;
       char spol;     
};
struct qu {
       klijent element;
       qu *sljedeci;
};
struct que {
       qu *front, *rear;       
};
typedef struct que red;
 
klijent FrontQ(red *Q){
        if ( Q->front != Q->rear) 
             return( Q->front->sljedeci->element);
                            
};
void EnQueueQ(klijent x,red *Q){
     qu *novi = new qu;
     novi->element = x;
     novi->sljedeci = NULL;
     Q->rear->sljedeci = novi;
     Q->rear = novi;
};
 
bool IsEmptyQ(red *Q){
     if(Q->front == Q->rear) return true;
     else return false;
     }
void DeQueueQ(red *Q){
     if(IsEmptyQ(Q)){
              return;
              }
     qu *pom = Q->front;
     Q->front = (Q->front)->sljedeci;
     delete pom;
}
red *InitQ(red *Q){
    Q=new red;
    qu *novi=new qu;
    novi->sljedeci=NULL;
    Q->front=novi;
    Q->rear=novi;
    return Q;   
}
