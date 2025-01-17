#include <iostream>
#include <cmath>
using namespace std;
int main() {
  long long n, x;
  cin >> n;
  x = n / pow(2, 16) + n % int(pow(2, 16)) * pow(2, 16);
  cout << x << endl;
  return 0;
}
/*
这道题其实就是让我们把n转换为二进制

前十六位边为后十六位，后十六位变为前十六位

再转回十进制

但我们其实不用这么麻烦

不需要转二进制

直接写为运算：

前十六位：n>>16;

后十六位：n-n>>16<<16

再简化一下：

前十六位：n/2^16

后十六位：n%2^16

那么。。。

2^16=64*1024=65536

题目描述

给出一个小于2322 
32
 的正整数。这个数可以用一个3232位的二进制数表示（不足3232位用00补足）。我们称这个二进制数的前1616位为“高位”，后1616位为“低位”。将它的高低位交换，我们可以得到一个新的数。试问这个新的数是多少（用十进制表示）。

例如，数13145201314520用二进制表示为0000000000010100000011101101100000000000000101000000111011011000（添加了1111个前导00补足为3232位），其中前1616位为高位，即00000000000101000000000000010100；后1616位为低位，即00001110110110000000111011011000。将它的高低位进行交换，我们得到了一个新的二进制数0000111011011000000000000001010000001110110110000000000000010100。它即是十进制的249036820249036820。

输入输出格式

输入格式：
一个小于2322 
32
 的正整数

输出格式：
将新的数输出

输入输出样例

输入样例#1： 复制
1314520
输出样例#1： 复制
249036820
*/