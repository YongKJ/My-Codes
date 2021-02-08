#include <iostream>
using namespace std;
const int OK=1,ERROR=0,OVERFLOW=-2,MAXSIZE=100;
typedef int Status,QElemType,SElemType;
typedef struct{
	QElemType *base;
	int front;
	int rear;
}SqQueue;
Status InitQueue(SqQueue &Q){
	Q.base=new QElemType[MAXSIZE];
	if(!Q.base)exit(OVERFLOW);
	Q.front=Q.rear=0;
	return OK;
}
Status QueueLength(SqQueue Q){
	return (Q.rear-Q.front+MAXSIZE)%MAXSIZE;
}
Status EnQueue(SqQueue &Q,QElemType e){
	if((Q.rear+1)%MAXSIZE==Q.front)return ERROR;
	Q.base[Q.rear]=e;
	Q.rear=(Q.rear+1)%MAXSIZE;
	return OK;
}
Status DeQueue(SqQueue &Q,QElemType &e){
	if(Q.front==Q.rear)return ERROR;
	e=Q.base[Q.front];
	Q.front=(Q.front+1)%MAXSIZE;
	return OK;
}
SElemType GetHead(SqQueue Q){
	SElemType T=0;
	if(Q.front!=Q.rear)
		T=Q.base[Q.front];
	return T;
}
int main(){
	return 0;
}
