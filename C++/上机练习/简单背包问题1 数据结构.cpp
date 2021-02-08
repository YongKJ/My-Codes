#include <iostream>
#include <map>
using namespace std;
int W, n, w, t, s;
map<int, int> x,y;
void dfs() {
  if (s == W)
    t = 1;
  for (int i = 1; i <= n; i++)
    if (y[i] == 0)
      y[i] = 1, s += x[i], dfs(), y[i] = 0, s -= x[i];
}
int main(){
  while (t = s = 0, cin >> W >> n) {
    for (int i = 1; i <= n; i++)
      cin >> w, x[i] = w, y[i] = 0;
    dfs(), cout << (t ? "YES" : "NO") << endl;
  }
  return 0;
}
            
/*
描述


设有一个背包可以放入的物品重量为S，现有n件物品，
重量分别是w1，w2，w3，…wn。 
问能否从这n件物品中选择若干件放入背包中，
使得放入的重量之和正好为S。 
如果有满足条件的选择，则此背包有解，否则此背包问题无解。
输入


输入数据有多行，包括放入的物品重量为s，物品的件数n，
以及每件物品的重量（输入数据均为正整数）

多组测试数据。

输出


对于每个测试实例，若满足条件则输出“YES”，若不满足则输出“NO“

样例输入

20 5
1 3 5 7 9

样例输出

YES

提示

使用递归函数
*/