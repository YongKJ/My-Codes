#include <stdio.h>
int main() 
{
  int n, k, i, j, t, a[5000] = {0};
  while (scanf("%d%d",&n,&k)!=EOF) 
  {
    t = 1;
    for (i = 1; i <= k; i++) 
      for (j = 1; j <= n; j++)
        if (j % i == 0)
          a[j] = !a[j];
          if(a[1]==1)
            printf("1");
    for (i = 2; i <= n; i++)
      if (a[i] == 1)
        printf(" %d", i);
          printf("\n");
  }
}