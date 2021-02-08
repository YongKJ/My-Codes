#include <stdio.h>
void f(unsigned long x, int n, int flag);
int main() 
{
  unsigned long x;
  int n;
  scanf("%lu%d", &x, &n);
  f(x, n, 1);
  return 0;
}
void f(unsigned long x,int n,int flag)
{
  if (!x) 
  {
    if (flag)
      putchar('0');
    return;
  }
  f(x / n, n, 0);
  putchar(x % n < 10 ? '0' + x % n : 'A' + x % n - 10);
}