#include <iostream>
#include <cstring>
using namespace std;
int main(){
  int n, m;
  while (cin >> n >> m) {
    int s[n + 1], f[m + 1];
    memset(f, 0, sizeof(f)), f[0] = 1;
    for (int i = 1; i <= n; i++)
      cin >> s[i];
    for (int i = 1; i <= n; i++)
      for (int j = m; j >= s[i]; j--)
        f[j] = f[j] + f[j - s[i]];
    cout << f[m] << endl;
  }
  return 0;
}
/*
题目背景

uim神犇拿到了uoi的ra（镭牌）后，立刻拉着
基友小A到了一家……餐馆，很低端的那种。

uim指着墙上的价目表（太低级了没有菜单），
说：“随便点”。

题目描述

不过uim由于买了一些辅（e）辅（ro）书，
口袋里只剩MM元M10000(M≤10000)。

餐馆虽低端，但是菜品种类不少，有NN种N100
(N≤100)，第ii种卖aia 
i
​	 元ai1000(a 
i
​	 ≤1000)。由于是很低端的餐馆，所以每种菜
只有一份。

小A奉行“不把钱吃光不罢休”，所以他点单一定刚
好吧uim身上所有钱花完。他想知道有多少种点菜
方法。

由于小A肚子太饿，所以最多只能等待11秒。

输入输出格式

输入格式：
第一行是两个数字，表示NN和MM。

第二行起NN个正数aia 
i
​	 （可以有相同的数字，每个数字均在
10001000以内）。

输出格式：
一个正整数，表示点菜方案数，保证答案
的范围在intint之内。

输入输出样例

输入样例#1： 复制
4 4
1 1 2 2
输出样例#1： 复制
3
*/