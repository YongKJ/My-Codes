#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
char c[20];
double lan() {
  cin >> c;
    switch (c[0]) {
    case '+':return lan() + lan();
    case '-':return lan() - lan();
    case '*':return lan() * lan();
    case '/':return lan() / lan();
    default:return atof(c);
    }
}
int main() {
  printf("%f\n", lan());
  return 0;
}