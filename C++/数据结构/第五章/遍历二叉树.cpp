#include <iostream>
#include <stack>
using namespace std;
typedef struct tnode {
  int x;
  tnode *lc, *rc;
} * tree;
void otra(tree t) {
  if (!t)
    return;
  otra(t->lc);
  cout << t->x;
  otra(t->rc);
}
void notra(tree t) {
  stack<tree> s;
  for (tree p = t; p || !s.empty();) {
    if (p)
      s.push(p), p = p->lc;
    else
      cout << s.top()->x, p = s.top()->rc, s.pop();
  }
}
  	
int main() {
  tree L = new tnode, p = L;
  L->lc = L->rc = NULL;
  stack<tree> S;
  S.push(p);
  for (int i = 0, n; i < 5; i++) {
    tree s = new tnode;
    s->lc = s->rc = NULL;
    cin >> s->x;
    if (!p->lc)
      p->lc = s;
    else
      p->rc = s;
    S.push(s);
  }
return 0; }