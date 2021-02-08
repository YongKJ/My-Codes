#include <iostream>
using namespace std;
int main()
{
  int m, n,x,y,z,j,a[10];
  while(cin>>m>>n)
  {
    j = 0;
    for (int i = m; i <= n; i++) 
    {
      x = i % 10;
      y = i / 10 % 10;
      z = i / 100;
      if (i == x * x * x + y * y * y + z * z * z) 
        a[j++] = i;
    }
    if(j==0)
      cout << "no" << endl;
    else
     {
      for (int i = 0; i < j; i++) 
      {
        if (i == j - 1)
          cout << a[i] << endl;
        else
          cout << a[i] << " ";
      }
    }
  }
  return 0;
}