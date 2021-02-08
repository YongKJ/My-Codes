#include <iostream>
#include <string>
using namespace std;
int n, i;
char s[100];
typedef struct node {
  char x;
  node *lc, *rc;
} *sqlist;
void insert(sqlist &l) {
  if (i==strlen(s))
    return;
  if (s[i] == '#')
    l = NULL,i++;
  else {
    l = new node, l->x = s[i++], n++;
    insert(l->lc), insert(l->rc);
  }
}
void out(sqlist &l) {
  if (!l)
    return;
  out(l->lc);
  out(l->rc);
  cout << l->x << (--n ? " " : "\n");
}
int main() {
  while (i=n=0,cin >> s) {
    sqlist l;
    insert(l);
    cout << l->x << endl;
   // cout << l->lc->x << " " << l->rc->x << endl,cout<<-1<<endl;
    out(l);
  }
  return 0;
}
/*
8
123#45#6

输入

第1行：先序串（结点数≤26，以单个大写字母表示）

输出

第1行：后序序列

样例输入
9
AB#C##D##
4
ABCD
5
ABCDE
7
AB##C##
样例输出

CBDA
*/