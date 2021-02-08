#include <iostream>
using namespace std;
class Money {
public:
  void show_result();

private:
  int sum;
};
int main() {
  Money d1;
  d1.show_result();
  return 0;
}
void Money::show_result(){
  sum = 0;
  for (int i=0;i<=20;i++)
    for (int j=0;j<=50;j++)
      if (100 - 5 * i - 2 * j >= 0) {
        sum++;
        cout << 100 - 5 * i - 2 * j << "\t" << i << "\t" << j << endl;
      }
  cout << sum << endl;
}