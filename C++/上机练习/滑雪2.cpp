#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int n, m;
int a[101][101];
int dp[101][101];
int dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};
int solve(int x, int y)
{
if (dp[x][y]>0)
    return dp[x][y];
for (int i=0;i<4;i++) {
int nx=x+dx[i];
int ny=y+dy[i];
if (0<=nx&&nx<n&&0<=ny&&ny<m&&a[nx][ny]<a[x][y]){
dp[x][y]=max(dp[x][y],solve(nx,ny)+1);
}
}
return dp[x][y];
}
int main()
{

cin>>n>>m;
memset(dp,0,sizeof(dp));
for (int i=0;i<n;i++){
            for(int j=0;j<m;j++)
            cin>>a[i][j];
}
int ans=0;
for (int i = 0; i < n; i++) {
  for (int j = 0; j < m; j++)
    ans = max(ans, solve(i, j));
}
cout << ans + 1;

return 0;
}