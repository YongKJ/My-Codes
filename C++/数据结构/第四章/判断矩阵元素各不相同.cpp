#include <iostream>
using namespace std;
int main(){
  int s[10][10],n,m,flag;
  while (flag = 1, cin >> n >> m) {
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        cin >> s[i][j];
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        for (int p = i, num = s[i][j]; p < n; p++)
          for (int q = j; q < m; q++)
            if (!(p == i && q == j) && num == s[p][q])
              flag = 0;
    cout << (flag ? "Yes" : "No") << endl;
  }
  return 0;
}
/*
输入:
3 3
1 2 3
4 5 6
7 8 9
3 4
1 2 3 10
4 5 6 11
7 8 9 11

输出:
Yes
No
*/