#include <iostream>
using namespace std;
int main(){
  int n, m;
  while(cin>>n>>m){
    int s[3000],a[n*(n-1)/2],t;
    for (int i=0;i<n;i++)
      cin >> s[i];
    for (int i = 0, k = 0; i < n; i++) {
      t = s[i];
      for (int j = i + 1; j < n; j++)
        a[k++] = t + s[j];
    }
    for (int i = 0; i < n * (n - 1) / 2; i++)
      for (int j = i + 1; j < n * (n - 1) / 2; j++)
        if (a[i] < a[j]) {
          t = a[i];
          a[i] = a[j];
          a[j] = t;
        }
    cout << a[0];
    for (int i = 1; i < m; i++)
      cout << " " << a[i];
    cout << endl;
  }
  return 0;
}
   
/*
样例输入

4 4
1 2 3 4
4 5
5 3 6 4

样例输出

7 6 5 5
11 10 9 9 8
*/