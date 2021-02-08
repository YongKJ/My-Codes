#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main()
{
  double x1, y1, x2, y2,s,a,b;
  while (cin >> x1 >> y1 >> x2 >> y2) {
    a = (x1 - x2) * (x1 - x2);
    b = (y1 - y2) * (y1 - y2);
    s = sqrt(a + b);
    cout << setiosflags(ios::fixed) << setprecision(2) << s << endl;
  }
  return 0;
}