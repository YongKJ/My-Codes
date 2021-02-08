#include <stdio.h>
int main()
{
  int n, x, y, t, a[100][100] = {0},i,j;
  scanf("%d", &n);
  x = 0, y = n - 1;
  t = a[x][y]=1;
  while (t < n * n) 
  {
    while (x+1 < n && a[x+1][y] == 0)
      a[++x][y] = ++t;
    while (y-1 >=0 && a[x][y-1] == 0)
      a[x][--y] = ++t;
    while (x-1 >=0 && a[x-1][y] == 0)
      a[--x][y] = ++t;
    while (y+1 < n && a[x][y+1] == 0)
      a[x][++y] = ++t;
  }
  for (i = 0; i < n; i++) 
  {
    for (j = 0; j < n; j++)
      printf("%2d ", a[i][j]);
    printf("\n");
  }
}