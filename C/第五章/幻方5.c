#include <stdio.h>
#define n 5
int main()
{
  int a[n][n] = {0}, i = n, j = n / 2, k;
  a[0][j] = 1;
  for (k = 2; k <= n * n;k++)
  {
    i -= 1;
    j += 1;
    if(i<0)
      i = n - 1;
     else if(j>n-1)
       j = 0;
        if (a[i][j]==0)
      a[i][j] = k;
    else
    {
      i = (i + 2) % n;
      j = (j - 1 + n) % n;
      a[i][j] = k;
    } 
  }
  for (i = 0; i < n; i++) 
  {
    printf("\t");
    for (j = 0; j < n; j++)
      printf("%4d", a[i][j]);
    printf("\n\n");
  }
}
  