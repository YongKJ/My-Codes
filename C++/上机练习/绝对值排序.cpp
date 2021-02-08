#include <iostream>
using namespace std;
int main()
{
  int n,s1[100],s2[100],t;
  while(cin>>n,n)
  {
    for (int i = 0; i < n; i++) 
    {
      cin >> s1[i];
      s2[i] = s1[i] < 0 ? -1 : 0;
      s1[i] = s1[i] < 0 ? -s1[i] : s1[i];
    }
    for (int i=0;i<n;i++)
      for (int j=i+1;j<n;j++)
        if (s1[i] < s1[j]) 
        {
          t = s1[i];
          s1[i] = s1[j];
          s1[j] = t;
          t = s2[i];
          s2[i] = s2[j];
          s2[j] = t;
        }
    for (int i = 0; i < n - 1; i++) 
    {
      if (s2[i] < 0)
        cout << -s1[i] << " ";
      else
        cout << s1[i] << " ";
    }
    if (s2[n - 1] < 0)
      cout << -s1[n-1] << endl;
    else
      cout << s1[n-1] << endl;
  }
  return 0;
}
    
          