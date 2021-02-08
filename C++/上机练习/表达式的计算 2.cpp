#include <iostream>
#include <string>
#include <stack>
#include <iomanip>
#include <cmath>
using namespace std;
class Count {
public:
  Count(string s);
  void handle();
  int Priority(char s);
  void f();
  void calculate(char s);

private:
  int  i, t;
  float x, y, tmp;
  string str;
  stack<float> num;
  stack<char> opt;
};
int main() {
  int t;
  string str;
  cin >> t;
  while (t-- && cin >> str)
    Count d1(str);
  return 0;
}
Count::Count(string s) {
  str = s, i = tmp = t = 0;
  handle();
}
int Count::Priority(char s){
  switch (s) {
  case '(':return 3;
  case '*':case '/':return 2;
  case '+':case '-':return 1;
  default:return 0;
  }
}
void Count::f() { y = num.top(), num.pop(), x = num.top(), num.pop(); }
void Count::calculate(char s){
  switch (s) {
  case '+':f(), num.push(x + y);break;
  case '-':f(), num.push(x - y);break;
  case '*':f(), num.push(x * y);break;
  case '/':f(), num.push(x / y);
  }
}
void Count::handle(){
  while (str[i]!='='||!opt.empty()) {
    if ('0' <= str[i] && str[i] <= '9') {
      if(t==0)
      tmp = tmp * 10 + str[i++] - '0';
      else
        tmp += (str[i] - '0') * pow(10.0, t - i), i++;
      if((str[i]<'0'||str[i]>'9')&&str[i]!='.')
        num.push(tmp), tmp = t = 0;
    }
    else{
      if (str[i] == '.') {
        t = i++;continue;
      }
      if (opt.empty() || (opt.top() == '(' && str[i] != ')') ||Priority(str[i]) > Priority(opt.top())) {
        opt.push(str[i++]);
        continue;
      }
      if (opt.top() == '(' && str[i] == ')') {
        opt.pop(), i++;
        continue;
      }
      if ((str[i] == '=' && !opt.empty()) ||(opt.top() != '(' && str[i] == ')') ||Priority(str[i]) <= Priority(opt.top())) {
        calculate(opt.top()), opt.pop();
        continue;
      }
    }
  }
  cout << fixed << setprecision(2) << num.top() << endl;
}
/*
描述


ACM队的mdd想做一个计算器，但是，他要做的不仅仅是一计算一个A+B的计算器，他想实现随便输入一个表达式都能求出它的值的计算器，现在请你帮助他来实现这个计算器吧。
比如输入：“1+2/4=”，程序就输出1.50（结果保留两位小数）

输入


第一行输入一个整数n，共有n组测试数据（n<10)。
每组测试数据只有一行，是一个长度不超过1000的字符串，表示这个运算式，每个运算式都是以“=”结束。这个表达式里只包含+-* /与小括号这几种符号。其中小括号可以嵌套使用。数据保证输入的操作数中不会出现负数。
数据保证除数不会为0

输出


每组都输出该组运算式的运算结果，输出结果保留两位小数。

样例输入

3
1.000+2/4=
((1+2)*5+1)/4=
(1.02+2*1.03)/4=

样例输出

1.50
4.00
0.77
*/