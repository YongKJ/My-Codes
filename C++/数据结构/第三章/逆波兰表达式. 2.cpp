#include <iostream>
#include <stack>
using namespace std;
float expr() {
  char x;
  float num = 0, t, x1, x2;
  stack<float> p;
  for (x=getchar();x!='$';num=0,x=getchar())
    switch (x) {
    case ' ':
      break;
    case '+':
      x1 = p.top(), p.pop(), x2 = p.top(), p.pop(), p.push(x2 + x1);
      break;
    case '-':
      x1 = p.top(), p.pop(), x2 = p.top(), p.pop(), p.push(x2 - x1);
      break;
    case '*':
      x1 = p.top(), p.pop(), x2 = p.top(), p.pop(), p.push(x2 * x1);
      break;
    case '/':
      x1 = p.top(), p.pop(), x2 = p.top(), p.pop(), p.push(x2 / x1);
      break;
    default:
      while (('0' <= x && x <= '9') || x == '.')
        if (x != '.')
          num = num * 10 + x - '0', x = getchar();
        else
          for (t = 10, x = getchar(); '0' <= x && x <= '9'; t *= 10, x = getchar())
            num += (x - '0') / t;
      p.push(num);
    }
  cout << "后缀表达式的值为";
  return p.top();
}
int main() {
  int t = 3;
  while (t--)
    cout << expr() << endl;
  return 0;
}
/*
输入:
234 34 + 2 * $
1 1 + $
12.47 11.29 - $

输出:
536
2
1.18
	
*/