#include <stdio.h>
int main() 
{
  int n, i, j, k,s=0;
  printf("用n,n+1,n+2,n+3这4个数字组成无重复数字的三位数。\n\n");
  printf("请输入一个整数:");
  scanf("%d", &n);
  if (n <= 0 || n >= 7)
  printf("这个整数超出取值范围！\n");
  else 
 {
   for(i=n;i<=n+3;i++)
   for(j=n;j<=n+3;j++)
   for(k=n;k<=n+3;k++) 
  {
    if (i != j && i != k && j != k) 
   {
     printf("%d%d%d  ", i, j, k);
     s++;
     if(s % 4 == 0)
     printf("\n");
   }
    
  }
     printf("\n一共有%d个不重复的三位数！\n", s);
 }
}
    
