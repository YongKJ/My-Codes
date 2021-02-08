#include <iostream>
#include <queue>
#include <string>
using namespace std;
int map[9][9] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 1, 1, 0, 0,
                 1, 1, 0, 0, 0, 1, 1, 0, 1, 0, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 1,
                 0, 0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 1,
                 1, 1, 0, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
const int go[4][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
int x1, y1, x2, y2, vis[10][10];
struct Node {
  int x, y, s;
};
int bfs(int x,int y){
  int xx, yy;
  Node now, to;
  queue<Node> q;
  now.x = x, now.y = y, now.s = 0, q.push(now), vis[x][y] = 1;
  while(q.empty()==0){
    now = q.front(), q.pop();
    if(now.x==x2&&now.y==y2)
      return now.s;    
    for (int i = 0; i < 4; i++) {
      xx = now.x + go[i][0], yy = now.y + go[i][1];
      if (0 <= xx && xx < 9 && 0 <= yy && yy < 9 && map[xx][yy] == 0 &&
          vis[xx][yy] == 0)
        vis[xx][yy] = 1, to.x = xx, to.y = yy, to.s = now.s + 1, q.push(to);
    }
  }
}
int main(){
  int t;
  cin >> t;
  while (memset(vis, 0, sizeof(vis)), t--) {
    cin >> x1 >> y1 >> x2 >> y2;
    cout << bfs(x1, y1) << endl;
  }
  return 0;
}
/*
2
3 1 5 7
3 1 6 7
*/