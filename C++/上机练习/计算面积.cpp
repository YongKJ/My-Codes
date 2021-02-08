#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
double area(double x) { return x * x; }
double area(double x, double y) { return x * y; }
double area(double x, double y, double z) {
  double p;
  p = (x + y + z) / 2;
  return sqrt(p * (p - x) * (p - y) * (p - z));
}
int main() {
  double x, y, z;
  cin >> x;
  cout << fixed << setprecision(3) << area(x) << endl;
  cin >> x >> y;
  cout << fixed << setprecision(3) << area(x, y) << endl;
  cin >> x >> y >> z;
  cout << fixed << setprecision(3) << area(x, y, z) << endl;
  return 0;
}