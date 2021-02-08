#include <stdio.h>
int main() 
{
  long a[100], i, n;
  for (a[0] = 1, a[1] = 1, i = 0; i < 100; i++)
    a[i + 2] = a[i + 1] + a[i];
  scanf("%ld", &n);
  printf("%ld\n", a[n - 1]);
}