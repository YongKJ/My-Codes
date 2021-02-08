#include<cstdio>
#include<cstring>
const int N=11;
int vis[N][N],n,m,x0,y0,nm,ans=0;
int fx[8][2]={{1,2},{-1,2},{1,-2},{-1,-2},{2,1},{2,-1},{-2,1},{-2,-1}};
void dfs(int x,int y){
  int tmpx, tmpy;
  for (int i = 0; i < 8; i++) {
    tmpx = x + fx[i][0], tmpy = y + fx[i][1];
    if (tmpx >= 0 && tmpx <= n - 1 && tmpy >= 0 && tmpy <= m - 1 &&
        !vis[tmpx][tmpy])
      vis[tmpx][tmpy] = 1, dfs(tmpx, tmpy), vis[tmpx][tmpy] = 0;
    else if (tmpx + 1 == x0 && tmpy + 1 == y0)
      ans++;
  }
}
int main(){
	int t;
	scanf("%d",&t);
        while (t--) {
          memset(vis, 0, sizeof(vis));
          scanf("%d%d%d%d", &n, &m, &x0, &y0);
          ans = 0;
          vis[x0-1][y0-1] = 1;
          dfs(x0 - 1, y0 - 1);
          printf("%d\n", ans);
        }
        return 0;
}