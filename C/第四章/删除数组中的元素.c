#include <stdio.h>
void del(int a[],int n,int x)
{
  int i, j, t;
  for(i=0;i<n;i++)
    if (a[i] == x)
      for (j = i; j + 1 < n; j++)
        a[j] = a[j + 1];
  for (i = 0; i < n-1; i++)
    printf("%d ", a[i]);
  printf("\n");
}
int main()
{
  int a[100], n, i, x;
  scanf("%d", &n);
  for (i = 0; i < n; i++)
  scanf("%d",& a[i]);
  scanf("%d", &x);
  del(a, n, x);
}
  