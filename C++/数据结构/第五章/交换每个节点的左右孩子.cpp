#include <iostream>
#include <string>
using namespace std;
int len;
char str[100];
typedef struct tree1 {
  char data;
  tree1 *lchild = NULL, *rchild = NULL;
} * tree;
tree creat(tree T, int i) { 
if(i*2<=len){
  if (i * 2 <= len) {
    T->lchild = new tree1;
    T->lchild->data = str[i * 2];
    T->lchild = creat(T->lchild, i * 2);
  }
  if (i * 2 + 1 <= len) {
    T->rchild = new tree1;
    T->rchild->data = str[i * 2 + 1];
    T->rchild = creat(T->rchild, i * 2 + 1);
  }
} else T->lchild = T->rchild = NULL;
return T;
}
void change(tree l) {
  if (!l->rchild&&!l->lchild)
    return;
  else {
    cout << 0 << endl;
    cout << l->lchild->data << " " << l->rchild->data << endl;
    tree t = l->lchild;
    l->lchild = l->rchild, l->rchild = t;
    change(l->lchild), change(l->rchild);
  }
}
void pre(tree T) {
  if (T)
    cout << T->data, pre(T->lchild), pre(T->rchild);
}
int main(){
  while (cin >> str) {
    len = strlen(str);
    for (int i = len; i > 0; i--)
      str[i] = str[i - 1];
    tree T = new tree1;
    T->data = str[1], T = creat(T, 1), pre(T), cout << endl,cout<<-1<<endl, change(T),cout<<-2<<endl;
     pre(T), cout << endl;
  }
  return 0;
}
/*
ABCDE
ABCDF

No
*/