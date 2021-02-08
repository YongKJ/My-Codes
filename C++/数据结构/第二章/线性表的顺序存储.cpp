#include <iostream>
using namespace std;
const int MAXSIZE=10,n=3,OK=1,ERROR=0,OVERFLOW=-2;
typedef int Status;
#define Polynomial ElemType
struct Polynomial{
	float coef;
	int expn;
};
bool operator==(ElemType &a,ElemType &b){
	return a.coef==b.coef&&a.expn==b.expn;
}
typedef struct{
	Polynomial *elem;
	int length;
}SqList;
/*strust Book{
	char no[20];
	char name[50];
	float price;
};
typedef strust{
	Book *elem;
	int length;
}SqList;*/
Status InitList(SqList &L){
	L.elem=new ElemType[MAXSIZE];
	if(!L.elem)
	exit(OVERFLOW);
	L.length=0;
	return OK;
}
Status LocateElem(SqList &L,ElemType e){
	for(int i=0;i<L.length;i++)
	if(L.elem[i]==e)
	return i+1;
	return 0;
}
Status GetElem(SqList &L,int i,ElemType &e){
	if(i<1||i>L.length)
		return ERROR;
	e=L.elem[i-1];
	return OK;
}
Status ListInsert(SqList &L,int i,ElemType &e){
	if(i<1||i>L.length+1||L.length==MAXSIZE)
		return ERROR;
	for(int j=L.length-1;j>=i-1;j--)
		L.elem[j+1]=L.elem[j];
	L.elem[i-1]=e;
	L.length++;
	return OK;
}
Status ListDelete(SqList &L,int i){
	if(i<1||i>L.length)
		return ERROR;
	for(int j=i;j<=L.length-1;j++)
		L.elem[j-1]=L.elem[j];
	L.length--;
	return OK;
}
void In(SqList &L,int n){
	if(n>0)
	for(int i=0;i<n;i++)
		cin>>L.elem[i].coef>>L.elem[i].expn,L.length++;//²»ÄÜL.elem->coef,L.elem->expn
}
void Out(SqList &L){
	for(int i=0;i<L.length;i++)
		cout<<L.elem[i].coef<<" "<<L.elem[i].expn<<endl;
}
int main(){
	SqList L;
	ElemType e;
	InitList(L);
	In(L,n);
	Out(L);
	if(GetElem(L,1,e))
	cout<<e.coef<<" "<<e.expn<<endl;
	return 0;
}