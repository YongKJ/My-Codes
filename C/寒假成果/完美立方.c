#include <stdio.h>
int main() 
{
  int a, b, c, d, n;
  long sum1, sum2;
  scanf("%d", &n);
  if(n<=100)
  for (a = 2; a <= n; a++)
    for (b = 2; b < a; b++)
      for (c = b; c < a; c++)
        for (d = c; d < a; d++) 
        {
          sum1 = a * a * a;
          sum2 = b * b * b + c * c * c + d * d * d;
          if (sum1 == sum2)
            printf("Cube = %d, Triple = (%d,%d,%d)\n", a, b, c, d);
        }
}