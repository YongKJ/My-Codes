#include <iostream>
#include <string>
using namespace std;
int main(){
  int k;
  string n;
  while(cin>>n>>k){
    int map[10][10] = {0}, dp[10][10] = {0}, l = n.length();
    for (int i = 0; i < l; i++)
      map[i + 1][i + 1] = n[i] - '0';
    for (int i=1;i<=l;i++)
    for (int j=i+1;j<=l;j++)
      map[i][j] = map[i][j - 1] * 10 + map[j][j];
     for (int i=1;i<=l;i++)
     for (int j = 0; j < i; j++) {
       if (j == 0) {
         dp[i][j] = map[1][i];
         continue;
       }
       for (int k = 1; k < i; k++)
         dp[i][j] = max(dp[i][j], dp[k][j - 1] * map[k + 1][i]);
     }
     cout << dp[l][k - 1] << endl;
  }
  return 0;
}
                  
      
  	