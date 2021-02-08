#include <iostream>
#include <map>
using namespace std;
int main(){
  int n, m;
  while(cin>>m>>n){
    map<int, int> x;
    for (int i = 0; i < m; i++)
      x[i] = 1;
    for (int i = 0, j = 0, s = 0; i < m - 1; j = (j + 1) % m) {
      s += x[j];
      if (s == n)
        s = x[j] = 0, i++;
    }
    for (int i = 0; i < m; i++)
      if (x[i] == 1)
        cout << i + 1 << endl;
  }
  return 0;
}
    
/*
描述


m只猴子要选大王，选举办法如下：所有猴子按照
1..m编号站成一个圆圈，从1号开始按照1、2、3……n
报数，凡报到n的猴子退出到圈外，如此循环，直到圆
圈内只有一只猴子时，这只猴子为大王。 其中：0<m，
n<100

输入


m和n。

输出


大王猴子的编号。

样例输入

4 2

样例输出

1
*/