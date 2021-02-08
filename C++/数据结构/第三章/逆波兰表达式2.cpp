#include <iostream>
#include <string>
#include <stack>
#include <cstdlib>
#include <iomanip>
using namespace std;
int main(){
  string s, x;
  stack<string> p;
  stack<double> q;
  do {
    cin >> s;
    p.push(s);
  } while (getchar() != '\n');
  //x = p.top(), p.pop();
  while(!p.empty()){
    x = p.top(), p.pop();
    double x1, x2;
    switch (x[0]) {
    case '+':
      x1 = q.top(), q.pop(), x2 = q.top(), q.pop(), q.push(x2 + x1);
      cout << x2 + x1 << endl;
      break;
    case '-':
      x1 = q.top(), q.pop(), x2 = q.top(), q.pop(), q.push(x2 - x1);
      cout << x2 - x1 << endl;
      break;
    case '*':
      x1 = q.top(), q.pop(), x2 = q.top(), q.pop(), q.push(x2 * x1);
      cout << x2 * x1 << endl;
      break;
    case '/':
      x1 = q.top(), q.pop(), x2 = q.top(), q.pop(), q.push(x2 / x1);
      cout << x2 / x1 << endl;
      break;
    default:
      q.push(atof(&x[0]));
      //cout << atof(&x[0]) << endl;
    }
    //x = p.top(), p.pop();
  }
  cout << fixed << setprecision(6) << q.top() << endl;
  return 0;
}
	
/*
描述


逆波兰表达式是一种把运算符前置的
算术表达式，例如普通的表达式2 + 3
的逆波兰表示法为+ 2 3。逆波兰表达
式的优点是运算符之间不必有优先级
关系，也不必用括号改变运算次序，例
如(2 + 3) * 4的逆波兰表示法为* + 2 3 4。
本题求解逆波兰表达式的值，其中运算符
包括+ - * /四个。

输入


输入为一行，其中运算符和运算数之间
都用空格分隔，运算数是浮点数。

输出


输出为一行，表达式的值。
可直接用printf("%f\n", v)输出表达式的值v。

样例输入

* + 11.0 12.0 + 24.0 35.0

      35
+    24                59
+    12       +      12
*     11       *      11

样例输出

1357.000000

提示


1、可使用atof(str)把字符串转换
为一个double类型的浮点数。atof
定义在math.h中。
2、使用函数递归调用的方法求解。

题目来源

数据结构
*/