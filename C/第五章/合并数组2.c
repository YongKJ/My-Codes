#include <stdio.h>
int main() {
  int n, m, t, i, j,k;
  scanf("%d", &n);
  int a[n];
  for (i = 0; i < n; i++)
    scanf("%d", &a[i]);
  scanf("%d", &m);
  int b[m];
  for (i = 0; i < m; i++)
    scanf("%d", &b[i]);
  t = n + m;
  int c[t];
  for (i = 0; i < n; i++)
    c[i] = a[i];
  for (i = 0; i < m; i++)
    c[i + n] = b[i];
  for (i = 0; i < t - 1; i++)
    for (j = 0; j < t - 1 - i; j++)
      if (c[j] > c[j + 1]) 
      {
        k = c[j];
        c[j] = c[j + 1];
      }
  for (i = 0; i < t; i++)
    printf("%d ", c[i]);
  printf("\n");
}