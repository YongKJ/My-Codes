#include <iostream>
#include <string>
using namespace std;
int main() {
  int t;
  string s;
  cin >> t;
  while (t--&&cin >> s) {
    int nextval[s.size()];
    nextval[0] = -1;
    for (int i = 0, j = -1; i < s.size();)
      if (j == -1 || s[i] == s[j])i++, j++, nextval[i] = (s[i] != s[j] ? j : nextval[j]);
      else j = nextval[j];
    for (int i = 0; i < s.size(); i++)
      cout << nextval[i]+1 << (i != s.size()-1 ? " " : "\n");
  }
  return 0;
}
/*
输入
2
abaabcac
aaaab
1
abcaabbabcab
1
abcabaa
1
ababaabab

输出
0 1 0 2 1 3 0 2
0 0 0 0 4

012345678
   abaabcac
   01021302
*/