#include <iostream>
#include <iomanip>
using namespace std;
template <typename T> T sum(int n, T *p) {
  T s = 0;
  for (int i = 0; i < n; i++)
    s += p[i];
  return s;
}
int main(){
  int n,p1[20];
  float p2[20];
  while (cin >> n) {
    for (int i = 0; i < n; i++)
      cin >> p1[i];
    cout << sum(n, p1) << endl;
    cin >> n;
    for (int i = 0; i < n; i++)
      cin >> p2[i];
    cout << fixed << setprecision(2) << sum(n, p2) << endl;
  }
  return 0;
}
	