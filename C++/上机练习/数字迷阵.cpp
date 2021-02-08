#include <iostream>
#include <map>
using namespace std;
const int num = 10;
class number {
public:
  number(int x, int y, int z);
  int search(int n);
  void plus(int a[],int n);
  void show();

private:
  int n, m, d, max;
  map<int, int> p;
};
int main() {
  int x, y, z;
  while (cin >> x >> y >> z)
    number d1(x, y, z);
  return 0;
}
number::number(int x, int y, int z) {
  n = x, m = y, d = z;
  max = x > y ? x : y;
  for (int i = 1; i <= num*num; i++)
    p[i] = 1;
  show();
}
void number::plus(int a[],int k){
  int s = 0;
  map<int, int>::iterator q;
  if (k == 0)
    a[0] = 1, a[1] = 2, p[1] --, p[2] --;
        else {
          for (q = p.begin(); q != p.end(); q++) {
            //cout << q->first << " ";
            if(q->second)
              s++;
            if (s == 1&&q->second) {
              //cout << q->first << " ";
              a[0] = q->first, q->second = 0;
            }
           else if (s == 3&&q->second) {
              //cout << q->first << endl;
              a[1] = q->first, q->second = 0;
              break;
            }
          }
        }
       // cout << endl;
        cout << a[0] << " " << a[1] << " ";
        for (int i = 2; i < num; i++) {
          a[i] = a[i - 1] + a[i - 2];
          cout << a[i] << " ";
          if (p.find(a[i]) != p.end())
            p[a[i]] --;
        }
        cout << endl<<endl;
}
void number::show() {
  int s[10][10] = {0};
  for (int i = 0; i < num; i++)
    plus(s[i], i);
  cout << s[n - 1][m - 1] % d << endl;
//  cout <<s[n-1][m-1]<<" " <<s[n - 1][m - 1] % d << endl;
}
/*
描述


小可可参观科学博物馆时，看到一件藏品，上面有密密麻麻的数字，如下所示：

1     2      3     5     8     13      21     34  ……

4     7     11   18   29     47     76     123……

6    10    16   26   42     68     110    178……

9    15    24   39   63    102    165    267……

12   20   32   52   84    136    220    356……

14   23   37   60   97    157    254    411……

…………………………………………………………………

小可可发现了这些数的规律，比如第1行是Fibonacci数列。老师问小可可，能够算出第i行的第j个数对m取模的结果? 

输入


包括多组数据。每组有3个数，分别表示i、j、m的值。

输出

第i行的第j个数对m取模的结果。

样例输入

1 2 99
2 8 100

样例输出

2
23
*/