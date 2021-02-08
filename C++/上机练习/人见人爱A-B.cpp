#include <iostream>
using namespace std;
int main(){
  int n, m,k,t;
  while(k=0,cin>>n>>m,n||m){
    int x[100], y[100], z[100];
    for (int i=0;i<n;i++)
      cin >> x[i];
    for (int i=0;i<m;i++)
      cin >> y[i];
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) {
        if (x[i] == y[j])
          break;
        if (x[i] != y[j] && j == m - 1)
          z[k++] = x[i];
      }
    if (k == 0)
      cout << "NULL" << endl;
    else {
      for (int i = 0; i < k; i++)
        for (int j = i + 1; j < k; j++)
          if (z[i] > z[j])
            t = z[i], z[i] = z[j], z[j] = t;
        for (int i = 0; i < k; i++)
          cout << z[i] << " ";
      cout << endl;
    }
      
  }
  return 0;
}
/*
Sample Input
3 3 1 2 3 1 4 7
3 7 2 5 8 2 3 4 5 6 7 8 
0 0
 

Sample Output
2 3 
NULL
*/