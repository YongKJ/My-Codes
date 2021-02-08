#include <stdio.h>
#include <math.h>
int main()
{
  int n,i,j,t=1,a,b,k,l,r;
  double c;
  scanf("%d", &n);
  while(scanf("%d%d",&a,&b)!=EOF)
  {
    int s[a];
    k = 0;
    for (i = 0, j = 1; i < a; i++, j++) 
    {
      s[i] = j, r = 1, l = pow(b, r);
      while (s[i]%l==0)
        k++, r++, l = pow(b, r);
     }
      printf("%d\n", k);
      if (++t > n)
        break;
    }
}