Status Mathching(){
	InitStack(S);
	flag=1;
	cin>>ch;
	while(ch!='#'&&flag){
		switch(ch){
			case '[':
			case '(':
				Push(S,ch);
				break;
			case ')':
			if(!StackEmpty(S)&&GetTop(S)=='(')
				Pop(S,x);
			else flag=0;
			break;
			case ']':
			if(!StackEmpty(S)&&GetTop(S)=='[')
				Pop(S,x);
			else flag=0;
			break;
		}
		cin>>ch;
	}
	if(StackEmpty(S)&&flag) return true;
	else return false;
}