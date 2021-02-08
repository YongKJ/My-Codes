#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
#define min(x,y) x<y?x:y

double dp[10001],v[10001];
int cost[10001];

int main()
{
	int i,j,n,m;
	while(~scanf("%d%d",&n,&m) && (n||m))
	{
		for(i=0;i<=n;i++)   //10万存入dp中
			dp[i]=1;
		for(i=0;i<m;i++)
			scanf("%d%lf",&cost[i],&v[i]);    //概率存入v中
		for(i=0;i<m;i++)     //m个学校
		for(j=n;j>=cost[i];j--)      //10万到花费的钱
                  dp[j] = min(dp[j], dp[j - cost[i]] * (1 - v[i]));
                printf("%.1lf%%\n", (1 - dp[n]) * 100);
	}
	return 0;
}
//每一次的WA都是为了更好的AC