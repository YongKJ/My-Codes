#include <iostream>
using namespace std;
typedef struct node{
	int x;
	node *next;
}*sqlist;
void init(sqlist &l){
	sqlist p=l;
	for(int n;cin>>n,n;){
		sqlist s=new node;
		s->x=n,p->next=s,p=s;
	}
	p->next=NULL;
	for(sqlist i=l->next,q;i;i=i->next)
		for(sqlist j=i;j&&j->next;j=j->next)
			if(i->x==j->next->x)
			   q=j->next,j->next=q->next,delete q;
}
void print(sqlist &l){
	for(sqlist i=l->next;i;i=i->next)
		cout<<i->x<<(i->next?" ":"\n");
}
int main(){
	sqlist l=new node;
	init(l);
	print(l);
	return 0;
}
/*
实验二：链表的实现与应用      
实验时间：2018.10.23 地点，信工楼317
1、实验名称：单链表的实现与基本操作
	2、实验内容：建立链表、插入结点、删除结点等运算
	3、实验目的：掌握单握链表的基本操作
4、实验题目：从键盘输入一些整数，删除其中的重复元素，并使剩余元素的相对次序保持不变。
    例如，输入：2,3,1,3,4,2,3,1,5,0
	       输出：2,3,1,4,5
提示： 在输入每个元素时，先查询该元素是否存在，如果不存在，则将元素插入链表中。

*/