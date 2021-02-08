#include <iostream>
#include <cmath>
using namespace std;
int n, num;
void grass(int k, int s) {
  if (k == 4) {
    num = s == n ? num + 1 : num;
    return;
  }
  for (int i = 0; i <= sqrt(n); i++)
    grass(k + 1, s + i * i);
}
int main() {
  while (cin >> n)
    grass(0, 0), cout << num << endl;
  return 0;
}