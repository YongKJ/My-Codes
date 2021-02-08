#include <iostream>
#include <string>
using namespace std;
string s;
void Next() {
  int next[s.size()];
  next[0] = -1;
  cout << "01122312" << endl << endl;
  cout << "i=1,j=0,next[1]=0" << endl << endl;
  for (int i = 0, j = -1; i < s.size();){
    cout << "j=0或者s[" << i+1 << "]=s[" << j+1 << "]?"<<endl;
    if(j==-1)
     cout<<"(j=0)";
     else 
       cout << "(" << s[i] << (s[i]==s[j]?"=":"!=" )<< s[j] << ")";
    if (j == -1 || s[i] == s[j]) {
      i++, j++, next[i] = j;
      cout <<"Yes\ni++, j++, next[i]=j\ni=" << i+1 << " ,j=" << j+1 << " ,next[" << i+1 << "]=" << j+1
           << endl<<endl;
    } else {
      cout << "No\n    j=next[j]\nj=" << j + 1 << ",j=next[" << j + 1 << "]="<<(j==-1?0:next[j]+1)<<endl<<endl;
      j = next[j];
          }
  }
  for (int i = 0; i <s.size(); i++)
    cout << next[i]+1 << (i != s.size()-1 ? " " : "\n");
}
int main() {
  while (cin >> s)
    Next();
  return 0;
}
/*
输入
abaabcac
aaaab

输出
0 1 1 2 2 3 1 2
0 1 2 3 4
*/