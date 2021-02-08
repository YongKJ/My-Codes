#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main(){
  char s[100], c[50];
  while(cin.getline(s,100)){
    int n, j=0;
    stack<char> p, f; 
    for (int i = 0; i < strlen(s); i++) {
      if (s[i] == '(' || s[i] == ')')c[j++] = s[i];
      if(s[i]=='('||s[i]==',')p.push(s[i]);
      else if (s[i] == ')') {n = 1;
      while (p.top() != '(')
        n++, p.pop();
      p.pop();
    }
  }
    for (int i = 0; i < j; i++)
    if(c[i]==')'&&c[i-1]=='(')f.pop();
    else f.push(c[i]);
    cout <<f.size()/2+1<<" "<< n << endl;
  }
  return 0;
}

/*
描述


输入广义表序列，使用链表存储广义表，计算并输出
广义表的深度与宽度。

输入


广义表序列

输出


广义表的深度与宽度

样例输入

(a,(b,(c,d),e))
(a,b,c,d)
(a)
(1,(2),(3,(4),(5,(6))),(7))
()
(())
样例输出

3 2
1 4
1 1
4 4
1 1
2 1
*/