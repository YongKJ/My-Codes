#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define INF 500000000
const int maxn=2000+10;
int dp[50000+10];
int c[maxn],w[maxn]; //重量、价值 
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int M,V;
		scanf("%d%d",&M,&V);
		for(int i=0;i<M;i++){
			scanf("%d%d",&c[i],&w[i]);
		}
		
		dp[0]=0;
		for(int i=1;i<=V;i++)dp[i]=-INF;
		 
			for(int j=0;j<M;j++){
                          for (int i = c[j]; i <= V; i++) {
                            dp[i] = max(dp[i], dp[i - c[j]] + w[j]);
                          }
                        }

                        if (dp[V] < 0)
                          printf("NO\n");
                        else
                          printf("%d\n", dp[V]);
        }
        return 0;
}
/*
描述


直接说题意，完全背包定义有N种物品和一个容量为V的
背包，每种物品都有无限件可用。第i种物品的体积是c，
价值是w。求解将哪些物品装入背包可使这些物品的体积
总和不超过背包容量，且价值总和最大。本题要求是背包
恰好装满背包时，求出最大价值总和是多少。如果不能恰
好装满背包，输出NO

输入

第一行： N 表示有多少组测试数据（N<7）。 
接下来每组测试数据的第一行有两个整数M，V。 M表
示物品种类的数目，V表示背包的总容量。(0<M<=2000，
0<V<=50000)
接下来的M行每行有两个整数c，w分别表示每种物品的
重量和价值(0<c<100000，0<w<100000)

输出

对应每组测试数据输出结果（如果能恰好装满背包，输
出装满背包时背包内物品的最大价值总和。 如果不能恰
好装满背包，输出NO）

样例输入

2
1 5
2 2
2 5
2 2
5 1

样例输出

NO
1
*/