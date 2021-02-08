#include <iostream>
using namespace std;
int main(){
  int n;
  while (cin >> n) {
    int s[n + 1], Max = -1, f[n + 1];
    for (int i = 1; i <= n; i++)
      cin >> s[i], f[i] = 1;
    for (int i = 1; i <= n; i++)
      for (int j = 1; j < i; j++)
        if (s[i] > s[j])
          f[i] = max(f[i], f[j] + 1);
    for (int i = 1; i <= n; i++)
      Max = max(Max, f[i]);
    cout << Max << endl;
  }
  return 0;
}