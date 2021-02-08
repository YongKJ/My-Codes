#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int n;
int prime[40]={0,0,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,1,0,0};
//prime[i]表示i是否为素数
int a[30];
int visited[30];
int flag=0;
void DFS(int lest)
{
    if(lest>n)//第一个退出条件
        return;

    if(lest==n)//第二个退出条件
    {
        if(prime[a[n]+a[1]]==1)
        {
            flag=1;
            for(int i=1;i<=n;i++)
                printf("%d ",a[i]);
            printf("\n");
        }

    }
    //以上两个条件都是剪枝的内容

    for(int i=1;i<=n;i++)
    {
        if(visited[i]==0 && prime[a[lest]+i]==1)
        {
            a[lest+1]=i;
            visited[i]=1; 
            DFS(lest+1);
            visited[i]=0;

        }

    }

}
int main()
{
    int i=0;
    while(scanf("%d",&n)!=EOF && n!=0)
    {

        memset(visited,0,sizeof(visited));
        memset(a,0,sizeof(a));
        i++;
        flag=0;
        printf("Case %d:\n",i);
        a[1]=1;
        visited[1]=1;
        if (n == 1) //特殊情况
        {
          printf("%d\n", 1);
          continue;
        }
        if (n % 2 == 0) //奇数不可能成立，也是剪枝内容
          DFS(1);

        if (flag == 0)
          printf("No Answer\n");
    }
    return 0;
}
  	
/*
描述


将1-n这n个数摆成一个环，要求相邻的两个数的和
是一个素数，编程输出所有可能的解。

输入


包括多组数据，每组1个数n。n<20

输出


所有可能的解。

输出格式见样例。

样例输入

6
8

样例输出

Case 1:
1 4 3 2 5 6
1 6 5 2 3 4

Case 2:
1 2 3 8 5 6 7 4
1 2 5 8 3 4 7 6
1 4 7 6 5 8 3 2
1 6 7 4 3 8 5 2
*/