#include <iostream>
using namespace std;
int main()
{
  int x,s,y;
  while(cin >> x)
  {    
    s = 0;
    for (int i = 1; i <= x; i++) {
      cin >> y;
      s += y;
    }
    cout << s << endl;
  }
  return 0;
}
 
