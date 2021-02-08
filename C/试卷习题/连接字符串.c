#include <stdio.h>
#include <string.h>
void f(char *s1,char *s2,char *s3)
{
  while (*s1 != '\n') //fgets函数会在末尾处添加\n及\0
  {
    *s3= *s1;
    s3++;
    s1++;
  }
  while (*s2 != '\n') 
  {
    *s3 = *s2;
    s3++;
    s2++;
  }
  *s3 = '\0';
}
int main()
{
  char s1[200] = {0}, s2[200] = {0}, s3[400] = {0};
  int i;
  fgets(s1, 100, stdin);
  fgets(s2, 100, stdin);
  f(&s1[0], &s2[0], &s3[0]);
  for (i = 0; i < strlen(s3); i++) 
  {
    if (s3[i] == '\0')
      break;
    else
      printf("%c", s3[i]);
  }
  printf("\n");
}