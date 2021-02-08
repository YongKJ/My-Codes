#include <stdio.h>
int main() 
{
  int i;
  double p,s=0,j=1.0;
  for (i = 1; 1.0 / i >= 1e-7; i += 2) {
    s += j / i;
    j = -j;
  }
  p = 4 * s;
  printf("π=%lf", p);
}