#include <stdio.h>
#include <math.h>
int main()
{
  float a, b, c, d, x, y, t, m, n;
  scanf("%f%f%f%f", &a, &b, &c, &d);
  for (y = 2.5;fabs(y-x)>=0.00001; y = t) 
  {
    x = y;
    m = a * x * x * x + b * x * x + c * x + d;
    n = 3 * a * x * x + 2 * b * x + c;
    t = x - m / n;
   }
  printf("%.3f\n", t);
}