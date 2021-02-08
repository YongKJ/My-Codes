#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
class number {
public:
  number(int a, int b, int c);
  void two(int a);
  void show();

private:
  int n, x, t, j;
  string d[50000];
};
int main() {
  int a, b, c;
  while (cin >> a >> b >> c)
    number d1(a, b, c);
  return 0;
}
number::number(int a, int b, int c) {
  n = a, x = b, t = c, j = 0;
  d[j++] = "0";
  show();
}
void number::two(int a){
  string s;
  int sum=0;
  while (a) {
    sum += (a % 2 ? 1 : 0);
    s += (a % 2 ? '1' : '0');
    a /= 2;
  }
  reverse(s.begin(), s.end());
  if (s.size() <= n && sum <= x)
    d[j++] = s;
}
void number::show() {
  for (int i = 1; i <= pow(2.0, n*1.0); i++)
    two(i);
  for (int i = 1; i <= n - d[t - 1].size();i++)
    cout << 0;
  cout << d[t - 1] << endl;
}
	
  
  
/*
描述


给出3个数：n、x、i。考虑长度为n位的二进制数中，
含有1的个数小于等于x的数，按照从小到大的顺序排列，
求出第i个数。其中n<31

输入

每组包括3个数：n、x、i

输出

第i个数二进制形式。

样例输入

3 3 4
5 3 19

样例输出

011
10011
*/