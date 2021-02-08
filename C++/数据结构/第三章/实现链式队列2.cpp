#include <iostream>
using namespace std;
const int OK=1,ERROR=0,OVERFLOW=-2;
typedef int Status,QElemType,SElemType;
typedef struct QNode{
	QElemType data;
	struct QNode *next;
}QNode,*QueuePtr;
typedef struct{
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;
Status InitQueue(LinkQueue &Q){
	Q.front=Q.rear=new QNode;
	Q.front->next=NULL;
	return OK;
}
Status EnQueue(LinkQueue &Q,QElemType e){
	QueuePtr p=new QNode;
	p->data=e;
	p->next=NULL;
	Q.rear->next=p;
	Q.rear=p;
	return OK;
}
Status DeQueue(LinkQueue &Q,QElemType &e){
	if(Q.front==Q.rear)return ERROR;
	QueuePtr p=Q.front->next;
	e=p->data;
	Q.front->next=p->next;
	if(Q.rear==p)Q.rear=Q.front;
	delete p;
	return OK;
}
SElemType GetHead(LinkQueue Q){
	SElemType e;
	if(Q.front!=Q.rear)
		e=Q.front->next->data;
	return e;
}
int main(){
	return 0;
}