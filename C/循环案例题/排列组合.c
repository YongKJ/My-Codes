#include <stdio.h>
int main()
{
  int n,a,b,c;
  scanf("%d", &n);
  if (n > 0 && n < 7) 
  {
    for (a = n; a <= n + 3; a++)
      for (b = n; b <= n + 3; b++)
        for (c = n; c <= n + 3; c++)
          if (a != b && b != c && a != c)
            printf("%d%d%d ", a, b, c);
  }
}