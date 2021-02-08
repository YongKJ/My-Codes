#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
  double n,s;
  int m;
  while(cin>>n>>m)
  {
    s = 0;
    for (int i = 1; i <= m; i++) {
      s += n;
      n = sqrt(n);
    }
    cout <<setiosflags(ios::fixed)<<setprecision(2)<< s << endl;
  }
  return 0;
}
  