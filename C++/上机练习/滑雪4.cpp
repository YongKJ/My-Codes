#include <iostream>
#include <string>
using namespace std;
const int d[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
int h[101][101], map[101][101], sum, n, m;
int dfs(int x,int y){
  int a, b;
  if (h[x][y])
    return h[x][y];
  h[x][y] = 1;
  for (int i = 0; i < 4; i++) {
    a = x + d[i][0], b = y + d[i][1];
    if (1 <= a && a <= n && 1 <= b && b <= m && map[a][b] < map[x][y])
      h[x][y] = max(h[x][y], dfs(a, b) + 1);
  }
  return h[x][y];
}
int main(){
  while (memset(h, 0, sizeof(h)), cin >> n >> m) {
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++)
        cin >> map[i][j];
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++)
        sum = max(sum, dfs(i, j));
    cout << sum << endl;
  }
  return 0;
}