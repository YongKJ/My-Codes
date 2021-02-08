#include <iostream>
using namespace std;
int x, y, z;
int number(int n) {
  int t;
  if (n == 0)
    return z;
  if (n == 1)
    return x % z;
  t = number(n / 2);
  t = (t * t) % z;
  if (n % 2 != 0)
    t = (t * x) % z;
  return t;
}
int main() {
  while (cin >> x >> y >> z)
    cout << number(y) << endl;
  return 0;
}
/*
描述


给你三个数X(1<=X<=10^100)、
Y(1<=Y<=10^8)、Z(1<=Z<=10^4),
你能计算出X^Y%Z的值吗？

其中：X^Y表示X的Y次方。

输入


输入三个如上所描述的数X、Y、Z。多组输入。

输出


输出X^Y%Z的值。

样例输入

2 3 5
12345  2345  345 

样例输出

3
240

提示


注意：x的范围

大数除法、快速乘方
*/