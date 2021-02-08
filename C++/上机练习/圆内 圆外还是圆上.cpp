#include <iostream>
using namespace std;
class point {
public:
  double x0, y0;
  point(double x, double y);
};
class circle : public point {
public:
  circle(double x, double y, double z);
  void Dian(double n, double m);

private:
  double r;
};
int main(){
  double x, y, z, n, m;
  while (cin >> x >> y >> z >> n >> m) {
    circle d1(x, y, z);
    d1.Dian(n, m);
  }
  return 0;
}
point::point(double x, double y) {
  x0 = x;
  y0 = y;
}
circle::circle(double x, double y, double z) : point(x, y) { r = z; }
void circle::Dian(double n, double m) {
  double a, b, c;
  a = n - x0;
  b = m - y0;
  c = a * a + b * b;
  if (c == r * r)
    cout << "on" << endl;
  else if (c < r * r)
    cout << "in" << endl;
  else
    cout << "out" << endl;
}