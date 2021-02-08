#include <iostream>
using namespace std;
class street {
public:
  street(int a);
  void show();

private:
  int n;
};
int main() {
  int n;
  while (cin >> n, n)
    street d1(n);
  return 0;
}
street::street(int a) {
  n = a;
  show();
}
void street::show() {
  long s[17][17] = {0};
  s[n][0] = 1;
  for (int i = n; i >= 0; i--)
    for (int j = 1; j <= n+1; j++)
      s[i][j] = s[i][j - 1] + s[i + 1][j];
  cout << s[0][n+1] << endl;
}
/*
描述


一个4x4城市的街道布局如下所示。
从最左下方走到最右上方，每次只能往上或往右走。
一共有多少种走法?              

 	 	 	 
 	 	 	 
 	 	 	 
 	 	 	 
输入


输入很多行行数,每行1个数字代表n的值,当n=0时结束(2<=n<=15)
输出


输出对应每行n值的走法.
样例输入

1
2
5
0

样例输出

2
6
252
*/