#include <iostream>
#include <string>
#include <stack>
#include <queue>
using namespace std;
class Count {
public:
  Count(string str);
  void handle();
  void f();
  void calculate();

private:
  int x, y;
  string a;
  stack<int> ans;
  stack<char> s;
  queue<char> q;
};
int main() {
  string a;
  while (cin >> a, a[0] != '0')
    Count d1(a);
  return 0;
}
Count::Count(string str) { a = str, handle(); }
void Count::handle(){
  q.push(a[0]), s.push(a[1]);
  for (int i=2;i<a.size();i++){
    if(('0' < a[i]) && (a[i] <= '9'))
          q.push(a[i]);
    else if (a[i] == '+' || a[i]=='-'){
        if (s.top() == '*' || s.top() == '/')
          q.push(s.top()), s.pop();
        s.push(a[i]);
      }
     else if (a[i] == '*' || a[i] == '/' || a[i] == '(')
          s.push(a[i]);
      else if (a[i] == ')') {
        while (s.top() != '(')
          q.push(s.top()), s.pop();
        s.pop();
      }
  }
  while (!s.empty())
    q.push(s.top()), s.pop();
    while(!q.empty())
      cout << q.front(), q.pop();
    cout << endl;
  //calculate();
}
void Count::f() {
  y = ans.top(), ans.pop();
  x = ans.top(), ans.pop();
}
void Count::calculate(){
  while (!q.empty()) {
    if ('0' < q.front() && q.front() <= '9')
      ans.push(q.front() - '0'), q.pop();
    else if (q.front() == '+')
      f(), ans.push(x + y), q.pop();
    else if (q.front() == '-')
      f(), ans.push(x - y), q.pop();
    else if (q.front() == '*')
      f(), ans.push(x * y), q.pop();
    else if (q.front() == '/')
      f(), ans.push(x / y), q.pop();
  }
  cout << ans.top() << endl;
}
/*
样例输入

3+2+1
3-2-1
1+2*3
0


样例输出

6
0
7
*/
