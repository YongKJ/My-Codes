#include <stdio.h>
int main()
{
  int n, i, j,m;
  scanf("%d", &m);
  while(scanf("%d", &n)!=EOF)
  {
   if (n < 1 || n > 20)
   break;
   int a[20] = {0},s=1;
  a[n-1] = 1;
  while(a[n-1]<2)
  {
    a[0]++;
    for (i = 0, j = i + 1; j < n; i++, j++)
      if (a[i] == 2) {
        a[i] -= 2;
        a[j]++;
      }
    for (i = 0; i < n; i++)
      if (a[n - 1] == 2)
        break;
      else if (a[i] == 1)
        s++;
  }
  printf("%d\n", s);
  m--;
  if (m == 0)
    break;
  }
}