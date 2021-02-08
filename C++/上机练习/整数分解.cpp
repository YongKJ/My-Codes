#include <iostream>
using namespace std;
int main(){
  int t;
  cin >> t;
  while (t--) {
    int  n, m;
    long sum = 1;
    cin >> n >> m;
    int s[m], i = 0;
    while( n != 2 && n != 4)
      s[i++] = 3, n -= 3;
      while(n)
        s[i++] = 2, n -= 2;
    
  }
  return 0;
}
	
/*
描述

设n是一个正整数。现要求将n分解为k个自然数的和，
且使这些自然数的乘积最大。对于给定的正整数n，
*编程计算最优分解方案。

输入


输入包括多组测试数据，每组1行，分别为n和k。(n<100，k<50)

输出


最大乘积。

样例输入

2
10 3
5 4

样例输出

36
2
*/