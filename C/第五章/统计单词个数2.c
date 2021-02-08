#include <stdio.h>
#include <string.h>
int main() 
{
  char a[50];
  int i, j, k=0, l;
  fgets(a, 50, stdin);
  fputs(a, stdout);
  l = strlen(a);
  for (i=0; i<=l; i++) 
  {
    if (a[i] != ' ') 
    {
      k++;
      while (a[i] != ' ' && a[i] != '\0')
        i++;
    }
  }
  printf("%d\n", k);
}