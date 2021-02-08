#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
#define PI 3.14
class Shape {
public:
  virtual void print() = 0;
};
class Circle : public Shape {
public:
  Circle(double x, double y, double r);
  virtual void print();
  private:
    double x0, y0, r0;
};
class Rectangle : public Shape {
public:
  Rectangle(double x, double y, double x2, double y2);
  virtual void print();
  double x0, y0, n, m;
};
int main()
{   
      double x,y,r,x2,y2; 
     Shape *p;
     while (cin >> x >> y >> r) {
      p = new Circle(x, y, r);
      p->print();
      cin >> x >> y >> x2 >> y2;
      p = new Rectangle(x, y, x2, y2);
      p->print();
    }
    return 0;
}
Circle::Circle(double x, double y, double r) {
  x0 = x;
  y0 = y;
  r0 = r;
}
void Circle::print() {
  cout << fixed << setprecision(3) << r0 * 2 * PI << endl;
}
Rectangle::Rectangle(double x, double y, double x2, double y2) {
  x0 = x;
  y0 = y;
  n = x2;
  m = y2;
}
void Rectangle::print() {
  double a, b, c;
  a = fabs(n - x0);
  b = fabs(m - y0);
  c = (a * 2 + b * 2) * 2;
  cout << fixed << setprecision(3) << c << endl;
}
	