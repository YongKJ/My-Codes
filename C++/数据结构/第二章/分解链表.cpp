#include <iostream>
using namespace std;
typedef struct node {
  int x;
  node *next;
} * link;
int main(){
  link la = new node, pa = la;
  for (int i = 0; i < 7; i++) {
    link s = new node;
    cin >> s->x, pa->next = s, pa = s;
  }
  pa->next = NULL;
  link lb = la, lc = new node, pb = lb, pc = lc;
  for (link i = la->next; i; i = i->next) {
    if (i->x < 0)
      pb->next = i, pb = i;
    else
      pc->next = i, pc = i;
  }
  pc->next = pb->next = NULL;
  for (link i = lb->next; i; i = i->next)
    cout << i->x << (i->next ? " " : "\n");
  for (link i = lc->next; i; i = i->next)
    cout << i->x << (i->next ? " " : "\n");
  return 0;
}
  	