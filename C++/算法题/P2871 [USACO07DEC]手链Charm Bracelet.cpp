#include <iostream>
#include <string>
using namespace std;
struct goods {
  int c, w, v;
};
int main(){
  int n, m;
  while(cin>>n>>m){
    int f[m + 1];
    goods s[n];
    memset(f, -10, sizeof(f)),f[0]=0;
    for (int i = 0; i < n; i++) {
      cin >> s[i].c >> s[i].w;
      for (int j = s[i].c; j <= m; j++)
        f[j] = max(f[j], f[j - s[i].c] + s[i].w);
      cout << f[m] << endl;
    }
    cout << f[m] << endl;
  }
  return 0;
}
/*
题目描述

Bessie has gone to the mall's jewelry store and spies a charm
 bracelet. Of course, she'd like to fill it with the best charms
  possible from the N (1 ≤ N ≤ 3,402) available charms. Each
   charm i in the supplied list has a weight Wi (1 ≤ Wi ≤ 400), 
   a 'desirability' factor Di (1 ≤ Di ≤ 100), and can be used at
    most once. Bessie can only support a charm bracelet whose 
    weight is no more than M (1 ≤ M ≤ 12,880).

Given that weight limit as a constraint and a list of the 
charms with their weights and desirability rating, deduce 
the maximum possible sum of ratings.

有N件物品和一个容量为V的背包。第i件物品的重量是c[i]，价值是w[i]。求解将哪些物品装入背包可使这些物品的重量总和不超过背包容量，且价值总和最大。

输入输出格式

输入格式：
* Line 1: Two space-separated integers: N and M

* Lines 2..N+1: Line i+1 describes charm i with two 
space-separated integers: Wi and Di

第一行：物品个数N和背包大小M

第二行至第N+1行：第i个物品的重量C[i]和价值W[i]

输出格式：
* Line 1: A single integer that is the greatest sum of 
charm desirabilities that can be achieved given the 
weight constraints

输出一行最大价值。

输入输出样例

输入样例#1： 复制
4 6
1 4
2 6
3 12
2 7
输出样例#1： 复制
23
*/