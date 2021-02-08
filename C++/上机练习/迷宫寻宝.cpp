#include <iostream>
#include <string>
#include <set>
using namespace std;
char Map[15][15];
set<int> p;
int dp[15][15], s[4][2] = {-1, 0, 1, 0, 0, -1, 0, 1}, n, m, x, y, sum;
void dfs(int a, int b) {
  if(a==x&&b==y)
    p.insert(sum);
  for (int i = 0; i < 4; i++) {
    int x1 = a + s[i][0], y1 = b + s[i][1];
    if (0 <= x1 && x1 < n && 0 <= y1 && y1 < m && dp[x1][y1] == 0) {
      dp[x1][y1] = 1, sum++;
      dfs(x1, y1);
      dp[x1][y1] = 0, sum--;
    }
  }
}
int main(){
  int t,a,b;
  cin >> t;
  while(t--&&cin>>n>>m&&memset(dp,0,sizeof(dp))){
    for (int i=0;i<n;i++)
      for (int j = 0; j < m; j++) {
        cin >> Map[i][j];
        if (Map[i][j] == 'Y')
          a = i, b = j;
        else if (Map[i][j] == 'T')
          x = i, y = j;
        else if (Map[i][j] == '#')
          dp[i][j] = -1;
      }
    p.clear(), sum = 0, dfs(a, b);
    if (p.begin() == p.end())
      cout << "Impossible." << endl;
    else
      cout << *p.begin() << endl;
  }
  return 0;
}
        
/*
输入


有TN个测试数据；

我会给你一个迷宫，我会将它表示成矩阵形式，其中‘#’表示墙，
你是穿不过的。‘=’表示路，你当前所在的位置标记为‘Y’，
你要去的地方标记为‘T’。

 第一行为TN，

每个测试数据包含以下信息：

第一行：行M，列N（M,N>1&&M,N<21）

以下M行N列的矩阵就是迷宫信息了。


输出


    寻找一条路径可到目的地的，如果你去不了，
    输出“Impossible.”，否则输出你可到目的地的最少步数
    （也就是要走的方格数）。你的行动方向只能是上下左右。

样例输入

2
6 14
##===#======##
==T==###=###=#
##=#=#===#===#
====#=#=#####=
##===Y=#==##==
###=#==###=#==
4 8
==Y=##=#
==##==##
##==T=##
=#=##=##


样例输出

6
Impossible.
*/