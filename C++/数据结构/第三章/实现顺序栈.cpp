#include <iostream>
using namespace std;
struct sqstack {
  int *base;
  int *top;
  int Size;
};
int main() {
  int n = 7;
  sqstack q;
  q.top = q.base = new int[n], q.Size = n;
  for (int *&i = q.top, *j = q.base; i - j != q.Size; i++)
    cin >> *i;
  for (int *&i = q.top, *j = q.base; i != j; i--)
    cout << *(i - 1) << (i - 1 != j ? " " : "\n");
  return 0;
}
  
  