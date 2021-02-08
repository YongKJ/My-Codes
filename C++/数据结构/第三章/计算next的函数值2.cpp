#include <iostream>
#include <string>
using namespace std;
int main(){
  string s;
  while (cin >> s) {
    int next[s.size() + 1];
    next[1] = 0;
    cout << "01122312" << endl << endl;
    //cout << "01234" << endl << endl;
    cout << "i=1,j=0,next[1]=0" << endl << endl;
    for (int i = s.size(); i > 0; i--)
      s[i] = s[i - 1];
    for (int i = 1, j = 0; i < s.size();) {
      if(j==0)
       cout<<"(j=0)";
     else 
       cout << "(s[" << i << "]与s[" << j << "]比较 即"<< s[i] << (s[i]==s[j]?"=":"!=" )<< s[j] << ")";
      if (j == 0 || s[i] == s[j])
        i++, j++, next[i] = j,
                  cout << "Yes\ni++, j++, next[i]=j\ni=" << i << " ,j=" << j
                       << " ,next[" << i << "]=" << j << endl
                       << endl;
      else
        cout << "No\ni="<<i<<" ,j=" << (j == 0 ? 0 : next[j]) << endl << endl,j = next[j];
    }
    for (int i = 1; i <= s.size(); i++)
      cout << next[i] << (i != s.size() ? " " : "\n");
  }
  return 0;
  }
 /*
输入
abaabcac
aaaab
abcaabbabcab

输出
0 1 1 2 2 3 1 2
0 1 2 3 4

012345678
   abaabcac
   01122312
*/