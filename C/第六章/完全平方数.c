#include <stdio.h>
#include <math.h>
int main()
{
  int x = 1000, a, b, c, d;
  double y;
  while (x <= 9999) 
  {
    a = x /1000;
    b = x / 100 % 10;
    c = x / 10 % 10;
    d = x % 10;
    if (a == b && c == d && sqrt(x)==(int)sqrt(x))
      printf("%d\n", x);
    x++;
  }
}
    