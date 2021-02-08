#include <stdio.h>
#include <string.h>
int main()
{
  int i, j, t,m,n,k=0;
  char x[201] = "", y[201] = "";
  int a[202] = {0}, b[202] = {0}, c[404] = {0};
  scanf("%s%s", x,y);
  n = strlen(x);
  m = strlen(y);
  for  (i=1,j=n-1;i<=n;i++,j--)
    a[i] = x[j]-'0';
  for (i=1,j=m-1;i<=m;i++,j--)
    b[i] = y[j] - '0';
  if (n > m)
    t = n, n = m, m = t;
  for (i = 1; i <= m; i++) 
    c[i] = a[i] + b[i];
  for (i=1;i<=m;i++)
    if (c[i] >= 10) 
    {
      if (c[m] >= 10)
        m++;
      c[i + 1] += c[i] / 10;
      c[i] %= 10;
    }
  for (i = m; i >0; i--)
  printf("%d", c[i]);
  printf("\n");
}