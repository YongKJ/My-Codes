#include <iostream>
using namespace std;
int main()
{
  int a, b, s;
  while (cin >> a >> b&&(a||b)) {
    //if(0==a&&0==b)
    //  break;
    s = a + b;
    cout << s << endl;
  }
  return 0;
}