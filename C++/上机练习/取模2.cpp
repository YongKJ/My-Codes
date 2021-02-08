#include <iostream>
using namespace std;
int n, ans, y, z;
char x[101];
int number(int n) {
  int t;
  if (n == 1)
    return ans;
  t = number(n / 2), t = t * t % z;
  if (n % 2 != 0)
    t = t % z * ans % z;
  return t;
}
int main() {
  while (ans = 0, cin >> x >> y >> z) {
    for (int i = 0; x[i] != '\0'; i++)
      ans = (ans * 10 + x[i] - '0') % z;
    cout << number(y) << endl;
  }
  return 0;
}

/*
2 3 5
12345  2345  345 


(a⋅b)modm=(ism2+jsm+itm+jt)modm
                    =jtmodm
                    =((amodm)(bmodm))modm
大整数取模:！？？！？！？
int div_mod(char s[], int m) {
    int ans = 0;
    for (int i = 0; s[i] != '\0'; i++)
        ans = (ans * 10 + s[i] - '0') % num;

    return ans;
}
*/