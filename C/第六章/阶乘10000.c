#include <stdio.h>
int main()
{
  int i, j, n, c, t;
  while(scanf("%d",&n)!=EOF)
  {
    int a[50000],d=1;
    a[0] = 1;
    if (n >= 0 && n <= 10000) 
    {
    	
      for (i = 2; i <=n;i++)
      {
      	
        for (j = 1, c = 0; j <= d; j++) 
        {
          t = a[j - 1] * i + c;
          a[j - 1] = t % 10;
          c = t / 10;
        }

        while (c) 
        {
          a[++d - 1] = c % 10;
          c /= 10;
        }
        
      }
      
      for (i = d; i >= 1; i--)
        printf("%d", a[i - 1]);
      printf("\n%d", d);
    }
    
  }
}