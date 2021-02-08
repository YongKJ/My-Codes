#include <iostream>
#include <cmath>
using namespace std;
int main(){
  int n;
  while (cin >> n) {
    int num = 0;
    for (int a = 0; a <= sqrt(n); a++)
      for (int b = 0; a * a <= n && b <= sqrt(n); b++)
        for (int c = 0; a * a + b * b <= n && c <= sqrt(n); c++)
          for (int d = 0; a * a + b * b + c * c <= n && d <= sqrt(n); d++)
            if (a * a + b * b + c * c + d * d == n)
              num++;
    cout << num << endl;
  }
  return 0;
}