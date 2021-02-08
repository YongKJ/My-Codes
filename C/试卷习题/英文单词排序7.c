#include <stdio.h>
//#include <string.h>
int strcmp1(char *str1, char *str2)
{
    while(*str1 == *str2)                         //比较两个字符串
    {
      if (*str1 == '\0') 
      {
        return 0;
      }
      str1++;
      str2++;
    }
    return *str1 - *str2; //返回值
}
void f(char *s[],int n)
{
  int i, j;
  char *t;
  for  (i=0;i<n;i++)
    for (j = i + 1; j < n;j++)
      if (strcmp1(s[i], s[j]) > 0) 
      {
        t = s[i];
        s[i] = s[j];
        s[j] = t;
      }
  for (i = 0; i < n; i++)
    printf("%s", s[i]);
}
int main() 
{
  int i;
  char *s[100], a[100][20];
  for (i = 0; fgets(a[i], 20, stdin) != 0; i++) 
  {
    s[i] = a[i];
    if(i==3)
      break;
  }
  f(s, i + 1);
  return 0;
}