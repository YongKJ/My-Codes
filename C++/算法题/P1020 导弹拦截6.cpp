#include <iostream>
#include <cstdio>
#include <map>
using namespace std;
int main(){
  int n = 1, ans = 0;
  map<int, int> h, ht, best;
  do {
    cin >> h[n++];
  } while (getchar() == ' ');
  best[0] = 0x7ffffff;
  for (int i=1;i<n;i++)
    for (int j=ans;j>=0;j--)
      if (best[j] >= h[i]) {
        best[j + 1] = h[i], ans = max(ans, j + 1);
        break;
      }
  cout << ans << endl;
  ans = 0;
  for (int i=1;i<n;i++){
    for (int j=0;j<=ans;j++)
      if (ht[j] >= h[i]) {
        ht[j] = h[i];
        break;
      }
    if (ht[ans] < h[i])
      ht[++ans] = h[i];
  }
  cout << ans << endl;
  return 0;
}
/*
题目描述

某国为了防御敌国的导弹袭击，发展出一种导弹拦截系统。
但是这种导弹拦截系统有一个缺陷：虽然它的第一发炮弹
能够到达任意的高度，但是以后每一发炮弹都不能高于前
一发的高度。某天，雷达捕捉到敌国的导弹来袭。由于该
系统还在试用阶段，所以只有一套系统，因此有可能不能
拦截所有的导弹。

输入导弹依次飞来的高度（雷达给出的高度数据是50000≤
50000的正整数），计算这套系统最多能拦截多少导弹，
如果要拦截所有导弹最少要配备多少套这种导弹拦截系统。

输入输出格式

输入格式：
1行，若干个整数（个数100000≤100000）

输出格式：
2行，每行一个整数，第一个数字表示这套系统最多能
拦截多少导弹，第二个数字表示如果要拦截所有导弹最
少要配备多少套这种导弹拦截系统。

输入输出样例

输入样例#1： 复制
389 207 155 300 299 170 158 65
输出样例#1： 复制
6
2
说明

为了让大家更好地测试n方算法，本题开启spj，n方100分，
nlogn200分

每点两问，按问给分
*/
