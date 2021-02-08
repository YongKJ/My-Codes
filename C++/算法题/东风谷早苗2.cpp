#include <iostream>
#include <string>
using namespace std;
int main(){
  int n,x=0,y=0,l;
  string s;
  cin >> s >> n;
  l = s.size();
  for (int i = 0; i < n; i++) {
    if (s[i % l] == 'E')
      x++;
    else if (s[i % l] == 'S')
      y--;
    else if (s[i % l] == 'W')
      x--;
    else
      y++;
  }
  cout << x << " " << y << endl;
  return 0;
}