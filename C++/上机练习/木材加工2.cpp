#include <iostream>
using namespace std;
int n, k;
bool judge(int d[], int q) {
  int sum = 0;
  if (q == 0)
    return 0;
  for (int i = 0; i < n; i++)
    sum += d[i] / q;
  return sum >= k;
}
int main(){
    while(cin>>n>>k){
    int min = 99999, d[n];
    for (int i = 0; i < n; i++) {
      cin >> d[i];
      if (min > d[i])
        min = d[i];
    }
    if (!judge(d,1))
      cout << 0 << endl;
     else
       for (int i = min;; i--)
         if (judge(d, i)) {
           cout << i << endl;
           break;
         }
    }
    return 0;
}
            
	