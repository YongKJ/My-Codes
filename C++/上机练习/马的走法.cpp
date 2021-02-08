#include<stdio.h>
#include<string.h>
//注意数组下标从0开始，不是1，所以会有实际位置与数组下标相差1.
//int a[5][6];
int chess[4][5];//棋盘状态
const int t[2][8] = {{-1,-1,-2,-2,2,2,1,1},{-2,2,1,-1,1,-1,2,-2}};//马步方向
int sx,sy,tot;
void find_w(int p1,int p2);
int main(){
	while(scanf("%d%d",&sx,&sy)!=EOF){
		if(sx<0||sy<0||sx>4||sy>5){
			printf("ERROR\n"); continue;
		}
		memset(chess,0,sizeof(chess));
		chess[sx-1][sy-1]=1;
		tot = 0;
		find_w(sx-1,sy-1);
		printf("%d\n",tot);
	}
	return 0;
}
void find_w(int p1,int p2)	//(p1,p2)表示当前所在的位置
{
	int pi,pj,i;
	for(i=0;i<8;i++){
		pi = p1 + t[0][i];
		pj = p2 + t[1][i];
                if (pi >= 0 && pj >= 0 && pi <= 3 && pj <= 4 &&
                    chess[pi][pj] == 0) 
                  chess[pi][pj] = 1, find_w(pi, pj), chess[pi][pj] = 0;
                else if (pi + 1 == sx && pj + 1 == sy)
                  tot++;
        }
}
/*
描述

        在一个4*5的棋盘上，输入马的
        起始位置坐标（纵、横），求马
        能返回初始位置的所有不同走法的
        总数（马走过的位置不能重复,马走
        “日”字）。

输入

多个测试数据。 每组2个数，
表示起始位置坐标。

输出

输出不同走法的总数。

样例输入

2 2
1 3

样例输出

4596
4772

提示

DFS
2
4 5 2 2
4 5 1 3

*/