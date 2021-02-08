#include <iostream>
#include <set>
using namespace std;
int main(){
  int n;
  cin >> n;
  while(n--){
    int m, sum = 0, a;
    set<int> x;
    set<int>::reverse_iterator p, q;
    cin >> m;
    for (int i = 0; i < m; i++) {
      cin >> a;
      x.insert(a);
    }
    for (p = x.rbegin(), q = ++x.rbegin();; p++, q++,p++,q++
        ) {
      if (*p == 1 || *q == 1 || *p == 0 || *q == 0)
        sum += *p + *q;
      else
        sum += *p * *q;
        if(q == --x.rend() || q == x.rend())
          break;  
    }
    if(m%2!=0)
      sum += *p;
    cout << sum << endl;
  }
  return 0;
}
