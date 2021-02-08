#include <stdio.h>
int maxnum(int a, int b) 
{
  int max;
  if (a > b)
    max = a;
  else
    max = b;
  return max;
}
void main() 
{
  int x, y, z;
  printf("input two numbers:\n");
  scanf("%d%d", &x, &y);
  z = maxnum(x, y);
  printf("maxnum=%d", z);
}