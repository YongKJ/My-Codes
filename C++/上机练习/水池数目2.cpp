#include <iostream>
#include <string>
using namespace std;
const int s[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
int n, m,map[10][10], k[10][10],sum;
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
  while (sum = 0, memset(k, 0, sizeof(k)), t--) {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        cin >> map[i][j], k[i][j] = map[i][j] == 0 ? -1 : 0;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        if (k[i][j] == 0)
          dfs(i, j), sum++;
    cout << sum << endl;
  }
  return 0;
}
/*
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
*/