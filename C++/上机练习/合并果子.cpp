#include <iostream>
#include <queue>
#include <functional>
using namespace std;
int main(){
  int t,x,n,s;
  cin >> t;
  while(t--&&cin>>n){
    priority_queue<int, vector<int>, greater<int> > p;
  	while(n--&&cin>>x)
          p.push(x);
        s = 0;
        for (int s1,s2;p.size()!=1;) {
          s1= p.top();
          p.pop();
          s2 = p.top();
          p.pop();
          p.push(s1 + s2);
          s += s1 + s2;
        }
        cout << s << endl;
  }
  return 0;
}
//1 2 3 9
//9 3 2 1
//9 3 3		3
//9 6		    9
//15		     24