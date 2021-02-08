#include <iostream>
using namespace std;
int main(){
  int T, n;
  while(cin>>T>>n){
    int s[100] = {0}, t, v;
    for (int i = 1; i <= n; i++) {
      cin >> t >> v;
      for (int j = T; j >= t; j--) {
        cout << j << " " << j - t << endl;
        cout << s[j] << " " << s[j - t] << endl << v << endl;
        s[j] = max(s[j], s[j - t] + v);
        //cout << j << " " << j - t << endl;
        cout << s[j] << " " << s[j - t] << endl << endl;
       // cout << endl;
      }
      cout << endl;
    }
    cout << s[T] << endl;
  }
  return 0;
}
/*
70 3
71 100
69 1
1 2
*/
    