#include <stdio.h>
#include <string.h>
#define N 10
void f(char *s[],int n)
{
  int i, j;
  char t[100];
  for (i = 0; i < n - 1;i++)
    for (j = 0; j < n - 1 - i;j++)
      if (strcmp(s[j],s[j+1])>0) 
      {
        strcpy(t, s[j]);
        strcpy(s[j], s[j + 1]);
        strcpy(s[j + 1], t);
      }
}
int main()
{
  int i, j;
  char *s[N], a[N][10];
  for (i = 0; i < N; i++) 
  {
    scanf("%s",*( a+i));
    s[i] =*( a+i);
  }
  f(s, N);
  for (i = 0; i < N; i++)
  if(i==N-1)
    printf("%s", s[i]);
  else
    printf("%s\n", s[i]);
}