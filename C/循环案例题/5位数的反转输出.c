#include <stdio.h>
void main()
{
  int x;
  while(scanf("%d",&x)!=EOF)
  {
    int a[5], t = 0, i;
    while (x) 
    {
      a[t++] = x % 10;
      x /=10;
    }
    printf("%d\n", t);
    for (i = t-1; i >= 0; i--)
      printf("%d ", a[i]);
    printf("\n");
    for (i = 0; i < t; ++i)
      printf("%d",a[i]);
    printf("\n");
  }
}