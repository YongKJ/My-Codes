#include <stdio.h>
void main() 
{
  int a, b, c;
  printf("请输入三角形的三条边长:");
  scanf("%d%d%d", &a, &b, &c);
  if (a + b > c && a + c > b && b + c > a)
    if (a * a + b * b == c * c||a*a+c*c==b*b||b*b+c*c==a*a)
      printf("yes");
    else
      printf("no");
  else
    printf("not a triangle");
}