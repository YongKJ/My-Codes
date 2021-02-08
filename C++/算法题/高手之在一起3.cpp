#include <iostream>
#include <set>
#include <string>
using namespace std;
int main(){
  int n, m;
  string str;
  while(cin>>n>>m&&getline(cin, str)){
    int sum = 0;
    set<string> s;
    for (int i = 0; i < n; i++) 
      getline(cin, str), s.insert(str);
    for (int i = 0; i < m; i++) {
      getline(cin, str);
      if (str[str.size() - 1] != 13)
        str += char(13);
      if (s.find(str) != s.end())
        sum++;
    }
    cout << sum << endl;
  }
  return 0;
}