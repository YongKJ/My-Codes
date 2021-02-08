#include<stdio.h>
int a,b;
int fun(int n)
{
if(n==1||n==2)
return 1;
if(n>2)
return (a*fun(n-1)+b*fun(n-2));
}
int main() 
{
  int n, y;
  printf("please enter a b n value:");
  scanf("%d %d %d", &a, &b, &n);
  y = fun(n);
  printf("f(%d)=%d\n", n, y);
  return 0;
}