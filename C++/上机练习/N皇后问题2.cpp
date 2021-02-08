#include <iostream>
#include <cmath>
using namespace std;
int sum,t;
void queen(int x,int n,int s[]){
  if (x > n) {
    sum++;
    if (sum <= 3) {
      for (int i = 1; i <= n; i++)
        cout << s[i] << " ";
      cout << endl;
    }
  }
  else{
    for (int i = 1; i <= n; i++) {
      s[x] = i, t = 1;
      for (int j = 1; j < x; j++)
        if (abs(j - x) == abs(s[j] - s[x]) || s[j] == s[x])
          t = 0;
      if (t)
        queen(x + 1, n, s);
    }
  }
}
int main(){
  int n;
  while (sum = 0, cin >> n) {
    int s[n + 1];
    queen(1, n, s), cout << sum << endl;
  }
  return 0;
}