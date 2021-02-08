#include <iostream>
#include <set>
using namespace std;
int main() {
  set<long> a;
  long x;
  while (cin >> x, x)
    a.insert(x);
  set<long>::iterator p;
  for (p = a.begin(); p != a.end(); p++)
    if (p == --a.end())
      cout << *p << endl;
    else
      cout << *p << " ";
  return 0;
}