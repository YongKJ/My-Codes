#include <iostream>
using namespace std;
void in(char s[]) {
  static int i = 0;
  char c = getchar();
  if (c != '\n')
  in(s), s[i++] = c;
  s[i] = '\0';
}
int main() {
  int t = 2;
  char s[10];
  while (t--)
    in(s), cout << s << endl;
  return 0;
}