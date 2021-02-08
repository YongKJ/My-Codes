#include <stdio.h>
#include <string.h>
int n,m;//n为邮票种类,m为一封信上最多贴的邮票个数
int Max;
int ans[10000];//最终答案数组
int min(int a,int b)
{
    return a<b?a:b;
}
int panduan(int x[10000],int n,int sum)//能否用n种邮票，
//面值在x数组中,最多贴m张，表示出sum(是个动态规划问题，
//方法是求出dp[n][sum]看它是否小于sum,状态转移方程
//dp[i][j]=min(dp[i-1][j-k*x[i]]+k)(其中dp[i][j]表示用到第i种邮票，
//表示邮资为j的最少邮票
 {
     int i,j,k;
     int dp[15][1005];
     for (i=0;i<=n;i++)
        dp[i][0]=0;
       for (i=0;i<=sum;i++)
        dp[1][i]=i;
     for (i=2;i<=n;i++)
        for (j=1;j<=sum;j++)
     {
         dp[i][j]=9999;
         for (k=0;k<=j/x[i];k++)
            dp[i][j]=min(dp[i][j],dp[i-1][j-x[i]*k]+k);
     }
     if (dp[n][sum]>m)
        return 0;
        return 1;

 }
void DFS(int x[10000],int cur,int max)
{
    int i,j,next;
    if (cur==n)//如果已经得出了n种邮票
    {
        if (max>Max)//并且它的最大值已经大于当前最大邮资数
        {
            Max=max;
            for (i=1;i<=cur;i++)
                ans[i]=x[i];//更新答案数组

        }
         return;
    }
        for (next=x[cur]+1;next<=max+1;next++)//如果还没得到n中邮票，
        //那么从x[cur]+1~max+1选一个作为下一个邮资，因为max+1
        //没法表示，所以必定到max+1为止
        {
          x[cur+1]=next;//接下来是重点，用种类为cur+1,数目分别为
          //x[1..cur+1]的邮票,最多使用m张，能否表示出大于max的某个数
             for (i=max+1;i<=m*x[cur+1];i++)//这个数最少要为max+1(不然
             //没有意义了),最多是x[cur+1]*m
                if (panduan(x,cur+1,i)==0)//如果成立
                break;
                if (i>max+1)//如果至少让最大值更新了一次
                DFS(x,cur+1,i-1);
       }

}
int main() {
  int i, j, max, cur;
  int x[1000]; //中间传递的数组，存储当前的邮票值的解
  scanf("%d%d", &n, &m);
  Max = 0;
  max = m;
  cur = 1;
  x[cur] = 1;
  DFS(x, cur,
      max); // x存储当前的解,cur表示当前传递到
      //第几种邮票,max表示目前能表示到的最大值
  printf("%d\n", Max);
  for (i = 1; i <= n; i++)
    printf("%d ", ans[i]);
  return 0;
}