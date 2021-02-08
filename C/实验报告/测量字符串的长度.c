#include <stdio.h>
int intlenstr(char *str)
{
  int  t=0;
  while (*str++ != '\0') 
    t++;
  return t - 1;
}
  int main() 
  {
    char a[100];
    int b;
    fgets(a, 100, stdin);
    b = intlenstr(a);
    printf("%d\n", b);
    return 0;
  }
  