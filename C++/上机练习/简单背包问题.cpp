#include <iostream>
using namespace std;
int sum, s, n, map[20], out[20], d[20], flag;
void dfs(int x,int y) {
  if (sum >= s) {
    if (sum == s) {
      for (int i = 0; i < x; i++)
        cout << out[i] << " ";
      cout << endl, flag = 1;
    }
    return;
  }
  for (int i = y; i < n; i++)
    if (d[i] == 0) {
      d[i] = 1, sum += map[i], out[x] = map[i];
      dfs(x + 1, i);
      d[i] = 0, sum -= map[i], out[x] = 0;
    }
}
int main() {
  int t = 0;
  while (flag = 0, t++, sum = 0, memset(d, 0, sizeof(d)), cin >> s >> n) {
    for (int i = 0; i < n; i++)
      cin >> map[i];
    cout << "Case " << t << ":" << endl, dfs(0, 0);
    if (flag == 0)
      cout << "No" << endl;
  }
  return 0;
}
/*
描述


设有一个背包，可以存放的重量为s。
现有n件物品，重量分别为w1、w2、
…………wn。从n件物品中选择若干件，
使得放入背包的物品的重量之和刚好为s。
输出所有可能的解。

输入


包含多组测试数据。

第1行为重量为s和物品件数n。

第2行是n件物品的重量分别为w1、w2、…………wn。

 

输出


所有可能的解。如果没有解，输出“No”

样例输入

10 5
1 2 3 4 5
20 5
1 2 3 4 5

样例输出

Case 1:
1 2 3 4
1 4 5
2 3 5
Case 2:
No
*/