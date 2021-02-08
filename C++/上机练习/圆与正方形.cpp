#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
#define PI 3.14
class Out {
public:
  virtual void print()=0;
};
class circle : public Out {
public:
  circle(double x);
  virtual void print();

private:
  double r;
};
class square_in : public Out {
public:
  square_in(double x);
  virtual void print();

private:
  double diagonal;
};
class square_out : public Out {
public:
  square_out(double x);
  virtual void print();

private:
  double length;
};
int main(){
  int t;
  double x;
  Out *p;
  cin >> t;
  while (t--) {
    cin >> x;
    p = new circle(x);
    p->print();
    p = new square_in(x);
    p->print();
    p = new square_out(x);
    p->print();
  }
  return 0;
}
circle::circle(double x) { r = x; }
void circle::print() {
  double l, s;
  l = PI * 2 * r;
  s = PI * r * r;
  cout <<fixed<<setprecision(4)<< "Circle area is:" << s << endl;
  cout <<fixed<<setprecision(4)<< "Circle perimeter is:" << l << endl;
}
square_in::square_in(double x) { diagonal = x; }
void square_in::print() {
  double l, s, a;
  a = sqrt(2 * diagonal * diagonal);
  s = a * a;
  l = 4 * a;
  cout << fixed << setprecision(4) << "Incircle Rectangle area is:" << s << endl;
  cout << fixed << setprecision(4) << "Incircle Rectangle perimeter is:" << l
       << endl;
}
square_out::square_out(double x) { length = x; }
void square_out::print() {
  double l, s;
  s = 4 * length * length;
  l = 8 * length;
  cout << fixed << setprecision(4) << "Outcircle Rectangle area is:" << s
       << endl;
  cout << fixed << setprecision(4) << "Outcircle Rectangle perimeter is:" << l
       << endl;
}
  
		