#include <iostream>
using namespace std;
int gcd(int n, int m) {
  int r;
  if (n == m)
    return n;
  else
    while ((r = n % m) != 0)
      n = m, m = r;
  return m;
}
int main(){
  int a[100], n,sum;
  while (cin >> n&&n) {
    for (int i = 0; i < n; i++)
      cin >> a[i];
    sum = a[0] / gcd(a[0], a[1]) * a[1];
    for (int i = 2; i < n; i++)
      sum = sum / gcd(sum, a[i]) * a[i];
    cout << sum << endl;
  }
  return 0;
}
            