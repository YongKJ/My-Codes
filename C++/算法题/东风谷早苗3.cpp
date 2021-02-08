#include <iostream>
#include <string>
using namespace std;
int main() {
  int dx[105] = {0}, dy[105] = {0};
  int cx = 0, cy = 0, n, x = 0, y = 0;
  string s;
  dx['E'] = 1;
  dx['W'] = -1;
  dy['S'] = -1;
  dy['N'] = 1;
  cin >> s >> n;
  for (int i = 0; s[i]; i++)
    cx += dx[s[i]], cy += dy[s[i]];
  int r = n /s.size();
  x = r * cx;
  y = r * cy;
  n %= s.size();
  for (int i = 0; i < n; i++)
    x += dx[s[i]], y += dy[s[i]];
  cout << x << " " << y << endl;
  return 0;
}