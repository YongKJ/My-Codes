#include<stdio.h>
#include <iostream>
#include<algorithm>
#include<cstring>
using namespace std;

char str1[1001],str2[1001];
int dp[1001][1001];

int main()
{
	int N;
	scanf("%d",&N);
	while(N--)
	{
		int i,j;

		scanf("%s%s",str1+1,str2+1);
		
		int len1 = strlen(str1+1);
		int len2 = strlen(str2+1);
		
		memset(dp,0,sizeof(dp));    //初始化 
		
		for(i = 1; i <= len1; i++)
		{
                  for (j = 1; j <= len2; j++) {
                    if (str1[i] == str2[j])
                      dp[i][j] = dp[i - 1][j - 1] + 1;
                    else
                      dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]); //状态转移方程
                  }
                }
                for (int i=1;i<=len1;i++)
                  for (int j=1;j<=len2;j++)
                    cout << dp[i][j] << (j == len2 ? "\n" : " ");
                cout << endl;
                printf("%d\n", dp[len1][len2]);
        }
        return 0;
}
/*
述

       需要你做的就是写一个程序，得出最长公共子序列。
       最长公共子序列也称作最长公共子串(不要求连续)，
       英文缩写为LCS（Longest Common Subsequence）。
       其定义是，一个序列 S ，如果分别是两个或多个已知
       序列的子序列，且是所有符合此条件序列中最长的，
       则 S 称为已知序列的最长公共子序列。

输入

    第一行给出一个整数N(0<N<100)表示待测数据组数
    接下来每组数据两行，分别为待测的两组字符串。
    每个字符串长度不大于1000.

输出

   每组测试数据输出一个整数，表示最长公共子序列
   长度。每组结果占一行。

样例输入

2
asdf
adfsd
123abc
abc123abc

样例输出

3
6
*/