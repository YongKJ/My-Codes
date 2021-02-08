#include <stdio.h>
int main() 
{
  int a = 7,c;
  float x = 2.5, y = 4.7, s;
  c = 1/4;
  s = x + a % 3 + (int)(x + y) % 2 / 4;
  printf("%.1f   %d\n", s, c);
}
  