#include<cstdio>
#include<cmath>
#include<map>
#include<iomanip>
#include<iostream>
#include<string>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1e3+10;
int n,f[maxn],flag;

void get(int x,int y)
{
	if (!x) return;
	for (int i=0;i<x;i++)
	{
		if (y<=f[i]*f[x-i-1])
		{
			if (flag)
			{
				printf("(");
				get(i,(y-1)/f[x-i-1]+1);
				printf("X");
				get(x-i-1,(y-1)%f[x-i-1]+1);
				printf(")");
			}
			else 
			{
				flag=1;
				get(i,(y-1)/f[x-i-1]+1);
				printf("X");
				get(x-i-1,(y-1)%f[x-i-1]+1);
			}
			break;
		}
		else y-=f[i]*f[x-i-1];
	}
}

int main()
{
	f[0]=f[1]=1;
	for (int i=2;i<maxn;i++)
	{
          f[i] = (long long)f[i - 1] * (4 * i - 2) / (i + 1);
	}
        //for (int i=0;i<100;i++)
       //   cout << f[i] << (i != 99 ? " " : "\n");
        //cout << endl;
	while (scanf("%d",&n),n) 
	{
		flag=0;
		for (int i=1;i<maxn;i++)
		{
                  if (n <= f[i]) {
                    get(i, n);
                    break;
                  } else
                    n -= f[i];
                }
                printf("\n");
        }
        return 0;
}
/*
描述


一年一度的研究生面试又快要来临了。为了测试学生对树结构的认识，
同时也检验他们的编程能力，福州大学计算机系把面试的一项内容定为：
要求学生们编程按编号顺序打印出节点个数不少于m的所有二叉树。
二叉树编号规则如下：

仅有一个节点的树编号为1。
当满足以下条件之一时，定义二叉树a的编号比b大：
  1. a的节点数比b多。
  2. 若a的节点数与b相等，且a的左子树编号比b的左子树大。
  3. a的节点数和左子树编号都和b相等，且a的右子树编号比b的右
  子树大。

二叉树的节点用大写X表示，例如：

当然当m较大时，检验答案对错的工作也是很繁重的，所以教授只打算
对其中的若干个编号的二叉树进行抽查，他想麻烦你编制一个程序能够
产生编号为n的二叉树的标准答案。

输入


输入数据由多组数据组成。每组数据仅一个整数，表示n (1≤n≤10^8)的值。
输入数据以n=0表示结束，该数据不要处理。

输出


对于每组数据，输出仅一行，即你求出的标准答案。
二叉树的输出格式为：

 (左子树){若左子树为空则省略}X{根}(右子树){若右子树为空则省略}
其中{…}中的内容是说明，不必输出。例如，在上图中编号为5的树可表
示为X((X)X)；编号为6的树表示为(X)X(X)。

样例输入

5
6
0

样例输出

X((X)X)
(X)X(X)
*/