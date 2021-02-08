#include <stdio.h>
int main()
{
  int i=1,n=1;
  double s = 1,t;
  do
  {
    n *= i;
    t = 1.0 / n;
    s += t;
    i++;
  } while (t >=1e-6);
  printf("e=%f\n", s);
}
  
  