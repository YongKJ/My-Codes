#include <iostream>
#include <string>
#include <set>
using namespace std;
int n, m;
set<int> num;
string str[100], Map[100];
void dfs(string str[],int x,int y) {}
int main(){
  while (num.clear(),cin >> n >> m) {
    string str[n];
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        cin >> str[i][j], Map[i][j] = '0';
     for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        dfs(str, i, j);
  }
  return 0;
}
/*题描述：小人可以在迷宫中任意地方放置一个炸弹，
炸弹可以在以该点为中心的十字方向杀死怪物，
但是触碰到墙之后不再能传递攻击。求将一个炸弹
放在哪个位置可以杀死更多的怪物？？
输入： 
13 13
#############
#GG.GGG#GGG.#
###.#G#G#G#G#
#.......#..G#
#G#.###.#G#G#
#GG.GGG.#.GG#
#G#.#G#.#.#.#
##G...G.....#
#G#.#G###.#G#
#...G#GGG.GG#
#G#.#G#G#.#G#
#GG.GGG#G.GG#
#############
（上面“.”表示空，“#”表示墙壁，“G”表示怪物）
输出：
7 11 10 
即（7， 11）坐标处可以杀死10个怪物、
*/