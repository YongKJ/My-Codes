#include <iostream>
#include <cmath>
using namespace std;
class Erfen {
public:
  void set_numbers();
  void deal_with();
  void disp_result();

private:
  float x, y,t ;
  float calculate(float n);
};
int main() {
  Erfen d1;
  d1.set_numbers();
  d1.deal_with();
  d1.disp_result();
  return 0;
}
void Erfen::set_numbers() { cin >> x >> y; }
float Erfen::calculate(float n) {
  return 2 * n * n * n - 4 * n * n + 3 * n - 6;
}
void Erfen::deal_with(){
  float a,b,c;
  do {
    t = (x + y) / 2;
    a = calculate(x);
    b = calculate(y);
    c = calculate(t);
    if (a * c > 0)
      x = t;
    else
      y = t;
  } while (fabs(c) >= 1e-6);
}
void Erfen::disp_result() { cout <<endl << "Root is:" << t<<endl; }
  
  
  