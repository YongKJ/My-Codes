#include <iostream>
using namespace std;
char f(int &i){
  char a=' ';
  switch (i) {
  case 10:
    a = 'A';
    break;
  case 11:
    a = 'B';
    break;
  case 12:
    a = 'C';
    break;
  case 13:
    a = 'D';
    break;
  case 14:
    a = 'E';
    break;
  case 15:
    a = 'F';
    break;
  default:
    break;
  }
  return a;
}
int main(){
  int x, y, s[100], i;
  while(i=0,cin>>x>>y){
    if (x < 0) {
      cout << "-";
      x = -x;
    }
    do {
      s[i++] = x % y;
      x /= y;
    } while (x != 0);
    for (int j = i - 1; j >= 0; j--) {
      if (s[j] >= 10)
        cout << f(s[j]);
      else
        cout << s[j];
    }
    cout << endl;
  }
  return 0;
}

/*
Sample Input
7 2
23 12
-4 3
 

Sample Output
111
1B
-11
*/