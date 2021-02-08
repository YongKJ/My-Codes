SeQueue QueueInit(SeQueue Q){
	Q.front=Q.rear=0;
	Q.tag=0;
	return Q;
}
SeQueue QueueIn(SeQueue Q,int e){
	if(Q.tag==1&&Q.rear==Q.front)
		cout<<"队列已满"<<endl;
	else{
		Q.rear=(Q.rear+1)%m;
		Q.data[Q.rear]=e;
		if(Q.tag==0)
			Q.tag=1;
	}
	return Q;
}
ElemType QueueOut(SeQueue Q){
	if(Q.tag==0){
		cout<<"队列为空"<<endl;
		exit(0);
	}
	else{
		Q.front=(Q.front+1)%m;
		e=Q.data[Q.front];
		if(Q.front==Q.rear)
			Q.tag=0;
	}
	return e;
} 