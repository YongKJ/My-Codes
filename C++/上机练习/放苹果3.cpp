#include <iostream>
using namespace std;
int apple(int m, int n) {
  if (m == 0 || n == 1)
    return 1;
  if (m < n)
    return apple(m, m);
  else
    return apple(m, n - 1) + apple(m - n, n);
}
int main(){
  int t, x, y;
  cin >> t;
  while (t--) {
    cin >> x >> y;
    cout << apple(x, y) << endl;
  }
  return 0;
}
	