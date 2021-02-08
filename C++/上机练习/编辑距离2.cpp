#include <iostream>
#include <string>
using namespace std;
int main(){
  string s1, s2;
  while(cin>>s1>>s2){
    int l1 = s1.length(), l2 = s2.length(), dp[l1][l2],del,insert,sub;
    for (int i=0;i<l1;i++)
      dp[i][0] = i;
    for (int i=0;i<l2;i++)
      dp[0][i] = i;
    for (int i=1;i<l1;i++)
      for (int j = 1; j < l2; j++) {
        del = dp[i - 1][j] + 1, insert = dp[i][j - 1] + 1,
        sub = dp[i - 1][j - 1] + (s1[i] == s2[j] ? 0 : 1);
        dp[i][j] = min(min(del, insert), sub);
      }
    cout << dp[l1 - 1][l2 - 1] << endl;
  }
  return 0;
}
/*
abcdefg
aabcg
*/
      
    
    