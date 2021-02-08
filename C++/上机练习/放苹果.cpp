#include <iostream>
#include <set>
using namespace std;
int n, m, sum;
set<int> p;
void apple(int x,int y) {
  if (x == n) {
    sum++;
    return;
  }else{
    for (int i = y; i >= 0; i--) {
      p.insert(i);
      if (p.find(i) != p.end())
        apple(x + 1, m - y);
    }
  }
}
int main(){
  int t;
  cin >> t;
  while (p.clear(),sum = 0, t--) {
    cin >> m >> n;
    apple(1,m);
    cout << sum << endl;
  }
  return 0;
}
	
	
/*
描述

把M个同样的苹果放在N个同样的
盘子里，允许有的盘子空着不放，
问共有多少种不同的分法？（用K表示）
5，1，1和1，5，1 是同一种分法。

输入

第一行是测试数据的数目t（0 <= t <= 20）。
以下每行均包含二个整数M和N，以空格
分开。1<=M，N<=10。

输出

对输入的每组数据M和N，用一行输出相应的K。

样例输入

1
4 2

样例输出

3
*/