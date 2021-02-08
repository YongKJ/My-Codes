#include <iostream>
#include <cstdio>
using namespace std;
int leapyear(int year) 
{
  if ((0 == year % 4 && 0 != year % 100) || 0 == year%400)
    return 1;
  return 0;
}
const int N = 18;
const int YEARDAYS = 365;
int main()
{
  int byear, bmonth, bday, t,sum;
  cin >> t;
  while(t--)
  {
    scanf("%d-%d-%d", &byear, &bmonth, &bday);
    if(2==bmonth&&29==bday&&1!=leapyear(byear+N))
      cout << "-1" << endl;
    else {
      sum = 0;
      sum = YEARDAYS * N;
      for (int i = 1; i < N; i++)
        sum += leapyear(byear + i);
      if (2 < bmonth)
        sum += leapyear(byear + N);
      else if (2 > bmonth || 29 != bday)
        sum += leapyear(byear);
      cout << sum << endl;
    }
  }
    return 0;
  }
        