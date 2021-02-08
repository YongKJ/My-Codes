#include <iostream>
#include <string>
using namespace std;
int main(){
  int n,l1,l2;
  cin >> n;
  while(n--){
    string s1, s2;
    cin >> s1 >> s2;
    l1 = s1.length(), l2 = s2.length();
    int dp[l1+1][l2+1];
    memset(dp, 0, sizeof(dp));
    for (int i=1;i<=l1;i++)
      for (int j = 1; j <= l2; j++) {
        if (s1[i - 1] == s2[j - 1])
          dp[i][j] = dp[i - 1][j - 1] + 1;
        else
          dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    cout << dp[l1][l2] << endl;
  }
  return 0;
}
/*
1
asdf
adfsd
*/
      
      