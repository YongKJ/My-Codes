#include <iostream>
#include <string>
using namespace std;
const int s[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {-1, 0}};
int n, m, sum, count1[20][20];
char map[20][20];
void dfs(int x, int y) {
  int x1, y1;
  if(map[x][y]=='#')
    return;
    for (int i = 0; i < 4; i++) {
      x1 = x + s[i][0], y1 = y + s[i][1];
      //cout << x1 << " " << y1 << endl;
      if (0 <= x1 && x1 < n && 0 <= y1 && y1 < m && map[x1][y1] != '#'&&count1[x1][y1]==0){
        count1[x1][y1] = 1, sum++;
        cout << x1 << " " << y1 << endl;
        for (int i = 0; i < n; i++) {
          for (int j = 0; j <m ; j++)
            cout << count1[i][j] << " ";
          cout << endl;
        }
        cout << endl;
        dfs(x1, y1);
      }
    }
}
int main(){
  while (sum = 0, cin >> n >> m, n + m) {
    memset(count1, 0, sizeof(count1));
    for (int i = 0; i < n; i++)
      cin >> map[i];
    //cout << map[i] << endl;
    dfs(0, 0), cout << sum << endl;
    
    cout << 2 << endl;
  }
  return 0;
}
/*
描述

有一间长方形的房子，地上铺了红色、黑色两种颜色的
正方形瓷砖。你站在其中一块黑色的瓷砖上，只能向相
邻的黑色瓷砖移动。请写一个程序，计算你总共能够到
达多少块黑色的瓷砖。

输入

包括多个数据集合。每个数据集合的第一行是两个整数W
和H，分别表示x方向和y方向瓷砖的数量。W和H都不超
过20。在接下来的H行中，每行包括W个字符。每个字符
表示一块瓷砖的颜色，规则如下
1）‘.’：黑色的瓷砖；
2）‘#’：白色的瓷砖；
3）‘@’：黑色的瓷砖，并且你站在这块瓷砖上。
该字符在每个数据集合中唯一出现一次。
当在一行中读入的是两个零时，表示输入结束。

输出

对每个数据集合，分别输出一行，显示你从初始位置
出发能到达的瓷砖数(记数时包括初始位置的瓷砖)。

样例输入

3 4
..#.
@..#
##..
0 0

样例输出

7
*/