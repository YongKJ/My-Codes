#include <stdio.h>
#include <iostream>
using namespace std;
typedef struct            
//请比较教材上的类型定义并找出异同
{	int data[100];
 	int length;
} sqlist;
void init_list(sqlist *L){
	if(!(&L->data[0]))
		exit(-2);
	L->length=0;
}  
int get_elem(sqlist L,int i){
	if(i<0||i>L.length)
		return 0;
	return L.data[i-1];
}
void list_insert(sqlist *L,int i,int e){
	if(i<0||i>L->length+1||i==101){
		cout<<"ERROR"<<endl;
		exit(-2);
	}
	for(int j=L->length;j>i-1;j--)
		L->data[j]=L->data[j-1];
	L->data[i-1]=e,L->length++;
} 
void list_delete(sqlist *L,int i) {
	if(i<0||i>L->length){
		cout<<"ERROR"<<endl;
		exit(-2);
	}
	for(int j=i-1;j<L->length-1;j++)
		L->data[j]=L->data[j+1];
	L->length--;
}
void disp(sqlist L){
	for(int i=0;i<L.length;i++)
		cout<<L.data[i]<<(i!=L.length-1?" ":"\n");
}
int locate(sqlist L,int e){
	for(int i=0;i<L.length;i++)
		if(e==L.data[i])
			return i+1;
	return -1;
}
int main()  
{	int x,i;    	
	sqlist L1;
    init_list(&L1);
	printf("\n输入整数，０结束：\n");
	i=0,scanf("%d",&x); 
    while ( x ){
    	L1.data[i++]=x;
    	cin>>x;
    }
    L1.length=i;		
    disp(L1);
	printf("\n输入一个整数：");
	scanf("%d",&x); 
	if( (i=locate(L1,x))==-1 )
          list_insert(&L1, L1.length+1, x);
	else
          list_delete(&L1, i);
	disp(L1);     
	return 1;
}

/*
实验一：顺序表的实现
时间：2018.10.16     地点：信工楼317
1、实验名称：顺序表的基本操作
2、实验目的：掌握顺序表的实现与基本操作
3、实验内容：
		①从键盘输入若干个整数，以0结束。将这些整数（0除外）存入顺序表中。
		②再从键盘输入一个整数。如果源顺序表中存在这个整数，则将源顺序表中的这个整数删除；如果源顺序表中不存在这个整数，则将这个整数插入到顺序表。

参考程序
#include <stdio.h>
typedef struct            
//请比较教材上的类型定义并找出异同
{	int data[100];
 	int length;
} sqlist;
void init_list(sqlist *L)   
int get_elem(sqlist L,int i)
void list_insert(sqlist *L,int i,int e) 
	
void list_delete(sqlist *L,int i) 
void disp(sqlist L)  
}	
int locate(sqlist L,int e)  
void disp(sqlist L) ; 
int main()  
{	int x,i;    	sqlist L1;
    	init_list(&L1);
	printf("\n输入整数，０结束：\n");
	i=0;     scanf("%d",&x); 
    	while ( x )
    	{ 
   } 	
    	L1.length=i;		disp(L1);
	printf("\n输入一个整数：");
	scanf("%d",&x); 
	if  ( (i=locate(L1,x))==-1 )             ;
	     else  list_delete(&L1,i);
	disp(L1);     
	return 1;
}

 */