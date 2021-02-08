#include<stdlib.h>
#include<stdio.h>
#include<math.h>
int main()
{
int i,j,k;
int num=0;for(i=0;i<=20;i++)
{
for(j=0;j<=50;j++)
{
  for (k = 0; k <= 100; k++) {
    if (100 == k + 2 * j + 5 * i)
      num++;
  }
}
}
printf("Total Num is %d", num);
}