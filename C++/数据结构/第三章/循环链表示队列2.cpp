#include <iostream>
using namespace std;
typedef struct node {
  int data;
  node *next;
} *qnode;
struct qlnode {
  node *rear;
};
void reset(qlnode *&q) {
  q->rear = q->rear->next;
  for (qnode s, j = q->rear, i = j->next; i != j; delete s)
    s = i, i = s->next;
  q->rear->next = q->rear;
}
int empty(qlnode *&q) { return q->rear->next == q->rear; }
void in(qlnode *&q, int e) {
  qnode p = new node;
  p->data = e, p->next = q->rear->next, q->rear->next = p, q->rear = p;
}
int out(qlnode *&q){
  if (empty(q)) {
    cout << "error" << endl;
    return 0;
  }
  qnode t = q->rear->next, p = t->next;
  int x = p->data;
  t->next = p->next;
  if(p==q->rear)
    q->rear = t;
  delete p;
  return x;
}
int main(){
  qlnode *q = new qlnode;
  q->rear = new node, q->rear->next = q->rear;
  for (int i = 0; i < 3; i++) {
    qnode p = new node;
    cin >> p->data;
    p->next = q->rear->next, q->rear->next = p, q->rear = p;
  }
  for (qnode j = q->rear->next, i = j->next; i != j; i = i->next)
    cout << i->data << (i->next != j ? " " : "\n");
  return 0;
}