#include <iostream>
using namespace std;
int main()
{
  int t,x,y,z;
  double a;
  while(cin>>t&&t)
  {
    x = y = z = 0;
    while (t--)
    {
      cin >> a;
      if (a < 0)
        x++;
      else if (a == 0)
        y++;
      else
        z++;
    }
    cout << x << " " << y << " " << z << endl;
  }
  return 0;
}