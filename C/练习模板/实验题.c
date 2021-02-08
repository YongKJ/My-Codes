#include <stdio.h>
#define max(a, b) (a > b ? a : b);
void main()
 {
  int a, b, c, z;
  printf("input a&b:");
  scanf("%d,%d", &a, &b);
  c = max(a, b);
  printf("max=%d\n", c);
  if (a > b)
    z = a;
  else
    z = b;
  printf("z=%d", z);
}