#include <iostream>
#include <set>
using namespace std;
int main(){
  set<string> x;
  string str;
  while (cin >> str && str != "#") {
    x.insert(str);
    while (getchar() != '\n' && cin >> str)
      x.insert(str);
    cout << x.size() << endl;
    x.clear();
  }
  return 0;
}
    	
/*
样例输入

you are my friend
#

样例输出

4
*/