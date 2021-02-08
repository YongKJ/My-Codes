#include <iostream>
using namespace std;
int sum=0,vis[10]={0},map[3][4],s[8][2]={0,-1,-1,-1,-1,0,-1,1,0,1,1,1,1,0,1,-1};
void dfs(int x,int y){
	if(x==2&&y==3){
		sum++;
		return;
	}
	if(y>3)dfs(x+1,0);
	else
	for(int i=0;i<=9;i++){
		int flag=1;
		for(int j=0;j<8;j++){
			int xx=x+s[j][0],yy=y+s[j][1];
			if(0<=xx&&xx<=2&&0<=yy&&yy<=3&&(map[xx][yy]==i-1||map[xx][yy]==i+1)){
			flag= 0;break;
			}
		}
		if(!vis[i]&&flag){
			vis[i]=1,map[x][y]=i;
			dfs(x,y+1);
			vis[i]=0,map[x][y]=-100;
		}
	}
}
int main(){
	for(int i=0;i<3;i++)
		for(int j=0;j<4;j++)
			map[i][j]=-100;
	dfs(0,1),cout<<sum<<endl;
	return 0;
}
/*
填入0-9的数字。要求：连续的两个数字不能相邻。
（左右、上下、对角都算相邻）
一共有多少种方案呢？
请用程序算出方案的数目，答案是一个整数。

*/
