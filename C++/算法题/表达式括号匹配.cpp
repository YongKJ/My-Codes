#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main(){
  string s;
  while (cin >> s) {
    stack<char> f;
    for (int i = 0; s[i]!='@'; i++)
      if ( f.size()&&f.top()=='('&&s[i] == ')' )
        f.pop();
      else if(s[i]=='('||s[i]==')')
        f.push(s[i]);
    cout << (!f.size() ? "YES" : "NO") << endl;
  }
  return 0;
}
    

/*
题目描述

假设一个表达式有英文字母（小写）、
运算符（+，—，*，/）和左右小（圆）
括号构成，以“@”作为表达式的结束符。
请编写一个程序检查表达式中的左右圆
括号是否匹配，若匹配，则返回“YES”；
否则返回“NO”。表达式长度小于255，
左圆括号少于20个。

输入输出格式

输入格式：
一行：表达式

输出格式：
一行：“YES” 或“NO”

输入输出样例

输入样例#1： 复制
2*(x+y)/(1-x)@
(25+x)*(a*(a+b+b)@



输出样例#1： 复制
YES
输入样例#2： 复制
(25+x)*(a*(a+b+b)@
输出样例#2： 复制
NO
说明

表达式长度小于255，左圆括号少于20个
*/