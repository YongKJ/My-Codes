#include <iostream>
#include <cstring>
#include <queue>
#include <cstdio>
using namespace std;
struct Node{
  int x,y;
}Now,Next;
int MAP[2500][2500];             // 直接把大于0的数改成0就行了，所以不需要开标记数组
int dir[4][2] = {1,0,0,1,-1,0,0,-1};
int T,n,m;


void bfs(){                     // bfs过程
  queue<Node> q;
  Now.x = 0;
  Now.y = 0;
  q.push(Now);
  while(!q.empty()){
    Now = q.front();
    q.pop();
    for(int i=0;i<4;i++){
      Next.x = Now.x + dir[i][0];
      Next.y = Now.y + dir[i][1];
      if(Next.x>=0&&Next.y>=0&&Next.x<=n+1&&Next.y<=m+1&&MAP[Next.x][Next.y]!=0){
        MAP[Next.x][Next.y] = 0;
        q.push(Next);
      }
    }
  }
}


int main()
{
  scanf("%d",&T);
  while(T--){
    scanf("%d%d",&m,&n);
    memset(MAP,1,sizeof(MAP));         // 预处理
    for(int i=1;i<=n;i++){             // 从1开始输入，相当于地图外面有一圈 1
      for(int j=1;j<=m;j++){
        scanf("%d",&MAP[i][j]);
      }
    }
    bfs();
    for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
  printf("%d ",MAP[i][j]);
    }
    printf("\n");
  }
  }
  return 0;
}
/***
   [来源] NYOJ 92
   [题目] 图像有用区域
   [思路]
      因为要把没有被0包围住的数都改成0，所以可以在输入的地图外面预处理加一圈1，
      然后从0 0开始广搜，把遇到的正数都换成0，需要注意的是，题上的W,H指的是宽
      和高，之前一直当成高和宽，然后一直WA,，而且题上的W,H范围也反了，但是都开
      大点就没有什么影响了。
   [输入]
      1
      5 5
      100 253 214 146 120
      123 0 0 0 0
      54 0 33 47 0
      255 0 0 78 0
      14 11 0 0 0
   [输出]
      0 0 0 0 0
      0 0 0 0 0
      0 0 33 47 0
      0 0 0 78 0
      0 0 0 0 0
*/