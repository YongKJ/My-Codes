#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int max_size=110;
int R,C;
int dir[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
int h[max_size][max_size],dp[max_size][max_size];
int inMap(int x,int y){
     if(x>=0&&x<=R-1&&y>=0&&y<=C-1) return 1;
     return 0;
 }
 int max2(int a,int b,int c,int d){
     return max(max(a,b),max(c,d));
}
 int dfs(int i,int j){
    int nx,ny,down=0,up=0,left=0,right=0;
     if(dp[i][j]) return dp[i][j];
     nx=i+dir[0][0]; ny=j+dir[0][1];
     if(inMap(nx,ny)){
         if(h[i][j]>h[nx][ny]) up=dfs(nx,ny);
     }
     nx=i+dir[1][0]; ny=j+dir[1][1];
     if(inMap(nx,ny)){
         if(h[i][j]>h[nx][ny]) right=dfs(nx,ny);
     }
     nx=i+dir[2][0]; ny=j+dir[2][1];
     if(inMap(nx,ny)){
         if(h[i][j]>h[nx][ny]) down=dfs(nx,ny);
     }
    nx=i+dir[3][0]; ny=j+dir[3][1];
    if(inMap(nx,ny)){
         if(h[i][j]>h[nx][ny]) left=dfs(nx,ny);
     }
     dp[i][j]=max2(up,down,left,right)+1;
     return dp[i][j];
 }
int main(){
     scanf("%d%d",&R,&C);
     memset(h,0,sizeof(h));
     memset(dp,0,sizeof(dp));
     for(int i=0;i<R;i++){
         for(int j=0;j<C;j++){
             scanf("%d",&h[i][j]);
         }
     }
     int ans=-1;
     for(int i=0;i<R;i++){
       for (int j = 0; j < C; j++) {
         ans = max(ans, dfs(i, j));
       }
     }
     printf("%d\n", ans);
}
/*
描述


每到冬天,信息学院的张健老师总爱到二龙山去滑雪,
喜欢滑雪百这并不奇怪， 因为滑雪的确很刺激。
可是为了获得速度，滑的区域必须向下倾斜，
而且当你滑到坡底，你不得不再次走上坡或者等待升
降机来载你。张老师想知道载一个区域中最长底滑坡。
区域由一个二维数组给出。数组的每个数字代表点的
高度。

    一个人可以从某个点滑向上下左右相邻四个点之一，
    当且仅当高度减小。在下面的例子中，一条可滑行的
    滑坡为24-17-16-1。当然25-24-23-...-3-2-1更长。
    事实上，这是最长的一条。
输入

输入的第一行表示区域的行数R和列数C(1 <= R,C <= 100)。
下面是R行，每行有C个整数，代表高度h，0<=h<=10000。

输出

输出最长区域的长度。

样例输入

5 5
1 2 3 4 5
16 17 18 19 6
15 24 25 20 7
14 23 22 21 8
13 12 11 10 9

样例输出

25

提示


记忆式搜索
*/