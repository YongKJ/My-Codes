#include<stdio.h>
#include <stdlib.h>
#define MAXsize 100
typedef struct SqStack{
	int stacksize;
	int *top;
	int *base;
}SqStack;


int InitStack(SqStack *S)
{
S->base=(int*)malloc(sizeof(int)*MAXsize);
if(!S->base) exit(-2);
S->top=S->base;
S->stacksize=MAXsize;
return 1;
}


int Push (SqStack *S ,int e)
{
	if (S->top-S->base==MAXsize)
		return 0;
*S->top++=e;
return 1;
}


int Pop (SqStack *S)
{
	if(S->top==S->base)
		return 0;
	return *--S->top;
}


void conversion(){
	SqStack S;
        int n, e;
	InitStack(&S) ;
	scanf("%d",&n);

	while(n){
		Push(&S,n%8);
		n=n/8;
	}

	while((e=Pop(&S)))
	printf("%d",e);
        printf("\n");
}
int main() { conversion(); }