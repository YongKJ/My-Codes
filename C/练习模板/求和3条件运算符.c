#include <stdio.h>
void main() 
{
  int i;
  float s = 0;
  for (i=1;i<=100 ;i++ ) 
  s += (i % 2 != 0) ? 1.0 / i : -1.0 / i;
  printf("s=%f", s);
}