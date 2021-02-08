#include <iostream>
#include <stdio.h>
#include <string.h>
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
        for(int i=1;i<=ws;i++)
        {
            dp[i][1]=nik[1][i];
        }
        for(int i=2;i<=k;i++)
        {

            for(int j=1;j<=ws;j++)
            {
                int maxn=0;
                for (int k = 1; k < j; k++) {
                  maxn = max(dp[k][i - 1] * nik[k + 1][j], maxn);
                }

                dp[j][i] = maxn;
            }
        }
        printf("%d\n", dp[ws][k]);
    }
    return 0;
}
/*
描述

设I是一个十进制整数x。如果将x划分为k段，则可得到k个整数。
这k个整数的乘积称为x的一个k乘积。试设计一个算法，对于给
定的x和k，求出x的最大k乘积。


输入

输入文件由多组数据组成。每组数据格式如下：
第1行中有2个正整数x和k。

输出

x的最大k乘积。

样例输入

15  1
123  2

样例输出

15
36
*/