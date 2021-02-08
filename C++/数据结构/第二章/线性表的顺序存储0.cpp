#include <iostream>
using namespace std;
char f(int n) {
  if (n)
    return 'A';
  cout << "Hello world!" << endl;
  return 'B';
}
int main() {
  int n;
  while (cin >> n)
    cout << f(n) << endl;
  return 0;
}