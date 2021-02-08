#include <iostream>
using namespace std;
int main(){
  int t,n,m,Max;
  cin >> t;
  while(Max=-100,t--&&cin>>n){
    for (int sum = 0, i = 0; i < n; i++) {
      cin >> m, sum += m;
      Max = max(Max, sum), sum = max(sum, 0);
    }
    cout << Max << endl;
  }
  return 0;
}
      
  	
  