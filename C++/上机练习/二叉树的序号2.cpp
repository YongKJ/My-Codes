#include <iostream>
using namespace std;
int n,f[10], flag;
void get(int x, int y) {
  if (!x)return;
  for (int i=0;i<x;i++){
    if(y<=f[i]*f[x-i-1]){
      if (flag) {
        cout << "(";
        get(i, (y - 1) / f[x - i - 1] + 1);
        cout << "X";
        get(x - i - 1, (y - 1) % f[x - i - 1] + 1);
        cout << ")";
      } else {
        flag = 1;
        get(i, (y - 1) / f[x - i - 1] + 1);
        cout << "X";
        get(x - i - 1, (y - 1) % f[x - i - 1] + 1);
      }
      break;
    } else y -= f[i] * f[x - i - 1];
  }
}
int main(){
  f[0] = f[1] = 1;
  for (int i=2;i<10;i++)
    f[i] = f[i - 1] * (4 * i - 2) / (i + 1);
  while(flag=0,cin>>n,n){
    for (int i=1;i<10;i++){
      if (n <= f[i]) {
        get(i, n);break;
      } else n -= f[i];
    }
    cout << endl;
  }
  return 0;
}
/*
样例输入

5
6
0

样例输出

X((X)X)
(X)X(X)
*/
      