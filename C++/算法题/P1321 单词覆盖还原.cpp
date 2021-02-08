#include <iostream>
#include <string>
using namespace std;
int boy(string s,int y) {
  int num = 0;
  if (s[y] == 'b' && s[y + 1] == 'o' && s[y + 2] == 'y')num = 3;
  else if ((s[y] == 'b' && s[y + 1] == 'o')||(s[y] == 'o' && s[y + 1] == 'y'))num = 2;
  else num = 1;
  return num;
}
int girl(string s,int y) {
  int num = 0;
  if (s[y] == 'g' && s[y + 1] == 'i' && s[y + 2] == 'r'&&s[y + 3] == 'l')num = 4;
  else if ((s[y] == 'g' && s[y + 1] == 'i'&&s[y + 2] == 'r') || (s[y] == 'i' && s[y + 1] == 'r'&&s[y + 2] == 'l'))num = 3;
  else if ((s[y] == 'g' && s[y + 1] == 'i')||(s[y] == 'i' && s[y + 1] == 'r')||(s[y] == 'r' && s[y + 1] == 'l'))num = 2;
  else num = 1;
  return num;
}
int main(){
  string s;
  while (cin >> s) {
    int sum1=0, sum2=0;
    for (int i = 0; i < s.size();)
    if(s[i]=='b'||s[i]=='o'||s[i]=='y')
      sum1++, i += boy(s, i);
      else if(s[i]=='g'||s[i]=='i'||s[i]=='r'||s[i]=='l')
        sum2++, i += girl(s, i);
      else i++;cout << sum1 << endl << sum2 << endl;
  }
  return 0;
}
/*
题目描述

在一长串(3<=l<=255)中被反复贴有boy和girl两单词，
后贴上的可能覆盖已贴上的单词(没有被覆盖的用句点
表示)，最终每个单词至少有一个字符没有被覆盖。问
贴有几个boy几个girl?

输入输出格式

输入格式：
一行被被反复贴有boy和girl两单词的字符串。

输出格式：
两行，两个整数。第一行为boy的个数，第二行为girl的个数。

输入输出样例

输入样例#1： 复制
……boyogirlyy……girl…….
输出样例#1： 复制
4
2
*/