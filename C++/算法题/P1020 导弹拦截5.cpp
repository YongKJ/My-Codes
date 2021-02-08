#include<iostream>
using namespace std;
int n;
int h[1001],ht[1001],best[1001];
int ans=0;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	   cin>>h[i];
    best[0]=0x7fffffff;
    for(int i=1;i<=n;i++)
    	for(int j=ans;j>=0;j--)
    	   if(best[j]>=h[i]){best[j+1]=h[i];ans=max(ans,j+1);break;}
    cout<<ans;
    ans=0;
    for(int i=1;i<=n;i++)
    {
       for(int j=0;j<=ans;j++)
          {
         if (ht[j] >= h[i]) {
           ht[j] = h[i];
           break;
         }
       }
       if (ht[ans] < h[i])
         ht[++ans] = h[i];
    }
    cout << ' ' << ans;
    return 0;
}
/*
题目描述

某国为了防御敌国的导弹袭击，发展出一种导弹拦截系统。但是这种导弹拦截系统有一个缺陷：虽然它的第一发炮弹能够到达任意的高度，但是以后每一发炮弹都不能高于前一发的高度。某天，雷达捕捉到敌国的导弹来袭。由于该系统还在试用阶段，所以只有一套系统，因此有可能不能拦截所有的导弹。

输入格式输入数据为两行， 
第一行为导弹的数目N(n<=1000)

第二行导弹依次飞来的高度，所有高度值均为不大于30000的正整数。

输出格式输出只有一行是这套系统最多能拦截的导弹数和要拦截所有导弹最少要配备这种导弹拦截系统的套数。两个数据之间用一个空格隔开. 
样例输入
8
389 207 155 300 299 170 158 65

样例输出

6 2
*/