#include <iostream>
using namespace std;
class You {
public:
  You(int a, int b);
  void show();

private:
  int n, m;
};
int main() {
  int x, y;
  while (cin >> x >> y)
    You d1(x, y);
  return 0;
}
You::You(int a, int b) {
  n = a, m = b;
  show();
}
void You::show() {
  int s[n];
  for (int i = 0; i < n; i++)
    cin >> s[i];
  for (int i=1;;i++){
    int sum=0,t = i;
    for (int j = n-1, k = 1; j >= 0; j--,k=1) {
        while(k*s[j]<=t)
          k++;
        sum += k - 1;
        t -= (k - 1) * s[j];
    }
    if (sum > m) {
      cout << i - 1 << endl;
      break;
    }
  }
}
