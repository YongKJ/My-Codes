#include <stdio.h>
int main()
{
  int n,x, a[21],i,j;
 while( scanf("%d", &x)!=EOF)
 {
  n = x;
  i = 1;
  while (x) 
   {
    a[i++] = x % 10;
    x /= 10;
   }
   for (j = 1; j <= i / 2; j++)
     if (a[j] != a[i - j])
       break;
   if (a[j] != a[i - j])
     printf("%d不是回文数\n", n);
   else
     printf("%d是回文数\n", n);
 }
}