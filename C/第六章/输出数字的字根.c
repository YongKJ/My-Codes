#include <stdio.h>
void f(int x) 
{
  int a[5] = {0}, s = 0, i = 0;
  while (x) 
  {
    a[i] = x % 10;
    x /= 10;
    s += a[i++];
  }
  if (s < 10)
    printf("%d\n", s);
  else
    f(s);
}
int main()
{
  int x;
  while (scanf("%d", &x) != EOF) 
  {
    if (x == 0)
      break;
    else
      f(x);
  }
}
  