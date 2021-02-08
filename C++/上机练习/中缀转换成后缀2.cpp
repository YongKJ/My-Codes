#include <iostream>
#include <string>
#include <stack>
#include <queue>
using namespace std;
int Priority(char s){
  switch (s) {
  case '*':case '/':return 3;
  case '+':case '-':return 2;
  case '(':return 1;
  default:return 0;
  }
}
int main(){
  int t;
  string str;
  cin >> t;
  while(t--&&cin>>str){
    stack<char> q;
    queue<char> p;
    q.push('#');
    for (int i=0;i<str.size();i++){
      if('0' <= str[i] && str[i] <= '9')
        p.push(str[i]);
       else if(str[i]=='(')
         q.push(str[i]);
        else if (str[i] == ')') {
            while (q.top() != '(')
              p.push(q.top()), q.pop();
            q.pop();
        } else {
          while (Priority(str[i]) <= Priority(q.top()))
            p.push(q.top()), q.pop();
          q.push(str[i]);
        }
    }
    while (!q.empty())
      p.push(q.top()), q.pop();
    while (p.front()!='#')
      cout << p.front(), p.pop();
    cout << endl;
  }
  return 0;
}
/*
样例输入

2
1+2
(1+2)*3+4*5

样例输出

12+
12+3*45*+

if (str[i] == '+' || str[i] == '-' || str[i] == '*' ||str[i] == '/')
*/
          
    
	