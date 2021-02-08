#include <stdio.h>
#define MaxSize 8
void king(int m,int n)
{
    int p[MaxSize];
    int i,s=0,t;
    for (i=0; i<m; i++)         //构建初始序列，记录m只猴子在圈中
        p[i]=1;
    t=0;                        //首次报数的起始位置为0，是第1只猴子
    printf("出列顺序:");
    for (i=1; i<=m; )       //循环要执行m次，有m个猴子要出圈
    {
        s=s+p[t]; //s累加中，猴子在圈时加１相当于报数，出圈后是加０相当于没有报数。
        if(s==n)
        {
            p[t]=0;   //猴子出圈
            printf("%d ",t+1);      //输出出圈猴子的编号
            s=0;   //重新开始累加
            i++;   //报数的猴子加1
        }
        t=(t+1)%m;    //再报数时，从下一只猴子开始
    }
    printf("\n");
}

int main() 
{
  int m, n;
  scanf("%d %d", &m, &n);
  king(m, n);
  return 0;
}