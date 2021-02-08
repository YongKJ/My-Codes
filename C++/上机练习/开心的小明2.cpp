#include <iostream>
#include <string>
using namespace std;
int main(){
  int t, tm, tn;
  cin >> t;
  while (t--) {
    cin >> tm >> tn;
    int p[tn + 1], im[tn + 1], dp[tn + 1][tm + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= tn; i++)
      cin >> p[i] >> im[i];
    for (int i = 1; i <= tn; i++)
      for (int j = 0; j <= tm; j++)
        if (j >= p[i])dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - p[i]] + p[i] * im[i]);
    cout << dp[tn][tm] << endl;
  }
  return 0;
}
/*
1
1000 5
800 2
400 5
300 5
400 3
200 2
*/
  	