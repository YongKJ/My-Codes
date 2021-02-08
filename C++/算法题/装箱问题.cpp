#include <iostream>
using namespace std;
int main(){
  int m, n, x;
  while(cin>>m>>n){
    int f[m + 1];
    for (int i=0;i<=m;i++)f[i] = m;
    for (int i = 0; i < n; i++) {
      cin >> x;
      for (int j = m; j >= x; j--)
        f[j] = min(f[j], f[j - x] - x);
    }cout << f[m] << endl;
  }
  return 0;
}
    
/*
题目描述

有一个箱子容量为VV（正整数，0V200000≤V≤20000），
同时有nn个物品（0n300<n≤30，每个物品有一个体积
（正整数）。

要求nn个物品中，任取若干个装入箱内，使箱子的剩余
空间为最小。

输入输出格式

输入格式：
11个整数，表示箱子容量

11个整数，表示有nn个物品

接下来nn行，分别表示这nn个物品的各自体积

输出格式：
11个整数，表示箱子剩余空间。

输入输出样例

输入样例#1： 复制
24
6
8
3
12
7
9
7
输出样例#1： 复制
0
说明

NOIp2001普及组 第4题
*/