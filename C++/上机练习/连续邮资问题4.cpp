#include <iostream>
using namespace std;
const int max_nm = 10, max_postage = 1024, inf = 2147483647;
int n, m, x[max_nm], ans[max_nm], y[max_postage], maxstamp, r;
void backtrack(int i) {
  int *backup_y, backup_r, next, postage, num, tmp;
  if (i >= n) {
    if (r > maxstamp) 
      maxstamp = r;
    return;
  }
  backup_y = new int[max_postage];
  for (tmp=0;tmp<max_postage;tmp++)
    backup_y[tmp] = y[tmp];
  backup_r = r;
  for (next=x[i-1]+1;next<=r+1;next++){
    x[i] = next;
    for (postage = 0; postage < x[i - 1] * m; postage++) {
      if (y[postage] >= m)
        continue;
      for (num = 1; num <= m - y[postage]; num++)
        if (y[postage] + num < y[postage + num * next] &&
            (postage + num * next < max_postage))
          y[postage + num * next] = y[postage] + num;
    }
    while (y[r + 1] < inf)
      r++;
    backtrack(i + 1), r = backup_r;
    for (tmp = 0; tmp < max_postage; tmp++)
      y[tmp] = backup_y[tmp];
  }
  delete[] backup_y;
}
int main(){
  while (cin >> n >> m, n && m) {
    int i;
    x[0] = 1, r = m, maxstamp = 0;
    for (i = 0; i <= r; i++)
      y[i] = i;
    while (i < max_postage)
      y[i++] = inf;
    backtrack(1);
    cout << maxstamp << endl;
  }
  return 0;
}
      
        