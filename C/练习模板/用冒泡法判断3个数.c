#include <stdio.h>
int main() 
{
  int a[3],i,j,t;
  printf("请输入3个整数:");
  for (i = 0; i < 3; i++) 
    scanf("%d", &a[i]);
  for (i= 0; i < 2; i++) //3个数，2次循环
  {
    for (j = 0; j < 2- i; j++)//每次循环，进行2-i次判断，若符合判断结果，则将大的数往后挪。
      if (a[j] > a[j + 1]) 
      {
        t = a[j];
        a[j] = a[j + 1];
        a[j + 1] = t;
      }
  }
  printf("\n 由小到大排序:");
  for (i = 0; i < 3; i++) 
    printf("%d ", a[i]);
}
