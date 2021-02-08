#include <stdio.h>
long f1(int p) 
{
  int k;
  long r;
  long f2(int);
  k = p * p;
  r = f2(k);
  return r;
}
long f2(int q)
{
  long c = 1;
  int i;
  for (i = 1; i <= q; i++)
    c = c * i;
  return c;
}
void main() 
{
  int a, b;
  long s = 0;
  printf("input a,b=?");
  scanf("%d%d", &a, &b);
  s = f1(a) + f1(b);
  printf("\ns=%ld\n", s);
}
