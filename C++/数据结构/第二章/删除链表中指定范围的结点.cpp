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
  int n, m;
  cin >> n >> m;
  for (link i = la, t; i && i->next; i = i->next)
    if (n <= i->next->x && i->next->x <= m)
      t = i->next, i->next = t->next, delete t;
  for (link i = la->next; i; i = i->next)
    cout << i->x << (i->next ? " " : "\n");
  return 0;
}