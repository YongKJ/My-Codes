#include <stdio.h>
#include <string.h>
int main()
{
  int b[26] = {0}, i;
  char a[100];
  fgets(a, 100, stdin);
  for (i = 0; i < strlen(a); i++) 
  {
    if (a[i] >= 'A' && a[i] <= 'Z')
      b[a[i] - 65]++;
     else  if (a[i] >= 'a' && a[i] <= 'z')
      b[a[i] - 97]++;
  }
  for (i = 0; i < 26; i++)
    if (b[i] != 0)
      printf("%d ", b[i]);
}