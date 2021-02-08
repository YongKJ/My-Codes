#include <stdio.h>
#include <math.h>
int main() 
{
  int a, b, j;
  printf("请输入两个正整数:");
  scanf("%d%d", &a, &b);
  if(a<=1||b>=1000)
    printf("取值范围有误！");
  else
 {
  printf("%d到%d之间的素数:\n",a,b);
  if (a == 2) 
{
    printf("  2\n");
    a++;
  }
  for (; a <= b; a++) {
    for (j = 2; j <= sqrt(a); j++)
      if (a % j == 0)
        break;
    if (a % j != 0)
      printf("%3d\n", a);
  }
  }
}