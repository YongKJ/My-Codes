#include <stdio.h>
#include <math.h>
int main()
{
double  s, a,i, j, k, n, m ,x, b;
  while(scanf("%lf%lf", &n, &x)!=EOF)
{  k = 1, m =1,s=0;
    for (i = 1; i <= n; i++)
    {
      b = 1;
      for (j = 1; j <= k; j++)
      b *= j;
      a = pow(x, k);
      s += m * a / b;
      m *= -1;
      k += 2;
    }
    printf("%.6f\n", s);
  }
  return 0;
}
    
  