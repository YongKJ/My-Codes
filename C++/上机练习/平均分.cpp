#include <iostream>
#include <cstdio>
#include <iomanip>
using namespace std;
class Score {
public:
  void set_information(double a);
  void display(int x);
private:
  static double sum;
};
double Score::sum;
int main(){
  Score d1;
  char str[20];
  double n;
  int x = 0;
  while (cin>>str>>n) {
    d1.set_information(n);
    x++;
 /*   if (x == 4)
      break;*/
  }
  d1.display(x);
  return 0;
}
void Score::set_information(double a) {
  sum += a;
}
void Score::display(int x) {
  sum /= x;
  cout << fixed << setprecision(2) << sum << endl;
}