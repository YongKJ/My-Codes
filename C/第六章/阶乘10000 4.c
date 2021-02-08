#include <stdio.h>
#include <string.h>
void f(int *p) 
{
  int c;
  c = *p / 10000;
  *p %= 10000;
  *(p + 1) += c;
}
int main()
{
  int n, i, j, d, a[50000] = {0};
  while(scanf("%d",&n)!=EOF)
  {
    if (n < 0 || n > 10000)
      break;
    memset(a, 0, sizeof(a));
    a[0] = 1, d = 0;
    for (i = 1; i <= n; i++) 
    {
      for (j = 0; j <= d; j++)
        a[j] *= i;
      for (j = 0; j <= d; j++)
        if (j == d&&a[j]>10000)
          f(&a[j]), d++;
        else if (a[j] > 10000)
          f(&a[j]);
    }
    printf("%d", a[d]);
    for (i = d-1; i >= 0; i--)
      printf("%04d", a[i]);
    printf("\n");
  }
}