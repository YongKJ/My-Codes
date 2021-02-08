#include <iostream>
#include <ctype.h>
#include <string>
using namespace std;
int main(){
  int n;
  cin >> n;
  getchar();
  while(n--){
    string str;
    char yo=0;
    getline(cin, str);
    if(isalpha(str[0])||str[0]=='_')
    {
      yo = 1;
      for (int i = 1; str[i] != 0;i++)
        if (!isalnum(str[i]) && str[i] != '_') 
        {
          yo = 0;
          break;
        }
    }
      if (yo)
        cout << "yes" << endl;
      else
        cout << "no" << endl;
  }
    return 0;
  }