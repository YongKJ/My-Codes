#include <iostream>
#include <set>
using namespace std;
int main(){
  int n,a;
  while (cin >> n) {
    set<int> x;
    while (n-- && cin >> a)
      x.insert(a), cout << a << " ";
    cin >> n;
    while (n-- && cin >> a)
      if (x.find(a) == x.end())
        cout << a << (n != 0 ? " " : "\n");
  }
  return 0;
}
    
/*
描述


线性表a（有n个元素）和线性表b（有m个元素）的元素均为整数。
现将b中存在而a中不存在的元素插入到线性表a中。其中：0<m，n<100

输入


只有一个测试案例。

输入包括2行，第1行为n和n个整数，第2行为m和m个整数。

输出


输出插入元素后a中的元素。

样例输入

3 1 3 2
4 2 5 3 6

样例输出

1 3 2 5 6

提示

注意：输出的整数之间有1个空格，最后一个整数后面没有空格。
*/