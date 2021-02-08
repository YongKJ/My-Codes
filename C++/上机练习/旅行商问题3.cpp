#include <iostream>
#include <set>
#include <string>
using namespace std;
int n, Map[10][10], s[10][10], sum, y, flag;
set<int> p;
void dfs(int x,int z) {
  if (x == y&&flag==1) {
    if(z==n)
      p.insert(sum);
    return;
  }
  for (int i=1;i<=n;i++)
    if (s[x][i] == 0 && x != i) {
      s[x][i] = s[i][x] = 1, sum += Map[x][i];
      flag = 1, dfs(i,z+1);
      s[x][i] = s[i][x] = 0, sum -= Map[x][i];
    }
}
int main(){
  while (memset(s, 0, sizeof(s)), p.clear(), cin >> n) {
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
        cin >> Map[i][j];
    for (int i = 1; i <= n; i++)
      sum = flag = 0, y = i, dfs(i, 0);
    cout << *p.begin() << endl;
  }
  return 0;
}
/*
3
0 1 2
1 0 3
2 3 0
5 
0  7  6  1  3  
7  0  3  7  8 
6  3  0  12 11
1  7  12 0  2
3  8  11 2  0
4
0 30 6 4
30 0 5 10
6 5 0 20
4 10 20 0
4
0 30 6 100
30 0 5 10
6 5 0 20
100 10 20 0
4
0 30 600 100
30 0 5 10
600 5 0 20
100 10 20 0

6
20
25
66
155
*/