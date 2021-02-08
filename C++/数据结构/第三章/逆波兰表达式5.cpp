#include <iostream>
#include <string>
#include <stack>
#include <cstdlib>
#include <iomanip>
using namespace std;
int main(){
  string s, x;
  double x1, x2;
  while(cin>>s){
    stack<string> p;
    stack<double> q;
    p.push(s);
  do {
    cin >> s, p.push(s);
  } while (getchar() != '\n');
  while(!p.empty()){
    x = p.top(), p.pop();
    switch (x[0]) {
    case '+':
      x1 = q.top(), q.pop(), x2 = q.top(), q.pop(), q.push(x2 + x1);
      break;
    case '-':
      x1 = q.top(), q.pop(), x2 = q.top(), q.pop(), q.push(x2 - x1);
      break;
    case '*':
      x1 = q.top(), q.pop(), x2 = q.top(), q.pop(), q.push(x2 * x1);
      break;
    case '/':
      x1 = q.top(), q.pop(), x2 = q.top(), q.pop(), q.push(x2 / x1);
      break;
    default:
      q.push(atof(&x[0]));
    }
  }
  cout << fixed << setprecision(6) << q.top() << endl;
    }
  return 0;
}