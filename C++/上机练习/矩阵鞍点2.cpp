#include <iostream>
#include <map>
using namespace std;
struct node {
  int a, b;
}d;
class point {
public:
  point();
  void find(int x, int y);
  void handle();
  
private:
  int n, m, s[10][10], flag;
};
int main(){
  int t;
  cin >> t;
  while (t--) {
    point d1;
    if (t != 0)
      cout << endl;
  }
  return 0;
}
point::point() {
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> s[i][j];
  flag = 1, handle();
}
void point::find(int x, int y) {
  map<int, node> p, q;
  for (int i = 0; i < m; i++)
    d.a = x, d.b = i, p[s[x][i]] = d;
  for (int i = 0; i < n; i++)
    d.a = i, d.b = y, q[s[i][y]] = d;
  if (p.begin()->first == (--q.end())->first)
    flag = 0, cout << "A[" << p.begin()->second.a + 1 << "]["
                   << p.begin()->second.b + 1 << "]" << endl;
}
void point::handle() {
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      find(i, j);
  if (flag)
    cout << "NO." << endl;
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
	
	