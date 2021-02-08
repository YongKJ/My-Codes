#include <iostream>
#include <string>
using namespace std;
int main(){
  string str0, str1;
  while(cin>>str0>>str1){
    int length = 0, end = 0, arr[15][15] = {0}, n;
    if(str0==str1)
      cout << str0 << endl;
    for (int i = 0; str0[i]; i++)
       for (int j = 0; str1[j]; j++) {
         n = (0 <= i - 1 && 0 <= j - 1) ? arr[i - 1][j - 1] : 0;
         arr[i][j] = str0[i] == str1[j] ? n + 1 : 0;
         if (arr[i][j] > length)
           length = arr[i][j], end = i;
       }
     for (int i = end - length + 1; i <= end; i++)
       cout << str0[i];
     cout << endl;
  }
  return 0;
}
/*
样例输入

123abcdabcdef
aabcdf

样例输出

abcd
*/
            