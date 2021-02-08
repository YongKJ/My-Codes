#include <stdio.h>
#include <math.h>
int main()
{
   float a,b,c ,disc,x1,x2,p,q;
   while(scanf("%f%f%f",&a,&b,&c)!=EOF)
  { 
   disc=b*b-4*a*c;
   if(fabs(disc)<=1e-6)
   printf("x1=x2=%.6f\n",-b/(2*a));
   else
   {
     if(disc>1e-6)
     {
       x1=(-b+sqrt(disc))/(2*a);
       x2=(-b-sqrt(disc))/(2*a);
       printf("x1=%.6f x2=%.6f\n",x1,x2);
     } 
     else 
     {
       p = -b / (2 * a);
       q = sqrt(fabs(disc)) / (2 * a);
       printf("x1=%.6f+%.6fi x2=%.6f-%.6fi\n", p, q, p, q);
     }
   }
  }
  return 0;
}
