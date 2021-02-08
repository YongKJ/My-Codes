#include <iostream>
using namespace std;
class point {
public:
  double x, y;
  point(double x1,double y1);
};
class rectangle : public point {
public:
  rectangle(double n, double m, double n1, double m2);
  void display();

private:
  double x2, y2;
};
int main(){
  double a, b, c, d;
  while (cin >> a >> b >> c >> d) {
    rectangle d1(a, b, c, d);
    d1.display();
  }
  return 0;
}
point::point(double x1, double y1) {
  x = x1;
  y = y1;
}
rectangle::rectangle(double n, double m, double n1, double m2):point(n, m) {
  x2 = n1;
  y2 = m2;
}
void rectangle::display() {
  x += x2;
  y += y2;
  cout << x << " " << y << endl;
}