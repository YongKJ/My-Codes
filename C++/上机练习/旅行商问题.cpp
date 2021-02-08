#include <iostream>
#include <set>
#include <string>
using namespace std;
int n, Map[10][10], s[10][10], sum, y, flag;
set<int> p;
void dfs(int x) {
 // cout << 1 << endl;
  //cout << x << " " << y<<endl;
  if (x == y&&flag==1) {
    //cout << sum << endl;
    p.insert(sum);
    return;
  }
  cout << 1 << endl;
  for (int i=0;i<n;i++)
    if (s[x][i] == 0 && s[i][x] == 0 && x != i) {
      s[x][i] = 1, s[i][x] = 1, sum += Map[x][i];
      //cout << Map[x][i] << endl;
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
          cout << s[i][j] << " ";
        cout << endl;
      }
      cout << endl;
      //cout << 2 << endl;
     flag=1, dfs(i);
      s[x][i] = 0, s[i][x] = 0, sum -= Map[x][i];
    }
    
}
int main(){
  while (memset(s, 0, sizeof(s)), p.clear(), cin >> n) {
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        cin >> Map[i][j];
    for (int i = 0; i < n; i++)
    sum = 0, flag=0,y = 0, dfs(i);
    cout << *p.begin() << endl;
  }
  return 0;
}

/*
描述

旅行推销员问题（Travelling Salesman Problem，
 又称为旅行商问题、货郎担问题、TSP问题）
 是一个多局部最优的最优化问题：有n个城市，
 一个推销员要从其中某一个城市出发，
 唯一走遍所有的城市，再回到他出发的城市，
 求最短的路线长度。

输入


包含多组数据。

每组数据的第1行为n。

接下来有n行，每行n个数，
表示城市之间的距离。第i行的第j个数
表示第i个城市与第j个城市之间的距离。

 

输出

最短的路线长度。

样例输入

3
0 1 2
1 0 3
2 3 0

样例输出

6
*/