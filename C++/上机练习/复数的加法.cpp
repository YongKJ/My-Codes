#include <iostream>
using namespace std;
class Fushu {
public:
  Fushu(int x, int y);
  friend void Plus(Fushu n, Fushu m);

private:
  int x1, y1;
};
int main(){
  int a, b;
  while (cin >> a >> b) {
    Fushu d1(a, b);
    cin >> a >> b;
    Fushu d2(a, b);
    Plus(d1, d2);
  }
  return 0;
}
Fushu::Fushu(int x, int y) {
  x1 = x;
  y1 = y;
}
void Plus(Fushu n, Fushu m) {
  int x2,y2;
  x2 = n.x1 + m.x1;
  y2 = n.y1 + m.y1;
  if (y2 < 0)
    cout << x2 << y2 << "i" << endl;
  else
    cout << x2 << "+" << y2 << "i" << endl;
}