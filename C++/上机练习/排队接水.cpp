#include <iostream>
#include <set>
using namespace std;
int main(){
  int n;
  while(cin>>n){
    int a, sum = 0, t = 0;
    set<int> x;
    set<int>::iterator p;
    while (n--) {
      cin >> a;
      x.insert(a);
    }
    for (p = x.begin(); p != x.end(); p++)
      t += *p, sum += t;
    cout << sum << endl;
  }
  return 0;
}
/*
描述


N个人同时提水到一个水龙头前提水因为大家的水桶大小不一，
所以水龙头注满第i(i=1,2,3......N)个人所需要的时间是T(i) 编写
一个程序，对这N个人使他们花费的时间总和最小，并求出
这个时间。

例如有三个人a,b,c，用时分别是2,1,3 排队顺序为c,b,a的时候，
c要等待3，b要等待4，c要等待6，总和为3+4+6=13 排队顺序
为a,b,c的时候，a要等待2，b要等待3，c要等待6，总和为
2+3+6=11 11更小，要找出这样的最小值。

输入

一组测试数据的个数n 分别输入这n个测试数据。

输出

排队所花费的最少时间和。

样例输入

3
2 1 3

样例输出

10
*/