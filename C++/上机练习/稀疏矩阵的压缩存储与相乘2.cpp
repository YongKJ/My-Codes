#include <iostream>
#include <map>
using namespace std;
struct node {
  int x, y;
  bool operator<(const node &f1) const {
    return (f1.x == x ? f1.y > y : f1.x > x);
  }
} d, f;
int main(){
  int n, m, v, t;
  while(cin >> n >> m >> t){
    map<node, int> a, b;
  while (t--)
    cin >> d.x >> d.y >> a[d];
    cin >> m >> v >> t;
    while (t--)
      cin >> d.x >> d.y >> b[d];
     for (int i=1;i<=n;i++)
      for (int j = 1,sum=0;j<=v;j++){
        for (int k = 1; k <= m; k++) {
          d.x = i, d.y = k, f.x = k, f.y = j;
          if (a.find(d) != a.end() && b.find(f) != b.end())
            sum += a[d] * b[f];
        }
        if (sum != 0)
          cout << i << " " << j << " " << sum << endl, sum = 0;
      }
  }
  return 0;
}