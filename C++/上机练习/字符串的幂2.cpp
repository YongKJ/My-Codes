#include <iostream>
#include <string>
using namespace std;
string s1;
int Next[100];
void kmp() {
  string x = s1;
  int i = 0, j = Next[0] = -1, m = s1.size();
  while (i < m) {
    while (j != -1 && x[i] != x[j])
      j = Next[j];
    Next[++i] = ++j;
  }
}
int main(){
  while (memset(Next, 0, sizeof(Next)), cin >> s1) {
    kmp();
    int len = s1.size(), temp = len - Next[len];
    cout << (len % temp ? 1 : len / temp) << endl;
  }
  cout << endl;
  return 0;
}
/*
输入


包括多组数据，每组一个字符串s。

输出


最大的n

样例输入

abcd
aaaa
ababab
EOF
样例输出

1
4
3
*/
	