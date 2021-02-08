#include <iostream>
#include <string>
#include <queue>
using namespace std;
struct Node {
    int  x, y;
} Now, Next;
int map[10][10], t, n, m;
const int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
void bfs() {
  queue<Node> q;
  Now.x = 0, Now.y = 0, q.push(Now);
  while(!q.empty()){
    Now = q.front(), q.pop();
    for (int i = 0; i < 4; i++) {
      Next.x = Now.x + dir[i][0], Next.y = Now.y + dir[i][1];
      if (0 <= Next.x && Next.x <= n + 1 && 0 <= Next.y && Next.y <= m + 1 &&
          map[Next.x][Next.y] != 0)
        map[Next.x][Next.y] = 0, q.push(Next);
    }
  }
}
int main(){
  cin >> t;
  while(t--&&cin>>m>>n&&memset(map,1,sizeof(map))){
    for (int i=1;i<=n;i++)
      for (int j=1;j<=m;j++)
        cin >> map[i][j];
    bfs();
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++)
        cout << map[i][j] << " ";
      cout << endl;
    }
  }
  return 0;
}
/*

样例输入

1
5 5
100 253 214 146 120
123 0 0 0 0
54 0 33 47 0
255 0 0 78 0
14 11 0 0 0

样例输出

0 0 0 0 0
0 0 0 0 0
0 0 33 47 0
0 0 0 78 0
0 0 0 0 0
*/