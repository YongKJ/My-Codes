#include <iostream>
#include <queue>
int w, h, map[970][1450], dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
using namespace std;
struct point {
  int x, y;
};
void bfs(int a, int b) {
  queue<point> q;
  point now, to;
  now.x = a, now.y = b, q.push(now);
  while(!q.empty()){
    now = q.front(), q.pop();
    for (int i = 0; i < 4; i++) {
      to.x = now.x + dir[i][0], to.y = now.y + dir[i][1];
      if (to.x < 1 || to.x > h || to.y < 1 || to.y > w || map[to.x][to.y] == 0)
        continue;
      map[to.x][to.y] = 0, q.push(to);
    }
  }
}
int main(){
  int t;
  cin >> t;
  while (t--) {
    cin >> w >> h;
    for (int i = 1; i <= h; i++)
      for (int j = 1; j <= w; j++)
        cin >> map[i][j];
    bfs(1, 1);
    for (int i = 1; i <= h; i++)
      for (int j = 1; j <= w; j++)
        if (j == w)
          cout << map[i][j] << endl;
        else
          cout << map[i][j] << " ";
  }
  return 0;
}
      
        
  	