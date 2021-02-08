#include <iostream>
#include <string>
using namespace std;
int map[9][9] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 1, 1, 0, 0,
                 1, 1, 0, 0, 0, 1, 1, 0, 1, 0, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 1,
                 0, 0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 1,
                 1, 1, 0, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
int go[4][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}}, x, y, x1, y1, min1;
void dfs(int n,int m,int s){
  int xx, yy;
  if (n == x1 && m == y1) {
    min1 = min(min1, s);
    return;
  }
  else  if (s > min1)
    return;
    else
      for (int i = 0; i < 4; i++) {
        xx = n + go[i][0], yy = m + go[i][1];
        if (0 <= xx && xx < 9 && 0 <= yy && yy < 9 && map[xx][yy] == 0)
          map[xx][yy] = 1, dfs(xx, yy, s + 1), map[xx][yy] = 0;
      }
}
int main(){
  int t;
  cin >> t;
  while (min1 = 999999, t--) {
    cin >> x >> y >> x1 >> y1;
    dfs(x, y, 0);
    cout << min1 << endl;
  }
  return 0;
}
    