#include <math.h>
#include <stdio.h>
void main() 
{
  int a, b, i, j;
  while (scanf("%d%d", &a, &b) != EOF) 
  {
    if (a >= 2 && b > a && b < 1000) 
    {
      if (a == 2)
        printf("2 ");
      for (i = a; i<= b; i++) 
      {
        for (j = 2; j <= sqrt(i); j++)
          if (i % j == 0)
            break;
        if (i % j != 0)
          printf("%d ", i);
      }
      printf("\n");
      }
    }
  }
