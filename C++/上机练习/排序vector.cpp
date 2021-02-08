#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
int main(){
  vector<int> x;
  int t,k=2;
  while(cin>>t){
    x.push_back(t);
    while (cin >> t, t) {
      x.push_back(t);
    }
    sort(x.begin(), x.end());
    vector<int>::iterator y;
    for (y = x.begin(); y != x.end(); y++) {
      if (y == --x.end())
        cout << *y << endl;
      else
        cout << *y << " ";
    }
    x.clear();
    vector<int>().swap(x);
  }
  return 0;
}