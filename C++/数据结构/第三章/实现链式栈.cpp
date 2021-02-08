#include <iostream>
using namespace std;
typedef struct node {
  int data;
  node *next;
} * link;
int main(){
  link s;
  s = NULL;
  for (int i = 0; i < 7; i++) {
    link p = new node;
    cin >> p->data, p->next = s, s = p;
  }
  for (link &i = s, p; s; s = s->next, delete p)
    cout << i->data << (s->next ? " " : "\n"), p = s;
  return 0;
}
  