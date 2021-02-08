#include <iostream>
#include <stack>
using namespace std;
int main() {
  int n;
  stack<int> x;
  cin >> n;
  while (n)
    x.push(n % 5), n /= 5;
  while (!x.empty())
    cout << x.top(), x.pop();
  cout << endl;
  return 0;
}
/*
描述


输入一个十进制整数n，输出它对应的5进制。

要求使用堆栈。

输入


一个十进制整数n。

输出


n对应的5进制形式。

样例输入

13


样例输出

23
*/