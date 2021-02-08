#include <iostream>
#include <map>
using namespace std;
int main(){
  map < int,int> x;
  map<int,int>::iterator p;
  int n,m;
  while(cin>>n,n!=0){
    for (int i = 0; i < n; i++) {
      cin >> m;
      if (x.find(m) != x.end())
        x[m]++;
      else
        x[m] = 1;
    }
    cin >> m;
    if(p = x.find(m),x.find(m)!=x.end())
    cout << p->second << endl;
    else
      cout << "0" << endl;
    x.clear();
  }
  return 0;
}
    
	
/*
样例输入

3
80 60 90
60
2
85 66
0
5
60 75 90 55 75
75
0

样例输出

1
0
2
*/