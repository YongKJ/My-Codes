#include <iostream>
#include <set>
#include <string>
using namespace std;
int n, Map[10][10], s[10][10], sum, y, flag;
set<int> p;
void dfs(int x) {
  if (x == y&&flag==1) {
    p.insert(sum), cout << sum << endl;
    return;
  }
  for (int i=1;i<=n;i++)
    if (s[x][i] == 0 && x != i) {
      s[x][i] = 1, s[i][x] = 1, sum += Map[x][i];
      cout << x << " " << i << endl;
      flag = 1, dfs(i);
      s[x][i] = 0, s[i][x] = 0, sum -= Map[x][i];
    }
}
int main(){
  while (memset(s, 0, sizeof(s)), p.clear(), cin >> n) {
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
        cin >> Map[i][j];
    cout << endl;
    for (int i = 1; i <= n; i++)
      sum = flag =0, y = i, dfs(i), cout << endl;
    cout << *p.begin() << endl;
  }
  return 0;
}
 
 /*
3
0 1 2
1 0 3
2 3 0
*/