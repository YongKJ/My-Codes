#include <iostream>
#include <map>
using namespace std;
int main(){
  int n, m;
  while (cin >> n >> m) {
    map<int, int> s;
    map<int, int>::iterator p;
    for (int i = 0; i < 10; i++)s[i] = 0;
    for (int i = n; i <= m; i++)
      for (int j = i; j; j /= 10)
        if (s.find(j % 10) != s.end())
          s[j % 10]++;
    for (p = s.begin(); p != s.end();)
      cout << p->second << (++p != s.end() ? " " : "\n");
  }
  return 0;
}
/*
题目背景

Bessie 处于半梦半醒的状态。过了一会儿，她意识到她在数数，不能入睡。

题目描述

Bessie的大脑反应灵敏，仿佛真实地看到了她数过的一个又一个数。她开始注意
每一个数码(0..9)：每一个数码在计数的过程中出现过多少次？

给出两个整数M 和N (1 ≤M ≤N ≤2,000,000,000 以及N-M ≤500,000)，求
每一个数码出现了多少次。

例如考虑序列129--137: 129, 130, 131, 132, 133, 134, 135, 136, 137。
统计后发现：

0出现了1次，1出现了10次，2出现了2次，3出现了9次，4出现了1次，
5出现了1次，

6出现了1次，7出现了1次，8出现了0次，9出现了1次。

输入输出格式

输入格式：
第1行: 两个用空格分开的整数M 和N

输出格式：
第1行: 十个用空格分开的整数，分别表示数码(0..9)在序列中出现的次数。

输入输出样例

输入样例#1： 复制
129 137
输出样例#1： 复制
1 10 2 9 1 1 1 1 0 1
*/