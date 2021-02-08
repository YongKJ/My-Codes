#include <stdio.h>
int main()
{
  int a[4][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
  int(*p)[3] = a;
  int i, j, s1 = 0, s2 = 0;
  for (i=0;i<2;i++)
    for (j = 0; j < 3; j++) 
    {
      s1 += (*(p + i))[j];
      s2 += *(p + i)[j];
    }
  printf("s1=");
  for (i = 0; i < 2; i++)
    for (j = 0; j < 3; j++)
      printf("%d+", (*(p + i))[j]);
  printf("\b=%d\n", s1);
  printf("s2=");
  for (i = 0; i < 2; i++)
    for (j = 0; j < 3; j++)
      printf("%d+", *(p + i)[j]);
  printf("\b=%d\n", s2);
}