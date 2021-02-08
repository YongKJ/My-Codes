#include <iostream>
using namespace std;
int main(){
  int n, s, m;
  while(cin>>n>>s>>m){
    int a[n];
    for  (int i=0;i<n;i++)
      a[i] = 1;
    for (int i = s - 1, k = 0, sum = 0; k != n; i = ++i % n) {
      sum += a[i];
      if (sum == m - s + 1)
        cout << i + 1 << (++k != n ? " " : "\n"), sum = a[i] = 0;
    }
  }
  return 0;
}