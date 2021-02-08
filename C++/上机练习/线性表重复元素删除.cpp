#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
  int n;
  vector<int> x;
  vector<int>::iterator p;
  do {
    cin >> n;
    if (find(x.begin(), x.end(), n) == x.end())
      x.push_back(n);
  } while (getchar() != '\n');
  for (p = x.begin(); p != x.end(); p++)
    cout << *p << (p != --x.end() ? " " : "\n");
  return 0;
}

/*
描述


给定n（0<n<100）个整数，删除其中重复的整数，
使各个整数仅保留一份。

输入


输入数据只有1行，其中有若干个整数。

输出


输出处理结果，换行。

样例输入

86 75 90 78 78 93 88 80 86 78

样例输出

86 75 90 78 93 88 80
*/