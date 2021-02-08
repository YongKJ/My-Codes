#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)
struct parameter
{
	char *name;
	char *content;
	struct parameter *next;
};
typedef struct parameter parameter;
parameter *create()
{
	parameter temp,*p=&temp;
	p->next = NULL;
	return p;
}
parameter *addstr(parameter *p,char *name,char *content)
{
	parameter temps,*temp=&temps;
	int namesize = strlen(name);
	int contentsize = strlen(content);
	temp->name = (char *)malloc(namesize + 1);
	temp->content = (char *)malloc(contentsize + 1);
	if (temp->name&&temp->content)
	{
		strcpy(temp->name, name);
		strcpy(temp->content,content);
		p->next = temp;
		temp->next = NULL;
		return temp;
	}
	else
	{
		return NULL;
	}
}
char *_POST(parameter *temp,char *ch)
{
	parameter *p = temp , *q = temp->next;
	while(p->next)
	{
		if (!strcmp(q->name, ch))
		{
			return q->content;
	    }
		p = p->next;
		q = q->next;
	}
	return NULL;
}
void del(parameter *p)
{
	parameter *q=p->next;
	while (q)
	{
		p = q->next;
		free(q);
		q = p;
	}
}
void print(parameter *p)
{
	parameter *q=p->next;
	while (q)
	{
		p = q->next;
		printf("name:%s\ncontent:%s\n", p->name, p->content);
		q = p;
	}
}
int main(char argc, char *argv[]) {
  parameter *head = create();
  parameter *p = head;
  p = addstr(p, "爱你", "nidhi");
  p = addstr(p, "爱你", "nidhi");
  p = addstr(p, "爱你", "nidhi");
  print(head);
}