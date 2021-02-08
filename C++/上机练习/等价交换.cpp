#include <iostream>
#include <map>
#include <iomanip>
using namespace std;
struct Change {
  int x, y;
} a;
int main(){
  int n, m;
  while (cin >> m >> n) {
    float sum = 0;
    map<double, Change> c;
    map<double, Change>::reverse_iterator p;
    while (n--) {
      cin >> a.x >> a.y;
      c[a.y / a.x * 1.0] = a;
    }
    for (p = c.rbegin(); p != c.rend(); p++)
      if (m > 0)
        sum += (p->second).y, m -= (p->second).x;
    cout << fixed << setprecision(2) << sum << endl;
  }
  return 0;
}
/*
描述


黑龙江的五常大米全国闻名，每年到了秋天，
农民们把自己家的大米到集市上去买，
但由于五常地区还是一个比较落后的地方，
还实行物物交换，即农民用大米换白面，
可以用来蒸馒头啊！每个集市上大米换白面的
比例并不相等，如何能用最少的大米换到
最多的白面呢？（单位是斤）

输入


输入数据有多组，每组数据的第一行有2个数：
m和n,m代表大米的斤数，n代表有n集市，
接下来有n行，每行2个数t1和t2，
表示在这个集市可以用t1斤的大米换t2斤的
白面(只有t2斤的白面)。
输出


输出m斤大米能换到的白面的最大值(结果保留2位小数）
样例输入

5 3
1 2
4 9
1 5

样例输出

14.00
*/