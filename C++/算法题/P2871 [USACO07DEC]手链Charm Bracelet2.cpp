#include<iostream>
#include<algorithm> 
using namespace std;
struct bag{
	int w;//物品的重量
	int v;//物品的价值
	double c;//物品的性价比 
};
struct bag a[100];
int cmp(bag a,bag b)
{
	if(a.c>=b.c)
		return 1;
	return 0;
}
//返回背包中物品的价值
double backpack(int n,bag a[],double c)//n表示物品的数量，a表示按照物品性价比排序后的数组，c表示剩余空间 
{
	int i=0;
	int b=0;//获得的价值
	//当物品i可以装入背包中
	while(i<n&&a[i].w<c)
	{
		c=c-a[i].w;
		b+=a[i].v;
		i++;	
	}	
	//说明物品不能完全装入背包 
	if(i<n)
		b+=1.0*a[i].v*c/a[i].w ;
	return b;
} 
int main()
{
	int c;
	int n;
	int i;
	while(cin>>c>>n&&c)
	{
		for(i=0; i<n; i++)
		{
			cin>>a[i].w>>a[i].v;
			a[i].c = 1.0*a[i].v/a[i].w;
		}
		sort(a, a+n, cmp);//按照性价比排序 
		cout<<backpack(n,a,c);
	}
	return 0;	
} 
/*
输入样例#1： 复制
6 4
1 4
2 6
3 12
2 7
输出样例#1： 复制
23
*/