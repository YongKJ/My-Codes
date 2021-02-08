#include <iostream>
#include <cmath>
using namespace std;
class times {
public:
  times(double x, double y, double z);
  friend void seconds(times n, times m);

private:
  double hours, minutes, second;
};
int main(){
  double x, y, z;
  while (cin >> x >> y >> z) {
    times d1(x, y, z);
    cin >> x >> y >> z;
    times d2(x, y, z);
    seconds(d1, d2);
  }
  return 0;
}
times::times(double x, double y, double z) {
  hours = x;
  minutes = y;
  second = z;
}
void seconds(class times n, class times m) {
  double a, b, c, sum;
  a = m.hours - n.hours;
  b = m.minutes - n.minutes;
  c = m.second - n.second;
  sum = a * 60 * 60 + b * 60 + c;
  cout << n.hours << ":" << n.minutes << ":" << n.second << "-" << m.hours
       << ":" << m.minutes << ":" << m.second << "=" << fabs(sum) << endl;
}
/*
例输入

15 45 10 5 45 40
20 55 40 20 12 50

样例输出

15:45:10-5:45:40=35970
20:55:40-20:12:50=2570
*/