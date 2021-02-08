#include <stdio.h>
#include <math.h>
int main()
{
  float x, y, a, b, c, d,m,n,t,i,j;
  scanf("%f%f%f%f", &a, &b, &c, &d);
  for (x = -10, y = 10; fabs(y - x) >= 0.00001;) 
  {
    i = (x + y) / 2;
    m = a * x * x * x + b * x * x + c * x + d;
    n = a * y * y * y + b * y * y + c * y + d;
    j = a * i * i * i + b * i * i + c * i + d;
    if (m * j <= 0)
      y = i;
    if (n * j <= 0)
      x = i;
  }
  printf("%.3f\n", i);
}