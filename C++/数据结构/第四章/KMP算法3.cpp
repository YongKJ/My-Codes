#include <iostream>
#include <string>
using namespace std;
int kmp(string s, string t) {
  int next[100], flag;
  next[1] = 0;
  for (int i=0;s[i];i++)
    cout << s[i] << (s[i + 1] ? " " : "\n");
    for (int i=0;t[i];i++)
      cout << t[i] << (t[i + 1] ? " " : "\n");
  for (int i = 1, j = 0; t[i];)
    if (j == 0 || t[i] == t[j])
      i++, j++, next[i] = j;
    else
      j = next[j];
  for (int i=1;t[i];i++)
    cout << next[i] << (t[i+1] ? " " : "\n");
  for (int i = 1, j = 1; s[i] && t[j];)
    if (j == 0 || s[i] == t[j])
      i++, j++, flag = t[j] ? 0 : 1;
    else
      j = next[j];
  return flag;
}
int main() {
  string s, t;
  while (cin >> s >> t)
    cout << (kmp('#' + s, '#' + t) ? "Yes" : "No") << endl;
  return 0;
}