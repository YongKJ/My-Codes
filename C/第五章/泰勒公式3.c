#include <stdio.h>
int fac (int h)
{
	long f;
        if(h==1||h==0)  
        f=1;
        else  
        f=h*fac(h-1);
         return f;
}
int main()
{ 
        int n,i;
        double x;
        while(scanf("%d %lf",&n,&x)!=EOF)
    {
        double y,t=1.0;
        y=x/1.0;
        t=t*x;
        for (i = 3; i <= 2 * n - 1; i = i + 2) 
     {
        t = t * x * x;
        t = -t;
        y = y + t / fac(i);
      }
         printf("%.3f\n", y);
    }
 }