#include <iostream>
using namespace std;
int main(){
  int s[] = {50, 20, 10, 5, 1}, n;
  while(cin>>n){
    cout << "change:" << n << endl;
    for (int i = 0, k = 1; i < 5; i++, k = 1) {
      while (k * s[i] <= n)
        k++;
      if (k - 1 != 0)
        cout << s[i] << " yuan:" << k - 1 << endl;
      n -= (k - 1) * s[i];
    }
  }
  return 0;
}
          
/*
描述

买火车票时经常会碰到找钱问题。
售票员手中有50、20、10、5、1元的钱币，
你知道怎么找钱才能使找回的零钱张数最少吗？

输入

多组测试数据，输入需要找钱的钱数

输出

对每组测试数据按下面格式输出： 
第一行输出"change:",然后是你要找的钱 
以下几行按面值从大到小输出要找的张数，
格式如下：50 yuan: 1,如果1张也没有就不需要输出

样例输入

76

样例输出

change:76
50 yuan:1
20 yuan:1
5 yuan:1
1 yuan:1

提示

注意：有多组测试数据
*/