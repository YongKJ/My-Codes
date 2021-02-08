#include <math.h>
#include <stdio.h>
void main() 
{
  int i, j;
  for (i = 2; i <= 999; i++) 
  {
    for (j=2; j<=sqrt(i); j++) 
      if (i % j == 0)
        break;
      if (i % j != 0)
        printf("%d\n",i);
    }
  }