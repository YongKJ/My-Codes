#include <iostream>
#include <iomanip>
using namespace std;
template <typename T> T Plus(T x, T y) {
  T sum;
  sum = x + y;
  return sum;
}
int main(){
  int a, b;
  double n, m;
  while (cin >> a >> b) {
    cout<<Plus(a, b)<<endl;
    cin >> n >> m;
    cout<<fixed<<setprecision(3)<<Plus(n, m)<<endl;
  }
  return 0;
}