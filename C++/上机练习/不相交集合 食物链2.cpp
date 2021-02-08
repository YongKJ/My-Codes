#include <iostream>
#include <map>
using namespace std;
map<int, int> f;
int find(int x) {
  if (f[x] != x)
    f[x] = find(f[x]);
  return f[x];
}
void v(int x, int y) {
  int f1 = find(x), f2 = find(y);
  if (f1 != f2)
    f[f2] = f1;
}
int main(){
  int n, m, sum, a, b, d;
  while(sum=0,cin>>n>>m){
    for (int i=1;i<=n*3;i++)
      f[i] = i;
      while(m--&&cin>>d>>a>>b){
        if (a > n || b > n) {
          sum++;
          continue;
        } else  if (d == 1) {
          if (find(a) == find(b + n) || find(a) == find(b + n * 2))sum++;
          else v(a, b), v(a + n, b + n), v(a + n * 2, b + n * 2);
        } else {
          if (find(a) == find(b) || find(a) == find(b + n * 2))sum++;
          else v(a, b + n), v(a + n, b + n * 2), v(a + n * 2, b);
        }
      }
      cout << sum << endl;
  }
  return 0;
}
/*

 经典的题就是牛逼，这道题把我看的呀，因为弱
 刚学会并查集然后队里的题里面有这道题，就尝
 试的做了一哈，然后果断gg。

题意就是 判断有多少句假话。

只要满足

1） 当前的话与前面的某些真的话冲突，就是假话； 
2） 当前的话中X或Y比N大，就是假话； 
3） 当前的话表示X吃X，就是假话。 

都是假话。第2,3条都很好搞定，第一条就是关键了。

      这是我是参考的神犇的写法的，在建立父亲数组的
      时候建一个比原本大三倍的数组，每一个数都对应
      这三个节点。

举个栗子吧 比如 1号动物就有 1.a 1.b,1.c; 分别用
 1,1+n,1+2n来保存。

如果是真话，就会有两种操作。

第一种说法是"1 X Y"，表示X和Y是同类，就将
 x.a,y.a    x.b,y.b,  x.c, y.c分别用合并操作归成一组。

第二种说法是"2 X Y"，表示X吃Y。 就将 
x.a,y.b , x.b,y.c   ,x.c ,y.a归成一组。

每次输入时

如果首数字是1的话 就判断 x.a,y.c 和 x.c和y.a的
关系如果父节点相同的话就说明他俩有捕食关系
说明这句话是假话。

如果首字母是2的话 就判断x.a,y.a 和x.a,y.c的关系
 因为 如果想 x，y是同类或者y吃x 的话 。x吃y 都是假话。

      大神的思想果然是抽象的，我理解了好久才
      转换成我的想法。
*/
/*
样例输入

100 7
1 101 1 
2 1 2
2 2 3 
2 3 3 
1 1 3 
2 3 1 
1 5 5

样例输出

3
*/