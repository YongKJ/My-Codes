#include <stdio.h>
int main() {
  int m, n, t, i, j, s;
  while (scanf("%d", &m) != EOF) 
  {
    int a[m];
    if (m == 3)
      scanf("%d%d%d", &a[0], &a[1], &a[2]);
    else
      scanf("%d%d%d%d", &a[0], &a[1], &a[2], &a[3]);
      
    scanf("%d", &n); 
    int b[n];
    if (n == 3)
      scanf("%d%d%d", &b[0], &b[1], &b[2]);
    else
      scanf("%d%d%d%d", &b[0], &b[1], &b[2], &b[3]);
      
    s = m + n;
    int c[s];
    
    for (i = 0; i < m; i++)
      c[i] = a[i];
    for (i = 0; i < n; i++)
      c[i + m] = b[i];
      
    for (i = 0; i < s - 1; i++)
      for (j = 0; j < s - 1 - i; j++)
        if (c[j] > c[j + 1]) 
        {
          t = c[j];
          c[j] = c[j + 1];
          c[j + 1] = t;
        }
        
    for (i = 0; i < s; i++) 
    {
      if (i == s - 1)
        printf("%d", c[i]);
      else
        printf("%d ", c[i]);
    }
    printf("\n");
  }
}