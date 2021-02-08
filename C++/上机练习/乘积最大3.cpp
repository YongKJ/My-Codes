#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n,k;
char a[50];
long long num[50][50];
long long dp[50][50][10];

int main()
{
    cin >> n >> k;
    cin >> a;
    for (int i = 0; i < n; i++) {
      dp[i][i][0] = a[i] - '0';
      for (int j = i + 1; j < n; j++)
        dp[i][j][0] = dp[i][j - 1][0] * 10 + a[j] - '0';
    }
    for (int i=0;i<n;i++)
      for (int j=0;j<n;j++)
        cout << dp[i][j][0] << (j == n - 1 ? "\n" : " ");
    cout << endl;
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            for(int kk=1; kk<=k; kk++)
            {
                long long maxV = 0;
                for(int m=i; m<=j; m++)
                {
                  for (int left = 0; left <= kk; left++) {
                    maxV =
                        max(maxV, dp[i][m][left] * dp[m + 1][j][kk - left - 1]);
                  }
                }
                dp[i][j][kk] = maxV;
            }
        }
    }
    cout << dp[0][n - 1][k];
    return 0;
}