#include <iostream>
#include <cstring>
using namespace std;
int main(){
  int m, n;
  while(cin>>m>>n){
    int f[m + 1], v, w;
    memset(f, 0, sizeof(f));
    for (int i = 1; i <= n; i++) {
      cin >> v >> w;
      for (int j = m; j >= v; j--)
        f[j] = max(f[j], f[j - v] + v * w);
    }
    cout << f[m] << endl;
  }
  return 0;
}
    