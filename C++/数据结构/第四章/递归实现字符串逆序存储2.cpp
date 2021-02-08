#include <iostream>
using namespace std;
void deal(char s[], int i) {
  char c = s[i];
  static int j = 0;
  if (c)deal(s, i + 1), s[j++] = c;
  s[j] = '\0';
}
int main() {
  char s[20];
  while (cin >> s)
    deal(s, 0), cout << s << endl;
  return 0;
}