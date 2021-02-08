#include <iostream>
#include <map>
using namespace std;
class You {
public:
  You(int a, int b);
  void show();

private:
  int n, m;
};
int main() {
  int x, y;
  while (cin >> x >> y)
    You d1(x, y);
  return 0;
}
You::You(int a, int b) {
  n = a, m = b;
  show();
}
void You::show() {
  int s[n];
  for (int i = 0; i < n; i++)
    cin >> s[i];
  for (int i=1;;i++){
    int sum=0, t = i,k=0;
    do{
      map<int, int> x, y;
      k++;
      for (int j = 0; j <n; j++)
        x[t / s[j]] = t % s[j], y[t % s[j]] = t / s[j];
      if (k == 1) {
        sum += x.begin()->first;
        t = x.begin()->second;
      } else {
        sum += y.begin()->second;
        t = y.begin()->first;
      }
    } while (t);
    if (sum > m) {
      cout << sum << " " << i << endl;
      cout << i - 1 << endl;
      break;
    }
    //cout << 1 << endl;
  }
}
      	
    	
	
	
/*
描述


给你一套不同面值的邮票，例如｛1，3，5｝。
并规定在一个信封上面粘贴的最多邮票张数，
例如5张。你的目标是计算出最大的可以连续
贴出的面值的集合的元素个数。例如｛1，3，5｝
最多贴5张邮票而言，可以连续贴出面值从1到21。
而不能贴出面值22。

输入


第1行是邮票面值的种数m和一个信封上面粘贴的
最多邮票张数n。

第2行是m个数，表示邮票的面值。

输出


连续贴出面值的集合中的最大值。

样例输入

3  5
1 3  5

样例输出

21
*/