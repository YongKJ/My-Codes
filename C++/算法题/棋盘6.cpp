#include <iostream>
#include <cstring>
using namespace std;
int m, n, ans;
#define Max 0x7f7f7f7f
int Map[110][110], f[110][110],vis[110][110];
int s[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
void dfs(int x, int y, int sum, bool magic);
int main(){
  while (cin >> m >> n) {
    int x, y, z;
    memset(f, 127, sizeof(f));
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= n; i++)
      cin >> x >> y >> z, Map[x][y] = z + 1;
    ans = Max, dfs(1, 1, 0, false);
    cout << (ans == Max ? -1 : ans) << endl;
  }
  return 0;
}
void dfs(int x,int y,int sum,bool magic){
  if (x == m && y == m) {
    ans = min(ans, sum);
    return;
 }
 if (sum >= f[x][y])return;
 f[x][y] = sum;
 for (int i=0;i<4;i++){
   int x1 = x + s[i][0], y1 = y + s[i][1];
   if(1<=x1&&x1<=m&&1<=y1&&y1<=m&&!vis[x1][y1]){
     vis[x1][y1] = 1;
     if (Map[x1][y1]) {
       if (Map[x1][y1] == Map[x][y])
         dfs(x1, y1, sum, false);
       else
         dfs(x1, y1, sum + 1, false);
     } else if (!Map[x1][y1] && !magic) {
       Map[x1][y1] = Map[x][y];
       dfs(x1, y1, sum + 2, true);
       Map[x1][y1] = 0;
     }
     vis[x1][y1] = 0;
   }
 }
}