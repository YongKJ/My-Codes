#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
char s[20];
double lan() {
  cin >> s;
  if(strlen(s)==1&&!(s[0]>='0'&&s[0]<='9')){
    switch (s[0]) {
    case '+':
      return lan() + lan();
    case '-':
      return lan() - lan();
    case '*':
      return lan() * lan();
    case '/':
      return lan() / lan();
    }
  } 
    else
    return atof(s);
}
int main() {
  cout << fixed << setprecision(6) << lan() << endl;
  return 0;
}
/*
* + 11.0 12.0 + 24.0 35.0
*/
	