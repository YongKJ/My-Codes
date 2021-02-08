#include <iostream>
#include <string>
using namespace std;
int main(){
  int t,n,W;
  cin >> t;
  while (t-- && cin >> n >> W) {
    int w[n], v[n], dp[W + 1];
    for (int i = 0; i < n; i++)
      cin >> w[i] >> v[i];
    memset(dp, -10000, sizeof(dp)), dp[0] = 0;
    for (int i = 0; i < n; i++)
      for (int j = w[i]; j <= W; j++)
        dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
    if (dp[W] < 0)
      cout << "No" << endl;
    else
      cout << dp[W] << endl;
  }
  return 0;
}
  	
/*
2
1 5
2 2
2 5
2 2
5 1
*/