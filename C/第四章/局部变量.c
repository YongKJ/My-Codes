#include <stdio.h>
int fun(int a);
void main()
{
  int a = 3, b;
  b = a + 1;
  {
    float b = 6;
    printf("%f\n", a + b);
  }
  printf("%d\n", a + b);
  printf("%d\n", fun(a));
}
int fun(int a) 
{
  int m;
  m = 2 * a;
  return (m);
}