#include <stdio.h>
#include <string.h>
int search(char a[],int c)
{

  int i = 0;
  for (i=0;i<strlen(a);i++)
    if (a[i]==c)
      return i + 1;
    if (i ==strlen(a)&&a[i-1]!=c)
      return -1;
}
int main() 
{
  char c, a[100]="";
  fgets(a, 12, stdin) ;
    scanf("%c", &c);
    printf("%d\n", search(a, c));
}
 