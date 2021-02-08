#include <stdio.h>
#include<iostream>
#define Maxsize 100
using namespace std;
typedef struct 
{
	int *base;
	int *top;
	int stacksize;
}stack;
void Initstack(stack &s)
{
	s.base=new int[Maxsize];
	s.top=s.base;
	s.stacksize=Maxsize;
}
int push(stack &s,int e)
{
	if(s.top-s.base==s. stacksize)
	return 0;
	*s.top=e; 
	s.top++;
	return 1;
}
int pop(stack &s,int e)
{
	if(s.top==s.base)return 0; 
	while(s.top!=s.base)
	{
		e=*--s.top;
		cout<<e;
	}	
	return 1;
} 
int main()
{
	stack s1;
	Initstack(s1);
	int  x;
	int y;
	int z;
 	while(cin>>x,x!=0)
 	{
 		for(;x%8!=0;)
 		{
 			z=x%8;
 			if(x!=0)
 			push(s1,z);	
 			x=x/8;
		}
                pop(s1, y);
	 }
	 return 0;
} 