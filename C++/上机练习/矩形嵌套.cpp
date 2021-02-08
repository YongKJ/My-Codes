#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE	100
typedef struct {
	int length;
	int width;
}Rectangle;
int G[MAXSIZE][MAXSIZE];
Rectangle rec[MAXSIZE];
int n;//矩形数 
int count;
//a可以嵌套在b中 
int isInside(Rectangle a, Rectangle b)
{
	return ((a.length < b.length && a.width < b.width)
			|| (a.length < b.width && a.width < b.length)) ? 1 : 0;
}
void dp(int row, int length)
{
	if(length > count)
		count = length;
	printf("length=%d\n", length);
	for(int j = 0; j < n; j++)
	{
		if(G[row][j] > 0)
		{
			printf("%d->%d\n", row, j);
			dp(j, length + 1);
		}
	}
}
int main()
{
	scanf("%d", &n);
	int i = 0;
	while(i < n)
		scanf("%d%d", &rec[i].length, &rec[i++].width);
	for(i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			G[i][j] = isInside(rec[i], rec[j]);
	int max = 0;
	for(i = 0; i < n; i++)
	{
		count = 0;
		printf("begin from rect %d\n", i);
		dp(i, 1);
		if(count > max)
			max = count;
	}
	printf("%d\n", max);
	system("pause");
} 
/*
10
1 2
2 4
5 8
6 10
7 9
3 1
5 8
12 10
9 7
2 2
output
5
*/
/*
描述

有n个矩形，每个矩形可以用a,b来描述，表示长和宽。
矩形X(a,b)可以嵌套在矩形Y(c,d)中当且仅当a<c,b<d或
者b<c,a<d（相当于旋转X90度）。例如（1,5）可以嵌
套在（6,2）内，但不能嵌套在（3,4）中。你的任务是
选出尽可能多的矩形排成一行，使得除最后一个外，每
一个矩形都可以嵌套在下一个矩形内。

输入

第一行是一个正正数N(0<N<10)，表示测试数据组数，
每组测试数据的第一行是一个正正数n，表示该组测试
数据中含有矩形的个数(n<=1000)
随后的n行，每行有两个数a,b(0<a,b<100)，表示矩形的长和宽

输出

每组测试数据都输出一个数，表示最多符合条件的矩形数目，
每组输出占一行

样例输入

1
10
1 2
2 4
5 8
6 10
7 9
3 1
5 8
12 10
9 7
2 2

样例输出

5

提示

最长上升子序列
*/