#include <iostream>
using namespace std;
int main(){
  int s=0,a[3][4] = {{1, 2, -3, -4}, {0, -12, 13, 14}, {-21, 23, 0, -24}};
  for (int i=0;i<3;i++)
    for (int j = 0; j < 4; j++) 
      cout << a[i][j] << (j != 3 ? " " : "\n");
  cout << endl;
  for (int i=0;i<3;i++){
    for (int j = 0; j < 4; j++) {
      cout << a[i][j] << (j != 3 ? " " : "\n");
      if (a[i][j] < 0)
        continue;
      if (a[i][j] == 0) {
        cout << endl << i + 1 << " " << j + 1 << endl;
        break;
      }
      s += a[i][j];
     // cout << s << endl;
    }
  }
    cout <<endl<< s << endl;
    return 0;
  }