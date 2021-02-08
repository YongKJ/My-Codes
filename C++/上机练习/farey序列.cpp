#include <iostream>
#include <map>
using namespace std;
struct farey {
  int x, y;
} farey1;
int main() {
  int n;
  map<double, farey> x;
  map<double, farey>::iterator p;
  while (cin >> n){
    for (int i=1;i<=n;i++)
      for (int j=0;j<=i;j++)
        if (x.find(j * 1.0 / i) == x.end()) {
          struct farey d1;
          d1.x = j, d1.y = i;
          x[j * 1.0 / i] = d1;
        }
    for (p = x.begin(); p != x.end(); p++)
      cout << p->second.x << "/" << p->second.y << endl;
  }
  return 0;
}
/*
描述


所有0与1之间的分母不大于n的最简分数，把它们按照升序排列，得到的序列就是Farey序列。

n =2： {0/1, 1/2, 1/1} 
n =3： {0/1, 1/3, 1/2, 2/3, 1/1} 
n =4： {0/1, 1/4, 1/3, 1/2, 2/3, 3/4, 1/1} 
n =5： {0/1, 1/5, 1/4, 1/3, 2/5, 1/2, 3/5, 2/3, 3/4, 4/5, 1/1}

给出n，输出相应的Farey序列。

输入


一个数n。

输出


相应的Farey序列。

样例输入

3

样例输出

0/1
1/3
1/2
2/3 
1/1
*/