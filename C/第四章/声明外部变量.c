#include <stdio.h>
int main() {
  int max(int, int);
  extern int A, B;
  printf("%d\n", max(A, B));
}
int A = 13, B = -8;
int max(int x, int y)
{
  int z;
  z = x > y ? x : y;
  return (z);
}