#include <iostream>
using namespace std;
int main(){
  int n;
  cin >> n;
  while(n--){
    int m,s[101],flag=1;
    cin >> m;
    for (int i=1;i<=m;i++)
      cin >> s[i];
    for (int i = 1; i <= m / 2;i++)
      if (s[s[i]] != i) {
        flag = 0;
        break;
      }
    if (flag)
      cout << "yes" << endl;
    else
      cout << "no" << endl;
  }
  return 0;
}
    
/*
样例输入

3
4 1 4 3 2
5 2 3 4 5 1
1 1

样例输出

yes
no
yes
*/