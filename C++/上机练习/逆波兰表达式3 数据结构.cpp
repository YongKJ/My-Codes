#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
char s[20];
double lan() {
  cin >> s;
  if(strlen(s)==1&&!(s[0]>='0'&&s[0]<='9'))
    switch (s[0]) {
    case '+':
      return lan() + lan();
    case '-':
      return lan() - lan();
    case '*':
      return lan() * lan();
    case '/':
      return lan() / lan();
    }
  else
    return atof(s);
}
int main() {
  cout << fixed << setprecision(6) << lan() << endl;
  return 0;
}
/*
描述


逆波兰表达式是一种把运算符前置的算术表达式，
例如普通的表达式2 + 3的逆波兰表示法为+ 2 3。
逆波兰表达式的优点是运算符之间不必有优先级关系，
也不必用括号改变运算次序，例如(2 + 3) * 4的逆波兰表示法为
* + 2 3 4。本题求解逆波兰表达式的值，其中运算符包括+ - * /四个。

输入


输入为一行，其中运算符和运算数之间都用空格分隔，
运算数是浮点数。

输出


输出为一行，表达式的值。
可直接用printf("%f\n", v)输出表达式的值v。

样例输入

* + 11.0 12.0 + 24.0 35.0

样例输出

1357.000000

提示


1、可使用atof(str)把字符串转换为一个double类型的浮点数。
atof定义在math.h中。
2、使用函数递归调用的方法求解。
*/