#include <iostream>
#include <stack>
using namespace std;
int main(){
  string s;
  while (cin >> s) {
    stack<char> x;
    for (int i = 0; i < s.length(); i++) {
      if (x.size() != 0 &&((x.top() == '(' && s[i] == ')') || (x.top() == '[' && s[i] == ']')))
        x.pop();
      else
        x.push(s[i]);
    }
    cout << (x.empty() ? "Yes" : "No") << endl;
  }
  return 0;
}
    
/*
输入


包括多组数据。每组1行，为包含括号的表达式。

输出


如果是正确的格式，输出“Yes”，否则输出“No”

样例输入

[([])]
[[
(]
[

样例输出

Yes
No
No
No
*/