#include <iostream>
using namespace std;
struct Data {
  int x, y;
} c[100],t;
int main(){
  int n;
  while (cin >> n, n) {
    int num = 1;
    for (int i = 0; i < n; i++)
      cin >> c[i].x >> c[i].y;
    for (int i = 0; i < n - 1; i++)
      for (int j = i + 1; j < n; j++)
        if (c[i].y > c[j].y || (c[i].y == c[j].y && c[i].x < c[j].x))
          t = c[i], c[i] = c[j], c[j] = t;
    for (int i = 0, k = c[i].y; i < n; i++)
      if (c[i].x >= k)
        k = c[i].y, num++;
    cout << num << endl;
  }
  return 0;
}
/*
12
1 3
3 4
0 7
3 8
15 19
15 20
10 15
8 18
6 12
5 10
4 14
2 9
0
*/
        