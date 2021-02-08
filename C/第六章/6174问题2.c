#include <stdio.h>
int compare(int number)
{
  int i = 0, j, t, a[100] = {0}, smaller, bigger, number_t;
  while (number) 
  {
    a[i++] = number % 10;
    number /= 10;
  }
  for (i = 0; i < 4; i++)
    for (j = i + 1; j < 4; j++)
      if (a[i] > a[j])
        t = a[i], a[i] = a[j], a[j] = t;
  smaller = a[0] * 1000 + a[1] * 100 + a[2] * 10 + a[3];
  bigger = a[3] * 1000 + a[2] * 100 + a[1] * 10 + a[0];
  number_t = bigger - smaller;
  return number_t;
}
int main()
{
  int number, number_1, n, k;
  scanf("%d", &n);
  while (n != 0) 
  {
    scanf("%d", &number);
    number_1 = compare(number);
    k = 1;
    while (1)
      if (number_1 != 6174)
        k++, number_1 = compare(number_1);
      else
        break;
    printf("%d\n", ++k);
    n--;
  }
}