#include <iostream>
#include <map>
using namespace std;
struct node {
  int x, y;
};
map<int, node>  q;
void hanoi(int n, int a, int b, int c) {
  static int i = 0;
  if (n == 1)
    q[i].x = a, q[i++].y = c;
  else
    hanoi(n - 1, a, c, b), q[i].x = a, q[i++].y = c, hanoi(n - 1, b, a, c);
}
int main() {
  int t, n, m, flag, a, b;
  cin >> t;
  while (q.clear(), t-- && cin >> n >> m) {
    hanoi(n, 1, 2, 3);
    for (int i = 0; i < m; i++)
      cin >> a >> b, flag = (a == q[i].x && b == q[i].y);
    cout << (flag ? "legal" : "illegal") << endl;
  }
  return 0;
}
/*
描述


        在印度，有这么一个古老的传说：在世界中心贝拿勒斯
        （在印度北部）的圣庙里，一块黄铜板上插着三根宝石针。
        印度教的主神梵天在创造世界的时候，在其中一根针上从下
        到上地穿好了由大到小的64片金片，这就是所谓的汉诺塔。
        不论白天黑夜，总有一个僧侣在按照下面的法则移动这些金片：
        一次只移动一片，不管在哪根针上，小片必须在大片上面。
        僧侣们预言，当所有的金片都从梵天穿好的那根针上移到另外
        一根针上时，世界就将在一声霹雳中消灭，而梵塔、庙宇和众
        生也都将同归于尽。

      现在我们把三根针编号为1，2，3。所有的金片在初始时都在
      1号针上，现在给你的任务是判断一系列的指令过程中，是否
      会出现非法的指令。而非法指令有以下两种情况：

       1、某个针上已经没有金片了，但是指令依然要求从该处移
       动金片到其它针上。

       2、把一个大的金片移动到了小的金片上。
       
输入


第一行输入一个整数N表示测试数据的组数(N<10)
每组测试数据的第一行有两个整数P,Q(1<P<64,1<Q<100)，分别表示
汉诺塔的层数与随后指令的条数
随后的Q行，每行都输入两个整数a,b，(1<=a,b<=3)表示一条指令。
指令1 2表示把1号针最上面的金片移动到2号针最上面。
数据保证a,b不会相同。

输出


如果存在非法指令，请输出illegal
不存在非法指令则输出legal

样例输入

3
2 1
1 2
3 3
1 2
1 3
3 2
2 1
2 1


1
3 3
1 2
1 3
3 2

样例输出

legal
illegal
illegal
*/