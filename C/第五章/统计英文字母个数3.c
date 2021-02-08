#include <stdio.h>
#include <string.h>
int main()
{
  int i;
  char a[100];
  while(fgets(a,100,stdin)!=0)
  {
    int t = 0;
    for (i = 0; i < strlen(a); i++) 
      if ((a[i] >= 'A' && a[i] <= 'Z')||(a[i] >= 'a' && a[i] <= 'z'))
        t++;
    printf("%d\n", t);
  }
}