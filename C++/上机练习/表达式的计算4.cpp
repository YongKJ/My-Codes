#include <iostream>
#include <string>
#include <stack>
using namespace std;
class Count {
public:
  Count(string str);
  void handle();
  void f();
  void calculate();

private:
  int x, y;
  string str
  stack<int> num, opt;
};
int Priority(char s){
  switch (s) {
  case '(':return 3;
  case '*':case '/':return 2;
  case '+':case '-':return 1;
  default:return 0;
  }
}
void calculate(char s){
  switch (s) {
  case '+':
    y = num.top(), num.pop(), x = num.top(), num.pop();
    num.push(x + y);
    break;
  case '-':
    y = num.top(), num.pop(), x = num.top(), num.pop();
    num.push(x - y);
    break;
  case '*':
    y = num.top(), num.pop(), x = num.top(), num.pop();
    num.push(x * y);
    break;
  case '/':
    y = num.top(), num.pop(), x = num.top(), num.pop();
    num.push(x / y);
  }
}
int main(){
  string str;
  while(cin >> str,str[0]!='0'){
    stack<int> num, opt;
    int i = 0, tmp = 0;
  while(str[i]!='\0'&&opt.empty()){
    if ('0' <= str[i] && str[i] <= '9') {
      tmp = tmp * 10 + str[i] - '0', i++;
      if (str[i] < '0' || str[i] > '9')
        num.push(tmp), tmp = 0;
    }
    else{
        if(opt.empty()||(opt.top()=='('&&str[i]!=')')||Priority(str[i])>Priority(opt.top())){
          opt.push(str[i]), i++;
          continue;}
          if(opt.top()=='('&&str[i]==')'){
          opt.pop(), i++;
          continue;}
          if((str[i]=='\0'&&opt.empty())||(opt.top()=='('&&str[i]==')')||Priority(str[i])<=Priority(opt.top())){
            calculate(opt.top()), opt.pop();
          continue;}
    }
  }
  cout << num.top() << endl;
  }
  return 0;
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
          
	