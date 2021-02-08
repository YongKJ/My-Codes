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
   memset(f, -10000000, sizeof(f));
   f[0] = 0;
   scanf("%d%d", &m, &v);
   for (i = 1; i <= m; ++i)
     scanf("%d%d", &c[i], &w[i]);
   for (i = 1; i <= m; ++i)
     for (
         j = 0; j <= v;
         ++j) 
       if (j >= c[i])
         f[j] = f[j] > (f[j - c[i]] + w[i])
                    ? f[j]
                    : f[j - c[i]] + w[i]; 
   if (f[v] < 0)              
     printf("NO\n");
   else
     printf("%d\n", f[v]);
 }
}