#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<string.h>
using namespace std;

int map[102][102];
int height[102][102];
bool vis[102][102];
int R, C;
int ans;
int END;
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

bool check(int x,int y)
{
	if (x<1 || x>R || y<1 || y>C)
		return false;
	return true;
}

int dfs(int i,int j)
{
	if (height[i][j]) return height[i][j];//如果这个点的最长步数已知，就返回
	height[i][j] = 1;//没返回说明不知道，设为1
	for (int k = 0; k < 4; k++)//搜索4个方向
	{
		int tx = i + dx[k]; int ty = j + dy[k];//下一步的位置
		if (check(tx,ty)&&map[tx][ty] < map[i][j])//如果下一步的高度比当前高度低而且没出界,继续搜索
			height[i][j] = max(height[i][j], 1 + dfs(tx, ty));//当前的位置的最长高度等于现在位置的高度与1+dfs(下一个位置的最长高度)的最大值
	}
	return height[i][j];
}

int main()
{
	memset(height, 0, sizeof(height));
	cin >> R >> C;
	for (int i = 1; i <= R;i++)
	for (int j = 1; j <= C; j++)
		cin >> map[i][j];
	//搜索每一个点
	for (int i = 1; i <= R;i++)
          for (int j = 1; j <= C; j++) {
            ans = max(dfs(i, j), ans);
          }
        cout << ans;
        return 0;
}
/*
5 5
1 2 3 4 5
16 17 18 19 6
15 24 25 20 7
14 23 22 21 8
13 12 11 10 9

思路：用一个额外的数组记录每个位置的最长步数，
在搜索时如果遇到已经知道该位置的最长步数
就返回该位置的最长步数，节省搜索时间。
*/