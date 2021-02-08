#include<stdio.h>
int main()
{
   int i,j;
   double a[50][5],sum1[50],n,m,s;
   double ave1[50],ave2[5];
   while(scanf("%lf %lf",&n,&m)!=EOF)
   {
       if(n<=50&&m<=5)
       {
           for(i=0;i<n;i++)
           {   sum1[i]=0;
               for(j=0;j<m;j++)
               {
                   scanf("%lf",&a[i][j]);
                   sum1[i]=sum1[i]+a[i][j];
               }
               ave1[i]=sum1[i]/m;

           }
           for(i=0;i<m;i++)
           {   int b=0;
               for(j=0;j<n;j++)
               {

                   b=b+a[i][j];
               }
               ave2[i]=b/n;
           }
           s=0;
           for(i=0;i<n;i++)
           {   int t=1;
               for(j=0;j<m;j++)
               {
                   if(ave2[j]>a[i][j])
                   {t=0;break;}
               }
               if(t==1)
               s=s+1;
           }
          for(i=0;i<n-1;i++)
          {
              printf("%.2lf ",ave1[i]);
          }
          printf("%.2lf\n",ave1[i]);
          for (i = 0; i < m - 1; i++) {
            printf("%.2lf ", ave2[i]);
          }
          printf("%.2lf\n", ave1[i]);
          printf("%lfd\n", s);
       }
   }
}