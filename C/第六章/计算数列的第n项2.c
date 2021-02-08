#include <stdio.h>
int main()
{
  int f[122], i,n;
  while (scanf("%d", &n) != EOF) 
  {
    if (n < 1 || n > 1000000000)
      break;
    f[0] = 0;
     f[1] =f[2]= 1;
    for (i = 3; i <= 121; i++)
      f[i] = (49 * f[i - 1] + 27 * f[i - 2]) % 11;
    printf("%d\n", f[n%121]);
  }
  }
  