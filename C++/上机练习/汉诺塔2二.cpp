#include <iostream>
using namespace std;
int main() {
  int n;
  long s;
  while (s = 3, cin >> n) {
    for (int i = 1, t = 3; i <= n - 2; i++, t = s)
      s += t * 2;
    s *= 3;
    if (n == 1)
      cout << 2 << endl;
    else
      cout << --s << endl;
  }
  return 0;
}