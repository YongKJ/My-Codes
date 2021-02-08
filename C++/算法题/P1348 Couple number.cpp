#include <iostream>
using namespace std;
int main(){
  int a, b,sum;
  while (sum = 0, cin >> a >> b) {
    for (int i = a; i <= b; i++)
      if (i % 2 || !(i % 4))
        sum++;cout << sum << endl;
  }return 0;
}
    
/*
题目描述

任何一个整数N都能表示成另外两个整数a和b的平方差吗？
如果能，那么这个数N就叫做Couple number。你的工作就
是判断一个数N是不是Couple number。

输入输出格式

输入格式：
仅一行，两个长整型范围内的整数n1和n2，之间用1个空格
隔开。

输出格式：
输出在n1到n2范围内有多少个Couple number。

注意：包括n1和n2两个数，且n1<n2，n2 - n1 <= 10 000 000。

输入输出样例

输入样例#1： 复制
1 10
输出样例#1： 复制
7

思路

平方差公式即(a+b)(a-b)=a^2-b^2。

a^2-b^2=(a+b)(a-b)=>a+b与a-b奇偶性相同；
所以(a+b)(a-b)要么是奇数，要么是4的倍数。
*/