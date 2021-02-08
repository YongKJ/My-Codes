#include <stdio.h>
void main() 
{
  float a, b, c, d, m, n, max, min;
  printf("请输入四科成绩:");
  scanf("%f%f%f%f", &a, &b, &c, &d);
  m = a + b + c + d;
  n = m / 4;
  max = a > b ? a : b;
  max = max > c ? max : c;
  max = max > d ? max : d;
  min = a < b ? a : b;
  min = min < c ? min : c;
  min = min < d ? min : d;
  printf("总分=%7.2f\n平均分=%7.2f\n最高分=%7.2f\n最低分=%7.2f\n", m, n, max,
         min);
}