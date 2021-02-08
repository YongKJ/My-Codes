#include <stdio.h>
long fac(int n)
 {
  long f;
  if (n == 1 || n == 0)
    f = 1;
  else
    f = n * fac(n - 1);
  return f;
}
int main()
 {
  long y;
  int n;
  scanf("%d", &n);
  y = fac(n);
  printf("%d!=%ld", n, y);
}
          
	