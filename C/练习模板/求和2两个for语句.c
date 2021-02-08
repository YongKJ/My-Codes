#include <stdio.h>
void main() 
{
  int i;
  float s;
  for (i = 1; i <= 99; i += 2)
    s = s + 1.0 / i;
  for (i = 2; i <= 100; i += 2)
    s = s - 1.0 / i;
  printf("s=%f", s);
}
  