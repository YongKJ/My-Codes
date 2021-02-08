typedef struct queuenode{
	Datatype data;
	struct queuenode *next;
}QueueNode;
typedef struct{
	queuenode *rear;
}LinkQueue;
void InitQueue(LinkQueue *Q){
	QueueNode *s;
	Q->rear=Q->rear->next;
	while(Q->rear!=Q->rear->next){
		s=Q->rear->next;
		Q->rear->next=s->next;
		delete s;
	}
}
int EmptyQueue(LinkQueue *Q){
	return Q->rear->next->next==Q->rear->next;
}
void EnQueue(LinkQueue *Q,Datatype x){
	QueueNode *p=new QueueNode;
	p->data=x;
	p->next=Q->rear->next;
	Q->rear->next=p;
	Q->rear=p;
}
Datatype DeQueue(LinkQueue *Q){
	Datatype t;
	QueueNode *p;
	if(EmptyQueue(Q))
		Error("Queue underflow");
	p=Q->rear->next->next;
	x=p->data;
	if(p==Q->rear){
		Q->rear=Q->rear->next;
		Q->rear->next=p->next;
 } 
	else
		Q->rear->next->next=p->next;
	delete p;
	return x;
}
	