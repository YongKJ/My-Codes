#include <stdint.h>
void main()
{
  int j,i,sum;
  for (i = 6; i <= 1000; i++) 
  {
    sum = 1;
    for (j = 2; j < i; j++)
      if ((i % j) == 0)
        sum += j;
    if (i - sum == 0)

      printf("%d its factors are 1", i);
  }
}