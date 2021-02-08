#include <iostream>
#include <stack>
using namespace std;
int main(){
  char str[20];
  stack<char> a;
  int i;
  while(cin>>str){
    for (a.push(str[0]), i = 1; str[i] != '\0'; i++) {
      if (a.size() == 0)
        a.push(str[i]);
      else if (a.top() == '(' && str[i] == ')')
        a.pop();
      else
        a.push(str[i]);
    }
    if (a.empty())
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
    while (!a.empty())
      a.pop();
  }
  return 0;
}