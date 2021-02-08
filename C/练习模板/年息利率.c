#include <stdio.h>
void main() {
  float b, y;
  double a, sum;
  printf("请输入本金(单位:元)和存款期限(单位:年):");
  scanf("%f%f", &b, &y);
  switch ((int)y) {
  case 1:
    a = b * 2.5 * 0.01;
    break;
  case 2:
    a = b * 3.00 * 0.01;
    break;
  case 3:
    a = b * 3.5 * 0.01;
    break;
  case 4:
    a = b * 4.00 * 0.01;
    break;
  case 5:
    a = b * 4.5 * 0.01;
    break;
  default:
    a = b * 2.00 * 0.01;
    break;
  }
  sum = a + b;
  printf("存款到期时的利息:%f\n利息与本金的和:%f\n", a, sum);
}
