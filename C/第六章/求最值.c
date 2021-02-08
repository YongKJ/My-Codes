#include<stdio.h>
void f(int x[],int y,int *m,int *n)
{
  int i, j, t;
  for(i=0;i<y-1;i++)
  for(j=0;j<y-1-i;j++)
    if (x[j] < x[j + 1]) 
    {
      t = x[j];
      x[j] = x[j + 1];
      x[j + 1] = t;
    }
  *m = x[y - 1];
  *n = x[0];
}
int main()
{
    int i,n,max,min,a[100];
    while (scanf("%d", &n) != EOF) 
    {
      for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
      f(a, n, &min, &max);
      printf("%d %d\n", min, max);
    }
    return 0;
}