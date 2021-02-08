#include <stdio.h>
void f(char *s[], int n)
{
  int i, j=0,k;
  char t,*a,*b;
  for (i = 0; i <= n*n/2;i++)
     {
  	if(*s[j]>*s[j+1])
  	{
          a = s[j];
          b = s[j + 1];
          for (k = 0; k < 10; k++) 
          {
            t = *a;
            *a = *b;
            *b = t;
            a++;
            b++;
           }
          } 
        else
            j = (j + 1) % 3;
     }
     /*   for (i = 0; i < n;i++)
       printf("%c ",*s[i]);
     printf("\n");*/
     j = 0;
     for (i = 0; i < n*n/2;i++)
     {
          if(*s[j]==*s[j+1])
          {
          if(*(s[j]+1)>*(s[j+1]+1))
         {
          a = s[j];
          b = s[j + 1];
          for (k = 0; k < 10; k++) 
          {
            t = *a;
            *a = *b;
            *b = t;
            a++;
            b++;
          }
          }
          }
          else
            j = (j + 1) % 3;         
     }
}
int main() 
{
  char *s[4], a[100][10] = {0};
  int i, j, n=4;
  for (i = 0; i < n; i++)
    scanf("%s", a[i]);
  for (i = 0; i < n;i++)
    s[i] = &a[i][0];
  f(s, n);
  for (i = 0; i < n; i++) 
  {
    for (j = 0; j < 10; j++)
      if (a[i][j] != 0)
        printf("%c", a[i][j]);
    printf("\n");
  }
}