#include <iostream>
using namespace std;
typedef struct node {
  int x;
  node *next;
}*link;
int getmax(link q) {
  if (!q->next)
    return q->x;
  int max = getmax(q->next);
  return max > q->x ? max : q->x;
}
int getlength(link q) {
  if (!q->next)
    return 1;
  return 1 + getlength(q->next);
}
double getave(link q, int n) {
  if (!q->next)
    return q->x;
  double sum = q->x + getave(q->next, n - 1) * (n - 1);
  return sum / n;
}
	
int main() {
  int n = 5;
  link q = new node, p = q;
  for (int i = 0; i < n; i++) {
    link s = new node;
    cin >> s->x, p->next = s, p = s;
  }
  p->next = NULL;
  cout << getmax(q->next) << " " << getlength(q->next) << " "
       << getave(q->next, n) << endl;
  for (link i = q->next; i; i = i->next)
    cout << i->x << (i->next ? " " : "\n");
  return 0;
}
  