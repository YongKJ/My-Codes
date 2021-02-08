#include <iostream>
using namespace std;
int main() {
  long long a, b, c, x, y, z, n;
  char m;
  cin >> a >> m >> b >> m >> c;
  cin >> x >> m >> y >> m >> z;
  cin >> n;
  cout << ((x - a) * 60 * 60 + (y - b) * 60 + z - c) * n << endl;
  return 0;
}