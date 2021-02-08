#include <iostream>
#include <set>
using namespace std;
int main(){
  int n;
  while(cin>>n){
    set<int> x;
    set<int>::iterator p;
    int a, sum = 0;
    for (int i = 0; i < n; i++) {
      cin >> a;
      x.insert(a);
    }
    for (p = (++x.begin()); p != x.end(); p++)
      sum += *p;
    cout << sum << endl;
  }
  return 0;
}
/*
描述

在漆黑的夜里，n位旅行者来到了一座狭窄而且没有护栏的桥边。
如果不借助手电筒的话，大家是无论如何也不敢过桥去的。
不幸的是，他们一共只带了一只手电筒，而桥窄得只够让两个人同时过。
如果各自单独过桥的话，每人所需要的时间分别是a1、a2、...an分钟；
而如果两人同时过桥，所需要的时间就是走得比较慢的那个人单独行动时所需的时间。
问题是，如何设计一个方案，让这些人尽快过桥。

输入

输入分2行 
第一行是一个整数n(1<=n<=1000) 
第二行是n个整数，分别表示这n个人单独过桥需要的时间

输出

输出一行，他们过桥需要的总时间

样例输入

5
1 3 6 8 12

样例输出

29
*/