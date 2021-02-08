#include<stdio.h>
 int main()
 {
   int i,n,j;
   long p,sum=0;
   printf("Input n:");
   scanf("%d",&n);
     for(i=1;i<=n;i++)
     {
       p=1;
       for (j = 1; j <= i; j++)
       {
         p = p * j;
       }
       sum = sum + p;
     }
     printf("1！+2！+....+%d!=%ld\n", n, sum);
     return 0;
 }