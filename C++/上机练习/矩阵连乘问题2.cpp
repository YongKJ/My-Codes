#include <iostream>
#include <map>
#include <stack>
#include <string>
using namespace std;
struct node {
  int x, y;
} a;
int ans,flag;
node operator*(node a, node b) {
  flag = a.y == b.x ? 1 : 0;
  ans += a.x * b.x * b.y, a.y = b.y;
  return a;
}
int main(){
  int n, k;
  string s;
  while(ans=0,cin>>n){
    map<int, node> d;
    stack<int> p, q;
    while(n--)
      cin >> s >> a.x >> a.y, d[s[0]-'A'] = a;
    cin >> s;
    for (int i=0;i<s.length();i++){
      if (s[i] == ')') {
        while (p.top() != -1)
          q.push(p.top()), p.pop();
        p.pop(), k = q.top(), q.pop();
        while (!q.empty())
          d[k + q.top()] = d[k] * d[q.top()], k += q.top(), q.pop();
        p.push(k);
      } else
        p.push(s[i] == '(' ? -1 : s[i] - 'A');
    }
    while (!p.empty())
      q.push(p.top()), p.pop();
    k = q.top(), q.pop();
    while (!q.empty())
      d[k + q.top()] = d[k] * d[q.top()], k += q.top(), q.pop();
    if (flag)
      cout << ans << endl;
    else
      cout << "error" << endl;
  }
  return 0;
}
/*
样例输入

3
A 10 100
B 100 5
C 5 50
A(BC)

样例输出

75000
*/
      
    
            
	
	