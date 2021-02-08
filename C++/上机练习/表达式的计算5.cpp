#include <iostream>
#include <string>
#include <stack>
using namespace std;
class Count {
public:
  Count(string s);
  void handle();
  int Priority(char s);
  void f();
  void calculate(char s);

private:
  int x, y, i, tmp;
  string str;
  stack<int> num;
  stack<char> opt;
};
int main() {
  string str;
  while (cin >> str, str[0] != '0')
    Count d1(str);
  return 0;
}
Count::Count(string s) {
  str = s, i = tmp = 0;
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
  while (str[i]!='\0'||!opt.empty()) {
    if ('0' <= str[i] && str[i] <= '9') {
      tmp = tmp * 10 + str[i++] - '0';
      if(str[i]<'0'||str[i]>'9')
        num.push(tmp), tmp = 0;
    }
    else{
      if (opt.empty() || (opt.top() == '(' && str[i] != ')') ||Priority(str[i]) > Priority(opt.top())) {
        opt.push(str[i++]);
        continue;
      }
      if (opt.top() == '(' && str[i] == ')') {
        opt.pop(), i++;
        continue;
      }
      if ((str[i] == '\0' && !opt.empty()) ||(opt.top() != '(' && str[i] == ')') ||Priority(str[i]) <= Priority(opt.top())) {
        calculate(opt.top()), opt.pop();
        continue;
      }
    }
  }
  cout << num.top() << endl;
}
/*
样例输入

3+2+1
3-2-1
1+2*3
0


样例输出

6
0
7
*/