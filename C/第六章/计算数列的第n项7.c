#include <stdio.h>
int main()
{
  int a, b, n, i, k, f[200];
  while(scanf("%d",&n)!=EOF)
  {
    if(n<1||n>1000000000)
      break;
    f[0] = f[1] = 1;
    if(n>2)
    {
    for (i=2;i<200;i++)
    {
      f[i] = (49 * f[i - 1] + 27 * f[i - 2]) % 11;
      if (i >= 4 && f[i - 1] == f[2] && f[i] == f[3]) 
      {
        k = i - 3;
        break;
      }
    }
    printf("%d\n", f[2 + ((n - 3) % k)]);
    }
    else
      printf("1\n");
  }
}