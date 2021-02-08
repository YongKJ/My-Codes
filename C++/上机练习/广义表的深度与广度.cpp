#include <iostream>
#include <string>
#include <stack>
#include <set>
using namespace std;
int main() {
  char c[20];
  while (cin.getline(c, 20)) {
    set<int> q;
    stack<char> p;
    if(strlen(c)==2)
      cout << 0 << " " << 0 << endl;
      else{
    for (int i = 0,j=0; i < strlen(c); i++)
      if (c[i]=='('||c[i]==',')p.push(c[i]);
      else if (c[i] == ')') {
        int k = 0;
        while (p.top() != '(')
          k++, p.pop();
        p.pop();
        if (i == strlen(c) - 1)
          cout << k + 1 << " ";
        else
          q.insert(k + 1);
      }
    cout << (q.empty() ? 1 : *(--q.end())) << endl;
      }
  }
  return 0;
}
/*
描述


输入广义表序列，使用链表存储广义表，计算并输出广义表的深度与宽度。

输入


广义表序列

输出


广义表的深度与宽度

样例输入

(a,(b,(c,d),e))
(a,b,c,d)
(a)
样例输出

3 2
*/