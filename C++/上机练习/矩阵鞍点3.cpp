#include <iostream>
#include <set>
using namespace std;
int s[10][10], n, m, flag;
void find(int x, int y) {
  set<int> p, q;
  for (int i = 0; i < m; i++)
    p.insert(s[x][i]);
  for (int i = 0; i < n; i++)
    q.insert(s[i][y]);
  if (*p.begin() == *--q.end())
    flag = 0, cout << "A[" << x + 1 << "][" << y + 1 << "]" << endl;
}
int main(){
  int t;
  cin >> t;
  while (flag = 1, t-- && cin >> n >> m) {
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        cin >> s[i][j];
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        find(i, j);
    if (flag)cout << "NO." << endl;
    if (t != 0)cout << endl;
  }
  return 0;
}
/*
样例输入

2
2 2
2 3
1 1
2 3
4 5 1
7 6 -1

样例输出

A[1][1]

A[1][3]
*/