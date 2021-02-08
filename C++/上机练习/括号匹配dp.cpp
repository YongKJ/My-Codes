#include <iostream>
using namespace std;
#define MAX 105

int dp[MAX][MAX];

int link(char a, char b)
{
	if((a=='(' && b==')')||(a=='['&&b==']')) return 1;
	else return 0;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		string str;
		cin >> str;
		int len = str.size();
		for(int i = 0; i < len; i++)
		{
			dp[i][i] = 1;
		}
		for(int m = 1; m < len; m++)
		{
			for(int i = 0; i+m < len; i++)
			{
				int j = i+m;
				dp[i][j] = 9999;
				if(link(str[i], str[j])) dp[i][j] = min(dp[i][j], dp[i+1][j-1]);
                                for (int k = i; k < j; k++) {
                                  dp[i][j] =
                                      min(dp[i][j], dp[i][k] + dp[k + 1][j]);
                                }
                        }
                }
                printf("%d\n", dp[0][len - 1]);
        }
        return 0;
}
/*
首先，这个问题具体是很经典的区间动态规划问题，那么，
我们可以使用一个二维数组dp[i][j] 表示字符串s的第i..j字符
需要最少括号数，下面是具体的表示：

当i= j的时候，只有一个字符，那么，只要匹配一个字符就
行了，所以，dp[i][i] = 1

如果，当i < j的时候，s[i] = s[j]  那么，
dp[i][j] = min(dp[i][j],dp[i+1][j+1])，其中，
假设i <= k < j 状态转移方程为 dp[i][j] = min(dp[i][j],d[i][k] + dp[k+1][j])
*/
/*
描述

给你一个字符串，里面只包含"(",")","[","]"四种符号，
请问你需要至少添加多少个括号才能使这些括号匹配起来。
如：
[]是匹配的
([])[]是匹配的
((]是不匹配的
([)]是不匹配的

输入


第一行输入一个正整数N，表示测试数据组数(N<=10)
每组测试数据都只有一行，是一个字符串S，S中只包含以上所说的四种字符，S的长度不超过100
输出

对于每组测试数据都输出一个正整数，表示最少需要添加的括号的数量。每组测试输出占一行

样例输入

4
[]
([])[]
((]
([)]

样例输出

0
0
3
2
*/