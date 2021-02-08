#include <stdio.h>
int gcd(int n, int m);
int lcs(int n, int m);
int main() 
{
  long m, n, x, y;
  scanf("%ld%ld", &n, &m);
  if (n > 1 && n < 1000000000 && m > 1 && m < 1000000000) {
    x = gcd(n, m);
    y = lcs(n, m);
    printf("最大公约数:%ld\n最小公倍数:%ld\n", x, y);
  } 
  else
    printf("取值有误\n");
}
int gcd(int n,int m)
{
  int r;
  if (n == m)
    return n;
  else
    while ((r = n % m) != 0) 
    {
      n = m;
      m = r;
    }
  return m;
}
int lcs(int n, int m) 
{
  if (n == m)
    return n;
  else
    return n * m / gcd(n, m);
}