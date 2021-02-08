#include <iostream>
#include <string>
using namespace std;
const int sushu[40] = {0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1,
                 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0};
int huan[20], visited[20], n;
void DFS(int x) {
  if (x == n && sushu[huan[x] + huan[1]] == 1) {
    cout << huan[1];
    for (int i = 2; i <= n; i++)
      cout << " " << huan[i];
    cout << endl;
  }
  for (int i = 1; i <= n; i++)
    if (visited[i] == 0 && sushu[huan[x] + i] == 1)
      huan[x + 1] = i, visited[i] = 1, DFS(x + 1), visited[i] = 0;
}
int main(){
  int t = 0;
  while (t++, cin >> n) {
    memset(visited, 0, sizeof(visited)), memset(huan, 0, sizeof(huan));
    huan[1] = 1, visited[1] = 1;
    cout << "Case " << t << ":" << endl;
    if (n % 2 == 0 && n > 0)
      DFS(1);
    else if (n == 1)
      cout << 1 << endl;
    cout << endl;
  }
  return 0;
}
    