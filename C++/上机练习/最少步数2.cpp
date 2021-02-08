#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
int x1,y1,x2,y2;
int go[4][2]= {{1,0},{-1,0},{0,-1},{0,1}};//上下左右四个方向
int map[9][9]=
{
    1,1,1,1,1,1,1,1,1,
    1,0,0,1,0,0,1,0,1,
    1,0,0,1,1,0,0,0,1,
    1,0,1,0,1,1,0,1,1,
    1,0,0,0,0,1,0,0,1,
    1,1,0,1,0,1,0,0,1,
    1,1,0,1,0,1,0,0,1,
    1,1,0,1,0,0,0,0,1,
    1,1,1,1,1,1,1,1,1
};


struct Node
{
    int x,y,s;
};
bool vis[10][10];//走过的标记为1，没走的标记为0
int bfs(int x,int y)
{
    Node now,to;//现在的和将要走的
    now.x=x,now.y=y,now.s=0;
    queue<Node>q;
    vis[x][y]=1;//把当前的坐标标记
    q.push(now);
    while(!q.empty())
    {
        now=q.front();
        if(now.x==x2&&now.y==y2) return now.s;//满足条件，返回步数
        q.pop();
        for(int i=0;i<4;i++)
        {
            int xx=now.x+go[i][0],yy=now.y+go[i][1];//下一步要走的坐标
            if(xx>=0&&xx<9&&yy>=0&&yy<9&&map[xx][yy]==0&&vis[xx][yy]==0)//判断是否越界
            {
                vis[xx][yy]=1;//把走过的标记
                to.x=xx,to.y=yy,to.s=now.s+1;
                q.push(to);
            }
        }
    }
    return -1;//当队列为空，证明从起点到不了终点，返回-1
}
int main()
{
    int t;
    scanf("%d",&t);
    while (t--) {
      mem(vis, 0);                           //初始化标记数组
      scanf("%d%d%d%d", &x1, &y1, &x2, &y2); //输入起始和终点坐标
      printf("%d\n", bfs(x1, y1));
    }
    return 0;
}
/*
2
3 1 5 7
3 1 6 7
*/