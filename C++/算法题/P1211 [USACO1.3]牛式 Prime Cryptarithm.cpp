#include <iostream>
using namespace std;
int p[10];
int f(int n);
int check(int x, int y);
int main() {
  int key, n, ans = 0;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> key, p[key] = 1;
  for (int i = 100; i < 1000; i++)
    for (int j = 10; j < 100; j++)
      if (check(i, j))
        ans++;
  cout << ans << endl;
  return 0;
}
int check(int x, int y) {
  int test = x * y, a = x * (y % 10), b = x * (y / 10);
  if (a > 999 || b > 999 || test > 9999)
    return 0;
  if (f(x) && f(y) && f(a) && f(b) && f(test))
    return 1;
  else
    return 0;
}
int f(int n){
  while (n) {
    if (!p[n % 10])
      return 0;
    n /= 10;
  }
  return 1;
}
	
/*
题目描述
下面是一个乘法竖式，如果用我们给定的那n个
数字来取代*，可以使式子成立的话，我们就叫
这个式子牛式。

          ***
    x     **
   ----------
         ***
        ***
   ----------
        ****
（请复制到记事本）

数字只能取代*，当然第一位不能为0,况且给定的
数字里不包括0。

注意一下在美国的学校中教的“部分乘积”，第一
部分乘积是第二个数的个位和第一个数的积，第
二部分乘积是第二个数的十位和第一个数的乘积.

写一个程序找出所有的牛式。

输入输出格式
输入格式：
Line 1:数字的个数n。

Line 2:N个用空格分开的数字（每个数字都属于
{1,2,3,4,5,6,7,8,9}）。

输出格式：
共一行，一个数字。表示牛式的总数。

输入输出样例
输入样例#1： 
5
2 3 4 6 8
输出样例#1： 
1
说明
题目翻译来自NOCOW。

USACO Training Section 1.3
*/