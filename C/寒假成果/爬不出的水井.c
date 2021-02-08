#include <stdio.h>
int main()
{
  int i, n, m, s,x,y;
  while(scanf("%d%d%d",&s,&n,&m)!=EOF)
  {
    if (s == 0 && n == 0 && m == 0)
      break;
    for (i = 1;; i++) 
    {
      x = n * i - m * i;
      y = s - x;
      if (y == n)
        break;
    }
    printf("%d\n", i + 1);
  }
}