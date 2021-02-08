#include <iostream>
#include <set>
using namespace std;
int main(){
  int n, m;
  while (cin >> n) {
    set<int> x;
    set<int>::iterator p;
    while (n--)
      cin >> m, x.insert(m);
    cin >> n;
    while (n--)
      cin >> m, x.insert(m);
    for (p = x.begin(); p != x.end(); p++)
      cout << *p << (p != --x.end() ? " " : "\n");
  }
  return 0;
}
  	
/*
输入


 只有一个测试案例。

输入包括2行，第1行为n和n个整数，第2行为m和m个整数。

输出


线性表c中的元素。注意：整数之间有1个空格，最后一个整数后面没有空格。

样例输入

3 1 4 5
4 2 6 7 8

样例输出

1 2 4 5 6 7 8
*/