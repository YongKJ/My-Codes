#include <iostream>
using namespace std;
struct Data {
  int x,y;
} data;
class Jia {
public:
  Jia(int a);
  void show();

private:
  int n,s[100];
  Data d[100];
};
int main() {
  int n;
  while (cin >> n, n)
    Jia d1(n);
  return 0;
}
Jia::Jia(int a) {
  n = a;
  Data t;
  int k;
   for (int i = 0; i < n; i++) {
      cin >> d[i].x >> d[i].y;
      s[i] = d[i].y - d[i].x;
    }
    for (int i=0;i<n-1;i++)
      for (int j=i+1;j<n;j++)
        if (d[i].x > d[j].x || (d[i].x == d[j].x && d[i].y > d[j].y)) {
          t = d[i], d[i] = d[j], d[j] = t;
          k = s[i], s[i] = s[j], s[j] = k;
        }
    show();
}
void Jia::show(){
  Data k;
  int sum = 0, t, i, j;
  for (i = 0, j = s[0]; i < n; i++)
    if (s[i] < j) {
      sum++, k = d[i], t = i;
      break;
    }
  for (i = t + 1; i < n - 1; i++)
    if (k.x < d[i].x && k.y < d[i].y && k.x <= d[i].y && s[i] < s[i + 1])
      sum++, k = d[i];
  if (k.x < d[i].x && k.y < d[i].y && k.x <= d[i].y)
    sum++;
  cout << sum << endl;
}