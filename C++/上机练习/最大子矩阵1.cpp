#include <iostream>
#include <string>
using namespace std;
int main(){
  int t, n, m;
  cin >> t;
  while(t--&&cin>>n>>m){
    int a[n + 1][m + 1], dp[n + 1][m + 1], Max = -10000;
    memset(dp, 0, sizeof(dp));
    for (int i=1;i<=n;i++)
      for (int j=1;j<=m;j++)
        cin >> a[i][j];
    for (int i=1;i<=n;i++)
      for (int j=1;j<=m;j++)
        dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + a[i][j];
    for (int i=1;i<=n;i++)
      for (int j=i;j<=n;j++)
        for (int temp, sum = 0, k = 1; k <= m; k++)
          temp = dp[j][k] - dp[j][k - 1] - dp[i - 1][k] + dp[i - 1][k - 1],
          sum = sum > 0 ? sum + temp : temp, Max = max(Max, sum);
    cout << Max << endl;
  }
  return 0;
}
/*
1
4 4
0 -2 -7 0 
9 2 -6 2 
-4 1 -4 1 
-1 8 0 -2 

样例输出

15
*/