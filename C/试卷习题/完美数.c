#include <stdio.h>
int main() 
{
  int n, i, s, j;
  scanf("%d", &n);
  for (i = 6; i <= n; i++) 
  {
    s = 1;
    for (j = 2; j < i; j++)
      if (i % j == 0)
        s += j;
    if (i == s)
      printf("%d\n", i);
  }
}