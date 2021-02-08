#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
  int sum,t;
  cin >> t;
  while (t--) {
    char str[1000];
    sum = 0;
    cin >> str;
    for (int i = 0; i < strlen(str); i++)
      if (str[i] >= '0' && str[i] < '9')
        sum++;
    cout << sum << endl;
  }
  return 0;
}
    
  
  