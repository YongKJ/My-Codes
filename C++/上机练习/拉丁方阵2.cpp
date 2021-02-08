#include <iostream>
using namespace std;
int main(){
  int n;
  while(cin>>n){
    int *s = new int[n];
    for (int i=0;i<n;i++)
      s[i] = i + 1;
    for (int i = 0; i < n; i++) {
      for (int j = i; j < i + n; j++)
        cout << (j >= n ? s[j % n] : s[j]) << " ";
      cout << endl;
    }
  }
  return 0;
}