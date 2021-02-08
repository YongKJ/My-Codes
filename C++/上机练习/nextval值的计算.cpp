#include <iostream>
#include <string>
#include <map>
using namespace std;
int main(){
  int t;
  string s1;
  cin >> t;
  while ( t--&&cin >> s1) {
    map<int, int> Next;
    int i = 0, j = -1;
    Next[0] = -1;
    while (s1[i]) {
      if (j == -1 || s1[i] == s1[j])
        ++i, ++j, Next[i] = (s1[i] != s1[j] ? j : Next[j]);
      else j = Next[j];
    }
    for (int i = 0; i < s1.size(); i++)
      cout << Next[i] + 1 << (i != s1.size() - 1 ? " " : "\n");
  }
  return 0;
}
/*
描述


KMP算法是在已知模式串的nexvalt函数值的基础上执行的，
那么，如何求得模式串的nextval函数值呢?

输入


第一行是测试数据的组数n。
每组测试数据占一行，是一个模式串T(字符串长度不超过
500字符)。

输出


n行，每行输出模式串的nextval值。数据之间用空格区分，
最后一个数据之后没有空格。

样例输入

2
aaaab
abaabcac

样例输出

0 0 0 0 4
0 1 0 2 1 3 0 2
*/