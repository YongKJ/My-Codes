#include <iostream>
using namespace std;
typedef struct node {
  int *elem;
  int length;
} sqlist;
int main(){
  sqlist l;
  l.elem = new int[10],l.length=0;
  for (int i=0;i<7;i++)
    cin >> l.elem[i], l.length++;
  int n;
  cin >> n;
  cout << l.length << endl;
  for (int i=0;i<l.length;i++)
    if (l.elem[i] == n) {
      for (int j=i; j < l.length - 1; j++)
        l.elem[j] = l.elem[j + 1];
      l.length--, i--;
    }
  for (int i = 0; i < l.length; i++)
    cout << l.elem[i] << (i != l.length - 1 ? " " : "\n");
  return 0;
}