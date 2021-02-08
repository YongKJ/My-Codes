typedef struct{
	char name[20];
	char sex;
}Person;
#define MAXQSIZE 100
typedef struct{
	Person *base;
	int front;
	int rear;
}SqQueue;
SqQueue Mdancers,Fdancers;
void DancePartner(Person dancer[],int num){
	InitQueue(Mdancers);
	InitQueue(Fdancers);
	for(i=0;i<num;i++){
	p=dancer[i];
	if(p.sex=='F')
		EnQueue(Fdancers,p);
	else
		EnQueue(Mdancers,p);
	}
	cout<<"The dancing partners are:\n";
	while(!QueueEmpty(Fdancers)&&!QueueEmpty(Mdancers)){
	DeQueue(Fdancers,p);
	cout<<p.name<<" ";
	DeQueue(Mdancers,p);
	cout<<p.name<<endl;
	}
	if(!QueueEmpty(Fdancers)){
		p=GetHead(Fdancers);
		cout<<"The first woman to get a partner is£º"<<p.name<<endl;
	}
	else if(!QueueEmpty(Mdancers)){
		p=GetHead(Mdancers);
		cout<<"The first man to get a partner is:"<<p.name<<endl;
	}
}
