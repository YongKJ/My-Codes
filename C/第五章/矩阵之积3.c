#include <stdio.h>
int main()
{
  int n, m, k, i, j, t;
  scanf("%d%d", &n, &m);
  int a[n][m];
  for(i=0;i<n;i++)
    for (j = 0; j < m;j++)
      scanf("%d", &a[i][j]);
  scanf("%d%d",&m,&k);
  int b[m][k];
  for (i = 0; i < m;i++)
    for (j = 0; j < k;j++)
      scanf("%d", &b[i][j]);
  int c[n][k];
      for (i = 0; i < n;i++)
        for (j = 0; j < k; j++) 
        {
          c[i][j] = 0;
          for (t = 0; t < m; t++)
            c[i][j] += a[i][t] * b[t][j];
        }
      for (i = 0; i < n; i++) 
      {
        for (j = 0; j < k; j++)
          printf("%d ", c[i][j]);
        printf("\n");
      }
}