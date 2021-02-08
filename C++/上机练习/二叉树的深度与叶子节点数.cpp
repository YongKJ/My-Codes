#include <iostream>
#include <string>
using namespace std;
int i, m;
char s[100];
typedef struct node {
  char x;
  node *lc, *rc;
} *sqlist;
void insert(sqlist &l) {
  if (s[i] == '#')
    l = NULL,i++;
  else l = new node, l->x = s[i++], insert(l->lc), insert(l->rc);
}
void lev(sqlist l) {
  if (l) {
    if (!l->lc && !l->rc)
      m++;lev(l->lc), lev(l->rc);
  }
}
int dep(sqlist l) {
  if (!l)return 0;
  return max(dep(l->lc) + 1, dep(l->rc) + 1);
}
int main() {
  while (i = m = 0, cin >> s) {
    sqlist l;
    insert(l), lev(l), cout << dep(l) << " " << m << endl;
  }
  return 0;
}
/*
描述


 输入二叉树的先序序列，计算并输出该二叉树的
 深度与叶子节点个数。请将代码填写完整。

例如，下面二叉树对应的先序序列为“AB#D##C##"。 

           A

         /    \

       B      C

        \

         D
         
输入


叉树对应的先序序列为。

输出

二叉树的深度与叶子节点个数。

样例输入

AB#D##C##

样例输出

3 2

题目来源

数据结构
BiTree CreateBiTree()//建立二叉树
{
    ElemType x;
    BiTree T;
    scanf("%c",&x);
    if(x=='#')
        T=NULL;
    else
    {
        T=(BiTree)malloc(sizeof(BiTNode));
        T->data=x;
        T->Lchild=CreateBiTree();
        T->Rchild=CreateBiTree();
    }
    return T;
}
nt maxDepth(TreeNode *root) {
        if(root == nullptr)
            return 0;

        //分别计算左子树和右子树的深度
        int leftDepth = maxDepth(root->left) + 1;
        int rightDepth = maxDepth(root->right) + 1;

        return leftDepth > rightDepth ? leftDepth: rightDepth;
    }
*/