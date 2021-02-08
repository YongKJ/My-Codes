#include <iostream>
using namespace std;
class cycle {
public:
  cycle(int x1,int x2,int x3,int x4);
  int show(long i);

private:
  int a, b, c, d;
  static int t;
};
int main(){
  int a, b, c, d;
  long i;
  while (i = 1, cin >> a >> b >> c >> d, !(a < 0 && b < 0 && c < 0 && d < 0)) {
    cycle d1(a, b, c, d);
    while (i++)
      if (d1.show(i))
        break;
  }
  return 0;
}
int cycle::t = 1;
cycle::cycle(int x1, int x2, int x3, int x4) {
  a = x1, b = x2, c = x3, d = x4;
}
int cycle::show(long i){
  int flag = 0;
  long x, y, z, k;
  k = i + d;
  x = (k - a) % 23;
  y = (k - b) % 28;
  z = (k - c) % 33;
  if (x == 0 && y == 0 && z == 0) {
    cout << "Case " << t << ": the next triple peak occurs in " << i << " days."
         << endl;
    flag = 1,t++;
  }
  return flag;
}
  
	
/*
描述


        人生来就有三个生理周期，分别为体力、感情和智力周期，它们的周期长度为23天、28天和33天。
        每一个周期中有一天是高峰。在高峰这天，人会在相应的方面表现出色。例如，智力周期的高峰，人会思维敏捷，精力容易高度集中。
        因为三个周期的周长不同，所以通常三个周期的高峰不会落在同一天。对于每个人，我们想知道何时三个高峰落在同一天。
        对于每个周期，我们会给出从当前年份的第一天开始，到出现高峰的天数（不一定是第一次高峰出现的时间）。
        你的任务是给定一个从当年第一天开始数的天数，输出从给定时间开始（不包括给定时间）下一次三个高峰落在同一天的时间（距给定时间的天数）。
        例如：给定时间为10，下次出现三个高峰同天的时间是12，则输出2（注意这里不是3）。

输入


        输入四个整数：p, e, i和d。 
        p, e, i分别表示体力、情感和智力高峰出现的时间（时间从当年的第一天开始计算）。
        d 是给定的时间，可能小于p, e, 或 i。 
        所有给定时间是非负的并且小于等于365, 所求的时间小于等于21252。

输出


从给定时间起，下一次三个高峰同天的时间（距离给定时间的天数）。
*/
/*
样例输入

0 0 0 0
0 0 0 100
5 20 34 325
4 5 6 7
283 102 23 320
203 301 203 40
-1 -1 -1 -1

样例输出

Case 1: the next triple peak occurs in 21252 days.
Case 2: the next triple peak occurs in 21152 days.
Case 3: the next triple peak occurs in 19575 days.
Case 4: the next triple peak occurs in 16994 days.
Case 5: the next triple peak occurs in 8910 days.
Case 6: the next triple peak occurs in 10789 days.
*/