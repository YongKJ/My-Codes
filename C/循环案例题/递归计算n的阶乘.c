#include <stdio.h>
int f(int x) 
{
  if (x == 1 || x == 0)
    return 1;
  else
    return x * f(x-1);
}
int main() 
{
  int x;
  while (scanf("%d", &x) != EOF) 
  {
    if (x >= 0 && x < 14)
     printf("%d\n", f(x));
  }
}