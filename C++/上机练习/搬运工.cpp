#include <iostream>
#include <map>
#include <iomanip>
using namespace std;
int main(){
  int n, m;
  while(cin>>m>>n){
    int a, b;
    float sum = 0;
    map<int, int> x;
    map<int, int>::reverse_iterator p;
    while (n--) {
      cin >> a >> b;
      x[b] = a;
    }
    for (p = x.rbegin(); p != x.rend(); p++) {
      if (m >= p->second)
        sum += p->first * p->second, m -= p->second;
      else {
        sum += m * p->first;
        break;
      }
    }
    cout << fixed << setprecision(2) << sum << endl;
  }
  return 0;
}
/*
描述

搬运工的工作非常辛苦，不仅是因为要费体力，
而且干活要有技巧，不能总是用蛮力。
假设你是一名搬运工，给定一个最大载重量为
M公斤的卡车和N种食品，有食盐，白糖，大米等。
已知第 i 种食品的拥有Wi 公斤，其商品价值为Vi元/公斤，
编程确定一个装货方案，使得装入卡车中的所有物品
总价值最大。

输入

输入数据有多组，每组第1行有2个正整数，
分别为M和N（1 <= M,N <=100)，接下来有N行。
这N行里每行2个数，分别为正整数Wi和
正实数Vi(1.0 <= Wi,Vi <=100.0)代表每种食品的
重量和（价值/公斤）。

输出


对于每组数据输出卡车能装物品的最大值
（保留2位小数）。
样例输入

10 3
5 2
4 3
3 5


样例输出

33.00

提示


部分背包问题。
*/