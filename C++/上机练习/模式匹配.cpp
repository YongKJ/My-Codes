#include <iostream>
using namespace std;
int main(){
  string s1, s2;
  int t,n,i;
  cin >> t;
  while (n=i=0,t--&&cin >> s1 >> s2) {
    while (s2.find(s1, i) != string::npos)
      n++, i = s2.find(s1, i)+1;
    cout << n << endl;
  }
  return 0;
}
    