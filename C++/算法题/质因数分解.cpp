#include <iostream>
#include <cmath>
using namespace std;
int judge(int i) {
  int j, flag = 0;
  if (i == 2)
    return 1;
  for (j = 2; j <= sqrt(i); j++) {
    if (!(i % j))
      break;
  }
  if (i % j)
    flag = 1;
  return flag;
}
int main(){
  int n;
  while (cin >> n) {
    int ans = 1, t = 1;
    for (int i = 2; i <= n; i++)
      if (judge(i) && !(n % i))
        t *= i, ans = max(ans, i), n /= t;
    cout << ans << endl;
  }
  return 0;
}
/*
题目描述

已知正整数nn是两个不同的质数的乘积，试求出两者中较大的那个质数。

输入输出格式

输入格式：
一个正整数nn。

输出格式：
一个正整数pp，即较大的那个质数。

输入输出样例

输入样例#1： 复制
21
输出样例#1： 复制
7
说明

n2109n≤2×10 
9
 
NOIP 2012 普及组 第一题
*/