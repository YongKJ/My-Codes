#include<stdio.h>
double jc(int x)/*分母，求阶乘*/
{
	double s=1;
	int k=0;
	for(int i=0;i<x;i++)
	{
		k++;
		s=k*s;
	}
	return s;
}

double f(double x,int y)/*分子*/
{
	double s=1;
	for(int i=0;i<y;i++)
	{
		s=s*x;
	}	
	return s;
}

int main()
{
	double x,t,u;
	int i,n,j=1;
	while(scanf("%d%lf",&n,&x)!=EOF)
	{
          double sinx = 0;
	  t=2*n-1;
          for (i = 1; i <= t; i += 2) 
          {
            u = 0;
            u = f(x, i) / jc(i);
            sinx = sinx + j * u;
            j *= -1; /*分子前的正负*/
          }
          printf("%.3lf\n", sinx);
        }
}