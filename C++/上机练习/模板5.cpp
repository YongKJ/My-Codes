/*#include <iostream>
#include <iomanip>
using namespace std;
int main() {
  char a[10], b[10];
  cin.width(2);
  cin >> a >> b;
  cout << a << "," << b << endl;
  cout.width(2);
  cout << a << " " << b << endl;
  return 0;
}*/
#include <iostream>
using namespace std;
class test {
public:
  test();
  test(int n);
  test(test &t);

private:
  int a;
};
int main() {
  test t1(6);
  test t2 = t1;
  test t3;
  t3 = t1;
  return 0;
}
test::test() { cout << "default." << endl; }
test::test(int n) {
  a = n;
  cout << "Con." << endl;
}
test::test(test &t) {
  a = t.a;
  cout << "Copy Con." << endl;
}
