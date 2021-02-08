#include <stdio.h>
void f(int *p,int n)
{
  int i,j,t;
  for (i = 0; i < n;i++)
    for (j = i + 1; j < n;j++)
      if (*(p + i) < *(p + j)) 
      {
        t = *(p + i);
        *(p + i) = *(p + j);
        *(p + j) = t;
      }
}
    	
int main() 
{
  int n, m, i, a[100], *p;
  scanf("%d", &n);
  for (i = 0; i < n; i++)
    scanf("%d", &a[i]);
  scanf("%d", &m);
  p = a;
  f(p, n);
  for (i = 0; i < n;i++)
    if (a[i] == m) 
    {
      printf("%d\n", i + 1);
      break;
    }
    if(i==n)
    printf("wucishu!\n");
}