#include <iostream>
using namespace std;
int main() {
  int s[100], m, n;
  while(cin>>n>>m){
    for (int i=0;i<n;i++)
      cin >> s[i];
    while (m--) {
      int a, b, sum = 0;
      cin >> a >> b;
      for (int i = --a; i < b; i++)
        sum += s[i];
      cout << sum << endl;
    }
  }
  return 0;
}
/*
样例输入

5 2
1 2 3 4 5
1 3
2 4

样例输出

6
9

提示


也可以用数组求和
*/