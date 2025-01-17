#include<cstdio>
#include<string.h>
#include<iostream>
using namespace std;
const int maxn=100005;
int a[maxn];
int f[maxn];
int main()
{
   int n=0;
   int l,r,mid;
   while(scanf("%d",&a[++n])!=EOF)continue;
   n--;
   f[0]=1234123412;//这个数要大于50000，不然可能你就无法更新
   int ans1=0;
   for(int i=1;i<=n;i++){
          if(f[ans1]>=a[i]){
                f[ans1+1]=a[i];//结束点为a[i]
                ans1++; //当前最长不上升序列的长度加一
       }
       else {//二分查找
              l=0;r=ans1;
              while(l<r){
                     mid=(l+r)/2;
                    if(f[mid]>=a[i])l=mid+1;
                    else {
                        r=mid;    
              }
           }
           if(l!=0)f[l]=a[i];
       }
   }
   cout<<ans1<<endl;//输出第一问的答案
     memset(f,-1,sizeof(f));//这次前面要尽量小了，不然又无法更新
   int ans2=0;
   for(int i=1;i<=n;i++){
          if(f[ans2]<a[i]){
                f[ans2+1]=a[i];//结束点为a[i]
                ans2++; //当前最长上升序列长度加一
       }
       else {//二分查找
              l=0;r=ans2;
              while(l<r){
                     mid=(l+r)/2;
                    if(f[mid]>=a[i])r=mid;
                    else {
                      l = mid + 1;
                    }
              }
              f[l] = a[i];
       }
   }
   cout << ans2 << endl; //输出第二个答案
}
/*
题目描述

某国为了防御敌国的导弹袭击，发展出一种导弹拦截系统。但是这种导弹拦截系统有一个缺陷：虽然它的第一发炮弹能够到达任意的高度，但是以后每一发炮弹都不能高于前一发的高度。某天，雷达捕捉到敌国的导弹来袭。由于该系统还在试用阶段，所以只有一套系统，因此有可能不能拦截所有的导弹。

输入导弹依次飞来的高度（雷达给出的高度数据是50000≤50000的正整数），计算这套系统最多能拦截多少导弹，如果要拦截所有导弹最少要配备多少套这种导弹拦截系统。

输入输出格式

输入格式：
11行，若干个整数（个数100000≤100000）

输出格式：
22行，每行一个整数，第一个数字表示这套系统最多能拦截多少导弹，第二个数字表示如果要拦截所有导弹最少要配备多少套这种导弹拦截系统。

输入输出样例

输入样例#1： 复制
8
389 207 155 300 299 170 158 65
输出样例#1： 复制
6
2
说明

为了让大家更好地测试n方算法，本题开启spj，n方100分，nlogn200分

每点两问，按问给分
*/