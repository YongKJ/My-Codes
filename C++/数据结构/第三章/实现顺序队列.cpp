#include <iostream>
using namespace std;
struct sqqueue {
  int *base;
  int front;
  int rear;
};
int main() {
  int n = 7;
  sqqueue q;
  q.base = new int[n], q.front = q.rear = 0;
  for (int &i = q.rear, j = q.front; (i + 1) % n != j; i = ++i % n)
    cin >> q.base[i];
  for (int &i = q.front, j = q.rear; i != j; i = ++i % n)
    cout << q.base[i] << ((i + 1) % n != j ? " " : "\n");
  return 0;
}