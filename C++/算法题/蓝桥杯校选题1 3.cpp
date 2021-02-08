#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int main(){
  char a[101];
  int n;
  queue<char> s;
  cin >> a >> n;
  for (int k = 0; k < strlen(a); k++)
    s.push(a[k]);
  for (int i=1;i<=n;i++){
  	int m = s.size(), sum;
      char c;
      for (int j=1;j<=m;j++){
        if (j == 1) {
          if (j == m) {
            s.push('1');
            s.push(s.front());
            s.pop();
          } else {
            sum = 1;
            c = s.front();
            s.pop();
          }
        }
        else if(j!=1&&j!=m){
          if (c == s.front()) {
            sum++;
            s.pop();
          } else {
            s.push(char(sum + '0'));
            s.push(c);
            sum = 1;
            c = s.front();
            s.pop();
          }
        }
        else{
          if (c == s.front()) {
            s.push(char(sum + 1 + '0'));
            s.push(c);
            s.pop();
          } else {
            s.push(char(sum + '0'));
            s.push(c);
            s.push('1');
            s.push(s.front());
            s.pop();
          }
        }
      }
  }
  while (s.size()) {
    cout << s.front();
    s.pop();
  }
  cout << endl;
  return 0;
}
 