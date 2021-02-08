#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n,k;
char a[50];
//string a;
//vector<vector<long long>> num(n, vector<long long>(n+1, 0));
long long num[50][50];
long long dp[50][50][10];

int main()
{
    cin >> n >> k;
    cin >> a;
    for(int i=0; i<n; i++)
    {
        num[i][i] = a[i]-'0';
        dp[i][i][0] = num[i][i];
        for(int j=i+1; j<n; j++)
        {
            num[i][j] = num[i][j-1]*10+(a[j]-'0');
            dp[i][j][0] = num[i][j];
        }
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
                    if (dp[i][m][left] * dp[m + 1][j][kk - left - 1] > maxV)
                      maxV = dp[i][m][left] * dp[m + 1][j][kk - left - 1];
                  }
                }
                dp[i][j][kk] = maxV;
            }
        }
    }
    cout << dp[0][n - 1][k];
    return 0;
}
/*
状态转移方程：dp[i][j][kk] = max{dp[i][m][left]*dp[m+1][j][kk-left-1]}

dp[i][j][kk]表示从i到j（包含）使用kk个乘号分割时所得的最大值。
*/
/*

2000年是国际数学联盟确定的“2000——世界数学年”，又恰逢我国
著名数学家华罗庚先生诞辰90周年。在华罗庚先生的家乡江苏金
坛，组织了一场别开生面的数学智力竞赛的活动，你的一个好朋友
XZ也有幸得以参加。活动中，主持人给所有参加活动的选手出了
这样一道题目： 
设有一个长度为N的数字串，要求选手使用K个乘号将它分成K+1个
部分，找出一种分法，使得这K+1个部分的乘积能够为最大。 
同时，为了帮助选手能够正确理解题意，主持人还举了如下的一个例子： 
有一个数字串：312， 当N=3，K=1时会有以下两种分法： 
3*12=36 
31*2=62 
这时，符合题目要求的结果是：31*2=62 
现在，请你帮助你的好朋友XZ设计一个程序，求得正确的答案。

输入

多组测试数据 
每个测试数据的输入共有两行： 
第一行共有2个自然数N，K（K+1≤N≤40，1≤K≤6） 
第二行是一个长度为N的数字串。 

输出

对于输入，应输出所求得的最大乘积（一个自然数）。

样例输入

4  2
1231

样例输出

62
*/