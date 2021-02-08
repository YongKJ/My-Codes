#include <iostream>
using namespace std;
void JueDuiZhi(int &x);
void JueDuiZhi(float &x);
void JueDuiZhi(double &x);
int main() {
  int x;
  float y;
  double z;
  cin >> x >> y >> z;
  JueDuiZhi(x);
  JueDuiZhi(y);
  JueDuiZhi(z);
  cout << x << " " << y << " " << z << endl;
  return 0;
}
void JueDuiZhi(int &x) { x = x < 0 ? -x : x; }
void JueDuiZhi(float &x) { x = x < 0 ? -x : x; }
void JueDuiZhi(double &x) { x = x < 0 ? -x : x; }