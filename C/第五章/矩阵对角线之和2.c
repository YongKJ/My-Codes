#include <stdio.h>
int main()
{
  int n,i,j,s=0,t=0;
  scanf("%d", &n);
  int a[n][n];
  for (i = 0; i < n;i++)
    for (j = 0; j < n; j++) 
    {
      scanf("%d", &a[i][j]);
      
      if (i == j || i + j == n-1)
        s += a[i][j];
    }
  printf("%d\n", s);
}
      
      
      