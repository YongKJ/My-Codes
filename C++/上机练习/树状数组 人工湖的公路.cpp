#include<iostream>
#include<cstring>

using namespace std;

const int maxn = 100001;
int c[100001],ma[100001];

int lowbit(int t) //位运算
{
	return t & (-t);		
} 

void insert(int k,int d,int max) //快速修改
{
	while(k <= max)
	{
		c[k] += d;
		k = k + lowbit(k);
	}
} 

int getsum(int k) //快速求和
{
	int t = 0;
	while(k > 0)
	{
		t += c[k];
		k -= lowbit(k);	
	}
	return t;	
} 
int main()
{
	int i;
	int n,k;
	while(scanf("%d%d",&n,&k) != EOF)
	{
		memset(c,0,sizeof(c));
		for(i=1;i<=n;i++)
		{
			insert(i,1,n);
			ma[i] = 1; //ma数组记录当前这个城市是否和下一个相连 
		}
		while(k--)
		{
			int a,b,f;
			scanf("%d%d%d",&f,&a,&b);
			if(f == 0) //如果是好的公路 
			{
				if(a > b)
				{
					a = a ^ b;
					b = a ^ b;
					a = a ^ b;
				}
				if(b == n && a == 1)
				{
					if(ma[b] == 1) //通 
					{
						insert(b,-1,n);
						ma[b] = 0;
					}
					else
					{
						insert(b,1,n);
						ma[b] = 1;
					}
				}
				else
				{
					if(ma[a] == 1)
					{
						insert(a,-1,n);
						ma[a] = 0;
					}
					else
					{
						insert(a,1,n);
						ma[a] = 1;
					}
				}
			}
			if(f == 1)
			{
				if(a > b)
				{
					a = a ^ b;
					b = a ^ b;
					a = a ^ b;
				}
				int t1,t2,t3,t4;
				t1 = getsum(a - 1);
				t2 = getsum(b - 1);
				int flag = 0;
				if(t2 - t1 == b - a)
				{
					flag = 1;
					printf("YES\n");
				}
				if(!flag)
				{
					t3 = getsum(n) - t2;
					if(t3 + t1 == n - b + a)
					{
						printf("YES\n");
						flag = 1;
					}
				}
				if(!flag)
				{
					printf("NO\n");
				}
			}
		}
	}
	return 0;	
} 
/*
描述


水是生命之源，这些大家都知道。所以但凡有水的地方
都会有人。而且一般靠近江河湖海的地方人也特别的多。

人工湖是一个美丽壮阔的湖，在湖的四周分布着若干个
城市。由于水路并不发达，所以这些城市的交通一般都
是靠陆路。每个城市只和靠其左右的两个城市建有公路。
即，我们可以这么想象：湖是一个圆，在圆上分布着N个
城市，编号为1~N，编号为i的城市只和编号i%N+1,
(i-2+N)%N+1两个城市有公路相连。当然路是双向的。
由于城市之间的距离很远，有的路段常年不能得到很好的
维护，所以可能有两个相邻之间的城市的公路会坏掉，
当然这条公路就不能走了。但是这两个城市会在某个时候
派出“工程队“去把坏的路修好。由于路况很难预测，所以
YY市长会向你询问某两个城市的人民是否可以互相到达
彼此的城市。

输入


第一行有两个数2<=N<=100000,1<=M<=100000,分别代表
城市的数目和询问的次数接下来有M行，每行有一个标志
数f和两个相邻城市的编号x，y。

当f=0，如果x，y之间的公路是好的，则x，y之间的公路会
坏掉。如果是坏的，则x，y之间的公路将被修好。

当f=1，那就代表YY市长要开始询问了，那么后面你将回答
x，y之间是否可以互相可达。

输出


对于每一个询问，如果x，y互相可达则输出YES，否则输出
NO。每个输出占一行。

样例输入

5 10
1 2 5
0 4 5
1 4 5
0 2 3
1 3 4
1 1 3
0 1 2
0 2 3
1 2 4
1 2 5

样例输出

YES
YES
YES
NO
YES
NO

解题思路:

用一个数组记录当前这个城市是否和它的下一个城市相连,
若相连将数组设置为1，否则设置为0，第n个表示它是否和
第1个相连,这样就在询问两个城市是否相连时快速求出和
就可以了，但是需要求两次，如果顺时针或者逆时针可达,
那么就是可以到达,否则就是不可以到达。
*/