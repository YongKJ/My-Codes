#include <iostream>
using namespace std;
struct node {
  int x, y, z;
};
int main(){
  int an, am, bn, bm, a, b;
  while (cin >> an >> am >> a) {
    node ta[a];
    for (int i = 0; i < a; i++)
      cin >> ta[i].x >> ta[i].y >> ta[i].z;
    cin >> bn >> bm >> b;
    node tb[b];
    for (int i = 0; i < b; i++)
      cin >> tb[i].x >> tb[i].y >> tb[i].z;
    for (int i=1;i<=an;i++)
      for (int j=1,sum=0;j<=bm;j++){
        for (int p = 0; p < a; p++) {
          if (ta[p].x != i)continue;
          for (int q = 0; q < b; q++) {
            if (tb[q].y != j)continue;
            if (ta[p].y == tb[q].x)
            sum += ta[p].z * tb[q].z;
          }
        }
        if (sum != 0)
        cout << i << " " << j << " " << sum << endl, sum = 0;
      }
  }
  return 0;
}
/*
样例输入

3 4
4
1 1 3
1 4 5
2 2 -1
3 1 2
4 2
4
1 2 2
2 1 1
3 1 -2
3 2 4

样例输出

1 2 6
2 1 -1
3 2 4
*/