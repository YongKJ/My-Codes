#include <stdio.h>
static int k = 0;
void f(int x,int n)  
{
  int j;
  static int t[5] = {0}, i = 0;
  t[i++] = x % n;
  x /= n;
  if (x == 0) 
  {
    for (j = i - 1; j >= 0; j--)
      printf("%d", t[j]);
    i = k;
  }
  else 
    f(x, n);
}
int main()
{
    int x,n;
    while (scanf("%d%d",&x,&n)==2)
    {
      f(x, n);
      printf("\n");
    }

}    