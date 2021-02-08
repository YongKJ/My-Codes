#include <iostream>
using namespace std;
template <class T> class Test {
public:
  Test(T x, T y);
  T Max();

private:
  T n, m;
};
 int main() {
  int a, b;
  double c, d;
  cin >> a >> b >> c >> d;
  Test<int> t1(a, b);
  Test<double> t2(c, d);
  cout << t1.Max() << endl;
  cout << t2.Max() << endl;
  return 0;
}
template <class T> Test<T>::Test(T x, T y) {
  n = x;
  m = y;
}
template <class T> T Test<T>::Max() {
  T max = n > m ? n : m;
  return max;
}