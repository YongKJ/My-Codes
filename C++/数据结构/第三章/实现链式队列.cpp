#include <iostream>
using namespace std;
typedef struct node {
  int data;
  node *next;
} * queueptr;
struct link {
  queueptr front;
  queueptr rear;
};
int main(){
  link q;
  q.front = q.rear = new node, q.front->next = NULL;
  for (int i = 0; i < 7; i++) {
    queueptr p = new node;
    cin >> p->data, q.rear->next = p, q.rear = p;
  }
  q.rear->next = NULL;
  for (queueptr &i = q.front, j = q.rear, p; i != j; i = i->next, delete p)
    cout << i->next->data << (i->next->next ? " " : "\n"), p = i;
  return 0;
}