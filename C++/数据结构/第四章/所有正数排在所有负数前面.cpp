#include <iostream>
using namespace std;
int main(){
  int s[20], n;
  while (cin >> n) {
    for (int i=0;i<n;i++)
      cin >> s[i];
    for (int i = 0, j = n - 1, t; i < j;) {
      while (i < j && s[i] > 0)i++;
      while (i < j && s[j] < 0)j--;
      if (i < j)t = s[i], s[i] = s[j], s[j] = t;
    }
    for (int i=0;i<n;i++)
      cout << s[i] << (i != n - 1 ? " " : "\n");
  }
  return 0;
}
/*
输入:
5
-1 2 -3 4 -5

输出:
2 4 -3 -1 -5
*/
    	