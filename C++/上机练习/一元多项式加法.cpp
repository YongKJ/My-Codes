#include <iostream>
#include <map>
using namespace std;
int main(){
  int n, a, b;
  while (cin >> n) {
    map<int, int> x;
    map<int, int>::reverse_iterator p;
    while (n--)
      cin >> a >> b, x[b] = a;
    cin >> n;
    while (n--)
      cin >> a >> b, x[b] = (x.find(b) != x.end() ? x[b] + a : a);
    for (p = x.rbegin(); p != x.rend(); p++)
      if (p->second != 0)
        cout << p->second << " " << p->first << (p != --x.rend() ? " " : "\n");
  }
  return 0;
}
     
      
/*
描述


给定2个一元多项式，计算它们的和。例如：
f(x)=5x3-3x2+1和g(x)=3x4+3x2+x，
则h(x)=f(x)+g(x)=3x4+5x3+x+1。

输入


只有一个测试案例，输入包括2行。

第1行为多项式f(x)的项数n和n项的系数和次方
（按照次方从大到小）。第2行为多项式g(x)的项数m和m项的系数和次方
（按照次方从大到小）。

其中：0<m，n<100

输出


多项式h(x)每项的系数和次方（按照次方从大到小）。

样例输入

3 5 3 -3 2 1 0
3 3 4 3 2 1 1

样例输出

3 4 5 3 1 1 1 0
*/