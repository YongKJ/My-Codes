#include <iostream>
using namespace std;
int main()
{
  char str[5],t;
  while(cin>>str)
  {
    for (int i = 0; i < 3; i++)
      for (int j = i + 1;j<3;j++)
        if (str[i] > str[j]) 
        {
          t = str[i];
          str[i] = str[j];
          str[j] = t;
        }
    for (int i = 0; i < 3; i++)
      if (2 == i)
        cout << str[i] << endl;
      else
        cout << str[i] << " ";
  }
  return 0;
}
        