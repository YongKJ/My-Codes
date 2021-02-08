#include <iostream>
using namespace std;
typedef struct node {
  int x;
  node *next;
} * link;
int main(){
  link la, lb, j;
  la = new node, la->next = NULL;
  lb = new node, lb->next = NULL;
  for (int i = 0; i < 3; i++) {
    link s = new node;
    cin >> s->x;
    for ( j = la; j->next; j = j->next)
      if (j->next->x > s->x)break;
    s->next = j->next, j->next = s;
  }
  for (int i = 0; i < 4; i++) {
    link s = new node;
    cin >> s->x;
    for (j = lb; j->next; j = j->next)
      if (j->next->x > s->x)break;
    s->next = j->next, j->next = s;
  }
  link lc = la;
  j = la->next, lc->next = NULL;
  for (link i = lb->next,q; i || j;) {
    if (!j || i->x <= j->x)
      q = i, i = i->next;
    else
      q = j, j = j->next;
    q->next = lc->next, lc->next = q;
  }
  delete lb;
  for (link i = lc->next; i; i = i->next)
    cout << i->x << (i->next ? " " : "\n");
  return 0;
}
void union(LinkList &La,LinkList &Lb){
  LinkList pc = La, i = La->next;
  pc->next = NULL;
  for (LinkList j = Lb->next, q; i || j;) {
    if (!j || i->data <= j->data)
      q = i, i = i->next;
    else
      q = j, j = j->next;
    q->next = pc->next;
    pc->next = q;
  }
  delete Lb;
}
  