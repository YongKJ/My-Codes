#include <iostream>
using namespace std;
struct rectangle {
  int x1, y1, x2, y2;
};
struct point {
  int x, y, sum, last;
};
int main(){
  int n, m, x, y;
  while(cin>>n>>m>>x>>y){
    rectangle s1[x];
    point s2[y];
    for (int i=0;i<x;i++)
      cin >> s1[i].x1 >> s1[i].y1 >> s1[i].x2 >> s1[i].y2;
    for (int i = 0; i < y; i++) {
      cin >> s2[i].x >> s2[i].y;
      s2[i].sum = s2[i].last = 0;
    }
    for (int i=0;i<y;i++)
     for (int j=0;j<x;j++)
     if((s1[j].x1<=s2[i].x&&s2[i].x<=s1[j].x2)&&(s1[j].y1<=s2[i].y&&s2[i].y<=s1[j].y2))
       s2[i].sum++, s2[i].last = j + 1;
    for (int i = 0; i < y; i++) {
      cout << (s2[i].sum ? "Y " : "N\n");
      if (s2[i].sum)
        cout << s2[i].sum << " " << s2[i].last << endl;
    }
  }
  return 0;
}
      
/*
题目背景

一个大小为N*M的城市遭到了X次轰炸，每次都炸了一个每条边
都与边界平行的矩形。

题目描述

在轰炸后，有Y个关键点，指挥官想知道，它们有没有受到过
轰炸，如果有，被炸了几次，最后一次是第几轮。

输入输出格式

输入格式：
第一行，四个整数：n、m、x、y。

以下x行，每行四个整数：x1、y1、x2、y2，表示被轰炸的矩形
的左上角坐标和右下角坐标（比如1 3 7 10就表示被轰炸的地方
是从(1,3)到(7,10)的矩形）。

再以下y行，每行两个整数，表示这个关键点的坐标。

输出格式：
共y行，

每行第一个字符为Y或N，表示是否被轰炸，若为Y，在一个空格后
为两个整数，表示被炸了几次和最后一次是第几轮。

输入输出样例

输入样例#1： 复制
10 10 2 3
1 1 5 5
5 5 10 10
3 2
5 5
7 1
输出样例#1： 复制
Y 1 1
Y 2 2
N
说明

数据很弱！！！直接模拟！！！！

1<=N,M<=100
*/