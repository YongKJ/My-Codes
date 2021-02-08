#include <iostream>
using namespace std;
typedef struct node {
  int x;
  node *next;
} * sqlist;
int main(){
  sqlist l = new node, p = l, i;
  l->next = NULL;
  for (int n; cin >> n, n;) {
    for (i = l->next; i; i = i->next)
      if (i->x == n)break;
    if (i)continue;
    sqlist s = new node;
    s->x = n, s->next = p->next, p->next = s, p = s;
  }
  for (sqlist j = l->next; j; j = j->next)
    cout << j->x << (j->next ? " " : "\n");
  return 0;
}