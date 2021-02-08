#include <stdio.h>
#include <string.h>
int main()
{
  char a[100]="";
  int i, b = 0,c =0, m =0, n = 0;
  fgets(a,100,stdin);
  for (i = 0; i < strlen(a); i++) 
  {
    if ((a[i] >= 'A' && a[i] <= 'Z') || (a[i] >= 'a' && a[i] <= 'z'))
      b += 1;
    else  if (a[i] == ' ')
      m += 1;
    else   if (a[i] >= '0' && a[i] <= '9')
      c += 1;
    else if(a[i]!=10)
      n += 1;
  }
  printf("%d %d %d %d\n", b, m, c, n);
}