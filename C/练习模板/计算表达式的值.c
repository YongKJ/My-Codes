#include <stdio.h>
int main() 
{
  char op;
  float data1, data2,s;
  printf("请输入表达式:");
  scanf("%f %c %f", &data1, &op, &data2);
  switch (op) {
  case '+':
    s = data1 + data2;
    break;
  case '-':
    s = data1 - data2;
    break;
  case '*':
    s = data1 * data2;
    break;
  case '/':
    s = data1 / data2;
    break;
  }
  printf("%7.2f %c% 7.2f = %7.2f", data1, op, data2, s);
}