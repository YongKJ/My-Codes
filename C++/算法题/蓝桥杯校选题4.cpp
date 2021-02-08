#include <iostream>
#include <stack>
#include <map>
#include <cstring>
using namespace std;
struct data {
  char c;
  int number;
};
int main(){
  data t;
  char a[100001];
  stack<data> s;
  map<int, int> p;
  map<int, int>::iterator q;
  cin >> a;
  for (int i=0;i<strlen(a);i++){
    if (!s.empty()&&s.top().c == '(' && a[i] == ')') {
      p[s.top().number] = i + 1;
      s.pop();
    } else {
      t.number = i + 1;
      t.c = a[i];
      s.push(t);
    }
  }
  for (q = p.begin(); q != p.end(); q++)
    cout << q->first << " " << q->second << endl;
  return 0;
}
/*
描述
给定一个合法的括号序列，请你找出每一对匹配
左右括号的位置。
输入
一个只包含左右小括号的序列，长度不超过
100000。保证括号序列是合法的。
输出
对于序列中每一个左括号，输出它和与它匹配的
右括号的位置。
样例输入
(())()()

样例输出
1 4  
2 3  
5 6  
7 8
*/