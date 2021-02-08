#include <iostream>
#include <iomanip>
using namespace std;
int GetGPA(double x) {
  if (x >= 90)
    return 4;
  else if (x >= 80)
    return 3;
  else if (x >= 70)
    return 2;
   else if(x>=60)
     return 1;
  else
    return 0;
}
int main()
{
  int t;  
  while(cin >> t)
  {
    double x, y, sum = 0, k = 0;
    while (t--) {  
      cin >> x >> y;
      if (y ==-1)
        continue;
      else 
      {
        k += x;
        sum += x * GetGPA(y);
      }
    }
    if (sum==0)
      cout << "-1" << endl;
    else
      cout <<setiosflags(ios::fixed) << setprecision(2) << sum / k << endl;
  }
  return 0;
}