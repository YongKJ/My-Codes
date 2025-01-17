#include <iostream>
using namespace std;
int Min, n, m;
#define Max 0x7fffffff
int s[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
int a[101][101], d[101][101], bl[101][101];
void dfs(int x, int y, int c, int color);
int main() {
  while (cin >> m >> n) {
    int x, y, z;
    for (int i = 1; i <= m; i++)
      for (int j = 1; j <= m; j++)
        d[i][j] = Max, a[i][j] = 0, bl[i][j] = 1;
    for (int i = 1; i <= n; i++)
      cin >> x >> y >> z, a[x][y] = z + 1;
    Min = Max, dfs(1, 1, 0, a[1][1]);
    cout << (Min == Max ? -1 : Min) << endl;
  }
return 0; 
}
void dfs(int x,int y,int c,int color){
  if (x == m && y == m) {
    Min = min(Min, c);
    return;
  }
  for (int i=0;i<4;i++){
    int x1 = x + s[i][0], y1 = y + s[i][1];
    if (1 <= x1 && x1 <= m && 1 <= y1 && y1 <= m && bl[x1][y1] &&
        (a[x][y] || a[x1][y1])) {
      bl[x1][y1] = 0;
      if (!a[x1][y1] && c + 2 < d[x1][y1])
        d[x1][y1] = c + 2, dfs(x1, y1, c + 2, color);
      else if (a[x1][y1]&&a[x1][y1] == color && c < d[x1][y1])
        d[x1][y1] = c, dfs(x1, y1, c, color);
      else if (a[x1][y1]&&c + 1 < Min && c + 1 < d[x1][y1])
        d[x1][y1] = c + 1, dfs(x1, y1, c + 1, a[x1][y1]);
      bl[x1][y1] = 1;
    }
  }
}
    		
/*
题目描述

有一个mmm×m的棋盘，棋盘上每一个格子可能是红色、
黄色或没有任何颜色的。你现在要从棋盘的最左上角走
到棋盘的最右下角。

任何一个时刻，你所站在的位置必须是有颜色的
（不能是无色的）， 你只能向上、 下、左、 右四个方向
前进。当你从一个格子走向另一个格子时，如果两个格子
的颜色相同，那你不需要花费金币；如果不同，则你需要
花费 11个金币。

另外， 你可以花费 22 个金币施展魔法让下一个无色格子
暂时变为你指定的颜色。但这个魔法不能连续使用， 而且
这个魔法的持续时间很短，也就是说，如果你使用了这个
魔法，走到了这个暂时有颜色的格子上，你就不能继续使
用魔法； 只有当你离开这个位置，走到一个本来就有颜色
的格子上的时候，你才能继续使用这个魔法，而当你离开了
这个位置（施展魔法使得变为有颜色的格子）时，这个格子恢
复为无色。

现在你要从棋盘的最左上角，走到棋盘的最右下角，求花费的
最少金币是多少？

输入输出格式

输入格式：
第一行包含两个正整数mnm,n，以一个空格分开，分别代表棋盘
的大小，棋盘上有颜色的格子的数量。

接下来的nn行，每行三个正整数xycx,y,c， 分别表示坐标为xy(x,y)
的格子有颜色cc。

其中c1c=1 代表黄色，c0c=0 代表红色。 相邻两个数之间用一个空
格隔开。 棋盘左上角的坐标为11(1,1)，右下角的坐标为mm(m,m)。

棋盘上其余的格子都是无色。保证棋盘的左上角，也就是11(1,1) 
一定是有颜色的。

输出格式：
一个整数，表示花费的金币的最小值，如果无法到达，输出1−1。

输入输出样例

输入样例#1： 复制
5 7
1 1 0
1 2 0
2 2 1
3 3 1
3 4 0
4 4 1
5 5 0
输出样例#1： 复制
8
输入样例#2： 复制
5 5
1 1 0
1 2 0
2 2 1
3 3 1
5 5 0
输出样例#2： 复制
-1
*/