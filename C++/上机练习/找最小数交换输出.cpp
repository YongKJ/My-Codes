#include <iostream>
using namespace std;
int main()
{
  int n,t,min,a[100];
  while (cin >> n, n) 
  {
    min = 0;
    for (int i = 0; i < n; i++)
      cin >> a[i];
    for (int i = 0; i < n; i++)
      if (a[min] > a[i])
        min = i;
    t = a[0];
    a[0] = a[min];
    a[min] = t;
    for (int i = 0; i < n - 1; i++)
      cout << a[i] << " ";
    cout << a[n - 1] << endl;
  }
  return 0;
}
    
   