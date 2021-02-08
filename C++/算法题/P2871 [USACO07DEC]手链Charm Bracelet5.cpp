#include <iostream>
#include <string>
using namespace std;
int main(){
  int n, m, a, b;
  while(cin>>n>>m){
    int s[m + 1];
    memset(s, 0, sizeof(s));
    for (int i = 0; i < n; i++) {
      cin >> a >> b;
      for (int j = m; j >= a; j--)
        s[j] = max(s[j], s[j - a] + b);
    }
    cout << s[m] << endl;
  }
  return 0;
}