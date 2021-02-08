#include <iostream>
using namespace std;
class Time {
public:
  Time(int a, int b, int c);
  void operator++();

private:
  int y, m, d, num;
};
int main(){
  int x, y, z;
  while (cin >> x >> y >> z) {
    Time d1(x, y, z);
    ++d1;
  }
  return 0;
}
Time::Time(int a, int b, int c) {
  y = a, m = b, d = c;
  if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
    num = 31;
  else if (m == 4 || m == 6 || m == 9 || m == 11)
    num = 30;
  else if (m == 2)
    num = ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) ? 29 : 28;
}
void Time::operator++() {
  d++;
  if (m == 12 && d > num)
    y++, m = 1, d -= num;
  else if (d > num)
    m++, d -= num;
  cout << y << "/" << m << "/" << d << endl;
}
/*
描述


定义日期类，重载自增运算。

输入


包括多组数据，每组包括3个整数表示一个日期中的年、月、日。

输出


日期的下一天。输出格式见样例。

样例输入

2000 1 2
2012 2 28
2001 2 28
2011 12 31
2012 4 30

样例输出

2000/1/3
2012/2/29
2001/3/1
2012/1/1
2012/5/1
*/

  
  