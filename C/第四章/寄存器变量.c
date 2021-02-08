#include <stdio.h>
int fac(int n) 
{
  register int i;
  int f = 1;
  for (i = 1; i <= n; i++)
    f = f * i;
  return (f);
}
int main() {
  int i;
  for (i = 0; i <= 6; i++) 
  {
    printf("%d!=%d\n", i, fac(i));
  }
  }