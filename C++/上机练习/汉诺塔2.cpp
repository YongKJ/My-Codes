#include <iostream>
using namespace std;
class Tower {
public:
  Tower(int a);
  void show();

private:
  int n;
};
int main() {
  int n;
  while (cin >> n)
    Tower d1(n);
  return 0;
}
Tower::Tower(int a) {
  n = a;
  show();
}
void Tower::show(){
  long s=3;
  for (int i = 1, t = 3; i <= n - 2; i++) {
    s += t * 2;
    t = s;
  }
  s *= 3;
  if (n == 1)
    cout << 2 << endl;
  else
    cout << --s << endl;
}
  
  
	
/*
1
1

2 1
2 1
2

6 2 1 
6 2 1
6 2

24 
汉诺塔规则:
	
	有三根相邻的柱子，标号为A,B,C，
	A柱子上从下到上按金字塔状叠放着n个不同大小的圆盘，
	现在把所有盘子一个一个移动到柱子B上，
	并且每次移动同一根柱子上都不能出现大盘子在小盘子上方

描述


        汉诺塔的游戏大家都玩过了，规则什么的就不用再说一遍了吧。
        现在我们改变游戏的玩法，不允许直接从最左(右)边移到最右(左)边
        (每次移动一定是移到中间杆或从中间移出)，
        也不允许大盘放到下盘的上面。
        现在有N个圆盘，至少多少次移动才能把这些圆盘从最左边移到最右边？

输入


包含多组数据，每次输入一个N值(1<=N=35)。
输出


对于每组数据，输出移动最小的次数。
样例输入

1
3
12


样例输出

2
26
531440
*/