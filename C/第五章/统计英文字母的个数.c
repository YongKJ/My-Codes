#include <stdio.h>
#include <string.h>
#define N 100
int main()
{
  char a[N];
  int i, n[26] = {0};
  fgets(a,14,stdin);
  for (i = 0; i < strlen(a); i++) 
  {
    if (a[i] >= 'A' && a[i] <= 'Z')
      n[a[i] - 65]++;
    else if (a[i] >= 'a' && a[i] <= 'z')
      n[a[i] - 97]++;
  }
  for (i = 0; i < 26; i++)
    if (n[i] != 0)
      printf("%d ", n[i]);
}