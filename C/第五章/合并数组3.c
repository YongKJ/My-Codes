#include <stdio.h>
int main() {
  int m, n, t, i, j, s;
  while (scanf("%d", &m) != EOF) 
  {
    int a[m];
    for (i = 0; i < m;i++)
      scanf("%d", &a[i]);
    scanf("%d", &n); 
    int b[n];
    for (i = 0; i < n;i++)
      scanf("%d", &b[i]);
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
      if (i == s - 1)
        printf("%d\n", c[i]);
      else
        printf("%d ", c[i]);
    
  }
}