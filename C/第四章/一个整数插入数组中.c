#include <stdio.h>
int main()
{
  int a[6] = {11,26, 38, 73, 91};
  int i, j, t,n;
  for (i = 0; i < 5; i++)
    printf("%d  ", a[i]);
  printf("\n");
  scanf("%d", &n);
  a[5] = n;
  for (i = 0; i < 5; i++) 
  {
    for (j = 0; j < 5 - i;j++)
      if (a[j] > a[j + 1]) 
      {
        t = a[j];
        a[j] = a[j + 1];
        a[j + 1] = t;
      }
  }
  for (i = 0; i < 6; i++)
    printf("%d  ", a[i]);
}