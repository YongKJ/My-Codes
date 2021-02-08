#include <iostream>
#include <cstdlib>
using namespace std;
const int inf = 2147483647, maxn = 2000;
int k, h, maxstampval, stampval[maxn], maxval[maxn], y[maxn];
void search(int cur) {
  if (cur >= k) {
    if (maxval[cur - 1] > maxstampval)
      maxstampval = maxval[cur - 1];
    return;
  }
  int tmp[maxn];
  memcpy(tmp, y, sizeof(y));
  for (int i=stampval[cur-1]+1;i<=maxval[cur-1]+1;i++){
    stampval[cur] = i;
    for (int j = 0; j < stampval[cur - 1] * h; j++)
      if (y[j] < h) {
        for (int num = 1; num <= h - y[j]; num++)
          if (y[j] + num < y[j + i * num] && (j + i * num < maxn))
            y[j + i * num] = y[j] + num;
      }
    int r = maxval[cur - 1];
    while (y[r + 1] < inf)
      r++;
    maxval[cur] = r, search(cur + 1), memcpy(y, tmp, sizeof(tmp));
  }
}
int main(){
  while (cin >> h >> k, h + k) {
    stampval[0] = 1, maxval[0] = h, maxstampval = -2147483647;
    int i;
    for (i = 0; i <= h; i++)
      y[i] = i;
    while (i < maxn)
      y[i++] = inf;
    search(1);
    cout << maxstampval << endl;
  }
  return 0;
}
              