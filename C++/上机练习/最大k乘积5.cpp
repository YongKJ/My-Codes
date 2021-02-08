#include <iostream>
#include <string>
#include <iomanip>
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
      for (int j = 1;j<=l;j++)
        cout << setw(3) << map[i][j] << (j == l ? "\n" : " ");
    cout << endl;
     for (int i=1;i<=l;i++)
     for (int j = 0; j < i; j++) {
       if (j == 0) {
         dp[i][j] = map[1][i];
         continue;
       }
       for (int i = 1; i <= l; i++)
       for (int j = 0; j <= l; j++)
         cout << setw(3) << dp[i][j] << (j == l ? "\n" : " ");
       for (int k = 1; k < i; k++) {
         //cout << i << " " << j << " " << dp[i][j] << endl;
         cout << i << " " << j << " " << k << endl;
         cout << k << " " << j - 1 << " " << dp[k][j - 1] << "      " << k + 1 << " "
              << i << " " << map[k + 1][i] << endl;
         //cout << dp[k][j - 1] * map[k + 1][i] << endl;
             dp[i][j] = max(dp[i][j], dp[k][j - 1] * map[k + 1][i]);
             cout << dp[i][j] << endl;
       }
       cout << endl;
     }
     for (int i = 1; i <= l; i++)
       for (int j = 1; j <= l; j++)
         cout << setw(3) << dp[i][j] << (j == l ? "\n" : " ");
     cout << endl;
     cout << dp[l][k - 1] << endl;
  }
  return 0;
}
/*
代码思路：

区间DP 


设m(h,k) 表示: 从第h位到第K位所组成的十进制数
设dp(i,j)表示前i位(1-i)分成j段所得的最大乘积,
a数组储存给定的n个数字 ； 
则可得到如下经典的DP方程：
如果只分成一段，那么m[i][1]=w[1][i];
否则： 
 前i位(1:i)数字分j组乘积的最大值等于分为j-1组的结果再乘以一个因子

tips:预处理连续数字乘积和存放在m数组，dp[i][j]代表前i位有j个乘号。
dp[i][j]=max(dp[i][j],dp[k][j-1]*m[k+1][i]);    1<=k<i;
*/