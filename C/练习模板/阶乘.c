#include <stdio.h>
int main() 
{
  int i, n, j;
  long p, s=0;//s=0很重要！(
  printf("请输入一个整数:");
  scanf("%d",&n);
  for (i = 1; i <= n; i++) 
 {
   p = 1;
   for (j = 1; j <= i; j++) 
   p = p * j;
   s +=p;
 }
   printf("1!+…+%d!=%ld\n",n,s);
}