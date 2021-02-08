#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
#define PI 3.14
class Shape {
public:
  virtual void print() = 0;
};
class circle : public Shape {
public:
  circle(double r);
  virtual void print();

private:
  double r0;
};
class triangle : public Shape {
public:
  triangle(double x, double y, double z);
  virtual void print();

private:
  double a, b, c;
};
class rectangle : public Shape {
public:
  rectangle(double x, double y);
  virtual void print();

private:
  double n, m;
};
int main(){
  double x, y, z;
  Shape *p;
  while (cin >> x) {
    p = new circle(x);
    p->print();
    cin >> x >> y >> z;
    p = new triangle(x, y, z);
    p->print();
    cin >> x >> y;
    p = new rectangle(x, y);
    p->print();
  }
  return 0;
}
circle::circle(double r) { r0 = r; }
void circle::print() {
  cout << fixed << setprecision(3) << PI * r0 * r0 << endl;
}
triangle::triangle(double x, double y, double z) {
  a = x;
  b = y;
  c = z;
}
void triangle::print() {
  double p, s;
  p = (a + b + c) / 2;
  s = sqrt(p * (p - a) * (p - b) * (p - c));
  cout << fixed << setprecision(3) << s << endl;
}
rectangle::rectangle(double x, double y) {
  n = x;
  m = y;
}
void rectangle::print() { cout << fixed << setprecision(3) << n * m << endl; }
    