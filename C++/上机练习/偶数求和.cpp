#include <iostream>
using namespace std;
int main()
{
  int n, m,sum;
  while(cin>>n>>m)
  {
    sum = 0;
    for (int i=1,j=2;i<=n;i++,j+=2)
    {
      sum += j;
      if (i % m == 0&&i!=n) 
      {
        cout << sum / m << " ";
        sum = 0;
      } 
      else if (i % m == 0 && i==n)
        cout << sum / m << endl;
      else if (i % m != 0 && i == n)
        cout << sum<<endl;
    }
  }
  return 0;
}
       
      
      