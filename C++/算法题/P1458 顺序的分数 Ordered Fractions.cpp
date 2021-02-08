#include <iostream>
#include <map>
using namespace std;
struct number {
  int x, y;
};
int main(){
  int n;
  while (cin >> n) {
    number t;
    map<double, number> p;
    map<double, number>::iterator q;
    for (int i = 1; i <= n; i++)
      for (int j = 0; j <= i; j++) {
        double m = 1.0 * j / i;
        if(p.find(m)==p.end())
        t.x = j, t.y = i, p[m] = t;
      }
    for (q = p.begin(); q != p.end();q++)
      cout << q->second.x << "/" << q->second.y << endl;
  }
  return 0;
}
        
/*
输入一个自然数N,对于一个最简分数a/b
（分子和分母互质的分数）,满足1<=b<=N,0<=a/b<=1,
请找出所有满足条件的分数。

这有一个例子，当N=5时，所有解为：

0/1 1/5 1/4 1/3 2/5 1/2 3/5 2/3 3/4 4/5 1/1

给定一个自然数N，1<=n<=160，请编程按分数值递增
的顺序输出所有解。

注：①0和任意自然数的最大公约数就是那个自然数②
互质指最大公约数等于1的两个自然数。

输入输出格式

输入格式：
单独的一行一个自然数N(1..160)

输出格式：
每个分数单独占一行，按照大小次序排列

输入输出样例

输入样例#1： 复制
5
输出样例#1： 复制
0/1
1/5
1/4
1/3
2/5
1/2
3/5
2/3
3/4
4/5
1/1
说明

USACO 2.1

翻译来自NOCOW
*/