#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
class number {
public:
  number(int a, int b, int c);
  void show();

private:
  int n, x, t;
};
int main() {
  int a, b, c;
  while (cin >> a >> b >> c)
    number d1(a, b, c);
  return 0;
}
number::number(int a, int b, int c) {
  n = a, x = b, t = c;
  show();
}
void number::show() {
  string s;
  int k = 0;
  for (int i = 0;; i++) {
  string str;
  int j = i, sum = 0;
  while (j){
     sum += j % 2 ? 1 : 0;
     str += j % 2 ? '1' : '0';
    j /= 2;
  }
  if (str.size() <= n && sum <= x)
    k++;
  if (k == t) {
    s = str;
    break;
  }
  }
  reverse(s.begin(), s.end());
  for (int i = 1; i <= n - s.size();i++)
    cout << 0;
  cout << s << endl;
}