#include <iostream>
using namespace std;
int gcd(int x);
int main(){
  int n;
  cin >> n;
  for (int a = n;; a++) {
    int b = gcd(a);
    if (gcd(b) != b && gcd(b) == a) {
      cout << a << " " << b << endl;
      break;
    }
  }
  return 0;
}
int gcd(int x) {
  int sum = 1;
  for (int i = 2; i <= x / 2; i++)
    if (x % i == 0)
      sum += i;
  return sum;
}
/*
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
int n;
int gcd(int x)//这是一个求约数和的函数 
{
    int ans=0;
    for(int i=1;i<=x/2;i++)//循环到x/2可以省一些时间。 
    {
        if(x%i==0) ans+=i;//如果能整除就加上 
    }
    return ans;//返回。 
}
int main()
{
    scanf("%d",&n);//输入 
    for(int i=n;i;i++)//要不小于n的第一对 
    {
        if(gcd(i)!=gcd(gcd(i)) && gcd(gcd(i))==i)//先判断不能是自己，然后在判断两个数的约数和是否是等于对方 
        {
            printf("%d %d\n",i,gcd(i));//是就输出 
            return 0;//程序白白 
        }
    }
    return 0;
}
*/
/*
题目背景

小可可和所有其他同学的手腕上都戴有一个射频识别序列号码牌，这样老师就可以方便的计算出他们的人数。很多同学都有一个“好朋友” 。如果 A 的序列号的约数之和恰好等于B 的序列号，那么 A的好朋友就是 B。在这里，一个数的约数不包括这个数本身。因为一些同学的号码约数和大于其他任何同学的号码，所以这些同学没有好朋友。一些同学有一个“非常好友” 。当两个同学互为“好朋友”时，他们就是一对“非常好友” 。注意在这道题中，忽略那些自己是自己的“非常好友”的情况。

题目描述

给定一个序列号 S（6≤S≤18000） ，找出序列号不小于 S 的第一对“非常好友” 。

输入输出格式

输入格式：
一行一个整数S，即给定的序列号。

输出格式：
一行两个整数A 和 B（用空格隔开） 。A 表示第一个序列号不小于 S 的有“非常好友”的同学，B 是 A 的“非常好友” 。

输入输出样例

输入样例#1： 复制
206
输出样例#1： 复制
220 284
*/
/*
亲密数
如果a的所有正因子和等于b，b的所有正因子和等于a，因子包括1但不包括本身，且a不等于b，则称a，b为亲密数对。一般通过叠代编程求出相应的亲密数对。

#include<stdio.h>
int main()
{
int a,i,b,n;
printf("There are following friendly--numbers pair smaller than 3000:\n");
for(a=1;a<3000;a++) //穷举3000以内的全部整数
{
  for (b = 0, i = 1; i <= a / 2; i++) //计算数a的各因子，各因子之和存放于b
    if (!(a % i))
      b += i; //计算b的各因子，各因子之和存于n
  for (n = 0, i = 1; i <= b / 2; i++)
    if (!(b % i))
      n += i;
  if (n == a && a < b)
    printf("%4d..%4d ", a, b); //若n=a，则a和b是一对亲密数，输出
}
}
*/