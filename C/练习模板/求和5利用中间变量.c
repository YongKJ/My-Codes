#include <stdio.h>
void main() 
 {
  int i;
  float s = 0;
  for (i = 1; i <= 100; i += 2)
    s = s + (1.0 / i - 1.0 / (i + 1));
  printf("s=%f", s);
}
  