#include <iostream>
#include <cstring>
using namespace std;
int main()
{
  char str[300], str1[300][300];
  int i, j, k,n,len;
  cin >> n >> str;
  len = strlen(str);
  for (i = 0,k=0; i < len / n;i++)
    for (j = 0; j < n; j++) {
      if (0 == i % 2)
        str1[i][j] = str[k++];
      else
        str1[i][n - 1 - j] = str[k++];
    }
  for (i = 0; i < n; i++)
    for (j = 0; j < len; j++)
      cout << str1[j][n];
  return 0;
}