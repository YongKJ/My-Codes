#include <iostream>
using namespace std;
int main(){
  int t;
  cin >> t;
  while (t--) {
    int n, m, x, y;
    long s1 = 1, s2 = 1;
    cin >> n >> m;
    x = n / m, y = x + 1;
    s1 *= n - (m - 1) * x, s2 *= n - (m - 1) * y;
    for (int i = 0; i < m - 1; i++)
      s1 *= x, s2 *= y;
    cout << (s1 > s2 ? s1 : s2) << endl;
  }
  return 0;
}
/*
2
10 3
5 4
*/