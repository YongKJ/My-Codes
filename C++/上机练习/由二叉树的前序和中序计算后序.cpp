#include <stdio.h>  
#include <stdio.h>  
#include <iostream>  
using namespace std;  
struct TreeNode  
{  
  struct TreeNode* left;  
  struct TreeNode* right;  
  char  elem;  
};  
  
void BinaryTreeFromOrderings(char* inorder, char* preorder, int length)  
{  
  if(length == 0)  
    {  
      //cout<<"invalid length";  
      return;  
    }  
  char node_value = *preorder;  
  int rootIndex = 0;  
  for(;rootIndex < length; rootIndex++)  
    {  
      if(inorder[rootIndex] == *preorder)  
      break;  
    }  
  //Left  
  BinaryTreeFromOrderings(inorder, preorder +1, rootIndex);  
  //Right  
  BinaryTreeFromOrderings(inorder + rootIndex + 1, preorder + rootIndex + 1, length - (rootIndex + 1));  
  //cout<<node_value<<endl;
  cout << node_value;
  return;  
}  
  
  
int main(int argc, char* argv[])  
{  
    printf("Hello World!\n");  
    //char* pr="GDAFEMHZ";  
    //char* in="ADEFGHMZ";  
    char* pr="ABDC";  
    char* in="DBAC";  
    
    BinaryTreeFromOrderings(in, pr, 4);  
  
    printf("\n");  
    return 0;  
}  
/*
描述


      已知二叉树的前序和中序遍历，输出该二叉树的后序遍历。
      例如下面二叉树的前序和中序遍历为ABDC、DBAC，后序
      遍历为DBCA。 

           A

          /  \

         /    \

        B     C

       /

      /

     D

输入


包括多组测试数据。

每组1行，包含两个字符串，分别为叉树的前序和中序遍历。

输出


二叉树的后序遍历。

样例输入

ABDC DBAC
BCAD CBAD

样例输出

DBCA
CDAB

提示

类似  tyvj.cn 第1441题
*/