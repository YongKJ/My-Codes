#include <stdio.h>
void j(int);
int main() 
{
  int n;
  scanf("%d", &n);
  j2(n);
  return 0;
}

void j(int n) 
{
  int i, t, k,m=1;
  for(i=2;i<=n;i++)
  {
    if (n % i == 0) 
    {
      t = n / i;
      if(t==1)
     { 
     printf("%d\n%d\n", i,m);
      return;
      } 
      else 
      {
        printf("%d*\n%d\n", i,m);
        j(t);
        break;
      }
    }
  }
}

void j2(int n)
{
  int i,m=1;
  for(i=2;i<=n;i++)
  {
  	while(n!=i)
  	{
          if (n % i == 0) 
          {
            printf("%d*\n%d\n", i,m);
            n = n / i;
          } 
          else
            break;
          }
  }
  printf("%d\n%d\n", n,m);
}