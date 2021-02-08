#include <stdio.h>
#include <math.h>
int m(int x);
int m(int x) 
{
  int i;
  for (i = 2; i < sqrt(x); i++)
    if (x % i == 0)
      break;
  if (x % i != 0)
    return 1;
  else
    return 0;
}
int main()
{
  int a, b;
  scanf("%d%d", &a, &b);
  if(a>=2&&b>a&&b<1000)
  {
    int t,i,j,s=2;
    t = b - a;
    int c[999];
    for (i = 0; i < 999; i++) 
    {
      c[i] = s;
      s++;
    }
    if(a==2)
      printf("%d ", c[0]);
    for (i = 0; i < 999;i++)
      if (c[i] >= a && c[i] <= b) {
        if (m(c[i]))
          printf("%d ", c[i]);
      }
  }
}