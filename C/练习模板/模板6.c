#include <stdio.h>  
#include <stdlib.h>
#define MaxV 100				//  顶点个数最大值                
#define QueueSize 30           // 队列容量 
_Bool visited[MaxV];   
typedef struct     
{   	
		int vexs[MaxV];                    //顶点表   
    	int edges[MaxV][MaxV];     //邻接矩阵
    	int n,e;		//图中当前的顶点数和边数   
}MGraph;
//  建立图的邻接矩阵
void Create_Graph(MGraph *G)   
{   int i,j,k;   
    printf("请输入  顶点数,边数:\n");   
    scanf("%d,%d",&(G->n),&(G->e));     
    for(i=0;i<G->n;i++)  
		G->vexs[i]=i; 
    for(i=0;i<G->n;i++)   
           for(j=0;j<G->n;j++)   
                G->edges[i][j]=0;   
    printf("输入每条边的两个顶点的序号:\n");   
    for(k=0;k<G->e;k++)   
     {   scanf("%d,%d",&i,&j);   G->edges[i][j]=1;   }   
	printf("%d\n",k);
}

void DFS(MGraph G,int v)
{
	printf("%d",v);
	visited[v]=1;
	for(int w=0;w<G.n;w++)
		if(G.edges[v][w]&&!visited[w])
			DFS(G,w);
}
int main()
{
	MGraph g;
	Create_Graph(&g);
	DFS(g,0);
	printf("\n");
	return 0;
}

