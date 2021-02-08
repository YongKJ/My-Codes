#include <iostream>
using namespace std;
int n, dp[20][20],sum,Max;
struct rectangle {
  int l, w;
};
void dfs(int row,int s){
  sum = s > sum ? s : sum;
  for (int j = 0; j < n; j++)
    if (dp[row][j] > 0)
       dfs(j,s+1);
}
int main() {
  int t;
  cin >> t;
  while(t--&&(Max=0,cin>>n)){
    rectangle rec[n];
    for (int i=0;i<n;i++)
      cin >> rec[i].l >> rec[i].w;
    for (int i=0;i<n;i++)
      for (int j = 0; j < n; j++) {
        int t = ((rec[i].l < rec[j].l && rec[i].w < rec[j].w) ||
                 (rec[i].l < rec[j].w && rec[i].w < rec[j].l));
        dp[i][j] = t ? 1 : 0;
      }
    for (int i = 0; i < n; i++)
      sum = 0, dfs(i,1), Max = max(Max, sum);
    cout << Max << endl;
  }
  return 0;
}
/*
1
10
1 2
2 4
5 8
6 10
7 9
3 1
5 8
12 10
9 7
2 2
*/