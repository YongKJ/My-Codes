#include <iostream>
using namespace std;
void insert(char *s, char *t, int pos) {
  int i, x = 0;
  char *p = s, *q = t;
  if (pos < 1) {
    cout << "pos参数非法" << endl;
    exit(0);
  }
  for (i = 0; p[i]&&i<pos; i++);
  if (!p[i]) {
    cout << pos << "位置大于字符串s的长度" << endl;
    exit(0);
  }
  while (p[i])
    i++;
  while (q[x])
    x++;
  for (int j = i; j >= pos; j--)
    p[j + x] = p[j];
  for (int j = i, k = 1; k <= x; j++, k++)
    p[j] = q[k];
}
int main() {
  char s[100], t[50];
  while (cin >> s >> t)
    insert(s, t, 3), cout << s << endl;
  return 0;
}