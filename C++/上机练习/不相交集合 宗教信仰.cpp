#include <iostream>
#include <set>
#include <map>
using namespace std;
struct node {
  int x, y;
};
int main(){
  int n, m, t = 0, sum;
  while(sum=0,t++,cin>>n>>m,n||m){
    set<int> p;
    map<int, node> q;
    for (int i=0;i<m;i++)
      cin >> q[i].x >> q[i].y, p.insert(q[i].x), p.insert(q[i].y);
    for (int i = 0; i < m; i++) {
      set<int> d;
      if (q[i].x != 0 && q[i].y != 0)
        sum++, d.insert(q[i].x), d.insert(q[i].y);
      for (int j = i + 1; j < m; j++)
        if (d.find(q[j].x) != d.end() || d.find(q[j].y) != d.end())
          d.insert(q[j].x), d.insert(q[j].y), q[j].x = q[j].y = 0;
    }
    cout << "Case " << t << ": " << n - p.size() + sum << endl;
  }
  return 0;
}
/*
描述

世界上有许多不同的宗教，现在有一个你感兴趣的问题：
找出多少不同的宗教，在你的大学中的大学生信仰了多
少种不同的宗教。你知道在你的大学有n个学生
（0<n<= 50000）。若直接问每一个学生的宗教信仰不
大适合。此外，许多学生还不太愿意说出自己的信仰。
有一种方法来避免这个问题，询问m（0<=m<=n（n- 1）/ 2）
对学生，询问他们是否信仰同一个宗教（比如，可以询问他们
是否都参加同一教堂）。从这个数据，您可能不知道每个人
宗教信仰，但是你可以知道有多少不同宗教信仰。你可以假
设，每名学生最多信仰一个宗教。

输入


输入包含多组测试数据。每组测试数据的开头包含
两个整数n和m。接下来有m行，每行有两个整数i和j，
编号为i和j的同学信仰同一个宗教。学生的编号从从
1开始到n。当输入使n=0，m=0标志输入的结束。

输出


每组测试数据的输出只有一行，包含数据的组别
（从1开始）和学生最多信仰的宗教数。

样例输入

10 9
1 2
1 3
1 4
1 5
1 6
1 7
1 8
1 9
1 10
10 4
2 3
4 5
4 8
5 8
0 0

样例输出

Case 1: 1
Case 2: 7
*/