#include <iostream>
#include <string>
using namespace std;
string s;
typedef struct tree1{
	char x;
	tree1 *lc,*rc;
}*tree;
int max(int a,int b){return a>b?a:b;}
tree creat(tree T,int i){
	if(i*2<s.size()){
		if(i*2<s.size()){
			T->lc=new tree1;
			T->lc->lc=T->lc->rc=NULL;
			T->lc->x=s[i*2],T->lc=creat(T->lc,i*2);
		}

		if(i*2+1<s.size()){
			T->rc=new tree1;
			T->rc->lc=T->rc->rc=NULL;
			T->rc->x=s[i*2+1],T->rc=creat(T->rc,i*2+1);
		}
	} else T->lc=T->rc=NULL;
	return T;
}
void pre(tree T){
	if(T)pre(T->lc),cout<<T->x,pre(T->rc);
}
int depth(tree T){
	if(!T)return 0;
	return max(depth(T->lc),depth(T->rc))+1;
}
int main(){
	while(cin>>s){
		tree T=new tree1;
		s='#'+s,T->x=s[1],T=creat(T,1);
		pre(T),cout<<endl<<depth(T)<<endl;
	}
	return 0;
}
/*

实验六：树的遍历
1、 实验名称：二叉树的基本操作
   2、实验内容：二叉树的实现和及深度遍历运算   
   3、实验目的：掌握二叉树的结构、特点和操作
   4、实验题目：建立并遍历二叉树
*/