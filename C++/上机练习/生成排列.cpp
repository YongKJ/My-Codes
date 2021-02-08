#include <iostream>
#include <string>
using namespace std;
int pai[10], visited[10], n;
void DFS(int x) {
  if (x==n) {
    for (int i = 1; i <= n; i++)
      cout << pai[i] << " ";
    cout << endl;
  }
  for (int i = 1; i <= n; i++)
    if (visited[i] == 0)
      pai[x + 1] = i, visited[i] = 1, DFS(x + 1), visited[i] = 0;
}
int main(){
  while (cin >> n) {
    for (int i = 1; i <= n; i++) {
      memset(visited, 0, sizeof(visited)), memset(pai, 0, sizeof(pai));
      pai[1] = i, visited[i] = 1, DFS(1);
    }
  }
  return 0;
}
/*
描述


        一自然数N，设N为3，则关于N的字典序排列为123，
        132，213，231，312，321。对于一个自然数N
        (1<= N <= 9 ) , 你要做的便是生成它的字典序排列。

输入

自然数N。

输出


输出对应于N的字典序排列,每个排列占一行。

样例输入

3

样例输出

1 2 3
1 3 2
2 1 3
2 3 1
3 1 2
3 2 1

提示


注意：每个数后有空格

可以参考 pku 1833
*/