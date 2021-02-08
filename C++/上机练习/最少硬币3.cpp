#include <iostream>
#include <string>
using namespace std;
int main(){
  int n,m;
  while (cin >> n) {
    int t[n + 1], c[n + 1];
    for (int i = 1; i <= n; i++)
      cin >> t[i] >> c[i];
    cin >> m;
    int dp[m + 1];
    memset(dp, 9999, sizeof(dp)), dp[0] = 0;
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= c[i]; j++)
        for (int k = m; k >= t[i]; k--)
          dp[k] = min(dp[k], dp[k - t[i]] + 1);
    for (int i=0;i<=m;i++)
      cout << dp[i] << (i == m ? "\n" : " ");
    cout << (dp[m] == 9999 ? -1 : dp[m]) << endl;
  }
  return 0;
}