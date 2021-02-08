#include <iostream>
using namespace std;
string s1, s2;
void tree(char *s1, char *s2, int length) {
  if (length == 0)return;
  int i = 0;
  for (; i < length; i++)
    if (s1[i] == *s2)break;
  tree(s1, s2 + 1, i), tree(s1 + i + 1, s2 + i + 1, length - (i + 1)),cout << *s2;
}
int main() {  
  while (cin >> s1 >> s2)
    tree(&s2[0], &s1[0], s1.size()), cout << endl;
  return 0;
}
/*
样例输入

ABDC DBAC
BCAD CBAD

样例输出

DBCA
CDAB

提示

类似  tyvj.cn 第1441题
*/
  	