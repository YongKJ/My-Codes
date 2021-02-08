#include<stack>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1e4;
int T,n,tot=26,flag,ans;
char s[maxn];

struct rec
{
	int x,y;
	rec(int x=0,int y=0):x(x),y(y){}
        void read() { scanf("%d%d", &x, &y); }
} a[maxn];

rec operator*(rec a, rec b) {
  if (a.y != b.x)
    flag = 0;
  ans += a.x * a.y * b.y;
  return rec(a.x, b.y);
}

int main()
{
	//scanf("%d",&T);
	while (~scanf("%d",&n))
	{
		flag=1;	ans=0;
                for (int i = 0; i < n; i++) {
                  scanf("%s", s);
                  a[s[0] - 'A'].read();
                }
		scanf("%s",s);
		stack<int> p,q;
		for (int i=0;s[i];i++)
		{
			if (s[i]=='(')  
			p.push(-1);
			else if (s[i]==')')
			{
				
                          while (p.top() != -1) {
                            q.push(p.top());
                            p.pop();
                          }
				p.pop();	
				int k=q.top();	
				q.pop();
				
                                while (!q.empty()) {
                                  a[++tot] = a[k] * a[q.top()];
                                  k = tot;
                                  q.pop();
                                }
                                
                                p.push(k);
                        } else
                          p.push(s[i] - 'A');
                }
		while (!p.empty()) {
			q.push(p.top()); p.pop(); 
			}
		int k=q.top();	q.pop();
                while (!q.empty()) {
                  a[++tot] = a[k] * a[q.top()];
                  k = tot;
                  q.pop();
                }
                if (flag)
                  printf("%d\n", ans);
                else
                  printf("error\n");
        }
        return 0;
}
/*
描述

       给定n个矩阵{A1,A2,...,An}，考察这n个矩阵的连乘积A1A2...An。
       由于矩阵乘法满足结合律，故计算矩阵的连乘积可以有许多不同的
       计算次序，这种计算次序可以用加括号的方式来确定。 

       矩阵连乘积的计算次序与其计算量有密切关系。例如，
       考察计算3个矩阵{A1,A2,A3}连乘积的例子。设这3个矩阵的
       维数分别为10*100，100*5，和5*50。若按(A1A2)A3计算，
       3个矩阵连乘积需要的数乘次数为10*100*5+10*5*50 = 7500。
       若按A1(A2A3)计算，则总共需要100*5*50+10*100*50 = 75000
       次数乘。

       现在你的任务是对于一个确定的矩阵连乘方案，计算其需要的数乘次数。

输入


输入数据由多组数据组成。每组数据格式如下：
第一行是一个整数n (1≤n≤26)，表示矩阵的个数。
接下来n行，每行有一个大写字母，表示矩阵的名字，
后面有两个整数a,b，分别表示该矩阵的行数和列数，其中1<a,b<100。
第n+1行是一个矩阵连乘的表达式，由括号与大写字母组成，
没有乘号与多余的空格。如果表达式中没有括号则按照从左到右的
顺序计算，输入的括号保证能够配对。

输出


对于每组数据，输出仅一行包含一个整数，即将该矩阵连乘方案
需要的数乘次数。如果运算过程中出现不满足矩阵乘法法则的情况
（即左矩阵列数与右矩阵的行数不同），则输出“error”。

样例输入

3
A 10 100
B 100 5
C 5 50
A(BC)

样例输出

75000
*/