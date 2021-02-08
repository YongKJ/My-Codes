#include <iostream>
using namespace std;
class cylinder {
public:
  cylinder(double x, double y);
  void vol();

private:
  double r, h;
};
int main() {
  cylinder d1(2.2, 8.09);
  d1.vol();
  return 0;
}
cylinder::cylinder(double x, double y) {
  r = x;
  h = y;
}
void cylinder::vol() {
  double v;
  v = 3.1415926 * r * r * h;
  cout << v << endl;
}
  