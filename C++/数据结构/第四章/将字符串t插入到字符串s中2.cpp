#include <iostream>
using namespace std;
void insert(char *s, char *t, int pos) {
  int n = 0, m = 0;
  for (int i = 0; s[i]; i++)n++;
  for (int i = 0; t[i]; i++)m++;
  if (pos < 1 || n < pos) {
    cout << "Error" << endl;
    exit(0);
  }
  for (int i = n - 1; i >= pos - 1;i--)
    s[i + m] = s[i];
  for (int i = 0; i < m; i++)
    s[pos - 1 + i] = t[i];
  s[m + n] = '\0';
}
int main() {
  int pos;
  char s[100], t[50];
  while (cin >> s >> t>>pos)
    insert(s, t, pos), cout << s << endl;
  return 0;
}