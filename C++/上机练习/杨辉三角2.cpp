#include <iostream>
#include <cstdio>
using namespace std;
const int N = 31;
int main(){
  int s[N][N],n;
  
  for (int i=1;i<=N-1;i++){
  	if(i<=2)
          for (int j=1;j<=i;j++)
            s[i][j] = 1;
            else
              for (int j = 1; j <=i; j++) {
                if (j == 1 || j == i)
                  s[i][j] = 1;
                else
                  s[i][j] = s[i - 1][j - 1] + s[i - 1][j];
              }
  }
  while(cin>>n){
    for (int i = 1; i <= n; i++) {
      for (int k=1;k<=n-i;k++)
        cout << "    ";
      cout << s[i][1];
      for (int j = 2; j <= i; j++)
        printf("     %3d", s[i][j]);
      cout << endl;
    }
    cout << endl;
  }
  return 0;
}
  
/*
Sample Input
2 3
 

Sample Output
1
1 1

1
1 1
1 2 1
*/