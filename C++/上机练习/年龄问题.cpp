#include <iostream>
using namespace std;
int n, m, k, sum;
void age(int x) {
  if (x == 1)
    sum += k;
  else
    sum += m, age(x - 1);
}
int main() {
  while (sum = 0, cin >> n >> m >> k)
    age(n), cout << sum << endl;
  return 0;
}
	
	
/*
描述

有n个人坐在一起，问第n个人多少岁？
他说比第n-1个人大m岁。问第n-1个人
岁数，他说比第n-2个人大m岁。问第
n-2个人，又说比第n-3人大m岁。
......最后问第一个人，他说是K岁。
请问第n个人多大？

 

输入


有多组测试数据。每组一行，
分别输入3个整数 n, m 和k 

输出

输出第n个人的岁数

样例输入

5 2 10

样例输出

18
*/