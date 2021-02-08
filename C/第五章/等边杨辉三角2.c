#include "stdio.h"
int main()
{
    int a[11][20],i,j,k;
    //初始化
    for(i=0;i<11;i++)
     for(j=0;j<20;j++)
      a[i][j]=0;
     //给数组附值
    for(i=0;i<10;i++)
    {
     for(j=0;j<=i;j++)
     {
      if(j<1)a[i][j]=1;//开头的第一个数为1
      else if(i==0)break;
      else
      a[i][j]=a[i-1][j-1]+a[i-1][j];
                  //杨辉三角的规律
     }
    }
    //输出
    for (i = 0; i < 10; i++) 
    {
        for (k = 1; k <= 10-i;k++)
          printf("    ");//3个空格
        for (j = 0; j <= i; j++) //在这里只打印到i表明只打印多少个数
          printf("%6d  ", a[i][j]);
        printf("\n");
      
    }
}