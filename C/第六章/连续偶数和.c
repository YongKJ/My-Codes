#include<stdio.h>
int fun(int n)
{
  if(n==2)
    return 2;
  else
    return n + fun(n - 2);
}
void main()
{
    int n,sum;
    while(scanf("%d",&n)!=EOF)                            
    { 
            sum=fun(n);
            printf("%d\n",sum);
    }
} 