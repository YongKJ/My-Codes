#include <iostream>
#include <map>
using namespace std;
int main(){
  map<int, int> p;
  int n, m, x, y, z, s;
  cin >> n;
  while (s = 0, n-- && cin >> m >> x >> y >> z) {
    s += x + y + z;
    p.insert(make_pair(m, s));
  }
  map<int, int>::iterator q;
  cin >> n;
  while (n-- && cin >> m) {
    q = p.find(m);
    if (q != p.end())
      cout << q->second << endl;
    else
      cout << "Not" << endl;
  }
  return 0;
}
/*
4
1001 70 80 90
1002 60 70 80
1003 80 90 70
1004 70 85 85
2
1002
1005
*/
  