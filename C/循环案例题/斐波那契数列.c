#include <stdio.h>
int f(int n);
int main() 
{
  int n;
  while (scanf("%d", &n) != EOF) 
  {
    if (n < 0 || n > 20)
      break;
    n = f(n);
    printf("%d\n", n);
  }
}
int f(int n) 
{
  int s;
  if (n == 2 || n == 1)
    s = 1;
  else
    s = f(n - 1) + f(n - 2);
  return s;
}