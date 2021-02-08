#include <stdio.h>
int main()
{
   int i,j,t,a[100],n;
   while(scanf("%d",&n)!=EOF)
   {
     for(i=0;i<n;i++)
     scanf("%d",&a[i]);
     scanf("%d",&a[n]);
     for(i=0;i<=n;i++)
     for(j=i+1;j<=n;j++)
     if(a[j]<a[i])
     {
       t=a[j];
       a[j]=a[i];
       a[i]=t;
     }
     for(i=0;i<=n;i++)
     if(i==n)
     printf("%d\n",a[i]);
     else
     printf("%d ",a[i]);
   }
}  
