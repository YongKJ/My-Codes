#include <stdio.h>
int Handle(char *p);
int Count(char *p, int x);
int Judge(char *p);
int main(){
  int t,array[14],n,i;
  char a[2];
  scanf("%d", &t);
  while(t--){
    scanf("%d", &n);
    for (i = 0; i < n;i++){
      scanf("%s", a);