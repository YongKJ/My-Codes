#include <iostream>
using namespace std;
int f[100];
int find(int x) {
  if (f[x] != x)
    f[x] = find(f[x]);
  return f[x];
}
int main(){
  int n, m, t = 1, a, b;
  while (cin >> n >> m) {
    for (int i = 1; i <= n; i++)
      f[i] = i;
    while (m-- && cin >> a >> b)
      if (find(a) != find(b))
        n--, f[find(b)] = find(a);
    cout << "Case " << t++ << ": " << n << endl;
  }
  return 0;
}
/*
样例输入

10 9
1 2
1 3
1 4
1 5
1 6
1 7
1 8
1 9
1 10
10 4
2 3
4 5
4 8
5 8
0 0

样例输出

Case 1: 1
Case 2: 7
*/