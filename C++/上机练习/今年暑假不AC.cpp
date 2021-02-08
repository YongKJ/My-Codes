#include <iostream>
using namespace std;
struct Data {
  int x,y;
} data;
class Jia {
public:
  Jia(int a);
  void show();

private:
  int n;
};
int main() {
  int n;
  while (cin >> n, n)
    Jia d1(n);
  return 0;
}
Jia::Jia(int a) {
  n = a;
  show();
}
void Jia::show(){
    Data d1[n], t;
    int sum = 0, k, k1, t1;
    for (int i = 0; i < n; i++)
      cin >> d1[i].x >> d1[i].y;
    for (int i=0;i<n-1;i++)
      for (int j=i+1;j<n;j++){
        if (d1[i].x == d1[j].x) {
          if (d1[i].y > d1[j].y) {
            t = d1[i], d1[i] = d1[j], d1[j] = t;
          }
        } else if (d1[i].x > d1[j].x) {
          t = d1[i], d1[i] = d1[j], d1[j] = t;
        }
      }
    for (int i = 0; i < n; i++) {
      cout << d1[i].x << " " << d1[i].y<< endl;
    }
    cout << endl;
    k = d1[0].y < d1[1].y ? d1[0].y : d1[1].y, sum++;
    for (int i = 2; i < n-1; i++) {	
      if (d1[i].x >= k&&d1[i+1].y>d1[i].y)
        sum++, k = d1[i].y;
    }
    cout << sum << endl;
}
        
    
  	
/*
描述

“今年暑假不AC？”
“是的。”
“那你干什么呢？”
“看世界杯呀，笨蛋！”
“@#$%^&*%...”

确实如此，世界杯来了，球迷的节日也来了，
估计很多ACMer也会抛开电脑，奔向电视了。
作为球迷，一定想看尽量多的完整的比赛，
当然，作为新时代的好青年，你一定还会看
一些其它的节目，比如新闻联播（永远不要
忘记关心国家大事）、非常6+7、超级女生，
以及王小丫的《开心辞典》等等，假设你已
经知道了所有你喜欢看的电视节目的转播时间表，
你会合理安排吗？（目标是能看尽量多的完整节目）

输入

输入数据包含多个测试实例，每个测试实例的
第一行只有一个整数n(n<=100)，表示你喜欢看的
节目的总数，然后是n行数据，每行包括两个数据
Ti_s,Ti_e (1<=i<=n)，分别表示第i个节目的开始和结束时间，
为了简化问题，每个时间都用一个正整数表示。
n=0表示输入结束，不做处理。

输出


对于每个测试实例，输出能完整看到的电视节目的个数，
每个测试实例的输出占一行。
样例输入

12
1 3
3 4
0 7
3 8
15 19
15 20
10 15
8 18
6 12
5 10
4 14
2 9
0

样例输出

5
*/