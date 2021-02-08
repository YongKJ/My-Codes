#include <iostream>
#include <string>
using namespace std;
int main(){
  int n;
  while (cin >> n, n) {
    string str[n], t;
    for (int i = 0; i < n; i++) {
      cin >> str[i];
    }
    for (int i = 0; i < n; i++){
      for (int j = i + 1; j < n; j++) {
        if ((str[i] + str[j]) < (str[j] + str[i]))
          t = str[i], str[i] = str[j], str[j] = t;
      }
    }
    for (int i = 0; i < n; i++) {
      cout << str[i];
    }
    cout << endl;
  }
  return 0;
}
     
/*
描述


设有n个正整数，将他们连接成一排，
组成一个最大的多位整数。例如:n=3时，
3个整数13、312、343连成的最大整数为：
34331213。

输入


包含多组测试数据。

每组测试数据的第1行为N（0表示结束），
第2行为N个数。

 

输出


连接成的最大整数。 

样例输入

3
13  312  343
0

样例输出

34331213
*/