#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){  
  int n;
  cin >> n;
  char str[100];
  vector<char> x[100];
  vector<char>::iterator p;
  for (int i = 0; i < n && cin >> str;) {
    for (int j = 0; j < strlen(str);j++)
    x[i].push_back(str[j]);
    if (x[i].size() == n)
      i++;
  }
  for (int i = n - 1; i >= 0; i--) {
    sort(x[i].begin(), x[i].end());
    for (p = x[i].begin(); p != x[i].end(); p++)
      cout << *p;
    cout << endl;
  }
  return 0;
}
/*
样例输入

3
abc
edf
igh

样例输出

ghi
def
abc
*/