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
    pre(T), cout << endl;
  }
  return 0;
}
/*
描述


输入完全二叉树的层次遍历序列，输出该完全二叉树的中序遍历序列。

例如下面二叉树的层次遍历序列为“ABCDE",中序遍历为"DBEAC"。 

           A

         /    \

       B      C

     /    \

   D     E

输入


输入完全二叉树的层次遍历序列。

输出


输出该完全二叉树的中序遍历序列。

样例输入

ABCDE

样例输出

DBEAC
*/
  
	
	