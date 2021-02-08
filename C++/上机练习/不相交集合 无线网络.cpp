#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int map[1005][1005];
int mul(int x)
{
    return x*x;
}
int f[1005];
int find(int x)
{
    if(f[x]!=x)
        f[x]=find(f[x]);
    return f[x];
}
void merge(int a,int b)
{
    int f1=find(a);
    int f2=find(b);
    if(f1!=f2)
    {
        f[f2]=f1;
    }
}
void check(int a,int b)
{
    int f1=find(a);
    int f2=find(b);
    if(f1==f2)
    {
        printf("SUCCESS\n");
        return;
    }
    printf("FAIL\n");
}

int main()
{
    int n,flag[1005];
    double d;   
//  freopen("d:\\4.in","r",stdin);
//  freopen("d:\\4.out","w",stdout);
    memset(map,0,sizeof(map));
    memset(flag,0,sizeof(flag));
    scanf("%d%lf",&n,&d);
    int x[1005],y[1005],i,j;
    for(i=1;i<=n;i++)
        scanf("%d%d",&x[i],&y[i]);
    for(i=1;i<=n;i++)
        f[i]=i;
    for(i=1;i<n;i++)
        for(j=i+1;j<=n;j++)
            if(sqrt((double)(mul(x[i]-x[j])+mul(y[i]-y[j])))<=d)
            {
                map[i][j]=1;
                map[j][i]=1;
            }
    char s[5];
    int a,b;
    while(scanf("%s",s)!=EOF)
    {
        if(strcmp(s,"O")==0)
        {
            scanf("%d",&a);
            flag[a]=1;
            for(i=1;i<=n;i++)
                if(map[i][a]&&flag[i])
                    merge(a,i);
        } else {
          scanf("%d%d", &a, &b);
          check(a, b);
        }
    }
    return 0;
}
/*
题解

典型的并查集思想。 
对于O字符操作，是修该电脑，修好之后，要循环判断
一次，多少电脑能与该修复的电脑互联。 
对于S操作，即是判断两台电脑是否属于同于集合就行。
*/
/*
描述


一场地震在东南亚发生了。不幸的是ACM组织通过电脑
建立的无线网络遭到了毁灭性的影响—--网络中所有的电
脑都损坏了。在陆续的维修电脑之后，无线网络有逐渐
开始再一次运作了。由于硬件的制约，每两台电脑只能
保持不超过d米的距离，才可以直接进行通讯。但是每
台电脑又可以作为其它两台电脑通讯的中介点，也就是
说假设A电脑与B电脑不在能直接通讯的的范围内，但是
它们可以通过同时能与A和B电脑通讯的C电脑建立间接
通讯关系。
在维修的过程中，维修者可以进行两种操作：维修一台电
脑或者检测两台电脑之间是否能够通讯。你的任务就是解
答每一次的检测操作。

输入


第一行包含两个整数N和d (1 <= N <= 1001, 0 <= d <= 20000).
N表示电脑的数量，电脑编号从1开始到N，d为两台能直接通
讯的电脑所需保持的距离的最大值。在接下来的N行里，每行
包含两个整数xi, yi (0 <= xi, yi <= 10000),表示N台电脑的坐标。
接下来的一系列的输入都表示维修者的操作，每种操作都是
以下两种中的一种：
1. "O p" (1 <= p <= N),表示维修第p台电脑。
2. "S p q" (1 <= p, q <= N), 表示检测p与q电脑是否能够通讯。
输入不会超过300000 行。

输出


对于每组检测操作，若两台电脑能进行通讯就输出"SUCCESS"，
否则输出"FAIL"。

样例输入

4 1
0 1
0 2
0 3
0 4
O 1
O 2
O 4
S 1 4
O 3
S 1 4

样例输出

FAIL
SUCCESS
*/