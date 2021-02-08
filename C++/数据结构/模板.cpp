#define _CRT_SECURE_NO_DEPRECATE//关闭安全检查
#include<iostream>
#include <stdio.h>
using namespace std;
typedef int Status;
typedef int ElemType;
typedef struct LNode//存储结构； 
{
	ElemType data;
	struct LNode *next;
}LNode, *LinkList;
Status InitList_L(LinkList &L)//初始化 
{
	L = new LNode;
	L->next = NULL;
	return 0;
}
LNode* LocateElem_L(LinkList L, ElemType e)//查找 
{   
	LNode* p;
	p = L->next;
	while (p&&p->data != e)
	{
		p = p->next;
	}
	return p;
}

void disp(LNode *L)//输出 
{  
	LNode* P;
	P = new LNode;
	P = L->next;

	while (P)
	{
		cout << P->data << " ";
		P = P->next;
	}

}

int main()
{
	int x; LNode *L1, *S, *P; InitList_L(L1);
	cout << "输入整数，0结束：" << endl;
	scanf("%d", &x);
	P = L1;
	while (x)
	{

		if (LocateElem_L(L1, x) != NULL)//有一样的数据
		{
         cin >> x;
                } else {
                  S = new LNode;
                  S->data = x;
                  P->next = S;
                  P = S;
                  cin >> x;
                }
        }
        P->next = NULL;
        disp(L1);
        return 0;
}