#include <stdio.h>
int main()
{
  int i,n,j,s;
  while (scanf("%d", &n) != EOF) 
  {
    int a[n][n];
    s = 0;
    for (i = 0; i < n; i++)
      for (j = 0; j < n;j++)
        scanf("%d", &a[i][j]);
    for (i = 0; i < n; i++)    
      for (j = 0; j < n; j++)
        if (i == j || i + j == n-1)
          s += a[i][j];
    printf("%d\n", s);
  }
}
  