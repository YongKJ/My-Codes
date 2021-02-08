#include <iostream>
using namespace std;
class Number {
public:
  void set_numbers();
  void change();
  void disp_result();

private:
  int n, m;
};
int main() {
  Number d1;
  d1.set_numbers();
  d1.change();
  d1.disp_result();
  return 0;
}
void Number::set_numbers() { cin >> n >> m; }
void Number::change(){
  if (n > m) {
    int t = n;
    n = m;
    m = t;
  }
}
void Number::disp_result() { cout << n <<" " << m << endl; }
  