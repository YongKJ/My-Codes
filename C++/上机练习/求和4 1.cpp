#include <iostream>
using namespace std;
int main()
{
  int x,s,y,i;
  cin >> i;
  while(i!=0)
  {
    cin >> x;
    s = 0;
    for (int i = 1; i <= x; i++) {
      cin >> y;
      s += y;
    }
    cout << s;
    if (1 == i)
      cout << endl;
      else
        cout << endl << endl;
    i--;
  }
  return 0;
}