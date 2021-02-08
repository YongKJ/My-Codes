#include <iostream>
#include <string>
using namespace std;
int main(){
  int n, k;
  string s;
  while (cin >> n >> k >> s) {
    int dp[n + 1][n + 1][k + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; i++)
      for (int j = i + 1; j < n; j++)
        dp[i][i][0] = s[i] - '0',
        dp[i][j][0] = dp[i][j - 1][0] * 10 + s[j] - '0';
    for (int i = 0; i < n; i++)
      for (int j = i + 1; j < n; j++)
        for (int kk = 1, Max = 0; kk <= k; dp[i][j][kk] = Max, kk++, Max = 0)
          for (int m = i; m <= j; m++)
            for (int left = 0; left <= kk; left++)
              Max = max(Max, dp[i][m][left] * dp[m + 1][j][kk - left - 1]);
    cout << dp[0][n - 1][k] << endl;
  }
  return 0;
}
/*
4  2
1231

62
*/