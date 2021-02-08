#include <iostream>
#include <string>
using namespace std;
int kmp(char *s, char *t) {
  int ls = strlen(s), lt = strlen(t), next[100], flag;
  for (int i = ls; i > 0; i--)
    s[i] = s[i - 1];
  for (int i = lt; i > 0; i--)
    t[i] = t[i - 1];
  next[1] = 0;
  for (int i = 1, j = 0; t[i];)
    if (j == 0 || t[i] == t[j])
      i++, j++, next[i] = j;
    else
      j = next[j];
  for (int i = 1, j = 1; s[i] && t[j];)
    if (j == 0 || s[i] == t[j])
      i++, j++, flag = j > lt ? 1 : 0;
    else
      j = next[j];
  return flag;
}
int main() {
  char s[100], t[100];
  while (cin >> s >> t)
    cout << (kmp(s, t) ? "Yes" : "No") << endl;
  return 0;
}