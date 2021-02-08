#include <stdio.h>
int main() 
{
  long n, i, s, j;
  printf("请输入一个正整数:");
  scanf("%ld", &n);
  for (i = 6; i <= n; i++) 
{
    s = 1;//这里的赋值很重要！
    for (j = 2; j < i; j++)
    if (i % j == 0)
     s += j;
    if (i - s == 0) 
  {
    printf("完美数:%ld  ", i);
    printf("它的因子:");
    for (j=1; j<i; j++) 
   {
     if(i%j==0)
     printf("%ld ",j);
   }
     printf("\n");
  }
 }
}