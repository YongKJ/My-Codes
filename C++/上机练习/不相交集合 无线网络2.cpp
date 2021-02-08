#include <iostream>
#include <map>
#include <cmath>
using namespace std;
map<int, int> f, x, y, flag;
double mul(double x) { return x * x; }
int find(int x) {
  if (f[x] != x)
    f[x] = find(f[x]);
  return f[x];
}
void merge(int x, int y) {
  int f1 = find(x), f2 = find(y);
  if (f1 != f2)
    f[f2] = f1;
}
int main(){
  int n;
  double d;
  char s;
  while(cin>>n>>d){
    int map[10][10] = {0}, a, b;
    for (int i=1;i<=n;i++)
      cin >> x[i] >> y[i], f[i] = i,flag[i]=0;
    for (int i=1;i<=n;i++)
      for (int j=i+1;j<=n;j++)
      if(sqrt(mul(x[i]-x[j])+mul(y[i]-y[j]))<=d)
        map[i][j] = map[j][i] = 1;
     while(cin>>s){
       if (s == 'O') {
         cin>>a,flag[a] = 1;
         for (int i = 1; i <= n; i++)
           if (map[i][a] && flag[i])
             merge(a, i);
       } 
       else cin >> a >> b,cout << (find(a) == find(b) ? "SUCCESS" : "FAIL") << endl;
     }
  }
  return 0;
}
/*
样例输入

4 1
0 1
0 2
0 3
0 4
O 1
O 2
O 4
S 1 4
O 3
S 1 4

样例输出

FAIL
SUCCESS
*/
        	
        	
      
  	