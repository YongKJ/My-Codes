#include <stdio.h>
int main()
{
  int x, m, n, a[301] = {0}, i, s = 0;
  scanf("%d", &x);
  while (x-- != 0) 
  {
    scanf("%d%d", &m, &n);
    for (i = m; i <= n; i++)
      a[i] = 1;
  }
  for (i = 0; i < 301; i++)
    if (a[i] == 1)
      s++;
  printf("%d\n", s);
}