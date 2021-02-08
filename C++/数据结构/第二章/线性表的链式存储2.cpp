#include <iostream>
using namespace std;
const int MAXSIZE=10,n=3,OK=1,ERROR=0,OVERFLOW=-2;
typedef int Status;
#define Polynomial ElemType
struct Polynomial{
	float coef;
	int expn;
};
bool operator !=(ElemType &a,ElemType &b){
	return a.coef!=b.coef||a.expn!=b.expn;
}
typedef struct LNode{
	ElemType data;
	LNode *next;
}*LinkList;
/*Status InitList(LinkList &L){
	L=new LNode;
	L->next=NULL;
	return OK;
}*/
void CreateList_H(LinkList &L,int n){
	L=new LNode;
	L->next=NULL;
	for(int i=0;i<n;i++){
		LinkList p=new LNode;
		cin>>p->data.coef>>p->data.expn;
		p->next=L->next,L->next=p;
	}
}
void CreateList_R(LinkList &L,int n){
	L=new LNode;
	L->next=NULL;
	LinkList r=L;
	for(int i=0;i<n;i++){
	LinkList p=new LNode;
	cin>>p->data.coef>>p->data.expn;
	p->next=NULL,r->next=p,r=p;
	}
}
void OutList(LinkList &L){
	for(LinkList i=L->next;i;i=i->next)
	cout<<i->data.coef<<" "<<i->data.expn<<(i->next?" ":"\n");
}	
Status GetElem(LinkList &L,int i,ElemType &e){
	LinkList p=L;
	for(int j=0;p&&j<i;j++)
		p=p->next;
	if(p)e=p->data;
	return (p?OK:ERROR);
}
LNode* LocateElem(LinkList &L,ElemType &e){
	LinkList p=L;
	while(p&&p->data!=e)
		p=p->next;
	return p;
}
Status ListInsert(LinkList &L,int i,ElemType &e){
	LinkList p=L;
	for(int j=0;p&&j<i-1;j++)
		p=p->next;
	if(p){
	LinkList s=new LNode;
	s->data=e,s->next=p->next,p->next=s;
        return OK;
	}
	return ERROR;
}
Status ListDelete(LinkList &L,int i){
	LinkList p=L;
	 for(int j=0;p&&j<i-1;j++)
	 	 p=p->next;
	 if(p->next){
	 LinkList q=p->next;
	 p->next=q->next,delete q;
         return OK;
	}
	 return ERROR;
}
int main(){
	LinkList L;
	//ElemType e;
	CreateList_R(L,3);
	//cin>>e.coef>>e.expn;
	//ListInsert(L,1,e);
	OutList(L);
	ListDelete(L,3);
	OutList(L);
	//if(GetElem(L,3,e))
	//cout<<e.coef<<" "<<e.expn<<endl;
	//LinkList p=LocateElem(L,e);
	//cout<<p->data.coef<<" "<<p->data.expn<<endl;
	return 0;
}