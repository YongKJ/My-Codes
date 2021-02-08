#include <stdio.h>
#include <math.h>
int main() {
  int i, j, k=0;
  for (i = 100; i <= 200; i++) {
    for (j = 2; j <= sqrt(i); j++)
      if (i % j == 0)
        break;
    if (i % j != 0)
      printf("%d ", i), k++;
    if (k == 5)
      printf("\n"), k = 0;
  }
}