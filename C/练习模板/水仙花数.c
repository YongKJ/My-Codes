#include <stdio.h>
void main()
{
  int m, a, b, c;
  for (m = 100; m < 1000; m++)
  {
    a = m / 100;
    b = m / 10% 10;
    c = m %10;    
    if (a * a * a + b * b * b + c * c * c == m)
    printf("水仙花数:%d\n", m);
  }
}