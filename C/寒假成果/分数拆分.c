#include <stdio.h>
int main()
{
  int x, y, k, n;
  scanf("%d", &n);
  while(n--)
  {
    scanf("%d", &k);
    for (y=k+1;y<=2*k;y++)
      if (k * y % (y - k) == 0) 
      {
        x = k * y / (y - k);
        printf("1/%d=1/%d+1/%d\n", k, x, y);
      }
  }
}