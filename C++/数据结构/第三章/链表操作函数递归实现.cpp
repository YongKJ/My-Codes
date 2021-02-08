int GetMax(LinkList p){
	if(!p->next)
		return p->data;
	else{
		int max=GetMax(p->next);
		return p->data>=max?p->data:max;
	}
}
int GetLength(LinkList p){
	if(!p->next)
		return 1;
	else
		return GetLength(p->next)+1;
}
double GetAverage(LinkList p,int n){
	if(!p->next)
		return p->data;
	else{
		double ave=GetAverage(p->next,n-1);
		return (ave*(n-1)+p->data)/n;
	}
}
