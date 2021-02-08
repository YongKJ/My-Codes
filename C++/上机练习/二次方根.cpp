#include <iostream>
#include <cmath>
using namespace std;
class Kaigen {
public:
  void sroot(int &i);
  void sroot(long &i);
  void sroot(double &i);
  void disp_result();
  private:
    double a, b, c;
};
int main() {
  Kaigen d1;
  int i = 12;
  long j = 1234;
  double k = 12.34;
  d1.sroot(i);
  d1.sroot(j);
  d1.sroot(k);
  d1.disp_result();
  return 0;
}
void Kaigen::sroot(int &i) { a = sqrt(1.0 * i); }
void Kaigen::sroot(long &i) { b = sqrt(1.0 * i); }
void Kaigen::sroot(double &i) { c = sqrt(1.0 * i); }
void Kaigen::disp_result() {
  cout << "i 的二次方根是：" << a << endl;
  cout << "l 的二次方根是：" << b << endl;
  cout << "d 的二次方根是：" << c << endl;
}