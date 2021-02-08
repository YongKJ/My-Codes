#include <iostream>
using namespace std;
int main()
{
  int x, y,t,s1,s2;
  while(cin>>x>>y)
  {
    s1 = s2 = 0;
    if(x>y)
      t = x, x = y, y = t;
    for (int i = x; i <= y; i++) 
    {
      if (i % 2 != 0)
        s1 += i * i * i;
      else
        s2 += i * i;
    }
    cout << s2 << " " << s1 << endl;
  }
  return 0;
}
           