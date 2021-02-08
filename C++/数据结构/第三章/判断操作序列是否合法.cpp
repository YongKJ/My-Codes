#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main(){
  string s;
  while(cin>>s){
    int flag = 1;
    stack<char> p;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == 'I')
        p.push(s[i]);
      else {
        if (p.empty()) {
          flag = 0;
          break;
        }
        p.pop();
      }
    }
    cout << (p.empty() && flag ? "ture" : "false") << endl;
  }
  return 0;
}
  	
/*
输入:
IOIIOIOO
IOOIOIIO
IIIOIOIO
IIIOOIOO

输出:
Yes
No
No
Yes
*/