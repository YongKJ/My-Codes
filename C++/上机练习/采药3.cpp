#include <iostream>
using namespace std;
int main(){
  int T, n;
  while(cin>>T>>n){
    int s[71] = {0}, t, v;
    while (n-- && cin >> t >> v)
      for (int j = T; j >= t; j--)
        s[j] = max(s[j], s[j - t] + v);
    cout << s[T] << endl;
  }
  return 0;
}