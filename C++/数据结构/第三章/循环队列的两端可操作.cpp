#define M 7
typedef struct{
	elemtp data[M];
	int front,rear;
}cycqueue;
elemtp delqueue(cycqueue Q){
	if(Q.front==Q.rear){
		cout<<"¶ÓÁÐ¿Õ"<<endl;
		exit(0);
	}
	Q.rear=(Q.rear-1+M)%M;
	return Q.data[(Q.rear+1+M)%M];
}
void enqueue(cycqueue Q,elemtp x){
	if(Q.rear==(Q.front-1+M)%M){
		cout<<"¶ÓÂú"<<endl;
		exit(0);
	}
	Q.data[Q.front]=x;
	Q.front=(Q.front-1+M)%M;
}