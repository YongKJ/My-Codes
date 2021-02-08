#include <iostream>
using namespace std;
int main()
{
  int t;
  while(cin>>t)
  {
    int x,s=1;
    while (t--) 
    {
      cin >> x;
      if (x % 2 != 0)
        s *= x;
    }
    cout << s << endl;
  }
  return 0;
}