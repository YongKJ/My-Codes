#include <iostream>
using namespace std;
typedef struct node{
  int tag;
  node *link;
  union {
    node *link;
    char data;
  } element;
} glist;
glist *creat() {
  char ch;
  glist *gh;
  cin >> ch;
  if(ch==' ')
    gh = NULL;
  else {
    gh = new glist;
    if (ch == '(')
      gh->tag=1,gh->element.link = creat();
    else
      gh->tag = 0, gh->element.data = ch;
  }
  cin >> ch;
  if (gh != NULL) {
    if (ch == ',')
      gh->link = creat();
  }
    else
      gh->link = NULL;
  return gh;
}
int main() {
  creat();
  return 0;
}