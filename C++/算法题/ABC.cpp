#include <iostream>
using namespace std;
int main(){
  int a[3];
  char b[5];
  for (int i=0;i<3;i++)
    cin >> a[i];
  for (int i=0,t;i<3;i++)
    for (int j=i+1;j<3;j++)
    if(a[i]>a[j])
      t = a[i], a[i] = a[j], a[j] = t;
  cin >> b;
  for (int i = 0; i < 3; i++) {
    if (b[i] == 'A')
      cout << a[0];
    else if (b[i] == 'B')
      cout << a[1];
    else
      cout << a[2];
    cout << (i != 2 ? " " : "\n");
  }
  return 0;
}
/*
题意翻译

【题目描述】三个整数分别为 A ， B ， C . 这三个数字不会按照这样的顺序给你，但它们始终满足条件： A＜B＜C . 为了看起来更加简洁明了，我们希望你可以按照给定的顺序重新排列它们。

【输入格式】第一行包含三个正整数 A ， B 和 C ，不一定是按这个顺序。这三个数字都小于或等于100。第二行包含三个大写字母 “A” 、 “B” 和 “C” （它们之间_没有 _空格）表示所需的顺序.

【输出格式】在一行中输出A，B和C，用一个' '（空格）隔开.

感谢@smartzzh 提供的翻译

题目描述

You will be given three integers A, B and C. The numbers will not be given in that exact order, but we do know that A is less than B and B less than C. In order to make for a more pleasant viewing, we want to rearrange them in the given order.

输入输出格式

输入格式：
The first line contains three positive integers A, B and C, not necessarily in that order. All three numbers will be less than or equal to 100. The second line contains three uppercase letters 'A', 'B' and 'C' (with no spaces between them) representing the desired order.

输出格式：
Output the A, B and C in the desired order on a single line, separated by single spaces.

输入输出样例

输入样例#1： 复制
1 5 3
ABC
输出样例#1： 复制
1 3 5
输入样例#2： 复制
6 4 2
CAB
输出样例#2： 复制
6 2 4
*/