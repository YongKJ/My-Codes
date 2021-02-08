#include <iostream>
using namespace std;
int main(){
  int n;
  while(cin>>n){
    int s[10][10] = {0}, t = s[0][0] = 1, x = 0, y = 0;
    while (t < n * n) {
      while (y + 1 < n && s[x][y + 1] == 0)s[x][++y] = ++t;
      while (x + 1 < n && s[x + 1][y] == 0)s[++x][y] = ++t;
      while (y - 1 >= 0 && s[x][y - 1] == 0)s[x][--y] = ++t;
      while (x - 1 >= 0 && s[x - 1][y] == 0)s[--x][y] = ++t;
    }
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        cout << s[i][j] << (j != n - 1 ? " " : "\n");
  }
  cout << endl;
  return 0;
}
    
    
/*
描述


下面是一个5*5螺旋方阵。你的任务是按顺时针方向旋进的n*n螺旋方阵。

1 2 3 4 5

16 17 18 19 6

15 24 25 20 7

14 23 22 21 8

13 12 11 10 9

输入


输入只有一行，一个整数n，（1<=n<=100）。

输出


按n行n列的方式输出n*n螺旋方阵，行尾无空格，同一行上两个数之间空一格。

样例输入

5

样例输出

1 2 3 4 5
16 17 18 19 6
15 24 25 20 7
14 23 22 21 8
13 12 11 10 9
*/