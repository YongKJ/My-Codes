#include <iostream>
using namespace std;
#define n 3
struct cycqueue {
  int base[n];
  int rear, front;
};
void in(cycqueue &q,int e){
  if ((q.front - 1 + n) % n == q.rear) {
    cout << "队列已满" << endl;
    return;
  }
  q.base[q.front] = e, q.front = (q.front - 1 + n) % n;
}
int del(cycqueue &q){
  if (q.rear == q.front) {
    cout << "队列为空" << endl;
    return 0;
  }
  int t = q.base[q.rear];
  q.rear = (q.rear - 1 + n) % n;
  return t;
}
int main() {
  cycqueue q;
  q.front = q.rear = 0;
  for (int &i = q.front, j = q.rear; (i - 1 + n) % n != j; i = (i - 1 + n) % n)
    cin >> q.base[i];
  //cout << q.rear << " " << q.front << endl;
  for (int &i = q.rear, j = q.front; i != j; i = (i - 1 + n) % n)
    cout << q.base[i] << ((i - 1 + n) % n != j ? " " : "\n");
  return 0;
}
