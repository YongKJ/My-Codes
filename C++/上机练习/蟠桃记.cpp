#include <iostream>
using namespace std;
int main()
{
  int t,sum;
  while (cin >> t) {
    sum = 1;
    for (int i = 1; i < t; i++)
      sum = (sum + 1) * 2;
    cout << sum << endl;
  }
  return 0;
}
    