#include <iostream>
using namespace std;
typedef struct node {
  int x, data;
  node *next;
} * link, *LinkList;
int main(){
  link la, lb, j;
  la = new node, la->next = NULL;
  lb = new node, lb->next = NULL;
  for (int i = 0; i < 3; i++) {
    link s = new node;
    cin >> s->x;
    for ( j = la; j->next; j = j->next)
      if (j->next->x > s->x)break;
    s->next = j->next, j->next = s;
  }
  for (int i = 0; i < 4; i++) {
    link s = new node;
    cin >> s->x;
    for (j = lb; j->next; j = j->next)
      if (j->next->x > s->x)
        break;
    s->next = j->next, j->next = s;
  }
  link pc = la, i, q;
  for (i = lb->next, j = la->next; i && j;) {
    if (i->x < j->x)
      pc->next = i, pc = i, i = i->next;
    else if (i->x > j->x)
      pc->next = j, pc = j, j = j->next;
    else
      pc->next = i, pc = i, i = i->next, q = j, j = j->next, delete q;
  }
  pc->next = i ? i : j, delete lb;
  for (link i=la->next;i;i=i->next)
    cout << i->x << (i->next ? " " : "\n");
  return 0;
}
void MergeList(LinkList &La,LinkList &Lb){
  LinkList  pc=La,i = La->next, j = Lb->next, q;
  while(i&&j){
    if (i->data < j->data) {
      pc->next = i;
      pc = i;
      i = i->next;
    } else if (i->data > j->data) {
      pc->next = j;
      pc = j;
      j = j->next;
    } else {
      pc->next = i;
      pc = i;
      i = i->next;
      q = j;
      j = j->next;
      delete q;
    }
  }
  pc->next = i ? i : j;
  delete Lb;
}
  	
            
  	
  	