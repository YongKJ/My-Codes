#include <iostream>
#include <string>
using namespace std;
int main(){
  string s;
  while(cin>>s){
    int num[36] = {0};
    for (int i = 0; s[i]; i++) {
      if ('0' <= s[i] && s[i] <= '9')
        num[s[i] - '0']++;
      else if ('A' <= s[i] && s[i] <= 'Z')
        num[s[i] - 'A' + 10]++;
    }
    for (int i = 0; i < 10; i++)
      cout << "数字" << i << "的个数为" << num[i] << endl;
    for (int i = 10; i < 36; i++)
      cout << "字符" << char(i - 10 + 'A') << "的个数为" << num[i] << endl;
  }
  return 0;
}
    	