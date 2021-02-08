#include <stdio.h>
static int k,j;
void f(int a[],int n)
{
  int i,t;
  if (n == k / 2) 
  {
    for (i = 0; i < k; i++)
      printf("%d ", a[i]);
    printf("\n");
    j = 0;
  } 
  else 
  {
    t = a[j], a[j] = a[n - 1], a[n - 1] = t;
    j++, n--;
    f(a, n);
  }
}
int main()
{
          int a[20] = {0}, i, t;
          while(scanf("%d",&a[0])!=EOF)
          {
            for (i = 1;; i++) 
            {
              scanf("%d", &t);
              if (t == 0)
                break;
              else
                a[i] = t;
            }
            k = i;
            f(a, k);
          }
}