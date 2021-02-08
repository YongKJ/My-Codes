#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
class point {
public:
  point(double x, double y);
  friend double dist(point a, point b);

private:
  double n, m;
};
int main()
{
    int n;
    double x1,x2,y1,y2;
    cin>>n;
    while (n--) {
      cin >> x1 >> y1 >> x2 >> y2;
      point p1(x1, y1), p2(x2, y2);
      cout << fixed << setprecision(3) << dist(p1, p2) << endl;
    }
    return 0;
}
point::point(double x, double y) {
  n = x;
  m = y;
}

double dist(point a, point b) {
  double x1, y1,t;
  x1 = a.n - b.n;
  y1 = a.m - b.m;
  t = sqrt(x1 * x1+y1 * y1);
  return t;
}
	