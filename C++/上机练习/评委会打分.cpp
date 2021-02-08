#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
  int n,t,a[100],i,j;
  float sum;
  while (cin >> n) {
    sum = 0;
    for ( i = 0; i < n; i++)
      cin >> a[i];
    for (i = 0; i < n; i++)
      for (j = i + 1; j < n; j++)
        if (a[i] > a[j]) {
          t = a[i];
          a[i] = a[j];
          a[j] = t;
        }
    for (i = 1; i < n - 1; i++)
      sum += a[i];
    cout << setiosflags(ios::fixed) << setprecision(2) << sum / (n - 2)<< endl;
  }
  return 0;
}