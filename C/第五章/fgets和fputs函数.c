#include<stdio.h>
int main(void)
{
  char s[80];
  fputs(fgets(s, 80, stdin), stdout);
  return 0;
}