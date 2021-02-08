#include <iostream>
using namespace std;
int sum;
void dfs(int n) {
  if (n == 1)
    sum++;
  for (int i = 2; i <= n; i++)
    if (n % i == 0)
      dfs(n / i);
}
int main(){
  int n;
  while (sum = 0, cin >> n) {
    dfs(n);
    cout << sum << endl;
  }
  return 0;
}
	
/*
描述


     大于1的正整数 n 都可以分解为
      n = x1 * x2 * ... * xm。例如：当
      n=12时，共有8种不同的分解式：
12 = 12
12 = 6*2
12 = 4*3
12 = 3*4
12 = 3*2*2
12 = 2*6
12 = 2*3*2
12 = 2*2*3
    对于给定正整数n，计算n共有多少种不同的分解式。

输入

   一行一个正整数n （1<=n<=1000000）

输出

   n不同的分解式数目。

样例输入

12
20
10

样例输出

8
8
3
*/