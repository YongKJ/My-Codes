#include <stdio.h>
#include <math.h>
int main()
{
  double i, x, b, j ,a,s=0;
  while(scanf("%lf",&x)!=EOF)
{
    for (i = 1; i <= 10; i++) 
    {
      b = pow(-1, i -1) * pow(x, 2 * i - 1);
      a = 1;
      for (j =1; j <=2*i-1; j++)
       a *= j;
       s+= b / a;
    }
    printf("%.3f\n", b);
  }
}