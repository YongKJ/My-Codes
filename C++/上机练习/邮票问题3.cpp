#include <iostream>
using namespace std;
int main(){
  int n, m;
  while(cin >> n >> m){
  int s[n];
  for (int i = 0; i < n; i++)
    cin >> s[i];
  for (int i=1;;i++){
    int sum=0,t = i;
    for (int j = n-1, k = 1; j >= 0; j--,k=1) {
        while(k*s[j]<=t)
          k++;
        sum += k - 1;
        t -= (k - 1) * s[j];
    }
    if (sum > m) {
      cout << i - 1 << endl;
      break;
    }
  }
  }
  return 0;
}