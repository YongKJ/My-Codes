#include <iostream>
#include <map>
using namespace std;
int main(){
  map<double, int> p;
  int n;
  double m;
  cin >> n;
  while (n-- && cin >> m) {
    if (p.find(m) != p.end())
      p[m]++;
    else
      p[m] = 1;
  }
  map<double, int>::iterator q;
  for (q=p.begin();q!=p.end();q++)
    cout << q->first << " " << q->second << endl;
  return 0;
}
    
  
  
  
  
  /*
  样例输入

10
80.5
70
80.5
70.5
73.3
70.5
80.5
70
90
90

样例输出

70 2
70.5 2
73.3 1
80.5 3
90 2
*/