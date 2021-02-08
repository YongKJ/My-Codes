#include <iostream>
using namespace std;
int main(){
  int t, n;
  cin >> t;
  while (t-- && cin >> n) {
    int s[n], flag = 1;
    for (int i = 0; i < n; i++)
      cin >> s[i];
    for (int i = 0; i < n; i++){
      if(!flag)break;
      for (int j = i + 1, k = 100; j < n; j++) {
        if (s[i] > s[j])
          flag = k > s[j], k = s[j];
        if (!flag)break;
      }
    }
    cout << (flag ? "YES" : "NO") << endl;
  }
  return 0;
}
      
      
/*
样例输入

2
3
3 1 2
3
1 2 3

样例输出

NO
YES
*/