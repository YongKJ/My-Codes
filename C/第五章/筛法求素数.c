#include <stdio.h>
#include <math.h>
int main()
{
  int a, b, n, j,i;
  while(scanf("%d%d", &a, &b)!=EOF)
  {
  	if(a>=2&&b>a&&b<1000)
  {
    n = b - a;
    int f[n];
    for (i = 0; i < n; i++) 
    {
      f[i] = a;
      a++;
    }
    if(f[0]==2)
      printf("2 ");
    for (i = 0; i < n; i++) 
    {
      for (j = 2; j <=sqrt(f[i]); j++)
        if (f[i] % j == 0)
          break;
      if (f[i] % j != 0)
        printf("%d ", f[i]);
    }
    printf("\n");
   }
  }
}