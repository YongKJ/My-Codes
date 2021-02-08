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
  for (link i = la->next; i; i = i->next) {
    int t = 1;
    for (link j = lb->next; j; j = j->next)
      if (i->x == j->x)
        lc->next = i, lc = i, t = 0;
    if (t)delete i;
  }
  lc->next = NULL;
  for (link i = la->next; i; i = i->next)
    cout << i->x << (i->next ? " " : "\n");
  /*link s = new node;
  s->x = -1, s->next = lb;
  cout << sizeof(s) << " " << s << " " << s->x << " " << s->next << endl;
  delete s;
  cout << sizeof(s) << " " << s << " " << s->x << " " << s->next << endl;*/
  return 0;
}