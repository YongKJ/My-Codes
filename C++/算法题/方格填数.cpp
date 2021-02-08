#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
#define inf 0x3f3f3f3f
#define N 1000+10
#define LL long long
using namespace std;
int map[10][10];
int vis[10];
int cnt;
int go[4][2]= {{0,-1},{-1,-1},{-1,0},{-1,1}};//因为是从左到右从上到下依次，所以只需要搜索下，左下，左，左上，上四个方向即可
int judge(int x,int y,int num)
{
    for(int i=0;i<4;i++)
    {
        int xx=x+go[i][0];
        int yy=y+go[i][1];
        if(xx>=0&&xx<=2&&yy>=0&&yy<=3)//判断是否越界
        {
            if(map[xx][yy]==num-1||map[xx][yy]==num+1)//判断数字是否相邻
                return 0;
        }
    }
    return 1;
}
void dfs(int x,int y)
{
    if(x==2&&y==3)//(2,3)点时结束点的位置
    {
        cnt++;
        return;
    }
    if(y>3)//越界的时候，搜索下一层
    {
        dfs(x+1,0);
    }
    else
    {
        for(int i=0;i<=9;i++)//枚举要填的数
        {
            if(!vis[i]&&judge(x,y,i))
            {
                vis[i]=1;
                map[x][y]=i;//填数
                dfs(x,y+1);
                map[x][y]=-100;//搜索完毕，取消标记
                vis[i]=0;
            }
        }
    }
}
int main()
{
    for(int i=0; i<=2; i++)
        for(int j=0; j<=3; j++)
            map[i][j]=-100;//初始化一个最小值
    cnt=0;
    dfs(0,1);//因为(0,0)点没有,所以从(0,1)点搜索
    cout<<cnt<<endl;
    return 0;
}

/*
填入0-9的数字。要求：连续的两个数字不能相邻。
（左右、上下、对角都算相邻）
一共有多少种方案呢？
请用程序算出方案的数目，答案是一个整数。
*/ 
