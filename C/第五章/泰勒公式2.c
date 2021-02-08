#include  <stdio.h>
int fac(int n)
{ 
      long f;
      if(n==1||n==0) 
      f=1;
      else 
      f=n*fac(n-1);
      return f;
}

int main()
{
      int n,i;
      double x, y, t = 1.0, s = 1.0;
      scanf("%d %lf", &n, &x);
      y = x/1.0;
      t = t * x;
      for(i=3;i<=2*n-1;i=i+2)
  {
      t = t * x * x;
      t = -t;
      y = y + t / fac(i);
  }
     printf("%.3f\n", y);
} 