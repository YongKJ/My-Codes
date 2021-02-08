#include <stdio.h>
int main()
{
  int m,n=0, s, t, k , i;
  scanf("%d", &k);
  for (i = 0;; i++) 
  {
    m = k / 2;
    s = k % 2;
    k = m;
    if(s==1)
    n++;
    if (m == 0)
      break;
  }
  printf("%d\n", n);
}