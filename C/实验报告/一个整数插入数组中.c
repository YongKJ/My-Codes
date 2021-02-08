#include <stdio.h>
int main()
{
  int a[6] = {11,26, 38, 73, 91};
  int i, j, t;
  for (i = 0; i < 5; i++)
    printf("%d  ", a[i]);
  printf("\n");
  scanf("%d", &a[5]);
  for (i = 0; i < 6; i++) 
    for (j = i+1; j < 6;j++)
      if (a[i] > a[j])
        t = a[j], a[j] = a[i], a[i] = t;
  for (i = 0; i < 6; i++)
    printf("%d  ", a[i]);
  return 0;
}