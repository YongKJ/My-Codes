#include <stdio.h>
int func1(int n) {
  auto int m = 0;
  static int k = 5;
  k = k + 5;
  printf("auto:n=%d,m=%d,static k=%d\n", n, m, k);
  return (n + m + k);
}
int main() 
{
  int a = 2, i;
  for (i=0; i<3; i++)
    printf("i=%d,func1(a)=%d\n",i,func1(a));
  }