#include <iostream>
#include <map>
using namespace std;
int main(){
  int n,m=0;
  map<int, int> x;
  cin >> n;
  for (int i=1;i<=n;i++)
    x[i] = 1;
  for (int i = 2; i <= n; i++)
    for (int j = 1; j <= n; j++) {
      if (j % i == 0)
        x[j] = !x[j];
      if (i == n && x[j])
        m++;
    }
  for (int i = 1, j = 0; i <= n; i++)
    if (x[i])
      cout << i << (++j != m ? " " : "\n");
  return 0;
}
/*
题目背景

该题的题目是不是感到很眼熟呢?

事实上，如果你懂的方法，该题的代码简直不能再短。

但是如果你不懂得呢？那。。。（自己去想）

题目描述

首先所有的灯都是关的（注意是关！），编号为1的人走过来，把是一的倍数的灯全部打开，编号为二的的把是二的倍数的灯全部关上，编号为3的人又把是三的倍数的灯开的关上，关的开起来……直到第N个人为止。

给定N，求N轮之后，还有哪几盏是开着的。

输入输出格式

输入格式：
一个数N，表示灯的个数和操作的轮数

输出格式：
若干数，表示开着的电灯编号

输入输出样例

输入样例#1： 复制
5
输出样例#1： 复制
1 4
说明

1<=N<=2^40

数学题！
*/