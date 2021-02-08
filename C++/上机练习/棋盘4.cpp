#include <iostream>
#include <string>
using namespace std;
int tt, map[10][10];
void chess(int a, int b, int x, int y, int size) {
  if (size == 1)
    return;
  int t = tt++, s = size / 2;
  if (x < a + s && y < b + s)
    chess(a, b, x, y, s);
  else
    map[a + s - 1][b + s - 1] = t, chess(a, b, a + s - 1, b + s - 1, s);
  if (x < a + s && y >= b + s)
    chess(a, b + s, x, y, s);
  else
    map[a + s - 1][b + s] = t, chess(a, b + s, a + s - 1, b + s, s);
  if (x >= a + s && y < b + s)
    chess(a + s, b, x, y, s);
  else
    map[a + s][b + s - 1] = t, chess(a + s, b, a + s, b + s - 1, s);
  if (x >= a + s && y >= b + s)
    chess(a + s, b + s, x, y, s);
  else
    map[a + s][b + s] = t, chess(a + s, b + s, a + s, b + s, s);
}
int main(){
  int n, x, y;
  while (tt = 1, memset(map, 0, sizeof(map)), cin >> n >> x >> y) {
    chess(0, 0, x - 1, y - 1, n * 2);
    for (int i = 0; i < n * 2; i++)
      for (int j = 0; j < n * 2; j++)
        cout << map[i][j] << (j == n * 2 - 1 ? "\n" : " ");
  }
  return 0;
}