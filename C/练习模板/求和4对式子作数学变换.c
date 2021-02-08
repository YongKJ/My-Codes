#include <stdio.h>
int main() 
{
  int i;
  float s = 0,j=1;
  for (i = 1; i <= 100; i++)
 {
    s =s+ j / i;
    j = -j;
  }
  printf("s=%f", s);
}