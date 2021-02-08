#include <iostream>
using namespace std;
class number {
public:
  number(int a, int b, int c);
  void show();
  void magic();

private:
  int m, s, t, sum, time;
};
int main() {
  int m, s, t;
  while (cin >> m >> s >> t)
    number d1(m, s, t);
  return 0;
}
number::number(int a, int b, int c) {
  m = a, s = b, t = c;
  show();
}
void number::show(){
  sum = 0, time = 0;
  int n, m1 = m, t1 = t;
  while (m >= 10) {
    n = m / 10, sum += 60 * n, time += n;
    cout << sum << " " << time << endl;
    m %= 10, t -= time;
    cout << m << " " << t << endl;
    if(sum<=s)
      magic();
  }
  if (sum >= s)
    cout << "Yes" << endl << time << endl;
  else
    cout << "No" << endl << sum << endl;
}
void number::magic() {
  int m1, t1;
  m1 = 10 - m;
  t1 = m1 % 4 == 0 ? m1 / 4 : (m1 / 4) + 1;
  if (t >= t1 + 1)
    m += 4 * t1, t -= t1, time += t1;
  else
    sum += t * 17;
  cout << sum << " " << time << endl;
  cout << m << " " << t << endl;
}
	
/*
描述

恶魔猎手尤迫安野心勃勃.他背叛了暗夜精灵，
率深藏在海底的那加企图叛变：守望者在与
尤迪安的交锋中遭遇了围杀.被困在一个荒芜的
大岛上。为了杀死守望者，尤迪安开始对这个
荒岛施咒，这座岛很快就会沉下去，到那时，
刀上的所有人都会遇难：守望者的跑步速度，
为17m/s， 以这样的速度是无法逃离荒岛的。
庆幸的是守望者拥有闪烁法术，可在1s内移动
60m，不过每次使用闪烁法术都会消耗魔法值
10点。守望者的魔法值恢复的速度为4点/s，
只有处在原地休息状态时才能恢复。 
现在已知守望者的魔法初值M，他所在的初始
位置与岛的出口之间的距离S，岛沉没的时间T。
你的任务是写一个程序帮助守望者计算如何在
最短的时间内逃离荒岛，若不能逃出，则输出
守望者在剩下的时间内能走的最远距离。注意:
守望者跑步、闪烁或休息活动均以秒(s)为单位。
且每次活动的持续时间为整数秒。距离的单位为米(m)。

输入

多组测试数据，每组仅一行，包括空格隔开的
三个非负整数M，S，T。

输出

每组输出： 
第1行为字符串"Yes"或"No" (区分大小写)，即守望者
是否能逃离荒岛。
第2行包含一个整数，第一行为"Yes" (区分大小写）
时表示守望着逃离荒岛的最短时间
第一行为"No" (区分大小写) 时表示守望者能走的最远距离。

样例输入

39 200 4

样例输出

No
197
*/