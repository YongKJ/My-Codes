#include <iostream>
using namespace std;
struct number {
  int x;
};
typedef struct node {
  number data;
  node *next;
} * linklist;
void creat(linklist &l,int n){
  l = new node, l->next = NULL;
  for (int i = 0; i < n; i++) {
    linklist s = new node;
    cin >> s->data.x;
    linklist pre = l, q = l->next;
    while (q && q->data.x < s->data.x)
      pre = q, q = q->next;
    s->next = q, pre->next = s;
  }
}
void out(linklist l) {
  for (linklist i = l->next; i; i = i->next)
    cout << i->data.x << (i->next ? " " : "\n");
}
void add(linklist &la, linklist &lb,linklist &lc) {
  linklist pa = la->next, pb = lb->next, pc = lc = la;
  while (pa && pb) {
    if (pa->data.x < pb->data.x) 
      pc->next = pa, pc = pa, pa = pa->next;
    else if (pa->data.x > pb->data.x) 
      pc->next = pb, pc = pb, pb = pb->next;
    else {
      pc->next = pa, pc = pa, pa = pa->next;
      linklist q = pb;
      pb = pb->next, delete q;
    }
  }
  pc->next = (pa ? pa : pb), delete lb, out(lc);
}	
int main() {
  int t = 3;
  while (t--) {
    linklist pa, pb, pc;
    creat(pa, 3), creat(pb, 4);
    add(pa, pb, pc), cout << endl;
  }
  return 0;
}