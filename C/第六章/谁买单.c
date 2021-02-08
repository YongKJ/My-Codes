#include <stdio.h>
int main() 
{
  int n, m, i, t=0, s=0;
  scanf("%d", &n);
  int a[n];
  for (i = 0; i < n;i++)
    a[i] = 1;
  for (i=0; i<n-1; ) 
  {
    s += a[t];
    if (s == 3) 
    {
      a[t] = 0;
      s = 0;
      i++;
    }
    t = (t + 1) % n;
  }
  for (i = 0; i < n; i++)
    if (a[i] != 0)
      printf("%d\n", i + 1);
}