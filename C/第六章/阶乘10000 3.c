#include <stdio.h>
int main()
{
  int n, i, j, c, t;
  while(scanf("%d",&n)!=EOF)
  {
    if (n < 0 || n > 10000)
      break;
    int d = 1, a[50000];
    a[0] = 1;
    for  (i=2;i<=n;i++)
    {
      for (j = 0, c = 0; j < d; j++) 
      {
        t = a[j] * i + c;
        a[j] = t % 10;
        c = t / 10;
      }
      while (c) 
      {
        a[d++] = c % 10;
        c /= 10;
      }
    }
    for (i = d-1 ; i >= 0; i--)
      printf("%d", a[i]);
    printf("\n");
  }
}