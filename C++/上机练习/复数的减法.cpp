#include <iostream>
using namespace std;
int isRun(int y);
int days(int y, int m);
class Fushu {
public:
  Fushu(int x, int y);
  Fushu();
  friend Fushu operator-(Fushu x, Fushu y);
  void show();

private:
  int a, b;
};
int main(){
  int x, y, a, b;
  while (cin >> x >> y >> a >> b) {
    Fushu d1(x, y), d2(a, b), d3;
    d3 = d1 - d2;
    d3.show();
  }
  return 0;
}
Fushu::Fushu(int x, int y) {
  a = x;
  b = y;
}
Fushu::Fushu() {}
Fushu operator-(Fushu x, Fushu y) {
  int n, m;
  n = x.a - y.a;
  m = x.b - y.b;
  return Fushu(n, m);
}
/*void Fushu::show() {
  cout << a;
  if (b < 0)
    cout << b << "i" << endl;
  else
    cout << "+" << b << "i" << endl;
}*/
void Fushu::show() {
  cout << a;
  if (b >= 0)
    cout << "+";
  cout << b << "i" << endl;
}

          