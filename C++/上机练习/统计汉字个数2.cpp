#include<stdio.h>
#include<string.h>
int main()
{
char s[1000];
int i;
int k;
int lens;
int aa;

scanf("%d ",&aa);
while (aa--) {

  k = 0;
  gets(s);
  lens = strlen(s);
  for (i = 0; i < lens; i++)
    if ((s[i] < 32) || (s[i] > 126))
      k++;
  printf("%d\n", (k + 1) / 2);
  memset(s, '\0', sizeof(s));
}
}