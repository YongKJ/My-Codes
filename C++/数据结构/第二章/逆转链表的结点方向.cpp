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
  for (link i = la->next; i; i = i->next)
    cout << i->x << (i->next ? " " : "\n");
  link lb = la, t = la->next;
  lb->next = NULL;
  for (link i = t, j; i;)
    j = i, i = i->next, j->next = lb->next, lb->next = j;
  for (link i = la->next; i; i = i->next)
    cout << i->x << (i->next ? " " : "\n");
  return 0;
}