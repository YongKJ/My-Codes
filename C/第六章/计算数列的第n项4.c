#include <stdio.h>
int f(int n)
{
  if (n == 1 || n == 2)
    return 1;
  else
    return (49 * f(n - 1) + 27 * f(n - 2)) % 11;
}
int main()
{
  int n,t;
  while (scanf("%d", &n) != EOF) 
  {
    if (n < 1 || n > 1000000000)
      break;
     t = n % 11; 
     t = f(t);
    printf("%d\n", t);
  }
}