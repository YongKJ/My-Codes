#include<iostream>
#include<stdio.h>
#include<string>
#include<cstring>
using namespace std;
int f[50010],c[2010],w[2010];
int main()
{
 int test,m,v,i,j;
 scanf("%d",&test);
 while (test--) {
   memset(f, -10000000, sizeof(f)); //用来判断背包是否装满
   f[0] = 0;
   scanf("%d%d", &m, &v);
   for (i = 1; i <= m; ++i)
     scanf("%d%d", &c[i], &w[i]);
   for (i = 1; i <= m; ++i)
     for (
         j = 0; j <= v;
         ++j) //注意此循环与01背包的用一维数组表示的状态方程的区别，一个循环逆序，一个顺序
       if (j >= c[i])
         f[j] = f[j] > (f[j - c[i]] + w[i])
                    ? f[j]
                    : f[j - c[i]] + w[i]; //完全背包的状态方程，可画图加深理解
   if (f[v] < 0)                          //背包为装满
     printf("NO\n");
   else
     printf("%d\n", f[v]);
 }
}