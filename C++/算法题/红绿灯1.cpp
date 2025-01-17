#include <iostream>
using namespace std;
struct road {
  int d, r, g;
};
int find_other(road s[], int i, int sum) {
  int T = s[i].r + s[i].g, t1 = sum % T, t2 = T - t1;
  if (t1 > s[i].g) sum += t2;
  return sum;
}
int main(){
  int n;
  while (cin >> n) {
    road s[n];
    for (int i = 0; i < n; i++)
      cin >> s[i].d;
    for (int i = 0; i < n; i++)
      cin >> s[i].r;
    for (int i = 0; i < n; i++)
      cin >> s[i].g;
    for (int i = 0, sum = 0; i < n; i++) {
      sum = find_other(s, i, sum + s[i].d);
      cout << sum << endl;
    }
  }
  return 0;
}
	
/*
题目描述

在一个城市，有一条笔直的公路，在这条公路上有N个十字路口，每个路口都设有一个红绿灯，已知相邻的两个路口距离为Ai千米(1≤i＜N)，每个路口的红灯时间为Ri，绿灯时间为Gi，没有黄灯，现在有一辆车从距离1号十字路口M千米的位置出发，且此时所有路口的红绿灯刚好从红灯跳到绿灯，问这辆车通过每个路口的时间(不能闯红灯，这辆车的速度为1千米每分钟)。

输入输出格式

输入格式：
第一行两个正整数N和M

第二行N-1个正整数Ai

第三行N个正整数Ri，为红灯时间(分钟)

第四行N个正整数Gi，为绿灯时间(分钟)

输出格式：
共N行，每行一个正整数，为这辆车通过每个十字路口的最早时间。

输入输出样例

输入样例#1： 复制
5 3
2 4 3 2
3 4 3 4 3
2 3 2 3 1
输出样例#1： 复制
5
7
11
14
16
说明

【数据范围】

对于50%的数据 N≤1000

对于100%的数据 N≤10^5 M，Ai≤10 Ri，Gi≤5

5 
3 2 4 3 2
3 4 3 4 3
2 3 2 3 1

5
7
11
14
16

*/