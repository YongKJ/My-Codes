#include <stdio.h>
int main()
{
  int a[20][20] = {0}, i, j, k, t, n;
  scanf("%d", &n);
  for (i = 0; i < n; i++)
    for (j = 0; j <= i; j++) 
    {
      if (j < 1)
        a[i][j] = 1;
      else if (i == 0)
        break;
      else
        a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
    }
  for (i = 0; i < n; i++) 
  {
    for (k = 1; k < n - i; k++)
      printf("   ");
    for (j = 0; j <= i; j++)
      printf("%3d   ", a[i][j]);
    printf("\n");
  }
}