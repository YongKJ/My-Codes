#include <iostream>
#include <string>
using namespace std;
int index(string s, string t) {
  int Nextval[t.size()], flag;
  Nextval[0] = -1;
  for (int i = 0, j = -1; i < t.size();)
    if (j == -1 || t[i] == t[j])
      i++, j++, Nextval[i] = (t[i] == t[j] ? Nextval[j] : j);
    else
      j = Nextval[j];
  for (int i = 0, j = -1;i < s.size() && j < int(t.size());) //有符号数和无符号数运算的时候，有符号数会自动向无符号数转换(-1转换为无符号数时值为4294967295)
    if (j == -1 || s[i] == t[j])
      i++, j++, flag = j == t.size() ? 1 : 0;
    else
      j = Nextval[j];
  return flag;
}
int main() {
  string s, t;
  while (cin >> s >> t)
    cout << (index(s, t) ? "Yes" : "No") << endl;
  return 0;
}
/*
输入:
aabaabaabaac aabaac
aabaabaabaac aabad

输出:
Yes
No
*/