#include <iostream>
#include <cmath>
using namespace std;
int main(){
  long long n, f[49], x = 1, p = pow(2, 31);
  cin >> n;
  f[1] = f[2] = 1;
  for (int i=3;i<=n;i++)
    f[i] = (f[i - 1] + f[i - 2])%p;
  cout << f[n] << "=";
  for (int i=2;i<=f[n];i++)
    while (!(f[n] % i)) {
      if (x)
        x = 0, cout << i;
      else
        cout << '*' << i;
      f[n] /= i;
    }
  cout << endl;
  return 0;
}
/*

#include<bits/stdc++.h> 
using namespace std; 
long long n,f[49],x=1;
const long long p=pow(2,31);
int main()
{
    cin>>n;
    f[1]=1;
    f[2]=1;
    for(int i=3;i<=n;i++)
        f[i]=(f[i-1]+f[i-2])%p;//算斐波那契数列
    cout<<f[n]<<"=";
    for(int i=2;i<=f[n];i++){
        for(;f[n]%i==0;){
            if(x){x=0;cout<<i;}
            else cout<<'*'<<i;
            f[n]/=i;
        }
    }
    cout<<endl;
}

题目背景
大家都知道，斐波那契数列是满足如下性质的
一个数列：

f(1) = 1 f(1)=1
f(2) = 1f(2)=1
f(n) = f(n-1) + f(n-2)f(n)=f(n−1)+f(n−2) (n ≥ 2n≥2 且 nn 为整数)。
题目描述
请你求出第nn个斐波那契数列的数mod（或%）2^{31}2 
31
 之后的值。并把它分解质因数。

输入输出格式
输入格式：
n

输出格式：
把第nn个斐波那契数列的数分解质因数。

输入输出样例
输入样例#1： 
5
输出样例#1： 
5=5
输入样例#2： 
6
输出样例#2： 
8=2*2*2
说明
n \le 48n≤48
*/