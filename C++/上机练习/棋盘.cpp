#include<stdio.h>
int d[1111][1111];
int num=1;

void chess(int st , int en , int x , int y , int size)
{
	if(size<=1)
		return;
	int s=size>>1;
	int t=num++;
	if(x<s+st&&y<s+en) //左上方；
		chess(st,en,x,y,s);
	else
	{
		d[s+st-1][s+en-1]=t;
		chess(st,en,s+st-1,s+en-1,s);
	}
	if(x>=s+st&&y<s+en) //右上方；
		chess(s+st, en,x,y,s);
	else
	{
		d[s+st][s+en-1]=t;
		chess(s+st,en,s+st,en+s-1,s);
	}
	if(x<s+st&&y>=s+en) //左下方；
		chess(st,s+en,x,y,s);
	else
	{
		d[s+st-1][s+en]=t;
		chess(st,s+en,s+st-1,s+en,s);
	}
	if(x>=s+st&&y>=s+en) //右下方；
		chess(s+st,s+en,x,y,s);
	else
	{
		d[s+st][s+en]=t;
		chess(s+st,s+en,s+st,s+en,s);
	}
}

int main()
{
	int n , a1 ,a2,p,i;
	scanf("%d%d%d",&n,&a1,&a2);
	for(i=0,p=1;i<n;i++)
		p*=2;
	chess(1,1,a1,a2,p);
	for(a1=1;a1<=p;a1++)
	{
          for (a2 = 1; a2 < p; a2++) {
            printf("%d ", d[a1][a2]);
          }
          printf("%d\n", d[a1][a2]);
        }
        return 0;
}
/*
描述

TheBeet有一个块大小为(2N*2N)的棋盘。
这个棋盘是由一个个格子组成的。很不幸的，
在一个月黑风高的晚上，它被摔坏了。
不幸中的万幸，它只被摔坏了一个格子
（此格子可以在棋盘的任意位置）。

 

 
 

但是这个棋盘再也不能用来下棋了，
于是TheBeet想把这个棋盘切成如以下的
几种小块。但是TheBeet不想浪费任何一个格子，
您能帮助TheBeet么？

 


 

输入


每个输入文件只包含一组数据。

每组测试数据包含两行，第一行为N 
( 1 <= N <= 10)，表示棋盘的大小为2N。
接下来那行里面有两个数字x, y(1 <= x, y <= 2N)
表示这个残缺的格子在棋盘的第x行和第y列。

输出


如果不存在这样的划分情况，
您的程序只需要输出"-1"（不包含引号）。
否则输出整个棋盘的划分情况，每个相连的块用
一个正整数字（范围[1, (2N*2N-1) / 3]）来表示，
原先的空洞地方请输出0。如果有多个划分情况
满足题目要求，那么您只需要输出其中的一个。

样例输入

2
2 3

样例输出

2 2 3 3
2 1 0 3
4 1 1 5
4 4 5 5
*/