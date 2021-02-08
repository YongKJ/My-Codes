#include <iostream>
using namespace std;
int main(){
  int s[10][10], n, m,t;
  cin >> t;
  while (t--&&cin >> n >> m) {
    int min[10] = {0}, max[10] = {0}, flag = 1;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        cin >> s[i][j];
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        min[i] = s[i][j] < s[i][min[i]] ? j : min[i],
        max[j] = s[i][j] > s[max[j]][j] ? i : max[j];
    for (int i = 0, j = min[i]; i < n; i++, j = min[i])
      if (i == max[j])cout << "A[" << i + 1 << "][" << j + 1 << "]" << endl, flag = 0;
    if (flag)cout << "NO."<<endl;
    if(t)cout << endl;
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