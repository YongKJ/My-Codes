#include <iostream>
using namespace std;
struct list{
	int *elem;
	int length;
};
int main(){
	list l;
	l.elem=new int[100],l.length=0;
	do{
		cin>>l.elem[l.length++];
	}while(getchar()!='\n');
	for(int i=0,t;i<l.length/2;i++)
		t=l.elem[i],l.elem[i]=l.elem[l.length-i-1],l.elem[l.length-i-1]=t;
	for(int j=0;j<l.length;j++)
		cout<<l.elem[j]<<(j!=l.length-1?" ":"\n");
	return 0;
}

/*
实验三：线性表的应用
时间2018.10.30       地点：信工楼317
1、实验名称：线性表的应用
	2、实验内容：建立一个顺序表的逆换算法
	3、实验目的：掌握线性表的应用
4、实验题目：从键盘输入一些整数，建立顺序表然后逆序输出
    例如，输入：1，2，3，4，5，7，7，8，9，10
	       输出：10，9，8，7，6，5，4，3，2，1
请使用如下顺序表结构：
   struct List
   {	ElemType elem[MAXSIZE];
	   int leng; 
    };
*/