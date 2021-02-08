#include <stdio.h>
int main( )
{        int n,s,i;
  while (scanf("%d", &n),n) 
  {
    s = 1;
    for (i=1;i<n;i++)
      s = (s + 1) * 2;
    printf("%d\n", s);
  }
  return 0;
}