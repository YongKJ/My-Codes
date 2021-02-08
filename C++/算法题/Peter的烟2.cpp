#include <iostream>
using namespace std;
int main(){
  int n, k;
  while (cin >> n >> k) {
    int sum = n;
    while (n / k)
      sum += n / k, n = n / k + n % k;
    cout << sum << endl;
  }
  return 0;
}
/*
题目描述

Peter 有n根烟，他每吸完一根烟就把烟蒂保存起来，
k(k>1)个烟蒂可以换一个新的烟，那么 Peter 最终
能吸到多少根烟呢？

输入输出格式

输入格式：
每组测试数据一行包括两个整数n,k(1<n,k≤10 
8
 )。

输出格式：
对于每组测试数据，输出一行包括一个整数表示最终烟的根数。

输入输出样例

输入样例#1： 复制
4 3
输出样例#1： 复制
5
输入样例#2： 复制
10 3
输出样例#2： 复制
14
说明

1<n,k≤10 
8
*/