#include <string.h>
#include <algorithm>
#include <queue>
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
int x1,y1,x2,y2,min1=999999;//min1代表最小的步数
int go[4][2]= {{1,0},{-1,0},{0,-1},{0,1}};
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
void dfs(int x,int y,int s)
{
    if(x==x2&&y==y2)
    {
        min1=min(min1,s);
        return ;
    }//搜索结束条件，并且更新Min1
   
    if(s>min1) return ;//剪枝，当步数比这个min1大的时候没有搜索下去的必要了
    
    for(int i=0; i<4; i++)
    {
        int xx=x+go[i][0],yy=y+go[i][1];//下一步要到达的地方
        if(xx>=0&&xx<9&&yy>=0&&yy<9&&map[xx][yy]==0)//判断是否越界
        {
            map[xx][yy]=1;//先把走过的标记为墙
            dfs(xx,yy,s+1);//搜索下一层
            map[xx][yy]=0;//还原迷宫
        }
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    while (t--) {
      min1 = 999999;                         //初始化min1
      scanf("%d%d%d%d", &x1, &y1, &x2, &y2); //输入起始和终点坐标
      dfs(x1, y1, 0);                        //从0开始深搜
      printf("%d\n", min1);
    }
    return 0;
}
/*
描述

这有一个迷宫，有0~8行和0~8列：

 1,1,1,1,1,1,1,1,1
 1,0,0,1,0,0,1,0,1
 1,0,0,1,1,0,0,0,1
 1,0,1,0,1,1,0,1,1
 1,0,0,0,0,1,0,0,1
 1,1,0,1,0,1,0,0,1
 1,1,0,1,0,1,0,0,1
 1,1,0,1,0,0,0,0,1
 1,1,1,1,1,1,1,1,1

0表示道路，1表示墙。

现在输入一个道路的坐标作为起点，
再如输入一个道路的坐标作为终点，
问最少走几步才能从起点到达终点？

（注：一步是指从一坐标点走到其
上下左右相邻坐标点，如：从（3，1）
到（4,1）。）

输入

第一行输入一个整数n（0<n<=100），表示有n组测试数据;
随后n行,每行有四个整数a,b,c,d（0<=a,b,c,d<=8）分别表示起点的行、列，终点的行、列。

输出

输出最少走几步。

样例输入

2
3 1 5 7
3 1 6 7

样例输出

12
11

提示

DFS 或者BFS
*/