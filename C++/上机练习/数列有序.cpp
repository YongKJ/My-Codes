#include <iostream>
using namespace std;
int main()
{
  int n, m,num[100],t;
  while(cin>>n>>m&&(n||m))
  {
    for (int i = 0; i < n;i++)
      cin >> num[i];
    num[n] = m;
    for (int i=0;i<n+1;i++)
      for (int j=i+1;j<n+1;j++)
        if (num[i] > num[j]) {
          t = num[i];
          num[i] = num[j];
          num[j] = t;
        }
    for (int i = 0; i < n; i++)
      cout << num[i] << " ";
    cout << num[n] << endl;
  }
  return 0;
}
    