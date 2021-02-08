void conversion(int N){
	InitStack(S);
	while(N){
		Push(S,N%8);
		N/=8;
	}
	while(!StackEmpty(S)){
		Pop(S,e);
		cout<<e;
	}
}