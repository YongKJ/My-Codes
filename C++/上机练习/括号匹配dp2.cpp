#include <iostream>
#include <string>
using namespace std;
int main(){
  string s;
  int t;
  cin >> t;
  while(t--){
    cin >> s;
    int l = s.length(),dp[l][l];
    memset(dp, 0, sizeof(dp));
    for (int i=0;i<l;i++)
      dp[i][i] = 1;
    for (int m=1;m<l;m++)
      for (int i = 0; i < l - m; i++) {
        int j = i + m;
        dp[i][j] = 9999;
        if ((s[i]=='['&&s[j]==']')||(s[i]=='('&&s[j]==')'))
          dp[i][j] = min(dp[i][j], dp[i + 1][j - 1]);
        for (int k = i; k < j; k++)
          dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
      }
    cout << dp[0][l - 1] << endl;
  }
  return 0;
}
/*
4
[]
([])[]
((]
([)]
*/
  	