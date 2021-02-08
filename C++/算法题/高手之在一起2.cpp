#include <iostream>
#include <set>
#include <cstdio>
using namespace std;
int main(){
  int n, m;
  while(cin>>n>>m){
    int sum = 0;
    set<string> s;
    for (int i = 0; i < n; i++) {
      char c;
      string str,s1;
      while ((c=getchar())!='\n')
        str += c;
      cout << str << " " << -1 << endl;
      cin >> s1, cout << s1 << 0 << endl;
      s.insert(str);
    }
    for (int i = 0; i < m; i++) {
      char c;
      string str;
      while ((c = getchar()) != '\n')
        str += c;
      cout << str << " " << -2 << endl;
      if (s.find(str) != s.end())
        sum++;
    }
    cout << sum << endl;
  }
  return 0;
}
/*
题目背景

高手是可以复活的，这点我们大家都知道。

题目描述

高手列出了一个详尽的日程表，这次他要追求的则是一个心灵纯洁的小萝莉。他和她都是要上课的，但是也会有时间空闲，于是高手决定无时无刻都要跟着她。为了她，高手决定转学到一年级。现在高手已经花重金买下了她的日程表，每一天都会有她的行踪。现在列出了高手方便去的地方，以及不方便去的地方。其中方便去的地方可以去无限次，不方便去的地方不能去，一共有nn个方便去的地点，mm天。高手想知道他在这mm天中，最多能和她在一起多久。不方便去的地方是不会列出的。

输入输出格式

输入格式：
第一行nmn,m。

接下来nn行，每行一个地名，高手方便去的地方。

接下来mm行，每行一个地名，她这一天在的地方。

输出格式：
一个整数，他们在同一个地方的天数。

输入输出样例

输入样例#1： 复制
1
2
WC
CLASS
WC
输出样例#1： 复制
1
说明

1m10000001≤m≤1000000
1n201≤n≤20
*/