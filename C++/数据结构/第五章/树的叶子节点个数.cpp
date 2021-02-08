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
int compare(tree T, tree L) {
  if (!T && !L)
    return 1;
  if (!T || !L)
    return 0;
  if (T->data == L->data)
    return compare(T->lchild, L->lchild) && compare(T->rchild, L->rchild);
  else
    return 0;
}
void pre(tree T) {
  if (T)
    pre(T->lchild), cout << T->data, pre(T->rchild);
}
int main(){
  while (cin >> str) {
    len = strlen(str);
    for (int i = len; i > 0; i--)
      str[i] = str[i-1];
    tree T = new tree1;
    T->data = str[1], T = creat(T, 1);
     cin >> str;
    len = strlen(str);
    for (int i = len; i > 0; i--)
      str[i] = str[i-1];
    tree L = new tree1;
    L->data = str[1], L = creat(L, 1);
    cout << (compare(T, L) ? "Yes" : "No") << endl;
    //pre(T), cout << endl;
  }
  return 0;
}
/*
ABCDE
ABCDF
a
b

No
*/
