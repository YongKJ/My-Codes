#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
  char s[110][110], str[210];
  int i, j, len, k, n;
  while(cin>>n&&n)
  {
    cin >> str;
    len = strlen(str);
    k = 0;
    for (i=0;i<len;i++)
    {
      if (0 == i / n % 2) 
      {
        s[i / n][k] = str[i];
        k++;
      } 
      else 
      {
        k--;
        s[i / n][k] = str[i];
      }
    }
      for (i = 0; i < n; i++)
        for (j = 0; j < len / n; j++)
          cout << s[j][i];
      cout << endl;
    }
    return 0;
  }