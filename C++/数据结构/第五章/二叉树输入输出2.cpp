#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int n, m;
char s[100];
typedef struct node {
  char x;
  node *lc, *rc;
} * list;
void number() {
  float sum = 0;
    for (int i = 0;; i++) {
      sum += pow(2, i);
      if (sum > strlen(s)) {
        sum -= pow(2, i);
        n = sum - (strlen(s) - sum) / 2;
        break;
      }
    }
    cout << n << endl;
}
void insert(list &l) {}
void out() {}
int main(){
  while(n=0,cin>>s){
    number();
  }
  return 0;
}
/*
ABCDE
ABC
*/
    