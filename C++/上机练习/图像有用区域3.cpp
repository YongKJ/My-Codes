#include <cstdio>
#include <string>
#include <queue>
using namespace std;

int vis[970][1555];
int  mp[970][1555];

int w,h;
struct Node{
	int x,y;
};

int dir[4][2]={-1,0,1,0,0,-1,0,1};

void  bfs(){
	Node a,b;
	a.x=0;
	a.y=0;
	memset(vis,0,sizeof(vis));
	vis[a.x][a.y]=1;
	queue<Node>Q;
	Q.push(a);	
	while(!Q.empty()){
		a=Q.front();
		Q.pop();
		
		for(int i=0;i<4;i++)
		{
			b.x=a.x+dir[i][0];
			b.y=a.y+dir[i][1];
			if(b.x>=0&&b.y>=0&&b.x<=h+1&&b.y<=w+1&&!vis[b.x][b.y]&&mp[b.x][b.y])
			{
			vis[b.x][b.y]=1;
			Q.push(b);	
			}
			
		
		}
		
	}
	return ;
}

int main(){
	
	int t;
	scanf("%d",&t);
	
	while(t--){
		
		
		scanf("%d%d",&w,&h);
		for(int i=0;i<=h+1;i++)//加外圈
		{
			for(int j=0;j<=w+1;j++)
			{
				mp[i][j]=1;
				
			}
		}
		
	
		
		for(int i=1;i<=h;i++)
		{
			for(int j=1;j<=w;j++)
			{
				scanf("%d",&mp[i][j]);
			}
		}
		
		bfs();
		
		for(int i=1;i<=h;i++)
		for(int j=1;j<=w;j++)
		{
			if(vis[i][j])
			mp[i][j]=0;
		}
		for(int i=1;i<=h;i++)
		{
                  for (int j = 1; j <= w; j++) {
                    printf("%d ", mp[i][j]);
                  }
                  printf("\n");
                }
        }
}