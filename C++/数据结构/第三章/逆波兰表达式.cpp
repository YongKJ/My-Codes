void expr(){
	float OPND[30];
	init(OPND);
	float num=0.0;
	cin>>x;
	while(x!='$'){
		switch(x){
			case '0'<x<'9':
			while(('0'<=x&&x<='9')||x=='.')
			       if(x!='.'){
					num=num*10+x-'0';
					cin>>x;
				}
				else{
					scale=10.0;
					cin>>x;
					while('0'<=x&&x<='9'){
						num=num+(x-'0')/scale;
						scale*=10;
						cin>>x;
					}
				}
				push(OPND,num);
				num=0.0;
			case x=' ':break;
			case x='+':push(OPND,pop(OPND)+pop(OPND));break;
			case x='-':x1=pop(OPND),x2=pop(OPND);push(OPND,x2-x1);break;
			case x='*':push(OPND,pop(OPND)*pop(OPND));break;
			case x='/':x1=pop(OPND),x2=pop(OPND),push(OPND,x2/x1);break;
			default:break;
		}
		cin>>x;
	}
	cout<<"后缀表达式的值为"<<pop(OPND)<<endl;
}