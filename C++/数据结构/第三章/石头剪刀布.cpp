#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
int main() {
  for (int i=0;i<5;i++){
    srand((unsigned int)time(0));
    string text[] = {"石头", "剪刀", "布"}, user, computer = text[rand() % 3];
    cout << "请出拳(石头,剪刀,布):", cin >> user;
    cout << "用户:" << user << endl << "电脑:" << computer << endl;
    if ((user == "石头" && computer == "剪刀") ||
        (user == "剪刀" && computer == "布") ||
        (user == "布" && computer == "石头"))
      cout << "你赢了";
    else if (user == computer)
      cout << "平局";
    else
      cout << "你输了";
    cout << endl << endl;
  }
  return 0;
}
  
  