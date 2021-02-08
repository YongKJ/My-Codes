#include <stdio.h>
#define PI 3.14159
#define AREA(r) PI*r*r
void main() {
  float x, s;
  x = 10.0;
  s = AREA(x);
  printf("%.1f\n", s);
}