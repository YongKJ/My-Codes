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
 // cout << "A" << endl;
}
void out(linklist l) {
  //cout << "B" << endl;
  for (linklist i = l->next; i; i = i->next)
    cout << i->data.x << (i->next ? " " : "\n");
  cout << -1 << endl;
}
void add(linklist &la, linklist &lb,linklist &lc) {
  linklist pa = la->next, pb = lb->next, pc = lc = la;
  //cout << "B" << endl;
  out(pc);
  while (pa && pb) {
    if (pa->data.x < pb->data.x) {
      cout << pa->data.x <<" "<<"a"<< endl;
      pc->next = pa, pc = pa, pa = pa->next;
    } else if (pa->data.x > pb->data.x) {
      cout << pb->data.x <<" "<<"b"<< endl;
      pc->next = pb, pc = pb, pb = pb->next;
    }
    else {
      cout << pa->data.x <<" "<<"c"<< endl;
      pc->next = pa, pc = pa, pa = pa->next;
      linklist q = pb;
      pb = pb->next, delete q;
    }
  }
  //cout << endl;
  //cout << pc->data.x << endl;
  out(lc),cout<<"A"<<endl;
  //out(pb);
  pc->next = (pa ? pa : pb), delete lb;
  out(lc),cout<<"B"<<endl;
}	
int main() {
  int t = 3;
  while (t--) {
    linklist pa, pb,pc;
    creat(pa, 3);
    //out(pa);
    creat(pb, 4);
    //out(pb);
    add(pa, pb, pc);
    cout << endl;
  }
  return 0;
}