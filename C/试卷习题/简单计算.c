#include <stdio.h>
#include <stdlib.h>
int main()
{
  int data1, data2,s;
  char op;
  scanf("%d%c%d", &data1, &op, &data2);
  switch (op) 
  {
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
  default:
    exit(0);
  }
  printf("%d%c%d=%d\n", data1,op,data2,s);
}