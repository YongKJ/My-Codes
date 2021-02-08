#include<stdio.h>
 int main()
 { int n,d=0,i;
    scanf("%d",&n);
      int a[n],b[11]={0};
      for(i=0;i<n;i++)
      {
       scanf("%d ",&a[i]);
      b[a[i]/10]++;
      }
      for(i=0;i<=5;i++)
      d+=b[i];
      printf("%d ",d);
      for(i=6;i<9;i++)
          printf("%d ",b[i]);
      printf("%d\n",b[9]+b[10]);
      
 }  