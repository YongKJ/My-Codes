#include <iostream>
#include <string>
using namespace std;
typedef struct tree1 {
  char data;
  tree1 *lchild, *rchild;
} * tree;
tree creat(tree T, char *str, int i, int len) { 
if(i*2<=len){
  if (i * 2 <= len) {
    tree T1 = new tree1;
    T1->data = str[i * 2];
    T->lchild = T1, T->lchild = creat(T->lchild, str, i * 2, len);
  }
  if (i * 2 + 1 <= len) {
    tree T2 = new tree1;
    T2->data = str[i * 2 + 1];
    T->rchild = T2, T->rchild = creat(T->rchild, str, i * 2 + 1, len);
  }
} else T->lchild = T->rchild = NULL;
return T;
}
void pre(tree T) {
  if (T != NULL)
    pre(T->lchild), cout << T->data, pre(T->rchild);
}
int main(){
  char str[100];
  while (cin >> str) {
    int len = strlen(str);
    for (int i = len; i >= 0; i--)
      str[i + 1] = str[i];
    tree T = new tree1;
    T->data = str[1], T = creat(T, str, 1, len);
    pre(T), cout << endl;
  }
  return 0;
}
/*
样例输入

ABCDE
ABC
AB
样例输出

DBEAC
*/
  
	
	