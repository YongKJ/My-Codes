#include <iostream>
#include <string>
using namespace std;
const int s[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {-1, 0}};
int n, m, sum, count1[10][10];
char map[10][10];
void dfs(int x, int y) {
  int x1, y1;
  if(map[x][y]=='#')
    return;
    for (int i = 0; i < 4; i++) {
      x1 = x + s[i][0], y1 = y + s[i][1];
      if (0 <= x1 && x1 < n && 0 <= y1 && y1 < m && map[x1][y1] != '#' &&
          count1[x1][y1] == 0)
        count1[x1][y1] = 1, sum++, dfs(x1, y1);
    }
}
int main(){
  while (sum = 0, cin >> n >> m, n + m) {
    memset(count1, 0, sizeof(count1));
    for (int i = 0; i < n; i++)
      cin >> map[i];
    dfs(0, 0), cout << sum << endl;
  }
  return 0;
}