/*实验二：链表的实现与应用

实验时间：2019.4.17 地点，信工楼 318

1、实验名称：单链表的实现与基本操作

2、实验内容：建立链表、插入结点、删除结点等运算

3、实验目的：掌握单握链表的基本操作

4、实验题目：从键盘输入一些整数，删除其中的重复元素，并使剩

余元素的相对次序保持不变。

例如，输入：2,3,1,3,4,2,3,1,5,0

输出：2,3,1,4,5

提示： 在输入每个元素时，先查询该元素是否存在，如果不存在，则将元素插入链表中*/
#include <stdio.h>
#include <stdlib.h>
struct node
{
	int data;
	struct node *next;
};
void disp(struct node *h)
{struct node *p;
	p=h->next;
	if(p!=NULL)
	{
		printf("%5d",p->data );
		p=p->next;
	}
	printf("\n");
}
void insert(struct node *h,int x)
{
	struct node *t,*q;
	q=h;
	t =q->next;
	while (t!=NULL&& t->data!=x)
	{
		q=t;
		t=t->next;
	}
	if (t==NULL)
	{
		t=(struct node *)malloc(sizeof (struct node));
		q->next=t;
		t->data=x;
		t->next=NULL;
		}
}
int main ( )
{
	struct node *h;
	int x;
	h=(struct node *)malloc(sizeof(struct node));
	h->next=NULL;
	scanf("%d",&x);
        while (x != 0) {
          insert(h, x);
          scanf("%d", &x);
        }
        disp(h);
}