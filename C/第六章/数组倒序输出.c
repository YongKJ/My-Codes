#include <stdio.h>
int main()
{
  int a[20], n, i;
  while (scanf("%d", &n) != EOF) 
  {
    for (i = 0; i < n; i++)
      scanf("%d", &a[i]);
    for (i = n - 1; i >= 0; i--)
      if (i == 0)
        printf("%d\n", a[i]);
      else
        printf("%d ", a[i]);
  }
}