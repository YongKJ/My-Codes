#include <iostream>
#include <string>
using namespace std;
const int s[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
int n, m,map[10][10], k[10][10];
void dfs(int x,int y) {
  int x1, y1;
  for (int i = 0; i < 4; i++) {
    x1 = x + s[i][0], y1 = y + s[i][1];
    if (0 <= x1 && x1 < n && 0 <= y1 && y1 < m && map[x1][y1] == 1 &&
        k[x1][y1] == 0)
      k[x1][y1] = 1, dfs(x1, y1);
  }
}
int main(){
  int t;
  cin >> t;
  while (memset(k,0,sizeof(k)),t--) {
    cin >> n >> m;
    int sum = 0;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        cin >> map[i][j], k[i][j] = (map[i][j] == 0 ? -1 : 0);
    cout << endl;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++)
        cout << k[i][j] << " ";
      cout << endl;
    }
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        if (k[i][j] == 0)
          dfs(i, j), sum++;
    cout << sum << endl;
  }
  return 0;
}
/*
描述

学院校园里有一些小河和一些湖泊，现在，
我们把它们通一看成水池，假设有一张我们
学校的某处的地图，这个地图上仅标识了此处
是否是水池，现在，你的任务来了，请用计算
机算出该地图中共有几个水池。

输入

第一行输入一个整数N，表示共有N组测试数据
每一组数据都是先输入该地图的行数m(0<m<100)
与列数n(0<n<100)，然后，输入接下来的m行每行
输入n个数，表示此处有水还是没水（1表示此处是
水池，0表示此处是地面）

输出

输出该地图中水池的个数。
要注意，每个水池的旁边（上下左右四个位置）
如果还是水池的话的话，它们可以看做是同一个水
池。

样例输入

2
3 4
1 0 0 0 
0 0 1 1
1 1 1 0
5 5
1 1 1 1 0
0 0 1 0 1
0 0 0 0 0
1 1 1 0 0
0 0 1 1 1

样例输出

2
3
*/