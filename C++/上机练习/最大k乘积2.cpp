#include <iostream>
#include <stdio.h>
#include <string.h>
#include <iomanip>
using namespace std;

const int M=11;

int nik[M][M];
int dp[M][M];

int main()
{
    int ws,k;
    int n;
    while(scanf("%d%d%d",&ws,&k,&n)!=EOF)
    {
        memset(dp,0,sizeof(dp));
        cout << endl;
        if(k==1)
        {
            printf("%d\n",n);
            continue;
        }
        else
        for(int i=1;i<=ws;i++)
        {
            int p=10;
            for(int j=i;j<=ws;j++)
            {
                nik[i][j]=n%p;
                p*=10;
            }
            n/=10;
        }
        for (int i = 1; i  <=ws; i++)
          for (int j=1;j<=ws;j++)
            cout <<setw(3)<< nik[i][j] << (j == ws? "\n" : " ");
        cout << endl;
        for(int i=1;i<=ws;i++)
        {
            dp[i][1]=nik[1][i];
        }
        for (int i = 1; i  <=ws; i++)
          for (int j=1;j<=ws;j++)
            cout <<setw(3)<< dp[i][j] << (j == ws ? "\n" : " ");
        cout << endl;
        for(int i=2;i<=k;i++)
        {

            for(int j=1;j<=ws;j++)
            {
                int maxn=0;
                for (int k = 1; k < j; k++) {
                  cout << setw(3) << dp[k][i - 1] << " " << setw(3)
                       << nik[k + 1][j] << " " << setw(3)
                       << dp[k][i - 1] * nik[k + 1][j] << endl;
                  maxn = max(dp[k][i - 1] * nik[k + 1][j], maxn);
                }

                dp[j][i] = maxn;
            }
        }
        cout << endl;
        for (int i = 1; i  <=ws; i++)
          for (int j=1;j<=ws;j++)
            cout <<setw(3)<< dp[i][j] << (j == ws ? "\n" : " ");
        cout << endl;
        printf("%d\n", dp[ws][k]);
    }
    return 0;
}
/*
首先这个题目的dp[i][j]中存的应该是从末尾到i位分k段的最大乘积

前面数字为一段，用nik[i][j]来表示从i位到j位的数字

于是状态转移方程为 dp[i][j]=max{dp[j-1~i-1][j-1]*nik[j~i][i]}

这个问题中待分解的数比较小

而一个数分解后的乘积一定会比本身小

所以int型足够了
*/