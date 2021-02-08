#include <iostream>
using namespace std;
void salary(int &m, int &sum,int y);
int main()
{
  int n,m,sum;
  while(cin>>n,n)
  {
    sum = 0;
    for (int i = 1; i <= n; i++) {
      cin >> m;
      if (m >=100)
        salary(m, sum,100);
      if (m >=50)
        salary(m, sum,50);
      if (m >= 10)
        salary(m, sum,10);
      if (m >= 5)
        salary(m, sum,5);
      if (m >= 2)
        salary(m, sum,2);
      if (m == 1)
        sum++;
    }
    cout << sum << endl;
  }
  return 0;
}
void salary(int &m, int &sum, int y) {
  sum += m / y;
  m %= y;
}

	