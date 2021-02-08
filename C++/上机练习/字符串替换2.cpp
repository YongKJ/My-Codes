#include <iostream>
#include <cstring>
using namespace std;
int main() {
  char s[1000];
  while (gets(s)){
   for (int i = 0; i < strlen(s); i++)
    if (s[i] == 'y' && s[i + 1] == 'o' && s[i + 2] == 'u')cout << "we", i += 2;
    else cout << s[i];
   cout << endl;
  }
  return 0;
}