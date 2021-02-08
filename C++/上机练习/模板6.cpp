/*#include <iostream>
using namespace std;
int main() {
  int i = 4, j;
  cout << i << endl;
  cout << (i >> 1) << endl;
  return 0;
}*/
#include<stdio.h>
int main()
{
    int i,j;
    int a[]={1,2};
    scanf("%d",&j);
    for (i = 3; i != j; i++) {
      a[i] = a[i - 2] + a[i - 1];
      printf("%d", a[i]);
    }
}