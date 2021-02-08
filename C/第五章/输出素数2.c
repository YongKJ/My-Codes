#include <stdio.h>
int main()
{
  int c[1000],a,b,t,i,j,k;
  for (i = 0,t=2; i < 1000;i++,t++)
    c[i] = t;
  scanf("%d%d", &a, &b);
  if(a>=2&&b>a&&b<1000)
{
    i = 0;
    while (c[0] <= b) 
    {
      if (c[0] >= a) 
      {
        printf("%3d ", c[0]);
        i++;
        if (i % 10 == 0)
        printf("\n");
      }
      t = c[0];
      for (j = 0; j < 1000; j++)
        if (c[j] % t == 0)
          for (k = j; k+1 < 1000; k++)
            c[k] = c[k + 1];
    }
  }
}
 