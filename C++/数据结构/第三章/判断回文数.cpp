#include <iostream>
#include <string>
using namespace std;
typedef struct node {
  char x;
  node *next;
} * link;
int main(){
  string s;
  while (cin >> s) {
    int n = s.size();
    link l = NULL, p, t;
    for (int i = 0; i < n/ 2; i++)
      p = new node, p->x = s[i], p->next = l, l = p;
    for (int i = (n % 2 == 0 ? n / 2 : n / 2 + 1); i < s.size(); i++)
      if (l->x == s[i])
        t = l, l = l->next, delete t;
    cout << (!l ? "Yes" : "No") << endl;
  }
  return 0;
}
    