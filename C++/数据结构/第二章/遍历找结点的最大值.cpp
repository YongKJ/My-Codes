#include <iostream>
using namespace std;
typedef struct node {
  int x;
  node *next;
} * link;
int main(){
  link la = new node, pa = la;
  for (int i = 0; i < 7; i++) {
    link s = new node;
    cin >> s->x, pa->next = s, pa = s;
  }
  pa->next = NULL;
  link j = la->next;
  for (link i = la->next; i; i = i->next)
    if (i->x > j->x)j = i;
  cout << j->x << endl;
  return 0;
}
  
  