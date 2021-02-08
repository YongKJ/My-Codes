#include <iostream>
#include <map>
using namespace std;
struct node {
  int x, y;
  bool operator<(const node &f1) const {
    return (f1.x == x ? f1.y > y : f1.x > x);
  }
} d, f;
int main(){
  int n, m, v, t;
  while(cin >> n >> m >> t){
    map<node, int> a, b, c;
    map<node, int>::iterator p;
  while (t--)
    cin >> d.x >> d.y >> a[d];
    cin >> m >> v >> t;
    while (t--)
      cin >> d.x >> d.y >> b[d];
    cout << endl;
    cout << a.size() << " " << b.size() << endl << endl;
    for (p=a.begin();p!=a.end();p++)
      cout << p->first.x << " " << p->first.y << " " << p->second << endl;
    cout << endl;
      for (p=b.begin();p!=b.end();p++)
        cout << p->first.x << " " << p->first.y << " " << p->second << endl;
      cout << endl;
    for (int i=1;i<=n;i++)
      for (int j = 1,sum=0;j<=v;j++){
        for (int k = 1; k <= m; k++) {
          d.x = i, d.y = k, f.x = k, f.y = j;
          if (a.find(d) != a.end() && b.find(f) != b.end())
            sum += a[d] * b[f];
        }
        if (sum != 0)
          d.x = i, d.y = j, c[d] = sum, sum = 0;
      }
      for (p=c.begin();p!=c.end();p++)
        cout << p->first.x << " " << p->first.y << " " << p->second << endl;
  }
  return 0;
}
    
    
	
/*
描述


压缩存储稀疏矩阵方法之一就是采用三元组顺序表——
（顺序存储结构）
三元组顺序表又称有序的双下标法，对矩阵中的每个
非零元素用三个域分别表示其所在的行号、列号和元
素值。它的特点是，非零元在表中按行序有序存储，
因此便于进行依行顺序处理的矩阵运算。当矩阵中的
非0元素少于1/3时即可节省存储空间。
如下的矩阵：

3 0 0 5

0 -1 0 0
2 0 0 0
采用三元组表示为：
i j v
1 1 3
1 4 5
2 2 -1
3 1 2
输入


输入第一行为两个整数（<=50），表示第一个稀疏矩阵
的行和列.然后是矩阵非0的个数n,接着就是矩阵的三元组
表示。后面的数据与此相同。

输出


输出两个稀疏矩阵三元组相乘的结果。

注意：每行最后一个数据的后面无空格。

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