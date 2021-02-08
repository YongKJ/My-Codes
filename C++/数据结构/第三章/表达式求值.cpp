char EvaluateExpression(){
	InitStack(OPND);
	InitStack(OPTR);
	Push(OPTR,'#');
	cin>>ch;
	while(ch!='#'||GetTop(OPTR)!='#'){
		if(!In(ch)){
			Push(OPND,ch);
			cin>>ch;
		}
		else 
		switch(Precede(GetTop(OPTR),ch)){
			case '<':
				Push(OPTR,ch);
				cin>>ch;
				break;
			case '>'£º
				Pop(OPTR,theta);
				Pop(OPND,b);
				Pop(OPND,a);
				Push(OPND,Operate(a,theta,b));
				break;
			case '=':
				Pop(OPTR,x);
				cin>>ch;
				break;
		}
	}
	return GetTop(OPND);
}