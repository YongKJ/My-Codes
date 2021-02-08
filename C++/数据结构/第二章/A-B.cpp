#include <iostream>
using namespace std;
typedef struct node {
  int x;
  node *next;
} * link;
int main(){
  link la, lb;
  int sum = 0;
  la = new node, la->next = NULL;
  lb = new node, lb->next = NULL;
  for (int i = 0; i < 3; i++) {
    link s = new node, j;
    cin >> s->x;
    for ( j = la; j->next; j = j->next)
      if (j->next->x > s->x)break;
    s->next = j->next, j->next = s;
  }
  for (int i = 0; i < 4; i++) {
    link s = new node, j;
    cin >> s->x;
    for (j = lb; j->next; j = j->next)
      if (j->next->x > s->x)break;
    s->next = j->next, j->next = s;
  }
  for (link i = lb->next, t; i; i = i->next)
    for (link j = la;j&&j->next; j = j->next)
      if (j->next->x == i->x)
        t = j->next, j->next = t->next, delete t;
  for (link i = la->next; i; i = i->next)
    cout << i->x << (i->next ? " " : "\n"),sum++;
  cout << sum << endl;
    for (link i = lb->next; i; i = i->next)
      cout << i->x << (i->next ? " " : "\n");
  return 0;
}
    