#include <iostream>
#include <string>
using namespace std;
int kmp(string s, string t) {
  int nextval[100], flag;
  nextval[1] = 0;
  for (int i = 1, j = 0; t[i];)
    if (j == 0 || t[i] == t[j])
      i++, j++, nextval[i] = t[i] == t[j] ? nextval[j] : j;
    else
      j = nextval[j];
  for (int i=1;t[i];i++)
    cout << nextval[i] << (t[i + 1] ? " " : "\n");
  for (int i = 1, j = 1; s[i] && t[j];)
    if (j == 0 || s[i] == t[j])
      i++, j++, flag = t[j] ? 0 : 1;
    else
      j = nextval[j];
  return flag;
}
int main() {
  string s, t;
  while (cin >> s >> t)
    cout << (kmp('#' + s, '#' + t) ? "Yes" : "No") << endl;
  return 0;
}