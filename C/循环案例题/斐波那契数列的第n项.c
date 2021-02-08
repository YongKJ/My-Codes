#include <stdio.h>
int f(int n);
int main() 
{
  int n;
  scanf("%d", &n);
  n = f(n);
  printf("%d\n", n);
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
     
  