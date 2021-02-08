#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
int main() {
  for (int i = 0, j, k; i < 5; i++) {
    srand((unsigned int)time(0)), k = rand() % 3;
    string text[] = {"石头", "剪刀", "布"}, user;
    cout << "请出拳(石头,剪刀,布):", cin >> user;  
    cout << "用户:" << user << endl << "电脑:" << text[k] << endl;
    for (int t = 0; t < 3; t++)j = user == text[t] ? t : j;
    if ((j == 0 && k == 1) || (j == 1 && k == 2) || (j == 2 && k == 0))
      cout << "你赢了";
    else if (j == k)
      cout << "平局";
    else
      cout << "你输了";
    cout << endl << endl;
  }
  return 0;
}