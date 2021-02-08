//输入层次遍历输出中序

#include <cstdio>
#include <cstdlib>
#include <cstring>
//#define _OJ_
typedef struct tree1
{
    char data;
    struct tree1 *lchild;
    struct tree1 *rchild;
} tree1, *tree;

tree creat_tree(tree T, char *str, int i, int len)
{
    if(2 * i <= len) {

    tree T1, T2;
    if((2 * i) <= len) {//左儿子
     T1 = (tree) malloc (sizeof(tree1));
     T1->data = str[2 * i];
     T->lchild = T1;
     T->lchild = creat_tree(T->lchild, str, 2 * i, len);
    }

    if((2 * i + 1) <= len) {//右儿子
     T2 = (tree) malloc (sizeof(tree1));
     T2->data = str[2 * i + 1];
     T->rchild = T2;
     T->rchild = creat_tree(T->rchild, str, 2 * i + 1, len);
     }

  }
    else//如果传入的数值大于len那么他就是叶子节点
       T->lchild = T->rchild = NULL;

    return T;
}

void pre_oder(tree T)
{
  if (T != NULL) {
    pre_oder(T->lchild);
    printf("%c", T->data);
    pre_oder(T->rchild);
  }
}
int main(int argc, char const *argv[]) {
//#ifndef _OJ_ // ONLINE_JUDGE
//  freopen("input.txt", "r", stdin);
//#endif

  tree T;
  int i = 0, len = 0;
  char str[100];
  scanf("%s", str);

  len = strlen(str); //利用数组来存储完全二叉树那么左儿子为2i,右儿子为2i+1;
  for (i = len; i >= 0; i--)
    str[i + 1] = str[i]; // 0好不用，从一号开始
  T = (tree)malloc(sizeof(tree1));
  T->data = str[1];
  T = creat_tree(T, str, 1, len);
  pre_oder(T);
  printf("\n");

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