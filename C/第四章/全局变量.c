#include <stdio.h>
int a = 1;
extern int x;
int f1() 
{
  int t;
  t = x + 2 * a;
  x++;
  return (t);
}
int x = 3, y = 4;
int f2() 
{
  int t;
  t = a + x + y;
  return (t);
}
void main() 
{
  printf("f1()=%d\n", f1());
  printf("f2()=%d\n", f2());
}