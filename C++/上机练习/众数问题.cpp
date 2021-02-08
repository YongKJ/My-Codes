#include <iostream>
#include <map>
using namespace std;
int main(){
	map<int, int> x;
        map<int, int>::iterator p;
        int n, m, a, b, c;
        cin >> n;
        while (n--&&cin>>m){
          while (m-- && cin >> a) {
            if (x.find(a) != x.end())
              x[a]++;
            else
              x[a] = 1;
          }
            for (p=x.begin(),b=p->second;p!=x.end();p++)
              if (p->second > b) {
                b = p->second;
                c = p->first;
              }
            cout << c << " " << b << endl;
            x.clear();
        }
          return 0;
}
          
/*
样例输入

1
6
1 2 2 2 3 5

样例输出

2 3
*/