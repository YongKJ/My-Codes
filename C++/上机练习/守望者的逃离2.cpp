#include <iostream>
using namespace std;
class number {
public:
  number(int a, int b, int c);
  void show();
  void magic();

private:
  int m, s, t, sum, time;
};
int main() {
  int m, s, t;
  while (cin >> m >> s >> t)
    number d1(m, s, t);
  return 0;
}
number::number(int a, int b, int c) {
  m = a, s = b, t = c;
  show();
}
void number::show(){
  sum = 0, time = 0;
  int n, m1 = m, t1 = t;
  while (m >= 10) {
    n = m / 10, sum += 60 * n, time += n;
    m %= 10, t -= time;
    if(sum<=s)
      magic();
  }
  if (sum >= s)
    cout << "Yes" << endl << time << endl;
  else
    cout << "No" << endl << sum << endl;
}
void number::magic() {
  int m1, t1, t2;
  m1 = 10 - m;
  t1 = m1 % 4 == 0 ? m1 / 4 : (m1 / 4) + 1;
  t2 = (s - sum) % 17 == 0 ? (s - sum) / 17 : ((s - sum) / 17) + 1;
  if (t >= t1 + 1)
    m += 4 * t1, t -= t1, time += t1;
  else {
  if(t>=t2)
    sum += t2 * 17, time += t2;
    else
      sum += t * 17, time += t;
  }
}
