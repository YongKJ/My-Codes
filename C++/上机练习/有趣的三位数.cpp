#include <iostream>
#include <set>
using namespace std;
class number {
public:
  number(int a, int b, int c);
  int push1(int t);
  void show();

private:
  set<int> x;
  int s[3];
  static int t1;
};
int main(){
  for (int i=124;i<387;i++)
    for (int j = i+38;j<785; j++) {
      if (i + j < 982)
        number d1(i, j, i + j);
     else
        break;
    }
  return 0;
}
int number::t1 = 1;
number::number(int a, int b, int c) {
  s[0] = a, s[1] = b, s[2] = c;
  show();
}
int number::push1(int t){
  while (t){
    if (t % 10 != 0)
      x.insert(t % 10);
    t /= 10;
  }
  return x.size();
}
void number::show(){
  int t;
  t = push1(s[0]);
  if(t==3)
    t = push1(s[1]);
  if(t==6)
    t = push1(s[2]);
  if (t == 9)
    cout << s[0] << " " << s[1] << " " << s[2] <<" "<<t1++<< endl;
}
  		
    
/*
描述


有这样一组数，每组由三个三位数组成，
并且这三个数中1~9有且仅有一次，
更特殊的是这三个数中，
两个较小的数相加等于另外一个数（如124 659 783）。 
你的任务就是查找出所有满足上述条件的组
（以组出现，并且按照升序排列
（每组之间以按首元素升序。对于其中的一组，
三个数也按照升序排列））。

输入


no input

输出


输出所有满足题意的组
（每个组的三个数之间以一个空格）。

样例输入


样例输出

124 659 783
125 739 864
... ... ...
216 738 954
218 349 567
*/