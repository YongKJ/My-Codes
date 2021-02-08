#include <iostream>
using namespace std;
int main(){
  int n;
  while(cin>>n){
    long s[110] = {0};
    s[0] = s[1] = 1;
    for (int i = 2; i <= n; i++)
      for (int j = 0; j < i; j++)
        s[i] += s[j] * s[i - 1 - j];
    cout << s[n] << endl;
  }
  return 0;
}
/*
0 1 2 3 4   5    6      7     8        9       10        11        12          13          14             15             16  
1 1 2 5 14 42 132 429 1430 4862 16796 58786 208012 742900 2674440 9694845

描述

有n个A和n个B排成一排，
从第1个位置到任何位置，
B的个数不能超过A的个数。
问这样的排列有多少种？

输入


包括多组数据。每组1个n。

输出


排列有的种数。

样例输入

1
2
3

样例输出

1
2
5
*/