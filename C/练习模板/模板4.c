#include <stdio.h>
#include <stdlib.h>
#define MAXsize 100
typedef struct SqStack{	
int stacksize;	
int *top;
int *base;
} SqStack;
int InitStack(SqStack S) {
  S.base = (int *)malloc(MAXsize);
  if (!S.base)
    exit(-2);
  printf("-1\n");
  S.top = S.base;
  S.stacksize = MAXsize;
  return 1;
}
int Push(SqStack *S, int e) {
  printf("b\n");
  if (S->top - S->base == MAXsize)
    return 0;
  printf("a\n");
  *(S->top) = e, (S->top)++, printf("0\n");
  return 1;
}
int Pop(SqStack S) {
  if (S.top == S.base)
    return 0;
  return *--S.top;
}
void conversion(){	
SqStack S;
int n, e;
InitStack(S);
scanf("%d", &n);
while (n) {
  Push(&S, n % 8);
  n = n / 8;
}
printf("-2\n");
while((e=Pop(S))
printf("%d",e);
}
int main(){
 conversion();
 return 0;
}